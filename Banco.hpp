#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include "Cola.hpp"
#include <string>

using std::string;

class Banco {
private:
  int numDeCajas = 3;
  int tiempoTotalDeAtencion;
  int tamNombres;
  int agregarClienteCola;
  int eliminarClienteCola;
  string* nombres = nullptr;
  Cola<string> clientes;
  Cola<string> clientesAtendidos;
  struct Caja {
    string cliente;
    int tiempoDeAtencion;
    int tiempoTranscurrido = 0;
    void Actualizar(Cola<string> &clientes);
    void Imprimir() const;
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
  void ActualizarCola();
  void ImprimirCajas() const;
  int ObtenerTiempoTotal() const;
};

#endif // !BANCO_HPP_INCLUDED
