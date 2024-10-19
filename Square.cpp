#include "Square.h"
#include <cmath>
#include <iostream>

/*Comprueba, a partir de un array de 4 objetos Point2D proporcionado como parámetro, si esos vértices conforman un cuadrado válido.*/
bool Square::check(Point2D* vertices){
	if((Point2D::distance(vertices[0], vertices[1])) == (Point2D::distance(vertices[1], vertices[2])) && (Point2D::distance(vertices[2], vertices[3])) ==
	(Point2D::distance(vertices[3], vertices[0]))){
		return true;
	} else 
		return false;	
}

/*Constructor por defecto. Creará un cuadrado con el color que esté establecido por defecto, y los vértices v0=(-1,1); v1=(1,1), v2=(1,-1), y v3=(-1,-1).*/
Square::Square() : Rectangle(){

	// Reserva de memoria dinámica para los 4 vértices
	vs = new Point2D[N_VERTICES];
	
	// Asignación de los valores de los vértices
	vs[0] = Point2D(-1, 1);
	vs[1] = Point2D(1, 1);
	vs[2] = Point2D(1, -1);
	vs[3] = Point2D(-1, -1);	
}

/*Constructor por parámetros -> Si esos vértices NO conforman un cuadrado válido, lanzará una excepción std::invalid_argument*/
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices){

	// Comprobar si los vértices conforman un rectángulo = Si check es false
	if(!check(vertices)){
		throw std::invalid_argument("¡¡Los vértices no conforman un cuadrado!!");
	}

	// Reserva de memoria dinámica para los 4 vértices
	vs = new Point2D[N_VERTICES];
	
	// Copiamos los elementos del nuevo array vertices al array vs
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
	
}

// Método virtual -> Modifica los vértices del cuadrado. Si los vértices no conforman un rectángulo válido, devuelve std::invalid_argument
void Square::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw std::invalid_argument("¡¡Los vértices no conforman un cuadrado!!");
	}

	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];	
	}	

}

// Imprimirá por pantalla información básica sobre la figura
void Square::print(){
	std::cout << *this << std::endl;
}

// Sobrecarga global del operador <<
std::ostream& operator<<(std::ostream &out, const Square &square){
	out << "[Square: color = " << square.get_color() << ";" << " v0 = " << square.get_vertex(0) << ";" << " v1 = " << square.get_vertex(1) << ";" << 
	" v2 = " << square.get_vertex(2) << ";" << " v3 = " << square.get_vertex(3) << "]";  
	return out;

}


