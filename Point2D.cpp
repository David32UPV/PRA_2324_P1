#include "Point2D.h"
#include <ostream>
#include <cmath>

// Constructor
Point2D::Point2D(double x, double y){
	this->x = x;
	this->y = y;
}

// Calcula la distancia euclideana entre 2 puntos (a y b) -> Usar las funciones sqrt() y pow() de la librería <cmath>
double Point2D::distance(const Point2D &a, const Point2D &b){
	return sqrt(pow(((a.x) -(b.x)), 2) + (pow(((a.y) -(b.y)), 2)));
}

// Sobrecarga global del operador == -> Comprueba si dos puntos son iguales
bool operator==(const Point2D &a, const Point2D &b){
	return (a.x == b.x && a.y == b.y);
}

//Sobrecarga global del operador != -> Comprueba si dos puntos son diferentes.
bool operator!=(const Point2D &a, const Point2D &b){
	return !(a == b);	// Simplemente negamos el resultado de operator==
}

// Sobrecarga global del operador << -> Imprimir por pantalla el resultado
 std::ostream& operator<<(std::ostream &out, const Point2D &p){
	out << "C"<< p.x << "," <<  p.y << ")";
	return out;

 }
