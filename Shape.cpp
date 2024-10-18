// Implementaremos los métodos NO virtuales de Shape.h

#include "Shape.h"
#include <iostream>

// Constructor por defecto, crea una figura de color rojo. 
Shape::Shape(){
	color = "red";
}

// Constructor con parámetro: crea una figura del color especificado + Lanza excepción std::invalid_argument si el color proporcionado no es válido.
Shape::Shape(std::string color){
	
	if(color != "red" && color != "green" && color != "blue")
		throw std::invalid_argument("¡Color NO válido!");
	this->color = color;
}

// Devuelve el color de relleno de la figura.
std::string Shape:: get_color() const{
	return color;
}

// Modifica el color de relleno de la figura. Solo podrá ser uno de estos tres valores: "red", "green", "blue". Sino es uno de estos colores, lanza std::invalid_argument
void Shape::set_color(std::string c){
	if(c != "red" && c != "green" && c != "blue")
		throw std::invalid_argument("¡Color NO válido!");
	color = c;
}


