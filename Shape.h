/* Las guradas de importación se pueden entender con el siguiente ejemplo:
Imagina que tienes dos archivos .h que incluyen el mismo archivo de encabezado común. Cuando ambos archivos.h son incluidos en un archivo .c, el compilador trataría de procesar el contenido del archivo de encabezado común dos veces, lo cual generaría errores de redefinición.
*/

#ifndef SHAPE_H		// Si SHAPE_H no está definido
#define SHAPE_H		// Entonces define SHAPE_H

#include <string>
#include "Point2D.h"	// Como las clases herederas de Shape van a trabajar con la clase Point2D, incluimos su fichero de cabecera para así no tener que incluirlo
						// en las clases derivadas

// La interfaz determinará un conjunto de operaciones básicas que se pueden realizar sobre una forma o figura concreta
// Es una clase abstracta. Podemos hacer funciones tanto virtuales puras como clásicas (de toda la vida)
template <typename T> class Shape{
	
	// Atributos protegidos -> Accesibles desde clases derivadas (a diferencia de private)
	protected:		
		std::string color;		// Color de la figura. Solo podrá ser uno de estos tres valores: "red", "green", "blue".
	
	// Métodos públicos que serán implementados en clases derivadas
	public:
		// Constructor que crea una figura de color rojo
		 Shape();
		
		// Constructor con parámetro: crea una figura del color especificado + Lanza excepción std::invalid_argument si el color proporcionado no es válido.
		Shape(std::string color);
		
		// Devuelve el color de relleno de la figura.
		std::string get_color() const;

		// Modifica el color de relleno de la figura. Solo podrá ser uno de estos tres valores: "red", "green", "blue". Sino es uno de estos colores, lanza std::invalid_argument
		 void set_color(std::string c);

		 /****** Ahora van métodos virtuales puros (igualamos a 0) *******/
		
		// Método virtual puro. Calcula el área de una figura.
		virtual double area() const = 0;

		// Método virtual puro. Calcula el perímetro de una figura.
		virtual double perimeter() const = 0;

		// Método virtual puro. Traslada la figura sobre el espacio de representación, aplicando los incrementos de X e Y proporcionados.
		virtual void translate(double incX, double incY) = 0;

		// Método virtual puro. Imprimirá por pantalla información básica sobre la figura. 
		virtual void print() = 0;		// Usamos print y no el operator<< porque éste no puede ser polimórfico (que se pueda usar en varias clases herederas)

};


#endif 				// Fin del bloque protegido
