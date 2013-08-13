#include <stan/diff/rev/inv_cloglog.hpp>
#include <stan/diff/rev/exp.hpp>
#include <stan/diff/rev/operator_unary_negative.hpp>
#include <stan/diff/rev/operator_subtraction.hpp>

#include <stan/math/scalar/inv_cloglog.hpp>
#include <test/diff/util.hpp>
#include <gtest/gtest.h>

TEST(AgradRev,inv_cloglog) {
  using std::exp;
  using stan::diff::exp;
  AVAR a = 2.7;
  AVAR f = inv_cloglog(a);
  EXPECT_FLOAT_EQ(1 - std::exp(-std::exp(2.7)),f.val());

  AVEC x = createAVEC(a);
  VEC grad_f;
  f.grad(x,grad_f);

  AVAR a2 = 2.7;
  AVEC x2 = createAVEC(a2);
  AVAR f2 = 1 - exp(-exp(a2));
  VEC grad_f2;
  f2.grad(x2,grad_f2);

  EXPECT_EQ(1U,grad_f.size());
  EXPECT_FLOAT_EQ(grad_f2[0],grad_f[0]);
}
