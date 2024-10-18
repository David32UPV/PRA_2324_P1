// Implementación de los métodos de Circle.h y de los heredados de Shape.h

#include "Circle.h"
#include <cmath>
#include <iostream>

// Constructor por defecto. Crea un círculo del color que se haya establecido por defecto (en nuestro caso es el rojo), de centro (0,0) y radio 1.
// Llamamos al constructor de Shape que nos pone el color por defecto (el rojo)
// Al ser de tipo Point2D, la primera coordenada sería la x y la segunda la y
// Hacemos una lista de inicializacion para que pueda llamar a Shape() en el constructor de Circle y ya de paso inicializar sus atributos (los de Circle)
Circle::Circle() : Shape(), center(0, 0), radius(1.0){}

// Constructor con parámetros (igual que el de por defecto pero los valores se los pasamos como parámetros)
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius){}	

// Consultor (getter) del atributo center
Point2D Circle::get_center() const{
	return center;
}

// Modificador (setter) del atributo center
void Circle::set_center(Point2D p){
	center = p;
}

// Consultor (getter) del atributo radius
double Circle::get_radius() const{
	return radius;
}

// Modificador (setter) del atributo radius
void Circle::set_radius(double r){
	radius = r;
}

/*******  Implementación de los métodos abstractos heredados de la interfaz Shape  *********/	

double Circle::area() const{
	return M_PI * pow(radius, 2); 	// Area círculo = PI * radio²
}

double Circle::perimeter() const{
	return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;
}

// El objetivo es que cuando llamemos a std::cout << myCircle, se llame a la función print() para evitar duplicación de código.
// this es un puntero al objeto actual (instancia de Circle), luego *this desreferencia el puntero this, con lo que en *this obtengo el objeto actual de tipo Circle
// con std::cout << *this el compilador busca la sobrecarga de operator<< que toma un std::ostream& y un const Circle&
void Circle::print(){
	std::cout << *this << std::endl;
}

// Sobrecarga global del operador <<
/*Intentar reaprovechar la implementación del método abstracto print() (interfaz de Shape)  en  operator<<() (o viceversa), para evitar duplicidad de código.*/
std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "[Circle: color = " << c.get_color() << ";" << " center = " << c.get_center() << ";" << " radius = " << c.get_radius() << "]";  
	return out;
}


