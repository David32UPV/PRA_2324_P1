// Guarda de importación (ifndef: if not define)
#ifndef LIST_H
#define LIST_H

// La interfaz genérica List<T> es una clase abstracta pura y genérica (templatizada). Este tipo de clases SOLO definen los métodos (no tienen atributos)
template <typename T> class List{
	
	public:
		// Métodos virtuales puros que serán implementados en las clases derivadas
		virtual void insert(int pos, T e) = 0;
		virtual void append(T e) = 0;
		virtual void prepend(T e) = 0;
		virtual T remove(int pos) = 0;
		virtual T get(int pos) = 0;
		virtual int search(T e) = 0;
		virtual bool empty() = 0;
		virtual int size() = 0;

};
	

#endif
