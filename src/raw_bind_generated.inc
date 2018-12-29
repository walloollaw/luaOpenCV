// File generated automatically, do not modify 
namespace gen_wrap_cv{
identity<cv::Mat (*)(cv::InputArray,int)>::type imdecode0 = &cv::imdecode;
identity<cv::Mat (*)(cv::InputArray,int,cv::Mat *)>::type imdecode1 = &cv::imdecode;
auto imdecode = kaguya::overload(imdecode0,imdecode1);

identity<void (*)(const cv::Mat &,cv::Mat *)>::type split0 = &cv::split;
identity<void (*)(cv::InputArray,cv::OutputArrayOfArrays)>::type split1 = &cv::split;
auto split = kaguya::overload(split0,split1);

identity<cv::Mat (*)(const cv::String &,int)>::type imread = &cv::imread;
identity<void (*)(cv::InputArray,cv::OutputArray,int,int)>::type cvtColor = &cv::cvtColor;
identity<void (*)(cv::InputArray,cv::OutputArray,cv::Size,double,double,int)>::type resize = &cv::resize;
identity<void (*)(cv::InputArray,cv::OutputArray)>::type transpose = &cv::transpose;
}// end of namespace gen_wrap_cv

KAGUYA_BINDINGS(cv) {
using namespace kaguya;
	function("split", gen_wrap_cv::split);
	function("imread", gen_wrap_cv::imread);
	function("cvtColor", gen_wrap_cv::cvtColor);
	function("imdecode", gen_wrap_cv::imdecode);
	function("resize", gen_wrap_cv::resize);
    function("transpose", gen_wrap_cv::transpose);

  constant("INTER_NEAREST", cv::INTER_NEAREST);
  constant("INTER_LINEAR", cv::INTER_LINEAR);
  constant("INTER_CUBIC", cv::INTER_CUBIC);
  constant("INTER_AREA", cv::INTER_AREA);
  constant("INTER_LANCZOS4", cv::INTER_LANCZOS4);
  constant("INTER_LINEAR_EXACT", cv::INTER_LINEAR_EXACT);
  constant("INTER_MAX", cv::INTER_MAX);
  constant("COLOR_BGR2BGRA", cv::COLOR_BGR2BGRA);
  constant("COLOR_RGB2RGBA", cv::COLOR_RGB2RGBA);
  constant("COLOR_BGRA2BGR", cv::COLOR_BGRA2BGR);
  constant("COLOR_RGBA2RGB", cv::COLOR_RGBA2RGB);
  constant("COLOR_BGR2RGBA", cv::COLOR_BGR2RGBA);
  constant("COLOR_RGB2BGRA", cv::COLOR_RGB2BGRA);
  constant("COLOR_RGBA2BGR", cv::COLOR_RGBA2BGR);
  constant("COLOR_BGRA2RGB", cv::COLOR_BGRA2RGB);
  constant("COLOR_BGR2RGB", cv::COLOR_BGR2RGB);
  constant("COLOR_RGB2BGR", cv::COLOR_RGB2BGR);
  constant("COLOR_BGRA2RGBA", cv::COLOR_BGRA2RGBA);
  constant("COLOR_RGBA2BGRA", cv::COLOR_RGBA2BGRA);
  constant("COLOR_BGR2GRAY", cv::COLOR_BGR2GRAY);
  constant("COLOR_RGB2GRAY", cv::COLOR_RGB2GRAY);
  constant("COLOR_GRAY2BGR", cv::COLOR_GRAY2BGR);
  constant("COLOR_GRAY2RGB", cv::COLOR_GRAY2RGB);
  constant("COLOR_GRAY2BGRA", cv::COLOR_GRAY2BGRA);
  constant("COLOR_GRAY2RGBA", cv::COLOR_GRAY2RGBA);
  constant("COLOR_BGRA2GRAY", cv::COLOR_BGRA2GRAY);
  constant("COLOR_RGBA2GRAY", cv::COLOR_RGBA2GRAY);
  constant("COLOR_BGR2BGR565", cv::COLOR_BGR2BGR565);
  constant("COLOR_RGB2BGR565", cv::COLOR_RGB2BGR565);
  constant("COLOR_BGR5652BGR", cv::COLOR_BGR5652BGR);
  constant("COLOR_BGR5652RGB", cv::COLOR_BGR5652RGB);


  
#include "manual_bind.inc" 
}//end of KAGUYA_BINDINGS(cv) 
