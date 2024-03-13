#ifndef COLAS_HPP_INCLUDED
#define COLAS_HPP_INCLUDED

#include <iostream>
#include <exception>

template <typename T>
class Cola{
private:
  struct Elemento{
    T valor;
    Elemento* siguiente;
    Elemento(T valor, Elemento* siguiente = NULL);
  };
  Elemento* frente;
  Elemento* fondo;
  int tam;
public:
  Cola();
  ~Cola();
  Cola(const Cola &c);
  Cola& operator=(const Cola &c);
  void Encolar(T valor);
  void Desencolar();
  int ObtenerTam();
  T ObtenerTope();
  T ObtenerFondo();
  bool EstaVacia();
  void Vaciar();
  void Imprimir();

  class ColaVacia : public std::exception{
    public:
        virtual const char* what() const throw();
  };
};

// ******** Métodos indispensables
template<typename T>
Cola<T>::Elemento::Elemento(T valor, Elemento* siguiente /* = NULL */){
  this->valor = valor;
  this->siguiente = siguiente;
}

template<typename T>
Cola<T>::Cola(){
  frente = NULL;
  fondo = NULL;
  tam = 0;
}

template <typename T>
Cola<T>::Cola(const Cola<T> &c){
  frente = NULL;
  fondo = NULL;
  tam = 0;
  *this = c;
}

template <typename T>
Cola<T>::~Cola(){
  Vaciar();
}

template <typename T>
Cola<T>& Cola<T>::operator=(const Cola<T> &c){
  if (this == &c) return *this;
  Vaciar();
  Elemento* actual = c.frente;
  while (actual != NULL){
    Encolar(actual->valor);
    actual = actual->siguiente;
  }
  return *this;
}

// ******** Métodos normales
template<typename T>
void Cola<T>::Encolar(T valor){
  Elemento* nuevo = new Elemento(valor); // Nuevo elemento
  if (EstaVacia()){
    frente = nuevo;
  } else {
    fondo->siguiente = nuevo;
  }
  fondo = nuevo;
  ++tam;
}

template <typename T>
bool Cola<T>::EstaVacia(){
  return tam == 0;
}

template<typename T>
void Cola<T>::Desencolar(){
  if (EstaVacia()) throw EstaVacia();
  Elemento* aux = frente;
  frente = frente->siguiente;
  if (tam == 0) fondo = NULL;
  delete aux;
  --tam;
}

template <typename T>
int Cola<T>::ObtenerTam(){
  return tam;
}

template <typename T>
T Cola<T>::ObtenerTope(){
  if(EstaVacia()) throw EstaVacia();
  return frente->valor;
}

template <typename T>
T Cola<T>::ObtenerFondo(){
  if(EstaVacia()) throw EstaVacia();
  return fondo->valor;
}

template <typename T>
void Cola<T>::Imprimir(){
  if (EstaVacia()){
    std::cout << "( )" << std::endl;
  }
  else {
    Elemento* actual = frente;
    std::cout << "( ";
    while (actual != NULL){
      std::cout << actual->valor << ", ";
      actual = actual->siguiente;
    }
    std::cout << "\b\b )" << std::endl;
  }
}

template <typename T>
void Cola<T>::Vaciar(){
  while (!EstaVacia()){
    Desencolar();
  }
}


template <typename T>
const char* Cola<T>::ColaVacia::what() const throw()
{
    return "Se intent\242 manipular una cola vacia...";
}

#endif // !COLAS_HPP_INCLUDED
