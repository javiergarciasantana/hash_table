// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase DispersionFunction 
//
// COMPILACIÓN: make

#include <iostream>
#include <bits/stdc++.h>

#ifndef DISPERSION_FUNCTION_H
#define DISPERSION_FUNCTION_H

//nos devuelve la posicion de la tabla donde tenemos que guardar la clave
template<class Key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const Key& k) const = 0;
};

#endif