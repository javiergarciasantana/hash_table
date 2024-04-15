// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase List 
//
// COMPILACIÓN: make
//
//dispersion abierta

#include <vector>

#include "registro.h"
#include "sequence.h"

#ifndef LIST_H
#define LIST_H

template<class Key>
class List : public Sequence<Key> {
 public:
  List() {
    list_.clear();
  }

  bool search(const Key& k) const {
    for (int i = 0; i < list_.size(); ++i) {
      if (k == list_[i]) {
        return true;
      }
    }
    return false;
  }

  bool insert(const Key& k) {
    if (!search(k) && !isFull()) {
      list_.push_back(k);
      return true;
    }
    return false;
  }
  
  bool isFull() const {
    return false;
  }

 private:
  std::vector<int> list_;
};

#endif