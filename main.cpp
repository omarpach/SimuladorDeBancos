#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include "Cola.hpp"

using namespace std;

int main(){
    int tiempoTotal;
    int agregarCliente, eliminarCliente;
    Cola<int> clientes;

    srand(time(nullptr));

    agregarCliente = 1 + rand() % 10;
    eliminarCliente = 1 + rand() % 10;
    tiempoTotal = 120 + rand() % 240;

    try{
        for(int i = 1; i <= tiempoTotal; ++i){

            cout << "Reloj: " << i << "s\n" << endl;

            cout << "Cola: ";
            clientes.Imprimir();
            cout << "Tiempo para agregar un cliente: " << agregarCliente << endl;
            cout << "Tiempo para elimnar un cliente: " << eliminarCliente << endl;

            if(agregarCliente == 0){
                clientes.Encolar(i);
                cout << "Se agregó un cliente: ";
                clientes.Imprimir();
                agregarCliente = 2 + rand() % 10;
            }

            if(eliminarCliente == 0){
                if(!clientes.EstaVacia()){
                    clientes.Desencolar();
                    cout << "Se eliminó un cliente: ";
                    clientes.Imprimir();
                }
                eliminarCliente = 2 + rand() % 10;
            }

            --eliminarCliente;
            --agregarCliente;

             this_thread::sleep_for(chrono::seconds(1));
             system("cls");
        }
    }catch(Cola<int>::ColaVacia & exc){
        cerr << "Error: " << exc.what() << endl;
    }catch(...){
        cerr << "Error inesperado...";
    }






  return 0;
}
