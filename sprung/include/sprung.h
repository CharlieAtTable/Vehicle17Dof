#ifndef SPRUNG_H
#define SPRUNG_H

#include <nlohmann/json.hpp>

class Sprung {
  private:
    double M = 2100.0;
    double Ix = 1029.0;
    double Iy = 4116.0;
    double Iz = 4116.0;

  public:
    Sprung();
    Sprung(nlohmann::json j);
    double getM() { return M; }
    double getIx() { return Ix; }
    double getIy() { return Iy; }
    double getIz() { return Iz; }
};

#endif
