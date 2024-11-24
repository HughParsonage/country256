#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP C_any_nonASCII(SEXP);
extern SEXP C_DecodeCountry256(SEXP, SEXP, SEXP);
extern SEXP C_EncodeCountry256(SEXP, SEXP);
extern SEXP C_print256(SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"C_any_nonASCII",     (DL_FUNC) &C_any_nonASCII,     1},
    {"C_DecodeCountry256", (DL_FUNC) &C_DecodeCountry256, 3},
    {"C_EncodeCountry256", (DL_FUNC) &C_EncodeCountry256, 2},
    {"C_print256",         (DL_FUNC) &C_print256,         2},
    {NULL, NULL, 0}
};

void R_init_country256(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
