#include <iostream>

#ifndef VEHICULO_H
#define VEHICULO_H

//static unsigned counter = 0;

class Vehiculo {
 public:
  Vehiculo() {matricula_ = "0000";}
  Vehiculo(std::string matricula) : matricula_(matricula) {}
  operator long() const {
    long result = 0;
    int multiplier = 1;
    for (int i = matricula_.size() - 1; i >= 0; --i) {
      if (matricula_[i] >= '0' && matricula_[i] <= '9') {
        result += (matricula_[i] - '0') * multiplier;
      }
      multiplier *= 10;
    }
    return result;
  }
  bool operator==(const Vehiculo& otro_vehiculo) {
    //++counter;
    return matricula_ == otro_vehiculo.matricula_;
  }
  friend std::istream& operator>>(std::istream& in, Vehiculo& vehiculo) {
    in >> vehiculo.matricula_;
    return in;
  }

 private:
  std::string matricula_;
};

#endif