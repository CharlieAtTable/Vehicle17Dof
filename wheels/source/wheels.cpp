#include <iostream>
#include "wheels.h"
#include <fstream>

Axle::Axle() {
    std::cout << "Axle not init!" << std::endl;
}

/**
 * @brief       Construct a new Axle:: Axle object
 *
 * @param       j vehicle.json
 * @param       index axle number
 */
Axle::Axle(nlohmann::json j, int index) {
    // axle number
    axleNum = index;
    // read axle_settings
    auto axle_settings = j["axle"][index];
    // whether drive or steer
    if (axle_settings["driveline"] == "") {
        driveAxle = false;
    }
    if (axle_settings["steering"] == "") {
        steerAxle = false;
    }
    // tire
    std::string tire_file_name = axle_settings["tire"];
    std::ifstream tire_file(tire_file_name);
    nlohmann::json tire_json;
    tire_file >> tire_json;
    tire_file.close();
    tire = Tire(tire_json);
    // suspension
    std::string suspension_file_name = axle_settings["suspension"];
    std::ifstream suspension_file(suspension_file_name);
    nlohmann::json suspension_json;
    suspension_file >> suspension_json;
    suspension_file.close();
    // suspension = suspension(suspension_json);

    // location
    location = axle_settings["location"].get<std::vector<double>>();

    // driveline
    if (driveAxle) {
        std::string driveline_file_name = axle_settings["driveline"];
        std::ifstream driveline_file(driveline_file_name);
        nlohmann::json driveline_json;
        driveline_file >> driveline_json;
        driveline_file.close();
        // driveline = Tire(tire_json);
    }
    // steering
    if (steerAxle) {
        std::string steering_file_name = axle_settings["steering"];
        std::ifstream steering_file(steering_file_name);
        nlohmann::json steering_json;
        steering_file >> steering_json;
        steering_file.close();
        // steering = Tire(tire_json);
    }
}
