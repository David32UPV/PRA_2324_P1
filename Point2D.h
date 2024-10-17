#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

// Solo definimos!! -> Implementamos los métodos en Point2D.cpp

class Point2D{
    
	public:
	// Atributos
		double x,y;

	// Métodos
		// Constructor -> Recordar que en los Constructores, se inicializan los atributos de la clase a 0
		Point2D(double x = 0, double y = 0);

		// Calcula la distancia euclideana entre 2 puntos (a y b) -> Usar las funciones sqrt() y pow()de la librería <cmath>
		static double distance(const Point2D &a, const Point2D &b);
		
		// La sobrecarga global de operadores binarios (== o !=) necesitan el friend solo si se necesita acceder a atributos y/o métodos privados.
		// Cuando tienen el friend, se declara la funcion dentro de la clase pero se implementa fuera de la clase

		// Sobrecarga global del operador == -> Comprueba si dos puntos son iguales
		friend	bool operator==(const Point2D &a, const Point2D &b);

		//Sobrecarga global del operador != -> Comprueba si dos puntos son diferentes.
		friend bool operator!=(const Point2D &a, const Point2D &b);

		// Sobrecarga global del operador << -> Imprimir por pantalla el resultado
		friend std::ostream& operator<<(std::ostream &out, const Point2D &p);


};

#endif
