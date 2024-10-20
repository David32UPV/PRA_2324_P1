#include "Drawing.h"
#include <cmath>
#include <iostream>

// Constructor -> Reserva memoria dinámica para el atributo shapes.
// Aquí decidimos cuál de las dos clases derivadas se instanciará, i.e. si trabajamos con arrays o con listas enlazadas.
// En cualquiera de los casos, el puntero de la clase base actuará como interfaz a la clase derivada.
// Es mejor trabajar con listas enlazadas para que el array dinámico crezca a medida que añado figuras

// shapes[i] es en arrays estáticos, pero en arrays dinámicos usamos shapes->get(i)

/* Inicializar una lista enlazada vacía. No preocuparme por tamaños fijos como MINSIZE, ya que mi lista crece dinámicamente a medida que se añaden figuras*/
Drawing::Drawing(){
	shapes = new ListLinked<Shape*>();
}
// Destructor -> Libera la memoria dinámica reservada por shapes.
Drawing::~Drawing(){
	while(!shapes->empty()){		// Mientras la lista NO esté vacía, vamos liberando la memoria que ocupa cada figura
		delete shapes->remove(0);	// Liberamos la memoria de cada figura. Escogemos la posicion 0 para eliminar siempre el primer nodo en cada iteracion del bucle.
	}

	delete shapes;	// Liberamos la memoria de la lista una vez esté vacía
}

// Añade la figura shape al frente del dibujo -> Lo insertamos en la primera posición del array
void Drawing::add_front(Shape* shape){
	shapes->prepend(shape);
}

// Añade la figura shape al fondo del dibujo -> Lo insertamos en la última posición del array
void Drawing::add_back(Shape* shape){
	shapes->append(shape);
}

// Muestra por pantalla información de todas las figuras del dibujo.
void Drawing::print_all(){
	std::cout << "Drawing contents: " << std::endl;
	for(int i = 0; i < shapes->size(); i++){
		shapes->get(i)->print();	// No podemos hacer shapes->print() directamente porque primero tenemos que devolver el elemenro situado en la posicion i (cada figura)
	}
}

// Devuelve el área ocupada por todos los círculos presentes en el dibujo.
double Drawing::get_area_all_circles(){
	double area = 0.0;
	for(int i = 0; i < shapes->size(); i++){
		// Hacemos dyanmic_cast para convertir punteros (*) o referencias(&) entre tipos de datos polimórficos de manera segura	
		// Si shapes[i] apunta a un objeto de tipo Circle, el cast será exitoso y se asignará un puntero válido a circle, puediendo obtener el área de los circle
		if(Circle* circle = dynamic_cast<Circle*>(shapes->get(i))){
			area += circle->area();
		}
	}
	// Al final, devolvemos la suma del area de todos los círculos
	return area;
}

// Mueve todos los cuadrados del dibujo, aplicando los incrementos de X e Y proporcionados.
void Drawing::move_squares(double incX, double incY){
	for(int i = 0; i < shapes->size(); i++){
		// Si shapes[i] apunta a un objeto de tipo Square, el cast será exitoso y se asignará un puntero válido a square, puediendo trasladar los vértices de los square
		if(Square* square = dynamic_cast<Square*>(shapes->get(i))){
			square->translate(incX, incY);	
		}
	}
}




