#include <fstream>
#include <iostream>
// #include <memory>
#include "sprung.h"
#include "steering_system.h"
#include "suspension.h"
#include "tires.h"
#include "wheels.h"
#include "utilities.h"

int main(int argc, char** argv) {
    // Read vehicle JSON file
    std::ifstream vehicle_file("vehicle.json");
    nlohmann::json vehicle_json;
    vehicle_file >> vehicle_json;
    vehicle_file.close();

    // Sprung
    std::string sprung_file_name = vehicle_json["sprung"];
    std::ifstream sprung_file(sprung_file_name);
    nlohmann::json sprung_json;
    sprung_file >> sprung_json;
    sprung_file.close();
    auto car_body = Sprung(sprung_json);
    //[test]
    // std::cout << car_body.getIx() << std::endl;
    // std::cout << car_body.getIy() << std::endl;
    // std::cout << car_body.getIz() << std::endl;
    // std::cout << car_body.getM() << std::endl;

    // areo
    std::string areo_file_name = vehicle_json["areo"];
    std::ifstream areo_file(areo_file_name);
    nlohmann::json areo_json;
    areo_file >> areo_json;
    areo_file.close();

    // steering
    std::string steering_system_file_name = vehicle_json["steering_system"];
    std::ifstream steering_file(steering_system_file_name);
    nlohmann::json steering_json;
    steering_file >> steering_json;
    steering_file.close();

    // powertrain
    std::string powertrain_file_name = vehicle_json["powertrain"];

    // axle
    int axle_numbers = vehicle_json["axle"].size();
    std::vector<Axle> axles;
    for (int count = 0; count < axle_numbers; count++) {
        axles.push_back(Axle(vehicle_json, count));
    }
    //[test]
    // for (auto axle : axles) {
    //     std::cout << axle.drive() << std::endl;
    //     std::cout << axle.steer() << std::endl;
    //     std::cout << axle.num() << std::endl;
    //     for (const auto& val : axle.loc()) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
