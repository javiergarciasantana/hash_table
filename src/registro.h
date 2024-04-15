#include <bits/stdc++.h>
#include <cstdlib>

#ifndef REGISTRO_H
#define REGISTRO_H



class Registro {
 public:
  Registro() {
    clave_ = rand();
  }
  static unsigned counter;
  operator long() const {
    return clave_;
  }
  bool operator==(const Registro& reg) {
    ++counter;
    return clave_ == reg.clave_;
  }
  long getClave() {
    return clave_;
  }
 private:
  long clave_;
};

#endif