#include <opencv2/opencv.hpp>
#define KAGUYA_DYNAMIC_LIB
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <kaguya/another_binding_api.hpp>

#include "bind_helper.hpp"

#include "cv_bind_type_traits.hpp"

namespace gen_wrap_cv {
using namespace cv;
template <typename T>
struct identity {
  typedef T type;
};
}

void kaguya_manual_bind();


#include "raw_bind_generated.inc"
