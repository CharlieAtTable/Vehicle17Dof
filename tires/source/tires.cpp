#include <iostream>
#include "tires.h"

Tire::Tire() {
    std::cout << "tires not init!" << std::endl;
}

Tire::Tire(nlohmann::json j) {
    ;
}
