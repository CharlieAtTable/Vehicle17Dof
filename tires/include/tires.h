#ifndef TIRES_H
#define TIRES_H

#include "nlohmann/json.hpp"

class Tire {
  private:
    double radius;

  public:
    Tire();
    Tire(nlohmann::json j);
};

#endif
