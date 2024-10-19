// Implementación de los métodos de Rectangle.h y de los heredados de Shape.h

#include "Rectangle.h"
#include <cmath>
#include <iostream>

// Comprueba si los vértices conforman un rectángulo válido -> Hacer uso del método estático Point2D::distance().
bool Rectangle::check(Point2D* vertices){
	if((Point2D::distance(vertices[0], vertices[1])) == (Point2D::distance(vertices[2], vertices[3])) && (Point2D::distance(vertices[1], vertices[2])) ==
	(Point2D::distance(vertices[3], vertices[0]))){
		return true;
	} else 
		return false;
}

// Constructor por defecto -> Creará un rectángulo con el color que esté establecido por defecto, y los vértices v0=(-1,0.5); v1=(1,0.5), v2=(1,-0.5), y v3=(-1,-0.5).
Rectangle::Rectangle() : Shape(){
	
	// Reserva de memoria dinámica para los 4 vértices
	vs = new Point2D[N_VERTICES];
	
	// Asignación de los valores de los vértices
	vs[0] = Point2D(-1, 0.5);
	vs[1] = Point2D(1, 0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
}


// Constructor por parámetros que recibe el color y los vértices. Si los vértices NO conforman un rectángulo -> std::invalid_argument
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
	
	// Comprobar si los vértices conforman un rectángulo = Si check es false
	if(!check(vertices)){
		throw std::invalid_argument("¡¡Los vértices no conforman un rectángulo!!");
	}

	// Reserva de memoria dinámica para los 4 vértices
	vs = new Point2D[N_VERTICES];
	
	// Copiamos los elementos del nuevo array vertices al array vs
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}

}


//Constructor de copia -> Permitirá hacer una copia segura de rectángulos. Copiar un objeto implica crear una réplica de este en memoria, con idéntico estado interno
// Así, el constructor de copia crea un nuevo objeto en memoria, i.e. me están pasando un objeto de r como parámetro
Rectangle::Rectangle(const Rectangle &r) : Shape(r){
	
	// Reservar nueva memoria para vs y copiar los vértices del objeto fuente.
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = r.vs[i];	
	}

}

// Destructor -> Libera la memoria dinámica reservada por el array vs.
Rectangle::~Rectangle(){
	delete[]vs;
}

// Devuelve el Point2D del rectángulo que ocupa el índice ind. Lanza una excepción std::out_of_range si el índice no es válido (fuera del intervalo [0, N_VERTICES-1]).
Point2D Rectangle::get_vertex(int ind) const{
	if(ind < 0 || ind > N_VERTICES - 1){
		throw std::out_of_range("¡¡El índice está fuera del rango permitido!!");
	}
	// Si el índice es válido, devolver el vértice que está en esa posición (índice) del array vs -> vs[ind]
	return vs[ind];

}

// Sobrecarga del operador []. Devuelve el elemento situado en la posición ind. Lanza una excepción std::out_of_range si la posición no es válida
Point2D Rectangle::operator[](int ind) const{
	if(ind < 0 || ind > N_VERTICES - 1){
		throw std::out_of_range("¡¡El índice está fuera del rango permitido!!");
	} else
		return vs[ind];	
}

// Método virtual -> Modifica los vértices del rectángulo. Si los vértices no conforman un rectángulo válido, devuelve std::invalid_argument
void Rectangle::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw std::invalid_argument("¡¡Los vértices no conforman un rectángulo!!");
	}

	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];	
	}

}

// Sobrecarga del operador = (asignación de copia). Permitirá hacer una copia segura de rectángulos.
/*Para prevenir problemas en el operador de asignación, se verifica si el objeto que se está asignando es el mismo que el objeto actual (this).
Si son iguales, simplemente no se hace nada (se evita la asignación para evitar errores). Si no son iguales, se procede a copiar los datos.*/
Rectangle& Rectangle::operator=(const Rectangle &r){
	
	// Como this es ya un puntero, tenemos que compararlo con otro puntero (&r) y NO con r
	if(this != &r){
		// Cuando un Rectangle se asigna a otro, necesitas asegurarte de que el array vs del objeto destino no apunta a la misma memoria que el del objeto fuente.
		vs = new Point2D[N_VERTICES];
		for(int i = 0; i < N_VERTICES; i++){
			vs[i] = r.vs[i];	
		}

	}
	// this -> instancia de la clase que está llamando a operator=
	return *this;	// Siempre devuelve el objeto actual

}

/******** Implementación de los métodos abstractos heredados de la interfaz Shape  *********/


// Calcula el área de una figura. En nuestro caso del rectángulo: A = base * altura
double Rectangle::area() const{
	double base = Point2D::distance(vs[0], vs[1]);
	double altura = Point2D::distance(vs[0], vs[3]);
	return base * altura;
}

// Calcula el perímetro de una figura. En nuestro caso del rectángulo: P = base + base + altura + altura = 2 * (base + altura)
double Rectangle::perimeter() const{
	double base = Point2D::distance(vs[0], vs[1]);
	double altura = Point2D::distance(vs[0], vs[3]);
	return 2 * (base + altura);
}

// Traslada la figura sobre el espacio de representación, aplicando los incrementos de X e Y proporcionados. Idea: vs[0].x += incX
void Rectangle::translate(double incX, double incY){
	for(int i = 0; i < N_VERTICES; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

// Imprimirá por pantalla información básica sobre la figura 
void Rectangle::print(){
	std::cout << *this << std::endl;
}

// Sobrecarga global del operador <<
/*Intentar reaprovechar la implementación del método abstracto print() (interfaz de Shape)  en  operator<<() (o viceversa), para evitar duplicidad de código.*/
std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "[Rectangle: color = " << r.get_color() << ";" << " v0 = " << r.get_vertex(0) << ";" << " v1 = " << r.get_vertex(1) << ";" << " v2 = " << r.get_vertex(2)
	<< ";" << " v3 = " << r.get_vertex(3) << "]";  
	return out;
}

