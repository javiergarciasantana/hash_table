// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase feCuad
//
// COMPILACIÓN: make

#include <iostream>
#include <bits/stdc++.h>

#include "exploration_function.h"

#ifndef FE_CUAD_H
#define FE_CUAD_H

template<class Key>
class feCuad : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const {
    return i * i; 
  }
};

#endif