// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase fdPsrand
//
// COMPILACIÓN: make

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

#include "dispersion_function.h"

#ifndef FD_PSRAND_H
#define FD_PSRAND_H

//pasarle el tamano de la tabla
template<class Key>
class fdPsrand : public DispersionFunction<Key> {
 public:
  fdPsrand(const unsigned n): tableSize(n) {} 
  unsigned operator()(const Key& k) const {
    srand(k);
    return rand() % tableSize;
  }
  
 private:
  unsigned tableSize;
};

#endif