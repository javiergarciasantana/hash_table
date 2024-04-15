// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase feDouble
//
// COMPILACIÓN: make

#include <iostream>
#include <bits/stdc++.h>
#include "fd_module.h"

#include "exploration_function.h"
#include "dispersion_function.h"

#ifndef FE_DOUBLE_H
#define FE_DOUBLE_H

//double dispersion
template<class Key>
class feDouble: public ExplorationFunction<Key> {
 public:
  feDouble(DispersionFunction<Key>* fd) : fd_(fd) {}
  unsigned operator()(const Key& k, unsigned i) const {
    unsigned op = (*fd_)(k);
    return i * op; 
  }
 private:
  DispersionFunction<Key>* fd_;
};

#endif