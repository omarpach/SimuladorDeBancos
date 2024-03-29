#include "Banco.hpp"
#include "lib/Cola.hpp"
#include "lib/nocurses.h"
#include <chrono>
#include <thread>

using namespace std;

int main() {
  try {
    Banco banco;
    banco.LeerNombres("resources/Clientes.txt");

    int tiempoTotal = banco.ObtenerTiempoTotal();

    cout << "La caja atendera a cuantas personas pueda en " << tiempoTotal
         << " minutos." << endl;
    cout << "El tiempo de atención por personas es aleatorio" << endl;
    cout << "\n\nPresiona enter para continuar...";
    wait();   // Funcion esperar de nocurses.h
    clrscr(); // Limpiar pantalla de nocurses.h

    for (int i = 1; i <= tiempoTotal; ++i) {
      cout << "Reloj: " << i << endl;
      banco.ImprimirCajas();
      banco.ActualizarCola();
      banco.ActualizarCajas();
      cout << endl;
      this_thread::sleep_for(chrono::seconds(1));
      clrscr();
    }

    cout << "Termino el tiempo de atencion de la caja" << endl;
    cout << "\nLa caja terminara de atender a:" << endl;
    banco.ImprimirClientesPorAtender();
    cout << "\n\nAtendio en total a " << banco.ObtenerNumClientesAtendidos() << " personas, "
      << "cuyos nombres, en orden de atencion, son: " << endl;
    banco.ImprimirClientesAtendidos();
    cout << "\n\nQuedaron " << banco.ObtenerNumClientesPorAtender()
      << " personas por atender:" << endl;
    banco.ImprimirClientesPorAtender();
  } catch (const char *e) {
    cerr << "Error: " << e << endl;
  } catch (...) {
    cerr << "Error inesperado..." << endl;
  }
}
