// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase fdModule 
//
// COMPILACIÓN: make

#include <iostream>
#include <bits/stdc++.h>

#include "dispersion_function.h"

#ifndef FD_MODULE_H
#define FD_MODULE_H

template<class Key>
class fdModule: public DispersionFunction<Key> {
 public:
  fdModule(const unsigned n): tableSize(n){} 
  unsigned operator()(const Key& k) const {
    return k % tableSize; 
  }
 private:
  unsigned tableSize;
};

#endif