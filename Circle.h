#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <ostream>
#include "Shape.h"

// Comprobar si la sintaxis de este archivo.h es correcta: g++ -fsyntax-only Point2D.h

class Circle : public Shape {
    
	// Atributos privados
	private:
		Point2D center;		// Centro del círculo
		double radius;		// Radio del círculo

	// Métodos públicos
	public:
		// Constructor por defecto. Crea un círculo del color que se haya establecido por defecto (en nuestro caso es el rojo), de centro (0,0) y radio 1.
		Circle();	

		// Constructor con parámetros (igual que el de por defecto pero los valores se los pasamos como parámetros)
		Circle(std::string color, Point2D center, double radius);	
		
		// Consultor (getter) del atributo center
		Point2D get_center() const;

		// Modificador (setter) del atributo center
		void set_center(Point2D p);

		// Consultor (getter) del atributo radius
		double get_radius() const;

		// Modificador (setter) del atributo radius
		void set_radius(double r);

		// Sobrecarga global del operador << (friend)
		/*Intentar reaprovechar la implementación del método abstracto print() (interfaz de Shape)  en  operator<<() (o viceversa), para evitar duplicidad de código.*/
		friend std::ostream& operator<<(std::ostream &out, const Circle &c);

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
