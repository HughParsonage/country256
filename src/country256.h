#ifndef country256R_H
#define country256R_H

#if _OPENMP
#include <omp.h>
#define AS_NTHREAD int nThread = as_nThread(nthreads);
#else
#define AS_NTHREAD
#endif

#include <R.h>
#define USE_RINTERNALS
#include <Rinternals.h>
#include <Rversion.h>
#include <stdint.h> // for uint64_t rather than unsigned long long, intptr
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#if defined _OPENMP && _OPENMP >= 201511
#define FORLOOP(content) do {                                           \
_Pragma("omp parallel for num_threads(nThread)")                        \
  for (R_xlen_t i = 0; i < N; ++i) {                                    \
    content;                                                            \
  }                                                                     \
} while (0);                                                            \

#else
#define FORLOOP(content) do {                                       \
for (R_xlen_t i = 0; i < N; ++i) {                                  \
  content;                                                          \
}                                                                   \
} while (0);
#endif




#define MIN_YEAR 1948
#define MAX_YEAR 2075
#define NA_INT -2147483648
#ifndef NaN
  #define NaN NAN
#endif



typedef struct {
  unsigned int year : 7;
  unsigned int month : 4;
} YearMonth;

// validate dates are 1948-01-01 to 2075-12-31 (approximately 127 years)
#define MAX_IDATE 38715
#define MIN_IDATE -8036
#define NEG_MIN_IDATE 8036
#define RANGE_IDATE 46570

#define CLASS_FY 1
#define CLASS_Date 2
#define CLASS_IDate 3
#define CLASS_integer 4
#define CLASS_character 5


#endif
