#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include "Cola.hpp"

using namespace std;

int main(){
  int agregarCliente;
  int eliminarCliente;
  Cola<int> clientes;

  cout << "Numero de turnos: 100\n" << endl;
  srand(time(NULL));
  agregarCliente = rand() % 10 + 1;
  eliminarCliente = rand() % 10 + 1;

  for (int i = 0; i < 100; ++i){
    cout << "Reloj: " << i << "s\n" << endl;
    cout << "Cola: ";
    clientes.Imprimir();
    cout << "Tiempo para agregar un cliente: " << agregarCliente << endl;
    cout << "Tiempo para elimnar un cliente: " << eliminarCliente << endl;

    if (agregarCliente == 0){
      clientes.Encolar(i);
      cout << "Se agregó un cliente: ";
      clientes.Imprimir();
      agregarCliente = rand() % 10 + 1;
    }
    if (eliminarCliente == 0){
      try {
        clientes.Desencolar();
        cout << "Se eliminó un cliente: ";
        clientes.Imprimir();
      } catch (const char* e) {
        cerr << "Error: " << e << endl;
      }
      eliminarCliente = rand() % 10 + 1;
    }

    --agregarCliente;
    --eliminarCliente;

    this_thread::sleep_for(chrono::seconds(1));
    system("clear");
  }

  return 0;
}
