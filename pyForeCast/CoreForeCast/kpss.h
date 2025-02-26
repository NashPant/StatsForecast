#pragma once

#include <Eigen/Dense>
#include <iterator>
#include <cmath>
#include <numeric>
#include <memory>

template <typename Iterator>
auto KPSS(Iterator begin, Iterator end, size_t lags) {
  
//  template<typename Iterator> 
  //using T = std::iter_value_t<Iterator>;
  using T = typename Iterator::value_type;
  auto n = std::distance(begin, end);

  //const Eigen::Map<const Eigen::VectorX<T>> v(std::to_address(begin), n);
  const Eigen::Map<const Eigen::VectorX<T>> v(&(*begin), n);
  T mean = v.mean();
  Eigen::VectorX<T> resids = v.array() - mean;
  Eigen::VectorX<T> cresids(n);
  std::partial_sum(resids.begin(), resids.end(), cresids.begin());
  T eta = cresids.squaredNorm() / (n * n);
  T s = resids.array().square().sum();
  for (size_t i = 1; i < lags + 1; ++i) {
    T tmp = resids.head(n - i).dot(resids.tail(n - i));
    s += 2 * tmp * (1.0 - (i / (lags + 1.0)));
  }
  return n * eta / s;
}
