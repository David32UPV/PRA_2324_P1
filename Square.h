#include <stdexcept>
#include <iostream>
#include <ostream>
#include "Rectangle.h"

class Square : public Rectangle{

	// Métodos -> Debemos sobreescribir (override) os métodos virtuales print() y set_vertices() heredados de la clase Rectangle
	private:

		/*Comprueba, a partir de un array de 4 objetos Point2D proporcionado como parámetro, si esos vértices conforman un cuadrado válido.*/
		static bool check(Point2D* vertices);

		/*Constructor por defecto. Creará un cuadrado con el color que esté establecido por defecto, y los vértices v0=(-1,1); v1=(1,1), v2=(1,-1), y v3=(-1,-1).*/
		Square();
		
		/*Constructor por parámetros -> Si esos vértices no conforman un cuadrado válido, lanzará una excepción std::invalid_argument*/
		Square(std::string color, Point2D* vertices);
		
		// Sobrecarga global del operador <<
		friend std::ostream& operator<<(std::ostream &out, const Square &square);

		/*** Debemos declarar las funciones que se van a sobreescribir (override) en el .cpp de esta clase ***/

		// Método virtual -> Modifica los vértices del cuadrado. Si los vértices no conforman un rectángulo válido, devuelve std::invalid_argument
		virtual void set_vertices(Point2D* vertices);

		// Imprimirá por pantalla información básica sobre la figura
		virtual void print();

};
