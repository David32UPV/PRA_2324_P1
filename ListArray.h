#include "List.h"
#include <ostream>
#include <stdexcept>

template <typename T> class ListArray : public List<T>{

	// Miembros privados
	private:
		T* arr; 						// Puntero al inicio del array que almacenará los elementos de la lista de forma contigua, siendo los elementos de tipo T genérico
		int max; 						// Tamaño actual del array: no le ponemos const int max porque el tamaño se podrá alterar durante la vida de la lista
		int n;							// nº de elementos que contiene la lista
		static const int MINSIZE = 2;	// Tamaño mínimo del array que debe inicializarse a 2 (en el constructor)

		/* Redimensiona el array al tamaño especificado (new_size), para incrementar su capacidad(si está lleno)
		 o para reducirla (si está demasiado vacío)*/
		void resize(int new_size){
			// 1) Crear un nuevo array dinámico new_size elementos(usar new)
			T *arr_new = new T[new_size];

			// 2) Copiar el contenido del array actual (arr) en el nuevo array
			for(int i = 0; i < n; i++)
				arr_new[i] = arr[i];

			// 3) Liberar los recursos de memoria que ocupa arr (usar delete[])
			delete[] arr;

			// 4) Actualizar el puntero arr para que apunte a la dirección de memoria en la que se encuentra el nuevo array (arr_new)
			arr = arr_new;

			// 5) Actualizar max
			max = new_size;
		}							
	// Miembros públicos, incluidos los heredados de la clase base List<T>
	public:
		// Constructor de la clase
		ListArray(){
			MINSIZE;
			n = 0;
			max = MINSIZE;
			arr = new T[MINSIZE];		// Reserva de memoria dinámica para crear un array de tamaño MINSIZE de elementos de tipo T
		}

		// Destructor de la clase
		~ListArray(){
			delete[]arr;
		}
		
		// Sobrecarga de operador especial []
		T operator[](int pos){
			if(pos >= 0 && pos < n)	// Correcto si el elemento está dentro del rango [0, size()-1)]
				return arr[pos];		// Devuelve el elemento situado en la posición pos
			else
				throw std::out_of_range("Fuera del rango del array");
		}
		
		// Sobrecarga global del operador << (std::cout)
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			
			// Imprimir una instancia de ListArray<T> por pantalla
			if(list.n == 0)
				out << "List => []";
			else{
				out << "List => [";
				out << "\n";
				for (int i = 0; i < list.n; i++){
					out << "  ";
					out << list.arr[i];
					if(i != list.n -1){		// Si la posición del array i es distinto del ultimo elemento actual del array
						out << "\n";
					}
				}
				out << "\n";
				out << "]";
			}

			return out;
		}

		/******* Implementación de los metodos públicos heredados de la clase base List<T> *******/	
		
		// Inserta el elemento e en la posición pos del array
		// Es necesario desplazar todos los elementos a la derecha de esa posición 1 casilla hacia la derecha para hacer espacio
		void insert(int pos, T e) override{
			if(pos >= 0 && pos <= n){
				if(n == max){
					resize(2 * max);
				}
	
				for(int i = n; i > pos; i--){
					arr[i] = arr[i-1];		
				}
				
				// Asignación del elemento tras dejar hueco en el array
				arr[pos] = e;
				n++;
			}
			else
				throw std::out_of_range("Fuera del rango del array");
		}

		// Inserta el elemento e al final de la lista
		void append(T e) override {
		
			insert(n, e);  // Usa insert para agregar al final
		}			
		
		
		// Inserta el elemento e al principio de la lista
		void prepend(T e) override{

			insert(0, e);
			
		}
		
		// Elimina y devuelve el elemento situado en la posición pos.
		// Lanza una excepción std::out_of_range si la posición no es válida
		T remove(int pos) override{
			if(pos >= 0 && pos < n){
				// Guardamos el valor que será eliminado y es de tipo T
				T valor_eliminado = arr[pos];
				// Desplazamos TODOS  los elementos situados a la derecha del elemento a eliminar (pos) 1 posición a la izquierda, para así mantener la contigüidad del array
				for(int i = pos; i < n-1; i++){
					arr[i] = arr[i+1];
				}
			n--;
			return valor_eliminado;
			} else
				throw std::out_of_range("Fuera del rango del array");

		}
	
		// Devuelve el elemento situado en la posición pos.
		// Lanza una excepción std::out_of_range si la posición no es válida
		T get(int pos) override{
			if(pos >= 0 && pos < n){
				return arr[pos];
			} else
				throw std::out_of_range("Fuera del rango del array");
		}

		// Devuelve la 1ª posición en la que aparece el elemento e en el array. Devuelve -1 si no lo encuentra en el array
		int search(T e) override{
			for(int i = 0; i < n; i++){
				if(arr[i] == e)
					return i;
			}
			
			// Cuando acabas de revisar todo el array (te sales del bucle) y NO lo has encontrado, devuelves el -1
			return -1;

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
