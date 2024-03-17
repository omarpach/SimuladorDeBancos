#include "Cola.hpp"
#include "Banco.hpp"
#include <chrono>
#include <thread>


using namespace std;

int main() {
  try {
    Banco banco;
    banco.LeerNombres("Clientes.txt");

    int tiempoTotal = banco.ObtenerTiempoTotal();

    for (int i = 1; i <= tiempoTotal; ++i) {
       cout << "Reloj: " << i << endl;
       banco.ImprimirCajas();
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
