#ifndef __STAN__DIFF__REV__BESSEL_FIRST_KIND_HPP__
#define __STAN__DIFF__REV__BESSEL_FIRST_KIND_HPP__

#include <stan/diff/rev/var.hpp>
#include <stan/diff/rev/op/vv_vari.hpp>
#include <stan/diff/rev/op/vd_vari.hpp>
#include <stan/diff/rev/op/dv_vari.hpp>
#include <stan/math/constants.hpp>
#include <stan/math/scalar/bessel_first_kind.hpp>

namespace stan {
  namespace diff {

    namespace {

      class bessel_first_kind_dv_vari : public op_dv_vari {
      public:
        bessel_first_kind_dv_vari(int a, vari* bvi) :
          op_dv_vari(stan::math::bessel_first_kind(a, bvi->val_), a, bvi) {
        }
        void chain() {
          bvi_->adj_ += adj_ * (ad_ * stan::math::bessel_first_kind(ad_, bvi_->val_) / bvi_->val_ - stan::math::bessel_first_kind(ad_ + 1, bvi_->val_));
        }
      };
    }

    inline var bessel_first_kind(const int& v, 
                                 const var& a) {
      return var(new bessel_first_kind_dv_vari(v, a.vi_));
    }

  }
}
#endif
