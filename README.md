![Katawa Shoujo - Game Boy Advance Port](site/logo-github-nobg.png)

# Katawa Shoujo - Game Boy Advance Port

A faithful adaptation of *Katawa Shoujo* for the GBA, powered by the [Butano framework](https://github.com/GValiente/butano). Includes Python tools to convert assets and scripts from the **[Katawa Shoujo: Re-Engineered](https://github.com/fleetingheart/ksre)** project.

<div style="display: flex; justify-content: flex-start;">
    <img src="site/agb-ks-screenshot-1.png" alt="Katawa Shoujo - Game Boy Advance Port (event screenshot)" style="width: 50%;">
</div>
<div style="display: flex; justify-content: flex-start;">
    <img src="site/agb-ks-screenshot-2-en.png" alt="Katawa Shoujo - Game Boy Advance Port (dialog screenshot - en)" style="width: 50%;">
    <img src="site/agb-ks-screenshot-2-ru.png" alt="Katawa Shoujo - Game Boy Advance Port (dialog screenshot - ru)" style="width: 50%;">
</div>

---

## Features

- **Visual Novel Gameplay** optimized for GBA.
- **Tools** for converting assets and scripts.

---

## Requirements

1. **DevkitARM** ([Setup Guide](https://devkitpro.org/wiki/Getting_Started))
   - Windows: Use [DevkitPro Installer](https://github.com/devkitPro/installer/releases/latest).
   - macOS/Linux: Install via `devkitpro-pacman`.
     ```bash
     sudo dkp-pacman -S devkitARM
     ```
   - Verify: `arm-none-eabi-gcc --version`
2. **Python 3.12** for tools.
3. **Butano** [afska's fork](https://github.com/afska/butano)
4. ***For CLion IDE users***:
   - Open "Settings" > "Advanced Settings" > "Makefile"
   - Replace "--just-print" with "V=1" for analyzer options.

---

## Contribution

1. **Fork** the repository.
2. **Clone** the forked repository.
3. **Create a branch** for your feature.
4. **Test** your changes on emulators and hardware.
5. Submit a pull request.

---

## Credits

- **[Four Leaf Studios](https://www.katawa-shoujo.com)** for creating *Katawa Shoujo*.
- **[Butano Framework](https://github.com/GValiente/butano)** by GValiente for the GBA development framework.
- **[afska](https://github.com/afska)** for GSM Player integration for Butano
- **[GSM Player](https://github.com/pinobatch/gsmplayer-gba)** by Damian Yerrick for the GBA audio player.
- **[libagmv](https://github.com/RyandracusCodesGames/libagmv)** by RyandracusCodesGames for the video player.
- **[Katawa Shoujo: Re-Engineered](https://codeberg.org/fhs/katawa-shoujo-re-engineered)** by **[Fleeting Heartbeat Studios](https://www.fhs.sh/)** for the great adaptation Katawa Shoujo to the modern Ren'Py engine.

---

## License

This project is licensed under the **Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License**. See the [LICENSE](LICENSE.md) file for details.

