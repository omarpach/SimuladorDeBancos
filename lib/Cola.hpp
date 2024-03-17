#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

#include <exception>
#include <iostream>

template <typename T> class Cola {
public:
  class ColaVacia : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  Cola();

  ~Cola();

  Cola(const Cola<T> &cola);

  Cola<T> &operator=(const Cola<T> &cola);

  void Encolar(T valor);

  void Desencolar();

  int ObtenerTam() const;

  T ObtenerFrente() const;

  T ObtenerFondo() const;

  bool EstaVacia() const;

  void Vaciar();

  void Imprimir() const;

private:
  int tam;

  struct Elemento {
    T valor;
    Elemento *siguiente;
    Elemento(T valor, Elemento *siguiente = nullptr);
  } * fondo;
};

/******************************************************************************************/

template <typename T>
Cola<T>::Elemento::Elemento(T valor, Elemento *siguiente /* = NULL */) {
  this->valor = valor;
  this->siguiente = siguiente;
}

/******************************************************************************************/

template <typename T> Cola<T>::Cola() {
  tam = 0;
  fondo = nullptr;
}

/******************************************************************************************/

template <typename T> Cola<T>::~Cola() { Vaciar(); }

/******************************************************************************************/

template <typename T>
Cola<T>::Cola(const Cola<T> &cola) : tam(0), fondo(nullptr) {
  *this = cola;
}

/******************************************************************************************/

template <typename T> Cola<T> &Cola<T>::operator=(const Cola<T> &cola) {
  if (this == &cola)
    return *this;

  Vaciar();
  Elemento *actual = cola.fondo->siguiente;
  while (actual != nullptr) {
    Encolar(actual->valor);
    actual = actual->siguiente;
  }
  return *this;
}

/******************************************************************************************/

template <typename T> void Cola<T>::Encolar(T valor) {
  if(EstaVacia()){
        fondo = new Elemento(valor, fondo);
        fondo -> siguiente = fondo;
    }
    else{
        Elemento *aux = fondo;
        fondo = new Elemento(valor, nullptr);
        fondo -> siguiente = aux -> siguiente;
        aux -> siguiente = fondo;
    }
    ++tam;
}

/******************************************************************************************/

template <typename T> void Cola<T>::Desencolar() {
  if(EstaVacia()) throw EstaVacia();
    Elemento *aux = fondo -> siguiente;
    fondo -> siguiente = aux -> siguiente;
    if(fondo == fondo -> siguiente) fondo = nullptr;
    delete aux;
    --tam;
}

/******************************************************************************************/

template <typename T> int Cola<T>::ObtenerTam() const { return tam; }

/******************************************************************************************/

template <typename T> T Cola<T>::ObtenerFrente() const {
  if (EstaVacia())
    throw "La cola se encuentra vacía...";
  return fondo->siguiente->valor;
}

/******************************************************************************************/

template <typename T> T Cola<T>::ObtenerFondo() const {
  if (EstaVacia())
    throw "La cola se encuentra vacía...";
  return fondo->valor;
}

/******************************************************************************************/

template <typename T> bool Cola<T>::EstaVacia() const { return tam == 0; }

/******************************************************************************************/

template <typename T> void Cola<T>::Vaciar() {
  while (!EstaVacia())
    Desencolar();
}

/******************************************************************************************/

template <typename T> void Cola<T>::Imprimir() const {
  if (EstaVacia())
    std::cout << char(179) << ' ' << char(179) << std::endl;
  else {
    Elemento *actual = fondo->siguiente;

    std::cout << char(179);
    for (int i = 0; i < tam; ++i) {
      std::cout << actual->valor << ", ";
      actual = actual->siguiente;
    }
    std::cout << "\b\b  ";
    std::cout << char(179) << std::endl;
  }
}

/******************************************************************************************/

template <typename T> const char *Cola<T>::ColaVacia::what() const throw() {
  return "Se intent\242 desencolar una cola vacia...";
}

#endif // COLA_HPP_INCLUDED
