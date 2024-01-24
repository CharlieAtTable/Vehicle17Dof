#include "sprung.h"

#include <iostream>
#include <nlohmann/json.hpp>

Sprung::Sprung() {
    std::cout << "sprung not init!" << std::endl;
}

Sprung::Sprung(nlohmann::json j) : M(j["M"]), Ix(j["Ix"]), Iy(j["Iy"]), Iz(j["Iz"]) {
    ;
}
