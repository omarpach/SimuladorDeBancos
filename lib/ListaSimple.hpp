#ifndef LISTASE_HPP_INCLUDED
#define LISTASE_HPP_INCLUDED

#define NO_ENCONTRADO -1
#include <iostream>

template <typename T>
class ListaSimple{
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
  /***** Prototipo Metodos fundamentales *****/
  ListaSimple();
  ~ListaSimple();
  ListaSimple(const ListaSimple &l);
  ListaSimple& operator=(const ListaSimple &l);

  /***** Prototipo Metodos de Agregar *****/
  void AgregarAlFrente(T valor);
  void AgregarAlFondo(T valor);
  void Agregar(int indice, T valor);
  /***** Prototipo Metodos de Eliminar *****/
  void EliminarAlFrente();
  void EliminarAlFondo();
  void Eliminar(int indice);
  void Vaciar();
  bool EstaVacia() const;
  /***** Prototipo Metodos de Utilidad *****/
  bool BuscarValor(T valor) const;
  int BuscarPosicion(T valor) const;
  T ObtenerFrente() const;
  T ObtenerFondo() const;
  T ObtenerElemento(int indice) const;
  void ModificarElemento(int indice, T valor);
  int ObtenerTam() const;
  void Imprimir() const;
  T* Arreglo() const;
};

/***** Metodos fundamentales *****/
template <typename T>
ListaSimple<T>::Elemento::Elemento(T valor, Elemento* siguiente /* = NULL */){
  this->valor = valor;
  this->siguiente = siguiente;
}

template <typename T>
ListaSimple<T>::ListaSimple(){
  frente = fondo = NULL;
  tam = 0;
}

template <typename T>
ListaSimple<T>::~ListaSimple(){
  Vaciar();
}

template <typename T>
ListaSimple<T>::ListaSimple(const ListaSimple &l){
  frente = fondo = NULL;
  tam = 0;
  *this = l;
}

template <typename T>
ListaSimple<T>& ListaSimple<T>::operator=(const ListaSimple<T> &l){
  if (this == &l) return *this;
  Vaciar();
  Elemento* porAgregar = l.frente;
  while (porAgregar != NULL){
    AgregarAlFondo(porAgregar->valor);
    porAgregar = porAgregar->siguiente;
  }
  return *this;
}

/***** Metodos de agregar *****/
template <typename T>
void ListaSimple<T>::AgregarAlFrente(T valor) {
  Elemento* nuevo = new Elemento(valor, frente);
  frente = nuevo;
  if (EstaVacia()) fondo = nuevo;
  ++tam;
}

template <typename T>
void ListaSimple<T>::AgregarAlFondo(T valor){
  Elemento* nuevo = new Elemento(valor);
  (EstaVacia() ? frente : fondo->siguiente) = nuevo;
  fondo = nuevo;
  ++tam;
}

template <typename T>
void ListaSimple<T>::Agregar(int indice, T valor){
  if (indice < 0 || indice > tam) throw "Indice fuera de rango";
  else if (indice == 0) AgregarAlFrente(valor);
  else if (indice == tam) AgregarAlFondo(valor);
  else {
    Elemento* anterior = frente;
    for (int i = 1; i < indice; ++i)
      anterior = anterior->siguiente;
    Elemento* nuevo = new Elemento(valor, anterior->siguiente);
    anterior->siguiente = nuevo;
    ++tam;
  }
}

/***** Metodos de eliminar *****/
template <typename T>
void ListaSimple<T>::EliminarAlFrente(){
  if (EstaVacia()) throw "La pila está vacía";
  Elemento* aux = frente;
  frente = frente->siguiente;
  delete aux;
  if (tam == 1) fondo = NULL;
  --tam;
}

template <typename T>
void ListaSimple<T>::EliminarAlFondo(){
  if (EstaVacia()) throw "La pila está vacía";
  Elemento* anterior = frente;
  while (anterior != NULL && anterior->siguiente != fondo)
    anterior = anterior->siguiente;
  delete fondo;
  fondo = anterior;
  if (tam == 1) frente = NULL;
  else anterior->siguiente = NULL;
  --tam;
}

template<typename T>
void ListaSimple<T>::Eliminar(int indice){
  if (indice < 0 || indice >= tam) throw "Indice fuera de rango";
  else if (indice == 0) EliminarAlFrente();
  else if (indice == tam-1) EliminarAlFondo();
  else {
    Elemento* anterior = frente;
    for (int i = 1; i < indice; ++i)
      anterior = anterior->siguiente;
    Elemento* porBorrar = anterior->siguiente;
    anterior->siguiente = porBorrar->siguiente;
    delete porBorrar;
    --tam;
  }
}

template <typename T>
void ListaSimple<T>::Vaciar(){
  while (!EstaVacia()) EliminarAlFrente();
}

template <typename T>
bool ListaSimple<T>::EstaVacia() const{
  return tam == 0;
}

/***** Metodos de utilidad *****/
template <typename T>
bool ListaSimple<T>::BuscarValor(T valor) const{
  for (Elemento* actual = frente; actual != NULL; actual = actual->siguiente)
    if (actual->valor == valor) return true;
  return false;
}

template <typename T>
int ListaSimple<T>::BuscarPosicion(T valor) const{
  Elemento* actual;
  int pos;
  for (pos = 0; actual != NULL && actual->valor != valor; ++pos)
    actual = actual->siguiente;
  return actual != NULL ? pos : NO_ENCONTRADO;
}

template <typename T>
T ListaSimple<T>::ObtenerFrente() const{
  return frente->valor;
}

template <typename T>
T ListaSimple<T>::ObtenerFondo() const{
  return fondo->valor;
}

template <typename T>
T ListaSimple<T>::ObtenerElemento(int indice) const{
  if (indice < 0 || indice >= tam) throw "Indice fuera de rango";
  else if (indice == 0) return ObtenerFrente();
  else if (indice == tam-1) return ObtenerFondo();
  else {
    Elemento* aux = frente->siguiente;
    for (int i = 1; i < indice; ++i)
      aux = aux->siguiente;
    return aux->valor;
  }
}

template <typename T>
void ListaSimple<T>::ModificarElemento(int indice, T valor){
  if (indice < 0 || indice >= tam) throw "Indice fuera de rango";
  else if (indice == 0) frente->valor = valor;
  else if (indice == tam-1) fondo->valor = valor;
  else {
    Elemento* aux = frente->siguiente;
    for (int i = 1; i < indice; ++i)
      aux = aux->siguiente;
    aux->valor = valor;
  }
}

template <typename T>
int ListaSimple<T>::ObtenerTam() const{
  return tam;
}

template <typename T>
void ListaSimple<T>::Imprimir() const{
  if (EstaVacia())
    std::cout << "( )" << std::endl;
  else {
    std::cout << "( ";
    Elemento* actual = frente;
    while (actual != NULL){
      std::cout << actual->valor << ", ";
      actual = actual->siguiente;
    }
    std::cout << "\b\b )" << std::endl;
  }
}

template <typename T>
T* ListaSimple<T>::Arreglo() const {
  T* arreglo = new T[ObtenerTam()];
  Elemento* aux = frente;
  int tamLista = ObtenerTam();
  for (int i = 0; i < tamLista; ++i) {
    arreglo[i] = aux->valor;
    aux = aux->siguiente;
  }
  return arreglo;
}

#endif // !LISTASE_HPP_INCLUDED
