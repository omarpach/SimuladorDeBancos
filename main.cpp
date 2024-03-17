#include "Cola.hpp"
#include "Banco.hpp"
#include <chrono>
#include <thread>
/* #include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <thread> */

using namespace std;

int main() {
  try {
    Banco banco;
    banco.LeerNombres("Clientes.txt");

    int tiempoTotal = banco.ObtenerTiempoTotal();

    for (int i = 1; i <= tiempoTotal; ++i) {
       cout << "Reloj: " << i << endl;
       banco.Imprimir();
       banco.ActualizarCola();
       banco.ActualizarCajas();
       this_thread::sleep_for(chrono::seconds(1));
       system("cls");
    }
  }catch (const char* e) {
    cerr << "Error: " << e << endl;
  }catch(...){
    cerr << "Error inesperado..." << endl;
  }
}

/* string NuevoCliente(int i);

int main() {
  int tiempoTotal;
  int agregarCliente, eliminarCliente;
  int numPersona = 1;
  Cola<string> clientes;

  srand(time(nullptr));

  agregarCliente = 1 + rand() % 10;
  eliminarCliente = 1 + rand() % 10;
  tiempoTotal = 120 + rand() % 240;

  try {
    for (int i = 1; i <= tiempoTotal; ++i) {

      cout << "Reloj: " << i << "s\n" << endl;

      cout << "Cola: ";
      clientes.Imprimir();
      cout << "Tiempo para agregar un cliente: " << agregarCliente << endl;
      cout << "Tiempo para elimnar un cliente: " << eliminarCliente << endl;

      if (agregarCliente == 0) {
        clientes.Encolar(NuevoCliente(numPersona));
        cout << numPersona << endl;
        cout << "Se agreg� un cliente: ";
        ++numPersona;
        clientes.Imprimir();
        agregarCliente = 2 + rand() % 10;
      }
      if (eliminarCliente == 0) {
        if (!clientes.EstaVacia()) {
          clientes.Desencolar();
          cout << "Se elimin� un cliente: ";
          clientes.Imprimir();
        }
        eliminarCliente = 2 + rand() % 10;
      }

      --eliminarCliente;
      --agregarCliente;

      this_thread::sleep_for(chrono::seconds(1));
      system("cls");
    }
  } catch (Cola<int>::ColaVacia &exc) {
    cerr << "Error: " << exc.what() << endl;
  } catch (const char *msn) {
    cerr << msn << endl;
  } catch (...) {
    cerr << "Error inesperado..." << endl;
  }

  return 0;
}

string NuevoCliente(int i) {
  string nombre;
  ifstream archivo("Clientes.txt");
  int cont = 0;

  if (!archivo)
    throw "Error al abrir el archivo...";

  if (archivo.is_open()) {
    while (getline(archivo, nombre)) {
      ++cont;
      if (cont == i)
        return nombre;
    }
    archivo.close();
  }
  throw "Ya no hay mas clientes...";
} */
