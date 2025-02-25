//  (C) Copyright John Maddock 2001.
//  (C) Copyright Jens Maurer 2001.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  config for libstdc++ v3
//  not much to go in here:

#define RTIBOOST_GNU_STDLIB 1

#ifdef __GLIBCXX__
#define RTIBOOST_STDLIB "GNU libstdc++ version " RTIBOOST_STRINGIZE(__GLIBCXX__)
#else
#define RTIBOOST_STDLIB "GNU libstdc++ version " RTIBOOST_STRINGIZE(__GLIBCPP__)
#endif

#if !defined(_GLIBCPP_USE_WCHAR_T) && !defined(_GLIBCXX_USE_WCHAR_T)
#  define RTIBOOST_NO_CWCHAR
#  define RTIBOOST_NO_CWCTYPE
#  define RTIBOOST_NO_STD_WSTRING
#  define RTIBOOST_NO_STD_WSTREAMBUF
#endif

#if defined(__osf__) && !defined(_REENTRANT) \
  && ( defined(_GLIBCXX_HAVE_GTHR_DEFAULT) || defined(_GLIBCPP_HAVE_GTHR_DEFAULT) )
// GCC 3 on Tru64 forces the definition of _REENTRANT when any std lib header
// file is included, therefore for consistency we define it here as well.
#  define _REENTRANT
#endif

#ifdef __GLIBCXX__ // gcc 3.4 and greater:
#  if defined(_GLIBCXX_HAVE_GTHR_DEFAULT) \
        || defined(_GLIBCXX__PTHREADS) \
        || defined(_GLIBCXX_HAS_GTHREADS) \
        || defined(_WIN32) \
        || defined(_AIX) \
        || defined(__HAIKU__)
      //
      // If the std lib has thread support turned on, then turn it on in Boost
      // as well.  We do this because some gcc-3.4 std lib headers define _REENTANT
      // while others do not...
      //
#     define RTIBOOST_HAS_THREADS
#  else
#     define RTIBOOST_DISABLE_THREADS
#  endif
#elif defined(__GLIBCPP__) \
        && !defined(_GLIBCPP_HAVE_GTHR_DEFAULT) \
        && !defined(_GLIBCPP__PTHREADS)
   // disable thread support if the std lib was built single threaded:
#  define RTIBOOST_DISABLE_THREADS
#endif

#if (defined(linux) || defined(__linux) || defined(__linux__)) && defined(__arm__) && defined(_GLIBCPP_HAVE_GTHR_DEFAULT)
// linux on arm apparently doesn't define _REENTRANT
// so just turn on threading support whenever the std lib is thread safe:
#  define RTIBOOST_HAS_THREADS
#endif

#if !defined(_GLIBCPP_USE_LONG_LONG) \
    && !defined(_GLIBCXX_USE_LONG_LONG)\
    && defined(RTIBOOST_HAS_LONG_LONG)
// May have been set by compiler/*.hpp, but "long long" without library
// support is useless.
#  undef RTIBOOST_HAS_LONG_LONG
#endif

// Apple doesn't seem to reliably defined a *unix* macro
#if !defined(CYGWIN) && (  defined(__unix__)  \
                        || defined(__unix)    \
                        || defined(unix)      \
                        || defined(__APPLE__) \
                        || defined(__APPLE)   \
                        || defined(APPLE))
#  include <unistd.h>
#endif

#if defined(__GLIBCXX__) || (defined(__GLIBCPP__) && __GLIBCPP__>=20020514) // GCC >= 3.1.0
#  define RTIBOOST_STD_EXTENSION_NAMESPACE __gnu_cxx
#  define RTIBOOST_HAS_SLIST
#  define RTIBOOST_HAS_HASH
#  define RTIBOOST_SLIST_HEADER <ext/slist>
# if !defined(__GNUC__) || __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 3)
#   define RTIBOOST_HASH_SET_HEADER <ext/hash_set>
#   define RTIBOOST_HASH_MAP_HEADER <ext/hash_map>
# else
#   define RTIBOOST_HASH_SET_HEADER <backward/hash_set>
#   define RTIBOOST_HASH_MAP_HEADER <backward/hash_map>
# endif
#endif

//
// Decide whether we have C++11 support turned on:
//
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus >= 201103)
#  define RTIBOOST_LIBSTDCXX11
#endif
//
//  Decide which version of libstdc++ we have, normally
//  stdlibc++ C++0x support is detected via __GNUC__, __GNUC_MINOR__, and possibly
//  __GNUC_PATCHLEVEL__ at the suggestion of Jonathan Wakely, one of the stdlibc++
//  developers. He also commented:
//
//       "I'm not sure how useful __GLIBCXX__ is for your purposes, for instance in
//       GCC 4.2.4 it is set to 20080519 but in GCC 4.3.0 it is set to 20080305.
//       Although 4.3.0 was released earlier than 4.2.4, it has better C++0x support
//       than any release in the 4.2 series."
//
//  Another resource for understanding stdlibc++ features is:
//  http://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html#manual.intro.status.standard.200x
//
//  However, using the GCC version number fails when the compiler is clang since this
//  only ever claims to emulate GCC-4.2, see https://svn.boost.org/trac/boost/ticket/7473
//  for a long discussion on this issue.  What we can do though is use clang's __has_include
//  to detect the presence of a C++11 header that was introduced with a specific GCC release.
//  We still have to be careful though as many such headers were buggy and/or incomplete when
//  first introduced, so we only check for headers that were fully featured from day 1, and then
//  use that to infer the underlying GCC version:
//
#ifdef __clang__

#if __has_include(<experimental/any>)
#  define RTIBOOST_LIBSTDCXX_VERSION 50100
#elif __has_include(<shared_mutex>)
#  define RTIBOOST_LIBSTDCXX_VERSION 40900
#elif __has_include(<ext/cmath>)
#  define RTIBOOST_LIBSTDCXX_VERSION 40800
#elif __has_include(<scoped_allocator>)
#  define RTIBOOST_LIBSTDCXX_VERSION 40700
#elif __has_include(<typeindex>)
#  define RTIBOOST_LIBSTDCXX_VERSION 40600
#elif __has_include(<future>)
#  define RTIBOOST_LIBSTDCXX_VERSION 40500
#elif  __has_include(<ratio>)
#  define RTIBOOST_LIBSTDCXX_VERSION 40400
#elif __has_include(<array>)
#  define RTIBOOST_LIBSTDCXX_VERSION 40300
#endif
//
//  GCC 4.8 and 9 add working versions of <atomic> and <regex> respectively.
//  However, we have no test for these as the headers were present but broken
//  in early GCC versions.
//
#endif

#if defined(__SUNPRO_CC) && (__SUNPRO_CC >= 0x5130) && (__cplusplus >= 201103L)
//
// Oracle Solaris compiler uses it's own verison of libstdc++ but doesn't 
// set __GNUC__
//
#define RTIBOOST_LIBSTDCXX_VERSION 40800
#endif

#if !defined(RTIBOOST_LIBSTDCXX_VERSION)
#  define RTIBOOST_LIBSTDCXX_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#endif

//  C++0x headers in GCC 4.3.0 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 40300) || !defined(RTIBOOST_LIBSTDCXX11)
#  define RTIBOOST_NO_CXX11_HDR_ARRAY
#  define RTIBOOST_NO_CXX11_HDR_TUPLE
#  define RTIBOOST_NO_CXX11_HDR_UNORDERED_MAP
#  define RTIBOOST_NO_CXX11_HDR_UNORDERED_SET
#  define RTIBOOST_NO_CXX11_HDR_FUNCTIONAL
#endif

//  C++0x headers in GCC 4.4.0 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 40400) || !defined(RTIBOOST_LIBSTDCXX11)
#  define RTIBOOST_NO_CXX11_HDR_CONDITION_VARIABLE
#  define RTIBOOST_NO_CXX11_HDR_FORWARD_LIST
#  define RTIBOOST_NO_CXX11_HDR_INITIALIZER_LIST
#  define RTIBOOST_NO_CXX11_HDR_MUTEX
#  define RTIBOOST_NO_CXX11_HDR_RATIO
#  define RTIBOOST_NO_CXX11_HDR_SYSTEM_ERROR
#  define RTIBOOST_NO_CXX11_SMART_PTR
#else
#  define RTIBOOST_HAS_TR1_COMPLEX_INVERSE_TRIG 
#  define RTIBOOST_HAS_TR1_COMPLEX_OVERLOADS 
#endif

//  C++0x features in GCC 4.5.0 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 40500) || !defined(RTIBOOST_LIBSTDCXX11)
#  define RTIBOOST_NO_CXX11_NUMERIC_LIMITS
#  define RTIBOOST_NO_CXX11_HDR_FUTURE
#  define RTIBOOST_NO_CXX11_HDR_RANDOM
#endif

//  C++0x features in GCC 4.6.0 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 40600) || !defined(RTIBOOST_LIBSTDCXX11)
#  define RTIBOOST_NO_CXX11_HDR_TYPEINDEX
#  define RTIBOOST_NO_CXX11_ADDRESSOF
#endif

//  C++0x features in GCC 4.7.0 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 40700) || !defined(RTIBOOST_LIBSTDCXX11)
// Note that although <chrono> existed prior to 4.7, "steady_clock" is spelled "monotonic_clock"
// so 4.7.0 is the first truely conforming one.
#  define RTIBOOST_NO_CXX11_HDR_CHRONO
#  define RTIBOOST_NO_CXX11_ALLOCATOR
#endif
//  C++0x features in GCC 4.8.0 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 40800) || !defined(RTIBOOST_LIBSTDCXX11)
// Note that although <atomic> existed prior to gcc 4.8 it was largely unimplemented for many types:
#  define RTIBOOST_NO_CXX11_HDR_ATOMIC
#  define RTIBOOST_NO_CXX11_HDR_THREAD
#endif
//  C++0x features in GCC 4.9.0 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 40900) || !defined(RTIBOOST_LIBSTDCXX11)
// Although <regex> is present and compilable against, the actual implementation is not functional
// even for the simplest patterns such as "\d" or "[0-9]". This is the case at least in gcc up to 4.8, inclusively.
#  define RTIBOOST_NO_CXX11_HDR_REGEX
#endif

#if defined(__clang_major__) && ((__clang_major__ < 3) || ((__clang_major__ == 3) && (__clang_minor__ < 7)))
// As of clang-3.6, libstdc++ header <atomic> throws up errors with clang:
#  define RTIBOOST_NO_CXX11_HDR_ATOMIC
#endif
//
//  C++0x features in GCC 5.1 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 50100) || !defined(RTIBOOST_LIBSTDCXX11)
#  define RTIBOOST_NO_CXX11_HDR_TYPE_TRAITS
#  define RTIBOOST_NO_CXX11_HDR_CODECVT
#  define RTIBOOST_NO_CXX11_ATOMIC_SMART_PTR
#  define RTIBOOST_NO_CXX11_STD_ALIGN
#endif

// Manually added by RTI from Boost 1.70
//
//  C++17 features in GCC 7.1 and later
//
#if (RTIBOOST_LIBSTDCXX_VERSION < 70100) || (__cplusplus <= 201402L)
#  define RTIBOOST_NO_CXX17_STD_INVOKE
#  define RTIBOOST_NO_CXX17_STD_APPLY
#  define RTIBOOST_NO_CXX17_HDR_OPTIONAL
#  define RTIBOOST_NO_CXX17_HDR_STRING_VIEW
#  define RTIBOOST_NO_CXX17_HDR_VARIANT
#endif

#if defined(__has_include)
#if !__has_include(<shared_mutex>)
#  define RTIBOOST_NO_CXX14_HDR_SHARED_MUTEX
#elif __cplusplus <= 201103
#  define RTIBOOST_NO_CXX14_HDR_SHARED_MUTEX
#endif
#elif __cplusplus < 201402 || (RTIBOOST_LIBSTDCXX_VERSION < 40900) || !defined(RTIBOOST_LIBSTDCXX11)
#  define RTIBOOST_NO_CXX14_HDR_SHARED_MUTEX
#endif

//
// Headers not present on Solaris with the Oracle compiler:
#if defined(__SUNPRO_CC)
#define RTIBOOST_NO_CXX11_HDR_FUTURE
#define RTIBOOST_NO_CXX11_HDR_FORWARD_LIST 
#define RTIBOOST_NO_CXX11_HDR_ATOMIC
// shared_ptr is present, but is not convertible to bool
// which causes all kinds of problems especially in Boost.Thread
// but probably elsewhere as well.
#define RTIBOOST_NO_CXX11_SMART_PTR
#endif

#if (!defined(_GLIBCXX_HAS_GTHREADS) || !defined(_GLIBCXX_USE_C99_STDINT_TR1))
   // Headers not always available:
#  ifndef RTIBOOST_NO_CXX11_HDR_CONDITION_VARIABLE
#     define RTIBOOST_NO_CXX11_HDR_CONDITION_VARIABLE
#  endif
#  ifndef RTIBOOST_NO_CXX11_HDR_MUTEX
#     define RTIBOOST_NO_CXX11_HDR_MUTEX
#  endif
#  ifndef RTIBOOST_NO_CXX11_HDR_THREAD
#     define RTIBOOST_NO_CXX11_HDR_THREAD
#  endif
#  ifndef RTIBOOST_NO_CXX14_HDR_SHARED_MUTEX
#     define RTIBOOST_NO_CXX14_HDR_SHARED_MUTEX
#  endif
#endif

#if (!defined(_GTHREAD_USE_MUTEX_TIMEDLOCK) || (_GTHREAD_USE_MUTEX_TIMEDLOCK == 0)) && !defined(RTIBOOST_NO_CXX11_HDR_MUTEX)
// Timed mutexes are not always available:
#  define RTIBOOST_NO_CXX11_HDR_MUTEX
#endif

//  --- end ---
