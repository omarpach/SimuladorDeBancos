#include "Banco.hpp"
#include "lib/ListaSimple.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

Banco::Banco() {
  std::srand(std::time(nullptr));
  this->tiempoTotalDeAtención = 120 + rand() % 120;
  this->reloj = 0;
  this->cajas = new Caja[numDeCajas];
}

Banco::~Banco() {
  delete[] cajas;
  delete[] nombres;
}

Banco::Banco(const Banco &b) {}

Banco &Banco::operator=(const Banco &b) {}

void Banco::LeerNombres(const char *archivo) {
  std::fstream fsArchivo(archivo);
  ListaSimple<string> listaNombres;
  if (!fsArchivo)
    throw "Archivo no encontrado";
  while (!fsArchivo.eof()) {
    string nombre;
    std::getline(fsArchivo, nombre);
    listaNombres.AgregarAlFondo(nombre);
  }
}
