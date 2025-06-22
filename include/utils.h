#ifndef UTILS_H
#define UTILS_H

// ==========================
// Common Utility Macros
// ==========================

// Mark unused parameters to avoid compiler warnings
#define UNUSED(x) (void)(x)

// Mark unused multiple parameters (GCC/Clang safe)
#define UNUSED_MULTI(...) (void)(sizeof((int[]){((void)(__VA_ARGS__), 0)...}))

// Get array size (number of elements)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// Minimum and Maximum
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Safe string compare (handles NULL)
#define STR_EQ(a, b) ( (a) && (b) && (strcmp((a), (b)) == 0) )

// Clamp a value between min and max
#define CLAMP(x, min_val, max_val) ( (x) < (min_val) ? (min_val) : ( (x) > (max_val) ? (max_val) : (x) ) )

// ==========================
// Future space for more utils
// ==========================

#endif // UTILS_H
