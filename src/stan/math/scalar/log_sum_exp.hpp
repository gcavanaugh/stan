#ifndef __STAN__MATH__SCALAR__LOG_SUM_EXP_HPP__
#define __STAN__MATH__SCALAR__LOG_SUM_EXP_HPP__

#include <stan/math/scalar/log1p.hpp>
#include <boost/math/tools/promotion.hpp>
#include <limits>

namespace stan {
  namespace math {

    /**
     * Calculates the log sum of exponetials without overflow.
     *
     * \f$\log (\exp(a) + \exp(b)) = m + \log(\exp(a-m) + \exp(b-m))\f$,
     *
     * where \f$m = max(a,b)\f$.
     * 
     * @param a the first variable
     * @param b the second variable
     */
    template <typename T1, typename T2>
    inline typename boost::math::tools::promote_args<T1,T2>::type
    log_sum_exp(const T2& a, const T1& b) {
      using std::exp;
      if (a > b)
        return a + log1p(exp(b - a));
      return b + log1p(exp(a - b));
    }

  }
}

#endif
