// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase feRedispersion
//
// COMPILACIÓN: make

#include <iostream>
#include <bits/stdc++.h>

#include "fd_psrand.h"
#include "exploration_function.h"
#include "dispersion_function.h"

#ifndef FE_REDISPERSION_H
#define FE_REDISPERSION_H

//double dispersion
template<class Key>
class feRedispersion: public ExplorationFunction<Key> {
 public:
  feRedispersion(DispersionFunction<Key>* fd) : fd_(fd) {}
  unsigned operator()(const Key& k, unsigned i) const {
    DispersionFunction<Key>* fd_2 = new fdPsrand<Key>(k);
    unsigned op = (*fd_2)(k);
    return i * op;
  }
 private:
  DispersionFunction<Key>* fd_;
};

#endif