// AUTOR: Javier Garcia Santana
// FECHA: 13/3/2023
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos Avanzadas
// PRÁCTICA Nº: 4
// COMENTARIOS: Fichero .cc main en el que se encuentra el
//              menu del programa
//
// COMPILACIÓN: make

#include "vehiculo.h"
#include "hash_table.h"


DispersionFunction<Vehiculo>* DispersionMenu(int table_size) {
  char dispersion_option;
  while(true) {  
    std::cout << "Elija el tipo de funcion de dispersion que desea emplear:\n" <<
                        "[1]-Modulo\n" <<
                        "[2]-Pseudo-aleatoria\n" <<
                        "[3]-Suma\n" <<
                        "[0]-Salir\n";
    std::cin >> dispersion_option;
    switch(dispersion_option) {
      case '0':
        exit(EXIT_SUCCESS);
      case '1':
      {  
        DispersionFunction<Vehiculo>* dispersion_function = new fdModule<Vehiculo>(table_size);
        return dispersion_function;
        break;
      }
      case '2':
      {  
        DispersionFunction<Vehiculo>* dispersion_function = new fdPsrand<Vehiculo>(table_size);
        return dispersion_function;
        break;
      }
      case '3':
      {  
        DispersionFunction<Vehiculo>* dispersion_function = new fdSum<Vehiculo>(table_size);
        return dispersion_function;
        break;
      }
      default:
        std::cerr << "OPCION NO VALIDA\n\n";
        break;
    }
  }
}

ExplorationFunction<Vehiculo>* ExplorationMenu(DispersionFunction<Vehiculo>* dispersion_function) {
  char exploration_option;
  while(true) {  
    std::cout << "Elija el tipo de funcion de exlporacion que desea emplear:\n" <<
                        "[1]-Cuadratica\n" <<
                        "[2]-Lineal\n" <<
                        "[3]-Doble dispersion\n" <<
                        "[4]-Redispersion\n" <<
                        "[0]-Salir\n";
    std::cin >> exploration_option;
    switch(exploration_option) {
      case '0':
        exit(EXIT_SUCCESS);
      case '1':
      {  
        ExplorationFunction<Vehiculo>* exploration_function = new feCuad<Vehiculo>;
        return exploration_function;
        break;
      }
      case '2':
      {  
        ExplorationFunction<Vehiculo>* exploration_function = new feLineal<Vehiculo>;
        return exploration_function;
        break;
      }
      case '3':
      {  
        ExplorationFunction<Vehiculo>* exploration_function = new feDouble<Vehiculo>(dispersion_function);
        return exploration_function;
        break;
      }
      case '4':
      {  
        ExplorationFunction<Vehiculo>* exploration_function = new feRedispersion<Vehiculo>(dispersion_function);
        return exploration_function;
        break;
      }
      default:
        std::cerr << "OPCION NO VALIDA\n\n";
        break;
    }
  }

}

int main() {
  DispersionFunction<Vehiculo>* dispersion_function;
  HashTable<Vehiculo> hash_table_copy;
  Vehiculo key;
  bool is_table_created = false;
  char option, dispersion_type;
  unsigned table_size, block_size;
  while (true) {
    std::cout << "[1]-Crear tabla hash\n" <<
                 "[2]-Buscar en la tabla hash\n" <<
                 "[3]-Insertar en la tabla hash\n" <<
                 "[0]-Salir\n";
    
    std::cin >> option;
    switch(option) {
      case '0':
        exit(EXIT_SUCCESS);
      case '1':
        while(true) {
          if (is_table_created) {
            break;
          }
          std::cout << "Inserte el tamano de la tabla hash:" << std::endl;
          std::cin >> table_size;
          std::cout << "Elija el tipo de dispersion que desea emplear:\n" <<
                      "[1]-Abierta\n" <<
                      "[2]-Cerrada\n" <<
                      "[0]-Salir\n";
          std::cin >> dispersion_type;
          switch (dispersion_type) {
            case '0':
              exit(EXIT_SUCCESS);
            case '1':
            {
              DispersionFunction<Vehiculo>* dispersion_function= DispersionMenu(table_size);
              HashTable<Vehiculo> hash_table(table_size, dispersion_function);
              hash_table_copy = hash_table;
              is_table_created = true;
              std::cout << "\nLA TABLA HA SIDO CREADA EXITOSAMENTE\n\n";
              break;
            }
            case '2':
            {
              DispersionFunction<Vehiculo>* dispersion_function = DispersionMenu(table_size);
              ExplorationFunction<Vehiculo>* exploration_finction = ExplorationMenu(dispersion_function);
              std::cout << "Introduzca el tamano del bloque:\n";
              std::cin >> block_size;
              HashTable<Vehiculo> hash_table(table_size, dispersion_function, exploration_finction, block_size);
              hash_table_copy = hash_table;
              is_table_created = true;
              std::cout << "\nLA TABLA HA SIDO CREADA EXITOSAMENTE\n\n";
              break;
              
            }
            default:
              std::cerr << "OPCION NO VALIDA\n\n";
          }
        }  
        break;
      case '2':
        if (is_table_created) {
          std::cout << "Introduzca la clave a buscar:\n";
          std::cin >> key;
          if (hash_table_copy.search(key)) {
            std::cout << "\nLa clave se ha encontrado\n\n";
            //std::cout << "Numero de comparaciones: " << counter << "\n\n";
          } else {
            std::cout << "\nLa clave no se ha encontrado\n\n";
          }
        } else {
          std::cerr << "ERROR: La tabla no ha sido creada todavia\n\n";
        }
        break;
      case '3':
        if (is_table_created) {
          std::cout << "Introduzca la clave a insertar:\n";
          std::cin >> key;
          if (hash_table_copy.insert(key)) {
            std::cout << "\nLa clave se ha insertado\n\n";
          } else {
            std::cout << "\nLa clave no se ha insertado\n\n";
          }
        } else {
          std::cerr << "ERROR: La tabla no ha sido creada todavia\n\n";
        }
        break;
      default:
        std::cerr << "OPCION NO VALIDA\n\n";
        break;
    }
  }
  return 0;
}
