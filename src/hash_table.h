// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .h en el que se instancia la
//              clase HashTable 
//
// COMPILACIÓN: make

#include <vector>
#include <iostream>
#include <bits/stdc++.h>

#include "list.h"
#include "block.h"
#include "fd_sum.h"
#include "fe_cuad.h"
#include "sequence.h"
#include "vehiculo.h"
#include "fe_double.h"
#include "fe_lineal.h"
#include "fd_module.h"
#include "fd_psrand.h"
#include "fe_redispersion.h"
#include "dispersion_function.h"
#include "exploration_function.h"

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template<class Key>
class HashTable  {
 public:
  HashTable() {
    tableSize_ = 0;
    blockSize_ = 0;
    fd_ = nullptr;
    fe_ = nullptr;
  }
  
  HashTable(int tableSize, DispersionFunction<Key>* fd = nullptr, 
            ExplorationFunction<Key>* fe = nullptr, int blockSize = 0) {
    tableSize_ = tableSize;
    blockSize_ = blockSize;
    fd_ = fd;
    table_ = new Sequence<Key>*[tableSize_];
    if (fe != nullptr && blockSize != 0) { 
      //block
      fe_ = fe;
      for (int i = 0; i < tableSize_; ++i) {
        Sequence<Key>* block = new Block<Key> (blockSize_);
        table_[i] = block;
      }
    } else {
      //list
      for (int i = 0; i < tableSize_; ++i) {
        Sequence<Key>* list = new List<Key> ();
        table_[i] = list;
      }
    }
  }
  
  bool search(const Key& k) const {
    unsigned jump, gap = 1;
    unsigned pos = (*fd_)(k);
    if (table_[pos]->search(k)) {
      return true;
    } else {
      if (table_[pos]->isFull()) {
        while (gap < tableSize_) {// do while
          jump = (*fe_)(k, gap);
          pos += jump;
          ++gap;
          // while (pos >= tableSize_) {
          //   pos = fabs(pos - tableSize_);
          // }
          if (pos >= tableSize_) {
            pos = pos % tableSize_;
          }
          if (table_[pos]->search(k)) {
            return true;
          } else {
            if (!table_[pos]->isFull()) {
              return false;
            }
          }
        }
      } else {
        return false;
      }
    }
  }

  bool insert(const Key& k) {
    // if (isFull()) {
    //   return false;
    // }
    if (!search(k)) {
      unsigned jump, gap = 1;
      unsigned pos = (*fd_)(k);
      if (table_[pos]->isFull()) {
        while (gap < tableSize_) {
          jump = (*fe_)(k, gap);
          pos += jump;
          ++gap;
          // while (pos >= tableSize_) {
          //   pos = fabs(pos - tableSize_);
          // }
          if (pos >= tableSize_) {
            pos = pos % tableSize_;
          }
          if (!table_[pos]->isFull()) {
            table_[pos]->insert(k);
            return true;
          } 
        }
      } else {
        table_[pos]->insert(k);
        return true;
      }
    } else {
      return false;
    }
  }

  bool isFull() {
    for (int i = 0; i < tableSize_; ++i) {
      if (!table_[i]->isFull()) {
        return false;
      }
    }
    return true;
  }

 private:
  int blockSize_;
  int tableSize_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_;
  Sequence<Key>** table_;
};

#endif