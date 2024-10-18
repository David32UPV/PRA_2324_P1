#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include <ostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape{

	// Atributos y Métodos
	protected:	
		Point2D* vs;	// Puntero a un array de 4 elementos de tipo Point2D, correspondientes a los vértices v0, v1, v2 y v3 de un rectángulo: Point2D = [v0, v1, v2, v3]
	private:
		static bool check(Point2D* vertices);	// Comprueba si los vértices conforman un rectángulo válido
	public:
		static int const N_VERTICES = 4;	// Constante con el número de vértices de un rectángulo (4).

		// Constructor por defecto -> Creará un rectángulo con el color que esté establecido por defecto, y los vértices v0=(-1,0.5); v1=(1,0.5), v2=(1,-0.5), y v3=(-1,-0.5).
		Rectangle();

		// Constructor por parámetros que recibe el color y los vértices. Si los vértices NO conforman un rectángulo -> std::invalid_argument
		Rectangle(std::string color, Point2D* vertices);

		//Constructor de copia -> Permitirá hacer una copia segura de rectángulos. 
		Rectangle(const Rectangle &r);

		// Destructor -> Libera la memoria dinámica reservada por el array vs.
		~Rectangle();
		
		// Devuelve el Point2D del rectángulo que ocupa el índice ind. Lanza una excepción std::out_of_range si el índice no es válido (fuera del intervalo [0, N_VERTICES-1]).
		Point2D get_vertex(int ind) const;
		
		// Sobrecarga del operador []. Devuelve el elemento situado en la posición ind. Lanza una excepción std::out_of_range si la posición no es válida
		Point2D operator[](int ind) const;

		// Método virtual -> Modifica los vértices del rectángulo. Si los vértices no conforman un rectángulo válido, devuelve std::invalid_argument
		virtual void set_vertices(Point2D* vertices);

		// Sobrecarga del operador = (asignación de copia). Permitirá hacer una copia segura de rectángulos. 
		Rectangle& operator=(const Rectangle &r);

		// Sobrecarga del operador << (recuerda declararlo como friend)
		friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

		/******** Declaración de los métodos abstractos heredados de la interfaz Shape  *********/	

		// Calcula el área de una figura.
		double area() const override;

		// Calcula el perímetro de una figura.
		double perimeter() const override;
		
		// Traslada la figura sobre el espacio de representación, aplicando los incrementos de X e Y proporcionados.
		void translate(double incX, double incY) override;

		// Imprimirá por pantalla información básica sobre la figura -> Lo modificamos para que acepte un flujo de salida y podamos llamar a print() desde operator<<
		// Ahora print puede imprimir en cualquier flujo, incluido el que se pase al operador <<

		// Flujo: movimiento de datos desde un origen hacia un destino (e.g. mover los datos desde el programa hacia la pantalla[cout <<])
		// En C++, los flujos se manejan a través de clases como std::ostream (flujo de salida[imprimir en consola]) y std::istream (flujo de entrada[leer del teclado])
		void print() override;
};

#endif
