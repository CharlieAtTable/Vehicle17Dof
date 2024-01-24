#ifndef WHEELS_H
#define WHEELS_H

#include "tires.h"
#include "suspension.h"
#include "steering_system.h"
#include <vector>
#include "nlohmann/json.hpp"

class Axle {
  private:
    bool driveAxle = false;
    bool steerAxle = false;
    int axleNum;
    Tire tire;
    Suspension suspension;
    SteeringSys steering;
    std::vector<double> location;

  public:
    Axle();
    Axle(nlohmann::json j, int index);
    bool drive(){return driveAxle;}
    bool steer(){return steerAxle;}
    int num(){return axleNum;}
    std::vector<double> loc(){return location;}
};

#endif
