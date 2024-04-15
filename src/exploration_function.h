// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase ExplorationFunction 
//
// COMPILACIÓN: make

#include <iostream>
#include <bits/stdc++.h>

#ifndef EXPLORATION_FUNCTION_H
#define EXPLORATION_FUNCTION_H

//nos da un desplazamiento y luego le pasamos las veces q se ha usado
template<class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

#endif