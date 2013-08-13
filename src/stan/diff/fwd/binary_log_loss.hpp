#ifndef __STAN__DIFF__FWD__BINARY__LOG__LOSS__HPP__
#define __STAN__DIFF__FWD__BINARY__LOG__LOSS__HPP__

#include <stan/diff/fwd/fvar.hpp>
#include <stan/meta/traits.hpp>
#include <stan/math/scalar/binary_log_loss.hpp>

namespace stan{

  namespace diff{

    template <typename T1, typename T2>
    inline
    fvar<typename stan::return_type<T1,T2>::type>
    binary_log_loss(const fvar<T1>& x1, const fvar<T2>& x2){
      using stan::math::binary_log_loss;
      using std::log;
      return fvar<typename 
                  stan::return_type<T1,T2>::type>(binary_log_loss(x1.val_,
                                                                  x2.val_),
                                      -x1.d_ * log(x2.val_)
                                      + x1.d_ * log(1 - x2.val_)
                                      - x2.d_ * x1.val_ / x2.val_ 
                                      + x2.d_ * (1 - x1.val_) / (1 - x2.val_));
    } 

    template <typename T1, typename T2>
    inline
    fvar<typename stan::return_type<T1,T2>::type>
    binary_log_loss(const T1& x1, const fvar<T2>& x2){
      using stan::math::binary_log_loss;
      using std::log;
      return fvar<typename 
                  stan::return_type<T1,T2>::type>(binary_log_loss(x1, x2.val_),
                        - x2.d_ * x1 / x2.val_ 
                        + x2.d_ * (1 - x1) / (1 - x2.val_));
    } 

    template <typename T1, typename T2>
    inline
    fvar<typename stan::return_type<T1,T2>::type>
    binary_log_loss(const fvar<T1>& x1, const T2& x2){
      using stan::math::binary_log_loss;
      using std::log;
      return fvar<typename 
                  stan::return_type<T1,T2>::type>(binary_log_loss(x1.val_, x2),
                                       -x1.d_ * log(x2) 
                                       + x1.d_ * log(1 - x2));
    } 
  }
}
#endif
