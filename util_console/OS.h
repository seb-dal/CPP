#ifndef _OS_H
#define _OS_H

#define TRUE 1
#define FALSE 0

#if defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__WIN64) || defined(__WIN64__)
#/**/define IS_WINDOWS TRUE
#else
#/**/define IS_WINDOWS FALSE
#endif

#if defined(__APPLE__) || defined(__MACH__)
#/**/define IS_MAC_OS TRUE
#else
#/**/define IS_MAC_OS FALSE
#endif

#if defined(__linux__) || defined(linux) || defined(__linux)
#/**/define IS_LINUX TRUE
#else
#/**/define IS_LINUX FALSE
#endif

#if defined(_WIN64) || defined(__WIN64) || defined(__WIN64__) || defined(__x86_64__) || defined(__MINGW64__)
#/**/define IS_64_BITS TRUE
#/**/define IS_32_BITS FALSE
#else
#/**/define IS_64_BITS FALSE
#/**/define IS_32_BITS TRUE
#endif

#if defined(_MSC_VER)
#/**/define IS_COMPILER_VISUAL_STUDIO TRUE
#/**/define IS_COMPILER_GCC FALSE
#/**/define IS_COMPILER_CLANG FALSE
#/**/define IS_COMPILER_MINGW FALSE
#/**/define IS_COMPILER_OTHER FALSE
#elif defined(__GNUC__)
#/**/define IS_COMPILER_VISUAL_STUDIO FALSE
#/**/define IS_COMPILER_GCC TRUE
#/**/define IS_COMPILER_CLANG FALSE
#/**/define IS_COMPILER_MINGW FALSE
#/**/define IS_COMPILER_OTHER FALSE
#elif defined(__clang__)
#/**/define IS_COMPILER_VISUAL_STUDIO FALSE
#/**/define IS_COMPILER_GCC FALSE
#/**/define IS_COMPILER_CLANG TRUE
#/**/define IS_COMPILER_MINGW FALSE
#/**/define IS_COMPILER_OTHER FALSE
#elif defined(__MINGW32__) || defined(__MINGW64__)
#/**/define IS_COMPILER_VISUAL_STUDIO FALSE
#/**/define IS_COMPILER_GCC FALSE
#/**/define IS_COMPILER_CLANG FALSE
#/**/define IS_COMPILER_MINGW TRUE
#/**/define IS_COMPILER_OTHER FALSE
#else
#/**/define IS_COMPILER_VISUAL_STUDIO FALSE
#/**/define IS_COMPILER_GCC FALSE
#/**/define IS_COMPILER_CLANG FALSE
#/**/define IS_COMPILER_MINGW FALSE
#/**/define IS_COMPILER_OTHER TRUE
#endif



#endif // _OS_H
