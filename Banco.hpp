#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include "lib/Cola.hpp" // Asegúrate de que la ruta y el archivo son correctos.
#include <string>

using std::string;

/**
 * @class Banco
 * @brief Simula el funcionamiento de un banco con clientes y cajas de atención.
 *
 * Esta clase representa un banco donde los clientes son generados en tiempos aleatorios,
 * añadidos a una cola y atendidos por cajas disponibles. La simulación incluye la gestión
 * de colas para clientes en espera, clientes siendo atendidos y clientes ya atendidos.
 */
class Banco {
private:
  int numDeCajas; ///< Número de cajas disponibles en el banco.
  int tiempoTotalDeAtencion; ///< Tiempo total de atención en todas las cajas.
  int tamNombres; ///< Tamaño del arreglo de nombres de clientes.
  int agregarClienteCola; ///< Contador de clientes agregados a la cola.
  int eliminarClienteCola; ///< Contador de clientes eliminados de la cola.
  string* nombres; ///< Arreglo de nombres de clientes para generar nombres aleatorios.
  Cola<string> clientes; ///< Cola de clientes en espera de ser atendidos.
  Cola<string> clientesAtendidos; ///< Cola de clientes que ya han sido atendidos.
  Cola<string> clientesPorAtender; ///< Cola de clientes que están siendo atendidos.

  /**
   * @struct Caja
   * @brief Representa una caja de atención en el banco, con un cliente siendo atendido y un contador de tiempo.
   */
  struct Caja {
    string cliente; ///< Nombre del cliente siendo atendido en la caja.
    int tiempoDeAtencion; ///< Tiempo requerido para atender al cliente actual.
    int tiempoTranscurrido; ///< Tiempo transcurrido desde que el cliente actual empezó a ser atendido.

    /**
     * @brief Actualiza el estado de la caja, atendiendo al cliente actual o tomando un nuevo cliente de la cola.
     * @param clientes Cola de clientes en espera.
     * @param clientesAtendidos Cola de clientes ya atendidos.
     * @param clientesPorAtender Cola de clientes que están siendo atendidos.
     */
    void Actualizar(Cola<string> &clientes, Cola<string> &clientesAtendidos, Cola<string> &clientesPorAtender);

    /// @brief Imprime el estado actual de la caja, mostrando el cliente siendo atendido y el tiempo restante.
    void Imprimir() const;
  };
  Caja* cajas; ///< Arreglo de cajas disponibles en el banco.

public:
  Banco(); ///< Constructor por defecto. Inicializa el banco con un número predeterminado de cajas.
  ~Banco(); ///< Destructor. Limpia todos los recursos dinámicos utilizados.
  Banco(const Banco &b); ///< Constructor de copia.
  Banco& operator=(const Banco &b); ///< Operador de asignación.

  /**
   * @brief Lee los nombres de los clientes desde un archivo y los almacena en el arreglo de nombres.
   * @param archivo Ruta al archivo que contiene los nombres de los clientes.
   */
  void LeerNombres(const char* archivo);

  /**
   * @brief Obtiene un nombre del arreglo de nombres basado en un índice.
   * @param indice Índice del nombre a obtener.
   * @return Nombre del cliente en el índice especificado.
   */
  string ObtenerNombre(int indice);

  /// @brief Obtiene un nombre aleatorio del arreglo de nombres.
  /// @return Nombre de cliente aleatorio.
  string ObtenerNombreAleatorio();

  /// @brief Actualiza el estado de todas las cajas, procesando o asignando clientes según sea necesario.
  void ActualizarCajas();

  /// @brief Actualiza la cola de clientes, añadiendo nuevos clientes según el tiempo de simulación.
  void ActualizarCola();

  /// @brief Imprime el estado de todas las cajas.
  void ImprimirCajas() const;

  /// @return El tiempo total de atención acumulado en todas las cajas.
  int ObtenerTiempoTotal() const;

  /// @return Número total de clientes que han sido atendidos.
  int ObtenerNumClientesAtendidos() const;

  /// @return Número de clientes que aún están por atender.
  int ObtenerNumClientesPorAtender() const;

  /// @brief Imprime la lista de clientes que han sido atendidos.
  void ImprimirClientesAtendidos() const;

  /// @brief Imprime la lista de clientes que no pudieron ser atendidos.
  void ImprimirClientesNoAtendidos() const;

  /// @brief Imprime la lista de clientes que están en proceso de ser atendidos.
  void ImprimirClientesPorAtender() const;
};

#endif // BANCO_HPP_INCLUDED
