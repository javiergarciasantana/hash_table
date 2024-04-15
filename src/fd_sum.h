// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase fdSum
//
// COMPILACIÓN: make

#include <iostream>
#include <bits/stdc++.h>

#include "dispersion_function.h"

#ifndef FD_SUM_H
#define FD_SUM_H

//pasarle el tamano de la tabla
template<class Key>
class fdSum: public DispersionFunction<Key> {
 public:
  fdSum(const unsigned n): tableSize(n){} 
  unsigned operator()(const Key& k) const {
    unsigned sum = 0, aux;
    unsigned key = k;
    while (key > 0){ 
      aux = key % 10;
      sum += aux;
      key /= 10;
    } 
    return (sum % tableSize);
  }
  
 private:
  unsigned tableSize;
};

#endif