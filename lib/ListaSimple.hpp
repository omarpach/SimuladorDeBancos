#ifndef LISTASE_HPP_INCLUDED
#define LISTASE_HPP_INCLUDED

#define NO_ENCONTRADO -1
#include <iostream>

/**
 * @class ListaSimple
 * @brief Implementa una lista enlazada simple de elementos de tipo genérico T.
 * 
 * Esta clase plantilla ofrece funcionalidades básicas de una lista enlazada, como agregar,
 * eliminar y buscar elementos, además de obtener información sobre la lista.
 * 
 * @tparam T Tipo de dato de los elementos de la lista.
 */
template <typename T>
class ListaSimple{
private:
  /**
   * @struct Elemento
   * @brief Define un nodo de la lista enlazada simple.
   * 
   * Cada nodo almacena un valor y un puntero al siguiente nodo en la lista.
   * 
   * @param valor El valor almacenado en el nodo.
   * @param siguiente Un puntero al siguiente nodo en la lista.
   */
  struct Elemento{
    T valor; ///< Valor almacenado en el nodo.
    Elemento* siguiente; ///< Puntero al siguiente nodo en la lista.

    /**
     * @brief Constructor de Elemento que inicializa un nodo con un valor y un puntero al siguiente nodo.
     * @param valor Valor del nodo.
     * @param siguiente Puntero al siguiente nodo en la lista, por defecto es NULL.
     */
    Elemento(T valor, Elemento* siguiente = NULL);
  };

  Elemento* frente; ///< Puntero al primer elemento de la lista.
  Elemento* fondo; ///< Puntero al último elemento de la lista.
  int tam; ///< Número de elementos en la lista.

public:
  /**
   * @brief Constructor por defecto que inicializa una lista vacía.
   */
  ListaSimple();

  /**
   * @brief Destructor que libera la memoria de todos los elementos de la lista.
   */
  ~ListaSimple();

  /**
   * @brief Constructor de copia.
   * @param l Otra lista de la cual se copiarán los elementos.
   */
  ListaSimple(const ListaSimple &l);

  /**
   * @brief Operador de asignación.
   * @param l Otra lista que se asignará a esta instancia.
   * @return Una referencia a esta instancia después de la asignación.
   */
  ListaSimple& operator=(const ListaSimple &l);

  // Metodos de Agregar

  /**
   * @brief Agrega un elemento al frente de la lista.
   * @param valor El valor a agregar.
   */
  void AgregarAlFrente(T valor);

  /**
   * @brief Agrega un elemento al final de la lista.
   * @param valor El valor a agregar.
   */
  void AgregarAlFondo(T valor);

  /**
   * @brief Inserta un elemento en una posición específica de la lista.
   * @param indice La posición en la que se insertará el elemento.
   * @param valor El valor del elemento a insertar.
   */
  void Agregar(int indice, T valor);

  // Metodos de Eliminar

  /**
   * @brief Elimina el elemento del frente de la lista.
   */
  void EliminarAlFrente();

  /**
   * @brief Elimina el elemento del fondo de la lista.
   */
  void EliminarAlFondo();

  /**
   * @brief Elimina un elemento en una posición específica de la lista.
   * @param indice La posición del elemento a eliminar.
   */
  void Eliminar(int indice);

  /**
   * @brief Elimina todos los elementos de la lista, dejándola vacía.
   */
  void Vaciar();

  /**
   * @brief Verifica si la lista está vacía.
   * @return true si la lista no tiene elementos, false en caso contrario.
   */
  bool EstaVacia() const;

  // Metodos de Utilidad

  /**
   * @brief Busca un valor en la lista.
   * @param valor El valor a buscar.
   * @return true si el valor se encuentra en la lista, false en caso contrario.
   */
  bool BuscarValor(T valor) const;

  /**
   * @brief Busca la posición de un valor en la lista.
   * @param valor El valor cuya posición se quiere encontrar.
   * @return La posición del valor en la lista o NO_ENCONTRADO si no se encuentra.
   */
  int BuscarPosicion(T valor) const;

  /**
   * @brief Obtiene el valor del primer elemento de la lista.
   * @return El valor del primer elemento de la lista.
   */
  T ObtenerFrente() const;

  /**
   * @brief Obtiene el valor del último elemento de la lista.
   * @return El valor del último elemento de la lista.
   */
  T ObtenerFondo() const;

  /**
   * @brief Obtiene el valor de un elemento en una posición específica de la lista.
   * @param indice La posición del elemento cuyo valor se quiere obtener.
   * @return El valor del elemento en la posición especificada.
   */
  T ObtenerElemento(int indice) const;

  /**
   * @brief Modifica el valor de un elemento en una posición específica de la lista.
   * @param indice La posición del elemento a modificar.
   * @param valor El nuevo valor para el elemento.
   */
  void ModificarElemento(int indice, T valor);

  /**
   * @brief Obtiene el tamaño actual de la lista.
   * @return El número de elementos en la lista.
   */
  int ObtenerTam() const;

  /**
   * @brief Imprime todos los elementos de la lista.
   */
  void Imprimir() const;

  /**
   * @brief Convierte la lista en un arreglo y lo devuelve.
   * @return Un puntero al arreglo que contiene todos los elementos de la lista.
   */
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
