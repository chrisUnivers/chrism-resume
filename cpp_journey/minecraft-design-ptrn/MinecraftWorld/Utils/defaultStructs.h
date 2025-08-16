#ifndef DEFALUT_STRUCTS_H
#define DEFAULT_STRUCT_H


#include <string>

namespace BlocksSurface {
    std::string dft = "default";
    std::string sis = "solid-ice snow";
    std::string sds = "solid-block snow";
    std::string sd  = "dirt no-grass";
    std::string sdg = "dirt grass";
};

namespace BlockColour {
    std::string dft  = "default";
    std::string iceb = "baby-ice-blue";
    std::string gr   = "green-grass"; 
    std::string sw   = "snow-white";
};

namespace WorldTakeUp {
    double plp = 67.0;
    double pl_ice = 9.0;
    double wdls_flf = 6.0;
    double wdls_bf = 8.0;
    double wdls_spl = 6.0;
    double wdls_jle = 4.0;
};
#endif //