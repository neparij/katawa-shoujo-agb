#ifndef GBA_MATH_H
#define GBA_MATH_H

typedef int32_t FIXED;
typedef struct { int x, y; } POINT;
typedef struct { int left, top, right, bottom; } RECT;
typedef struct { FIXED x, y, z; } VECTOR;

#define ABS(x)     ((x) >= 0 ? (x) : -(x))
#define SGN(x)     ((x) >= 0 ? 1 : -1)
#define SGN3(x)    ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define MIN(a, b)  ((a) < (b) ? (a) : (b))

#define CLAMP(x, min, max)     ((x) >= (max) ? ((max)-1) : ((x) < (min) ? (min) : (x)))
#define IN_RANGE(x, min, max)  ((uint32_t)((x) - (min)) < (uint32_t)((max) - (min)))
#define REFLECT(x, min, max)   ((x) >= (max) ? 2 * ((max) - 1) - (x) : ((x) < (min) ? 2 * (min) - (x) : (x)))
#define WRAP(x, min, max)      ((x) >= (max) ? (x) + (min) - (max) : ((x) < (min) ? (x) + (max) - (min) : (x)))

// --- Scalar math functions ---
static inline int min(int a, int b) {
    return a < b ? a : b;
}

static inline int max(int a, int b) {
    return a > b ? a : b;
}

static inline int clamp(int x, int min_val, int max_val) {
    return x < min_val ? min_val : (x >= max_val ? max_val - 1 : x);
}

static inline int clampi(int x, int min_val, int max_val) {
    return x < min_val ? min_val : (x > max_val ? max_val : x);
}

static inline float clampf(float x, float min_val, float max_val) {
    return x < min_val ? min_val : (x > max_val ? max_val : x);
}

static inline int reflect(int x, int min_val, int max_val) {
    return x < min_val ? 2 * min_val - x : (x >= max_val ? 2 * (max_val - 1) - x : x);
}

static inline int wrap(int x, int min_val, int max_val) {
    int range = max_val - min_val;
    while (x < min_val) x += range;
    while (x >= max_val) x -= range;
    return x;
}

// --- Fixed point ---
#define FIX_SHIFT   8
#define FIX_SCALE   (1 << FIX_SHIFT)
#define FIX_MASK    (FIX_SCALE - 1)
#define FIX_ONE     FIX_SCALE

#define FX_RECIPROCAL(a, fp)   (((1 << (fp)) + (a) - 1) / (a))
#define FX_RECIMUL(x, a, fp)   (((x) * ((1 << (fp)) + (a) - 1) / (a)) >> (fp))

static inline FIXED int2fx(int d)        { return d << FIX_SHIFT; }
static inline int fx2int(FIXED fx)       { return fx >> FIX_SHIFT; }
static inline float fx2float(FIXED fx)   { return fx / (float)FIX_SCALE; }
static inline FIXED float2fx(float f)    { return (FIXED)(f * FIX_SCALE); }

static inline FIXED fxadd(FIXED a, FIXED b) { return a + b; }
static inline FIXED fxsub(FIXED a, FIXED b) { return a - b; }
static inline FIXED fxmul(FIXED a, FIXED b) { return (a * b) >> FIX_SHIFT; }
static inline FIXED fxdiv(FIXED a, FIXED b) { return (a << FIX_SHIFT) / b; }

// --- Point ---
static inline POINT pt(int x, int y) { POINT p = { x, y }; return p; }

static inline POINT pt_add(POINT a, POINT b) {
    POINT r = { a.x + b.x, a.y + b.y };
    return r;
}

static inline POINT pt_sub(POINT a, POINT b) {
    POINT r = { a.x - b.x, a.y - b.y };
    return r;
}

static inline POINT pt_scale(POINT a, int s) {
    POINT r = { a.x * s, a.y * s };
    return r;
}

static inline int pt_dot(POINT a, POINT b) {
    return a.x * b.x + a.y * b.y;
}

static inline int pt_cross(POINT a, POINT b) {
    return a.x * b.y - a.y * b.x;
}

static inline bool pt_in_rect(POINT p, RECT r) {
    return p.x >= r.left && p.x < r.right && p.y >= r.top && p.y < r.bottom;
}

// --- Rect ---
static inline int rc_width(const RECT *r)  { return r->right - r->left; }
static inline int rc_height(const RECT *r) { return r->bottom - r->top; }

static inline RECT rc_set(int x, int y, int w, int h) {
    RECT r = { x, y, x + w, y + h };
    return r;
}

// --- Vector ---
static inline VECTOR vec(FIXED x, FIXED y, FIXED z) {
    VECTOR v = { x, y, z };
    return v;
}

static inline VECTOR vec_add(VECTOR a, VECTOR b) {
    VECTOR r = { a.x + b.x, a.y + b.y, a.z + b.z };
    return r;
}

static inline VECTOR vec_sub(VECTOR a, VECTOR b) {
    VECTOR r = { a.x - b.x, a.y - b.y, a.z - b.z };
    return r;
}

static inline VECTOR vec_scale(VECTOR a, FIXED s) {
    VECTOR r = {
        fxmul(a.x, s),
        fxmul(a.y, s),
        fxmul(a.z, s)
    };
    return r;
}

static inline FIXED vec_dot(VECTOR a, VECTOR b) {
    return fxadd(fxadd(fxmul(a.x, b.x), fxmul(a.y, b.y)), fxmul(a.z, b.z));
}

static inline VECTOR vec_cross(VECTOR a, VECTOR b) {
    VECTOR r = {
        fxsub(fxmul(a.y, b.z), fxmul(a.z, b.y)),
        fxsub(fxmul(a.z, b.x), fxmul(a.x, b.z)),
        fxsub(fxmul(a.x, b.y), fxmul(a.y, b.x))
    };
    return r;
}

#endif // GBA_MATH_H