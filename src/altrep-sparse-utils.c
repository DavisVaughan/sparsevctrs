#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

SEXP extract_val(SEXP x) {
  SEXP data1 = R_altrep_data1(x);
  SEXP out = VECTOR_ELT(data1, 0);
  return out;
}

SEXP extract_pos(SEXP x) {
  SEXP data1 = R_altrep_data1(x);
  SEXP out = VECTOR_ELT(data1, 1);
  return out;
}

R_xlen_t extract_len(SEXP x) {
  SEXP data1 = R_altrep_data1(x);
  SEXP len = VECTOR_ELT(data1, 2);

  R_xlen_t out = (R_xlen_t) INTEGER_ELT(len, 0);

  return out;
}

int is_altrep(SEXP x) {
  return ALTREP(x);
}

SEXP ffi_extract_altrep_class(SEXP x) {
  if (!is_altrep(x)) {
    return(R_NilValue);
  }

  return ATTRIB(ALTREP_CLASS(x));
}
