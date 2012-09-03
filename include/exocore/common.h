#ifndef EXOCORE_H_COMMON
#define EXOCORE_H_COMMON

typedef unsigned char ui8;
typedef signed char i8;
typedef unsigned short ui16;
typedef signed short i16;
typedef unsigned int ui32;
typedef signed int i32;
typedef unsigned long long ui64;
typedef signed long long i64;

typedef float f32;
typedef double f64;

typedef ui64 uiptr;
typedef i64 iptr;

typedef _Bool bool;

#define true 1
#define false 0

#define null ((void*)0)

#define attr(X) __attribute__((X))

#define expect(CND) __builtin_expect(CND, true)
#define prefetch(PTR, WRT) __builtin_prefetch(PTR, WRT)

#define bitsof(X) (sizeof(X) * 8)

#define _STRINGIFY(X) #X
#define STRINGIFY(X) _STRINGIFY(X)

attr(nonnull) attr(noreturn) void panic(const char* const message);

#define PANIC(MSG) panic("Kernel panic at " __FILE__ ":" STRINGIFY(__LINE__) ": " MSG)

#ifdef EXOCORE_DEBUG
#    define ASSERT(CND) \
         do \
         { \
             if (!expect(!!(CND))) \
                 PANIC("Assertion failed: " STRINGIFY(CND)); \
         } \
         while (false);
#else
#    define ASSERT(CND)
#endif

#define STATIC_ASSERT(CND) _Static_assert(CND, STRINGIFY(CND))

#endif
