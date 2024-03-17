#include "Banco.hpp"
#include "lib/ListaSimple.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

using std::string;

Banco::Banco() {
  std::srand(std::time(nullptr));
  this->tamNombres = 0;
  this->tiempoTotalDeAtencion = 120 + rand() % 120;
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
  std::ifstream fsArchivo(archivo);
  ListaSimple<string> listaNombres;
  if (!fsArchivo)
    throw "Archivo no encontrado";
  while (!fsArchivo.eof()) {
    string nombre;
    std::getline(fsArchivo, nombre);
    listaNombres.AgregarAlFondo(nombre);
  }
  this->nombres = listaNombres.Arreglo();
  this->tamNombres = listaNombres.ObtenerTam();
}

string Banco::ObtenerNombreAleatorio(){
  int i = rand() % tamNombres;
  return nombres[i];
}

string Banco::ObtenerNombre(int indice) {
  return nombres[indice];
}

int Banco::ObtenerTiempoTotalDeAtencion() {
  return tiempoTotalDeAtencion;
}

int Banco::ObtenerReloj() {
  return reloj;
}

void Banco::Caja::Imprimir() {
  std::cout << "La caja está atendiendo a " << cliente << "   ";
  std::cout << "Tiempo de atención: " << tiempoTranscurrido;
}