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

/******************************************************************************************/

Banco::Banco() {
  std::srand(std::time(nullptr));
  this->tamNombres = 0;
  this->tiempoTotalDeAtencion = 120 + rand() % 120;
  this->agregarClienteCola = 2 + rand() % 10;
  this->eliminarClienteCola = 2 + rand() % 10;
  //this->reloj = 0;
  this->cajas = new Caja[numDeCajas];
}

/******************************************************************************************/

Banco::~Banco() {
  delete[] cajas;
  delete[] nombres;
}

/******************************************************************************************/

Banco::Banco(const Banco &b) {}

/******************************************************************************************/

Banco &Banco::operator=(const Banco &b) {}

/******************************************************************************************/

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

/******************************************************************************************/

string Banco::ObtenerNombreAleatorio(){
  int i = rand() % tamNombres;
  return nombres[i];
}

/******************************************************************************************/

void Banco::ActualizarCajas(){
  for(int i = 0; i < numDeCajas; ++i)
    cajas[i].Actualizar(clientes);
}

/******************************************************************************************/

void Banco::ActualizarCola(){
    //std::cout << agregarClienteCola << std::endl;
    //std::cout << eliminarClienteCola << std::endl;
    //std::cout << clientes.EstaVacia();
   try{
       if(agregarClienteCola == 0){
       clientes.Encolar(ObtenerNombreAleatorio());
       agregarClienteCola = 2 + rand() % 10;
       }
       if(eliminarClienteCola == 0){
          if(!clientes.EstaVacia()){
             ActualizarCajas();
             clientes.Desencolar();
          }
          eliminarClienteCola = 2 + rand() % 10;
       }
       --agregarClienteCola;
       --eliminarClienteCola;
   }catch(Cola<string>::ColaVacia &exc){
       std::cerr << "Error: " << exc.what() << std::endl;
   }
}

/******************************************************************************************/

void Banco::Imprimir() const{
   ImprimirCajas();
   clientes.Imprimir();
}

/******************************************************************************************/

void Banco::ImprimirCajas() const{
   for(int i = 0; i < numDeCajas; ++i){
       cajas[i].Imprimir();
       std::cout << "\n\n";
   }
}

/******************************************************************************************/

int Banco::ObtenerTiempoTotal() const{
   return tiempoTotalDeAtencion;
}

/******************************************************************************************/

void Banco::Caja::Actualizar(Cola<string> &clientes){
   // Caja no esta atendiendo a cliente
   if(cliente.empty()){
      if(!clientes.EstaVacia()){
        cliente = clientes.ObtenerFrente();
        tiempoDeAtencion = 1 + rand() % 10;
        clientes.Desencolar();
      }
   }else{
       // Caja ocupada con cliente
       ++tiempoTranscurrido;
       if(tiempoTranscurrido == tiempoDeAtencion){
         cliente.clear();
         tiempoTranscurrido = 0;
       }
   }
}

/******************************************************************************************/

void Banco::Caja::Imprimir() const{
   std::cout << "Caja: " << std::endl;
   if(cliente.empty()) std::cout << "La caja esta desocupada..." << std::endl;
   else{
      std::cout << "La caja esta atendiendo a " << cliente << std::endl;
      std::cout << "Tiempo de atencion: " << tiempoTranscurrido << std::endl;
   }
}

/******************************************************************************************/


