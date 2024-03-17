#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include "lib/Cola.hpp"
#include <string>

using std::string;

class Banco {
private:
  int numDeCajas = 3;
  int tiempoTotalDeAtención;
  int reloj;
  int tamNombres;
  string* nombres = nullptr;
  Cola<string> clientes;
  Cola<string> clientesAtendidos;
  struct Caja {
    string cliente;
    int tiempoDeAtencion;
    int tiempoTranscurrido;
  };
  Caja* cajas;

public:
  // Metodos para el buen funcionamiento de la clase
  Banco();
  ~Banco();
  Banco(const Banco &b);
  Banco& operator=(const Banco &b);
  // Metodos de utilidad
  void LeerNombres(const char* archivo);
  string ObtenerNombre(int indice);
  string ObtenerNombreAleatorio();
  void ActualizarCajas();
  void Imprimir();
  void ImprimirCajas();
};

#endif // !BANCO_HPP_INCLUDED
