#include <ostream>

template <typename T> class Node {
    public:

		// Atributos
		T data;				// Elemento almacenado
		Node<T>* next;		// Puntero al siguiente nodo de la secuencia (o a nullptr si este es el último nodo de la secuencia)
    	
		// Métodos

		// Constructor
		 Node(T data, Node<T>* next = nullptr){			// next será nullptr en caso de que no se proporcione next
		 	this->data = data;
			this->next = next;
		 }

		// Sobrecarga operador << para imprimir una instancia de Node<T> por pantalla -> la función se limita a imprimir el atributo data de Node<T>
		 friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << node.data;
			return out;
		}


};
