#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

#include <exception>
#include <iostream>

/// @class Cola
/// @brief Implementa una estructura de datos de cola circular utilizando plantillas.
/// @tparam T Tipo de los elementos almacenados en la cola.
template <typename T>
class Cola {
public:
  /// @class ColaVacia
  /// @brief Excepción lanzada cuando se intenta operar sobre una cola vacía.
  class ColaVacia : public std::exception {
  public:
    /// @brief Proporciona el mensaje de error asociado a la excepción.
    /// @return Mensaje de error.
    virtual const char *what() const throw();
  };

  /// @brief Constructor por defecto.
  Cola();

  /// @brief Destructor.
  ~Cola();

  /// @brief Constructor de copia.
  /// @param cola Referencia a la cola a copiar.
  Cola(const Cola<T> &cola);

  /// @brief Operador de asignación.
  /// @param cola Referencia a la cola a asignar.
  /// @return Referencia a esta cola.
  Cola<T> &operator=(const Cola<T> &cola);

  /// @brief Encola un elemento al final de la cola.
  /// @param valor Elemento a encolar.
  void Encolar(T valor);

  /// @brief Desencola el elemento al frente de la cola.
  void Desencolar();

  /// @brief Obtiene el tamaño actual de la cola.
  /// @return Número de elementos en la cola.
  int ObtenerTam() const;

  /// @brief Obtiene el valor del elemento al frente de la cola.
  /// @return Valor del elemento al frente.
  /// @throw ColaVacia si la cola está vacía.
  T ObtenerFrente() const;

  /// @brief Obtiene el valor del elemento al fondo de la cola.
  /// @return Valor del último elemento.
  /// @throw ColaVacia si la cola está vacía.
  T ObtenerFondo() const;

  /// @brief Verifica si la cola está vacía.
  /// @return true si la cola está vacía, false en caso contrario.
  bool EstaVacia() const;

  /// @brief Vacía la cola, eliminando todos sus elementos.
  void Vaciar();

  /// @brief Imprime los elementos de la cola en consola.
  void Imprimir() const;

private:
  int tam; ///< Tamaño actual de la cola.

  /// @struct Elemento
  /// @brief Representa un elemento dentro de la cola.
  struct Elemento {
    T valor; ///< Valor del elemento.
    Elemento *siguiente; ///< Puntero al siguiente elemento en la cola.

    /// @brief Constructor del elemento.
    /// @param valor Valor del elemento.
    /// @param siguiente Puntero al siguiente elemento en la cola, nullptr por defecto.
    Elemento(T valor, Elemento *siguiente = nullptr);
  } * fondo; ///< Puntero al último elemento de la cola.
};

/******************************************************************************************/

template<typename T>
Cola<T>::Elemento::Elemento(T valor, Elemento* siguiente /* = NULL */){
  this->valor = valor;
  this->siguiente = siguiente;
}

/******************************************************************************************/

template <typename T>
Cola<T>::Cola()
{
    tam = 0;
    fondo = nullptr;
}

/******************************************************************************************/

template <typename T>
Cola<T>::~Cola()
{
    Vaciar();
}

/******************************************************************************************/

template <typename T>
Cola<T>::Cola(const Cola<T>& cola) : tam(0), fondo(nullptr)
{
    *this = cola;
}

/******************************************************************************************/

template <typename T>
Cola<T>& Cola<T>::operator=(const Cola<T>& cola)
{
    if(this == &cola) return *this;

    Vaciar();
    Elemento *actual = cola.fondo -> siguiente;
    while(actual != nullptr){
        Encolar(actual -> valor);
        actual = actual -> siguiente;
    }
    return *this;
}

/******************************************************************************************/

template <typename T>
void Cola<T>::Encolar(T valor)
{
	Elemento * nuevo = new Elemento(valor, EstaVacia() ? nullptr : fondo -> siguiente);
	(EstaVacia() ? nuevo -> siguiente : fondo -> siguiente) = nuevo;
	fondo = nuevo;
	++tam;

}

/******************************************************************************************/

template <typename T>
void Cola<T>::Desencolar()
{
    if(EstaVacia()) throw ColaVacia();
    Elemento *aux = fondo -> siguiente;

    if(tam > 1) fondo -> siguiente = aux -> siguiente;
    else fondo = nullptr;
    delete aux;
    --tam;

}

/******************************************************************************************/

template <typename T>
int Cola<T>::ObtenerTam() const
{
    return tam;
}

/******************************************************************************************/

template <typename T>
T Cola<T>::ObtenerFrente() const
{
    if(EstaVacia()) throw ColaVacia();
    return fondo -> siguiente -> valor;
}

/******************************************************************************************/

template <typename T>
T Cola<T>::ObtenerFondo() const
{
    if(EstaVacia()) throw ColaVacia();
    return fondo -> valor;
}

/******************************************************************************************/

template <typename T>
bool Cola<T>::EstaVacia() const
{
    return tam == 0;
}

/******************************************************************************************/

template <typename T>
void Cola<T>::Vaciar()
{
    while(!EstaVacia()) Desencolar();
}

/******************************************************************************************/

template <typename T>
void Cola<T>::Imprimir() const
{
    if(EstaVacia()) std::cout << char(179) << ' ' << char(179) << std::endl;
    else{
        Elemento *actual = fondo -> siguiente;

        std::cout << char(179);
        for(int i = 0; i < tam; ++i){
            std::cout << actual -> valor << ", ";
            actual = actual -> siguiente;
        }
        std::cout << "\b\b  ";
        std::cout << char(179) << std::endl;
    }


}

/******************************************************************************************/

template <typename T>
const char* Cola<T>::ColaVacia::what() const throw()
{
    return "Se intent\242 modificar una cola vacia...";
}


#endif // COLA_HPP_INCLUDED
