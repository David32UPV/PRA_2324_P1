#include <ostream>
#include "List.h"
#include "Node.h"
#include <stdexcept>

template <typename T> class ListLinked : public List<T> {

    private:
 		Node<T>* first;		// Puntero al primer nodo
		int n;				// Nº de elementos de la lista
		        
    public:
	
		// Esta función nos sirve para la tabla hash para acceder al atributo first pues es privado
		Node<T>* getFirst() const{
			return first;
		}

		// Esta función también nos sirve para la tabla hash para modificar el atrubuto first
		Node<T>* &getFirstRef(){
			return first;
		}

		// Constructor que inicializa los 2 atributos de instancia -> first será nullptr
		ListLinked(){

			first = nullptr;
			n = 0;
		}	

		// Destructor que libera la memoria dinámica reservada por los nodos Node<T> que componen la secuencia
		~ListLinked(){
			
			while(first != nullptr){	
				// 1) Situamos un puntero aux que apunte al nodo first->next
				Node<T>* aux = first->next;	

				// 2) Liberar la memoria ocupada por el nodo al que apunta a first	
				delete first;

				// 3) Actualizar first para que apunte al mismo nodo que aux (bypass)
				first = aux;

				// 4) Repetir los pasos 1-3 (del 1 al 3) hasta que se alcance el final de la secuencia enlazada (while del principio)
			} 
		}
		
		// Sobrecarga del operador especial [] -> devuelve el elemento situado en la posición pos
		T operator[](int pos){
			if(pos >= 0 && pos < n){
				Node<T>* aux = first;	// Empezamos en el nodo cabeza de la lista (al que apunta first)
				int i = 0;
				while(aux != nullptr && i < pos){
					aux = aux->next;
					i++;
				}
	
				return aux->data;	// Elemento situado en la posición pos

			} else{
				throw std::out_of_range("Fuera del rango del array: pos = " + std::to_string(pos));
			}
		}
		
		// Sobrecarga del operador << -> 
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){

			// Imprimir una instancia de ListArray<T> por pantalla
			if(list.n == 0)
				out << "List => []";
			else{
				out << "List => [";
				out << "\n";
				Node<T>* aux = list.first;
				int i = 0;

				while(aux != nullptr && i < list.n){
					out << "  ";
					out << aux->data;

					aux = aux->next;	
					if(i != list.n -1){		// Si la posición del array i es distinto del ultimo elemento actual del array
						out << "\n";
					}
					i++;

				}

				out << "\n";
				out << "]";
			}

			return out;
		}


	/******************* Implementación de los métodos de List<T>  **************************/

		// Inserta el elemento e en la posición pos del array + lanza excepcion si pos está fuera de los limites del array dinámico
		void insert(int pos, T e) override{
			if(pos >= 0 && pos <= n){
			
				// Nos creamos dos nodos prev y aux que vayan avanzando en los nodos de la secuencia enlazada
				// Al final del todo, aux apuntará al nodo que ocupa la posición de inversión y prev al nodo precedente (el de antes) del que apunta aux
				Node<T>* prev = nullptr;
				Node<T>* aux = first;
				int i = 0;

				while(aux != nullptr && i < pos){
					
					prev = aux;
					aux = aux->next;
					i++;
				}
				
				// Si hemos encontrado la posición pos y aux no llega a apuntar a nullptr
				
				// Si queremos insertar al principio de la secuencia
				if(aux == first){
					first = new Node<T>(e, first);
				}
				// Si queremos insertar en cualquier otra posición
				else{
					prev->next = new Node<T>(e, aux);	// Le paso el elemento que quiero en la posicion pos y el nodo que apunta al nodo siguiente
				}

				n++;

			} else
				throw std::out_of_range("Fuera del rango del array: pos = " + std::to_string(pos));


		}
		
		// Inserta el elemento e al final de la lista (n)
		void append(T e) override{
			insert(n, e);
		}
		
		// Inserta el elemento e al principio de la lista
		void prepend(T e) override{
			insert(0, e);
		}
		
		// Elimina y devuelve el elemento situado en la posición pos +  Lanza una excepción std::out_of_range si la posición no es válida
		T remove(int pos) override{
			if(pos >= 0 && pos < n){

				Node<T>* prev = nullptr;
				Node<T>* aux = first;
				int i = 0;

				while(aux != nullptr && i < pos){
					
					prev = aux;
					aux = aux->next;
					i++;
				}

				
				// Eliminamos el nodo que está al principio de la secuencia
				if(aux == first){
					first = first->next; 		// bypass
				}
				else{
					prev->next = aux->next;		 // bypass
				}
				
				// Hay que declarar valor eliminado despues del bucle y del bypass porque si lo ponemos antes del bucle solo me eiminará el primer elemento (-5)
				T valor_eliminado = aux->data;
				delete aux;
				n--;
				return valor_eliminado;


			} else{
				throw std::out_of_range("Fuera del rango del array: pos = " + std::to_string(pos));

			}
		}

		// Devuelve el elemento situado en la posición pos.
		// Lanza una excepción std::out_of_range si la posición no es válida
		T get(int pos) override{
			if(pos >= 0 && pos < n){

				Node<T>* aux = first;	// Empezamos en el nodo cabeza de la lista (al que apunta first)
				int i = 0;
				while(aux != nullptr && i < pos){
					aux = aux->next;
					i++;
				}

				return aux->data;	// Elemento situado en la posición pos

			} else
				throw std::out_of_range("Fuera del rango del array: pos = " + std::to_string(pos));


		}
		
		// Devuelve la 1ª posición en la que aparece el elemento e en el array. Devuelve -1 si no lo encuentra en el array
		int search(T e) override{
			
			Node<T>* aux = first;
			int i = 0;
			while(aux != nullptr && aux->data != e){
				aux = aux->next;
				i++;
			}

			if(aux != nullptr){
				return i;
			} else{
				return -1;
			}

		}
		
		// Indica si la lista está vacía
		bool empty() override{
			if(n == 0)
				return true;
			else
				return false;

		}

		// Devuelve el nº de elementos de la lista
		int size() override{
			
			return n;
		}	

};
