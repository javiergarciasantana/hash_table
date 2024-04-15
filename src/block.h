// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
// clase Block 
//
// COMPILACIÓN: make

//dispersion cerrada
#include "sequence.h"

#ifndef BLOCK_H
#define BLOCK_H

template<class Key>
class Block : public Sequence<Key> {
 public:
  Block(int n) {
    blockSize_ = n;
    block_ = new int[blockSize_];
    inserted_elements_ = 0;
  }
  bool search(const Key& k) const {
    for (int i = 0; i < blockSize_; ++i) {
      if (k == block_[i]) {
        return true;
      }
    }
    return false;
  }

  bool insert(const Key& k) {
    if (!search(k) && !isFull()) {
      block_[inserted_elements_] = k;
      ++inserted_elements_;
      return true;
    }
    return false;
  }

  bool isFull() const {
    for (int i = 0; i < blockSize_; ++i) {
      if (block_[i] != '/0') { //if not equal null character
        return false;
      }
    }
    return true;
  }

 private:
  int inserted_elements_;
  unsigned blockSize_;
  int* block_;
};

#endif