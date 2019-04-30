#include <rray.h>
#include <dispatch.h>

// -----------------------------------------------------------------------------

template <typename T>
xt::rarray<rlogical> rray__greater_impl(const xt::rarray<T>& x, const xt::rarray<T>& y) {
  const int& dims = rray__dims2(rray__dims(SEXP(x)), rray__dims(SEXP(y)));

  auto x_view = rray__increase_dims_view(x, dims);
  auto y_view = rray__increase_dims_view(y, dims);

  return x_view > y_view;
}

// [[Rcpp::export]]
Rcpp::RObject rray__greater(Rcpp::RObject x, Rcpp::RObject y) {
  DISPATCH_BINARY(rray__greater_impl, x, y);
}

// -----------------------------------------------------------------------------

template <typename T>
xt::rarray<rlogical> rray__greater_equal_impl(const xt::rarray<T>& x, const xt::rarray<T>& y) {
  const int& dims = rray__dims2(rray__dims(SEXP(x)), rray__dims(SEXP(y)));

  auto x_view = rray__increase_dims_view(x, dims);
  auto y_view = rray__increase_dims_view(y, dims);

  return x_view >= y_view;
}

// [[Rcpp::export]]
Rcpp::RObject rray__greater_equal(Rcpp::RObject x, Rcpp::RObject y) {
  DISPATCH_BINARY(rray__greater_equal_impl, x, y);
}

