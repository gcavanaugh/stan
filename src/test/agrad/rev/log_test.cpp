#include <stan/agrad/rev/log.hpp>
#include <test/agrad/util.hpp>
#include <gtest/gtest.h>
#include <boost/math/special_functions/fpclassify.hpp>
#include <stan/math/constants.hpp>
#include <stan/agrad/rev/numeric_limits.hpp>
#include <stan/agrad/rev/operator_less_than.hpp>
#include <stan/agrad/rev/operator_equal.hpp>
#include <stan/agrad/rev/operator_unary_negative.hpp>

TEST(AgradRev,log_a) {
  AVAR a(5.0);
  AVAR f = log(a); 
  EXPECT_FLOAT_EQ(log(5.0),f.val());

  AVEC x = createAVEC(a);
  VEC g;
  f.grad(x,g);
  EXPECT_FLOAT_EQ(1.0/5.0,g[0]);
}

TEST(AgradRev,log_inf) {
  AVAR a = std::numeric_limits<double>::infinity();
  EXPECT_TRUE(boost::math::isinf(log(a)));
}

TEST(AgradRev,log_0) {
  AVAR a(0.0);
  EXPECT_TRUE(boost::math::isinf(log(a)) && (log(a) < 0.0));
}

TEST(AgradRev,log_neg){
  AVAR a(0.0 - stan::math::EPSILON);
  EXPECT_TRUE(std::isnan(log(a)));
}
