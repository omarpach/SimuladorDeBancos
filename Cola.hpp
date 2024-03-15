
#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

#include <exception>


template <typename T>
class Cola{
public:
    class ColaVacia : public std::exception{
    public:
        virtual const char* what() const throw();
    };

    Cola();

    ~Cola();

    Cola(const Cola<T>& cola);

    Cola<T>& operator=(const Cola<T>& cola);

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



    struct Elemento{
        T valor;
        Elemento *siguiente;
        Elemento(T valor, Elemento* siguiente = nullptr);
    } * fondo;

};

#include "Cola.tpp"

#endif // COLA_HPP_INCLUDED

