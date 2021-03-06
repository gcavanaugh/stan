#ifndef __STAN__MATH__MATRIX__CHECK_RANGE_HPP__
#define __STAN__MATH__MATRIX__CHECK_RANGE_HPP__

#include <sstream> 
#include <stdexcept>

namespace stan {
  namespace math {

    namespace {

      void raise_range_error(size_t max,
                             size_t i, 
                             const char* msg,
                             size_t idx) {
        std::stringstream s;
        s << "INDEX OPERATOR [] OUT OF BOUNDS"
          << "; index=" << i
          << "; lower bound=1"
          << "; upper bound=" << max
          << "; index position=" << idx
          << "; " << msg
          << std::endl;
        throw std::out_of_range(s.str());
      }

    }

    inline
    void check_range(size_t max,
                     size_t i, 
                     const char* msg,
                     size_t idx) {
      if (i < 1 || i > max) 
        raise_range_error(max,i,msg,idx);
    }


  }
}
#endif
