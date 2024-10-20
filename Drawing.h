#include <stdexcept>
#include <iostream>
#include <ostream>
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "List.h"
#include "ListArray.h"
#include "ListLinked.h"

class Drawing{
	
	// Atributos
	private:
		List<Shape*>* shapes;	// Lista de figuras representadas en el dibujo. 		
	
	// Métodos
	public:
		// Constructor -> Reserva memoria dinámica para el atributo shapes.
		Drawing();
		
		// Destructor -> Libera la memoria dinámica reservada por shapes.
		~Drawing();
		
		// Añade la figura shape al frente del dibujo.
		void add_front(Shape* shape);
		
		// Añade la figura shape al fondo del dibujo.
		void add_back(Shape* shape);
		
		// Muestra por pantalla información de todas las figuras del dibujo.
		void print_all();

		// Devuelve el área ocupada por todos los círculos presentes en el dibujo.
		double get_area_all_circles();
		
		// Mueve todos los cuadrados del dibujo, aplicando los incrementos de X e Y proporcionados.
		void move_squares(double incX, double incY);

};
