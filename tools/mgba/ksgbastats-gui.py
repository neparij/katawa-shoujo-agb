#!/usr/bin/env python3
"""
GBA Stats Monitor
------------------------------------------
Receives colon-separated integer metrics over TCP and displays:
 - textual metrics (CPU, EWRAM, BG, SPR)
 - live plots for CPU and EWRAM usage
"""

import math
import queue
import socket
import sys
import threading
import tkinter as tk
from collections import deque
from dataclasses import dataclass
from tkinter import ttk

import matplotlib

matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.collections import LineCollection

# =============================================================================
# CONFIGURATION
# =============================================================================
HOST = "127.0.0.1"
PORT = 8888

CPU_HISTORY_LEN = 300

@dataclass
class Metric:
    value: int
    max_value: int
    unit: str
    show_relative: bool


metrics = {
    "CPU": Metric(0, 100, "%", False),
    "EWRAM": Metric(0, 262_144, "Bytes", True),
    "BG Tiles": Metric(0, 2048, "", True),
    "BG Maps": Metric(0, 4096, "", True),
    "BG Palettes": Metric(0, 256, "", True),
    "SPR Tiles": Metric(0, 1024, "", True),
    "SPR Palettes": Metric(0, 256, "", True),
}

# thread-safe queue (producer -> consumer)
data_q = queue.Queue()

# history buffers
cpu_history = deque(maxlen=CPU_HISTORY_LEN)
ewram_history = deque(maxlen=CPU_HISTORY_LEN)

running = True  # global exit flag

# =============================================================================
# GUI SETUP
# =============================================================================
root = tk.Tk()
root.title("GBA Stats Monitor")

frame_metrics = ttk.Frame(root)
frame_metrics.pack(side=tk.LEFT, padx=10, pady=10)

labels = {}
for i, key in enumerate(metrics):
    lbl = ttk.Label(frame_metrics, text=f"{key}: 0", anchor="w")
    lbl.grid(row=i, column=0, sticky="w", pady=2)
    labels[key] = lbl

dpi = root.winfo_fpixels("1i")

fig, (ax_cpu, ax_ram) = plt.subplots(2, 1, figsize=(7, 5), dpi=dpi)
plt.subplots_adjust(hspace=0.35)
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.get_tk_widget().pack(side=tk.RIGHT, padx=10, pady=10)

plot_y_cpu = dict(size=100, min=100, max=1000)
plot_y_ram = dict(size=262_144, min=262_144, max=262_144)

# =============================================================================
# HELPERS
# =============================================================================
def cpu_color(value: float):
    """Gradient green->red for CPU usage."""
    val = min(value, 150) / 150.0
    return val, 1 - val, 0

def ram_color(value: float):
    """Gradient blue->red for EWRAM usage."""
    ratio = min(max(value / metrics["EWRAM"].max_value, 0), 1)
    return ratio, 0.3, 1 - ratio

# =============================================================================
# TCP THREAD (PRODUCER)
# =============================================================================
def tcp_thread():
    global running
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.settimeout(1.0)
            try:
                s.connect((HOST, PORT))
                print(f"Connected to {HOST}:{PORT}")
            except Exception as e:
                print(f"Failed to connect to {HOST}:{PORT} -> {e}", file=sys.stderr)
                return

            buffer = ""
            while running:
                try:
                    data = s.recv(4096)
                    if not data:
                        break
                    buffer += data.decode(errors="ignore")

                    while "\n" in buffer:
                        line, buffer = buffer.split("\n", 1)
                        parts = line.strip().split(":")
                        if len(parts) < 7:
                            continue
                        try:
                            values = tuple(int(p) for p in parts[:7])
                        except ValueError:
                            continue
                        data_q.put(values)

                except socket.timeout:
                    continue
                except (ConnectionResetError, BrokenPipeError):
                    break
                except Exception as ex:
                    print("TCP thread error:", ex, file=sys.stderr)
                    break
    finally:
        running = False
        print("TCP thread exiting")

# =============================================================================
# GUI UPDATE LOOP (CONSUMER)
# =============================================================================
def update_gui():
    """Consumes data from queue and redraws GUI."""
    global running

    # Drain queue
    while not data_q.empty():
        try:
            values = data_q.get_nowait()
        except queue.Empty:
            break

        (
            metrics["CPU"].value,
            metrics["EWRAM"].value,
            metrics["BG Tiles"].value,
            metrics["BG Maps"].value,
            metrics["BG Palettes"].value,
            metrics["SPR Tiles"].value,
            metrics["SPR Palettes"].value,
        ) = values

        cpu_history.append(metrics["CPU"].value)
        ewram_history.append(metrics["EWRAM"].value)

    # Update labels
    for key, lbl in labels.items():
        m = metrics[key]
        text = f"{key}: {m.value}"
        if m.show_relative and m.max_value:
            pct = math.ceil(m.value / m.max_value * 100)
            text += f" / {m.max_value} {m.unit} ({pct}%)"
        else:
            text += f" {m.unit}"
        lbl.config(text=text)

    # Redraw CPU plot
    y_cpu = list(cpu_history)
    if y_cpu:
        _draw_line_plot(ax_cpu, y_cpu, "CPU Usage (%)", plot_y_cpu, cpu_color)

    # Redraw EWRAM plot
    y_ram = list(ewram_history)
    if y_ram:
        _draw_line_plot(ax_ram, y_ram, "EWRAM Usage (Bytes)", plot_y_ram, ram_color)

    canvas.draw_idle()

    if running and root.winfo_exists():
        root.after(33, update_gui)
    else:
        try:
            root.quit()
        except tk.TclError:
            pass

# -----------------------------------------------------------------------------
def _draw_line_plot(ax, y_values, title, scale, color_fn):
    """Draws gradient line plot with adaptive Y scale."""
    x_values = range(len(y_values))

    max_now = max(y_values)
    if max_now >= scale["size"]:
        scale["size"] = min(max_now, scale["max"])
    elif scale["size"] > scale["min"]:
        scale["size"] = max(scale["size"] - 2 - (scale["size"] - scale["min"]) / (scale["max"] / 100), scale["min"])

    ax.clear()
    ax.set_title(title, fontsize=10)
    ax.tick_params(axis="both", which="major", labelsize=8)
    ax.grid(True, linestyle="--", linewidth=0.5)
    ax.set_xlim(0, CPU_HISTORY_LEN)
    ax.set_ylim(0, scale["size"])

    if len(y_values) >= 2:
        segments = []
        colors = []
        for i in range(len(y_values) - 1):
            segments.append([(x_values[i], y_values[i]), (x_values[i + 1], y_values[i + 1])])
            avg_val = (y_values[i] + y_values[i + 1]) / 2
            colors.append(color_fn(avg_val))
        lc = LineCollection(segments, colors=colors, linewidths=1.2)
        ax.add_collection(lc)

# =============================================================================
# SHUTDOWN
# =============================================================================
def on_close():
    global running
    running = False
    # Give update_gui time to notice running=False
    root.after(100, lambda: root.destroy() if root.winfo_exists() else None)

# =============================================================================
# MAIN
# =============================================================================
if __name__ == "__main__":
    t = threading.Thread(target=tcp_thread, daemon=True)
    t.start()

    root.protocol("WM_DELETE_WINDOW", on_close)
    root.after(33, update_gui)
    root.mainloop()
