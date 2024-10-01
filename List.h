// Guarda de importación (ifndef: if not define)
#ifndef LIST_H
#define LIST_H

// La interfaz genérica List<T> es una clase abstracta pura y genérica (templatizada). Este tipo de clases SOLO definen los métodos (no tienen atributos)
template <typename T> class List{
	
	public:
		// Métodos virtuales puros que serán implementados en las clases derivadas
		virtual void insert(int pos, T e);
		virtual void append(T e);
		virtual void prepend(T e);
		virtual T remove(int pos);
		virtual T get(int pos);
		virtual int search(T e);
		virtual bool empty();
		virtual int size();

};
	

#endif
