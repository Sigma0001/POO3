#include <iostream>
using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0

class nodo {
public:
	nodo(char v, nodo *sig = NULL, nodo *ant = NULL) :
		valor(v), siguiente(sig), anterior(ant) {}

	char valor;

	nodo *siguiente;
	nodo *anterior;

	friend class lista;
};

typedef nodo * pnodo;

class lista {
public:
	lista() : plista(NULL) {}
	~lista();

	void Insertar(char v);
	void Borrar(char v);
	bool ListaVacia() { return plista == NULL; }
	void Mostrar();
	void Siguiente();
	void Anterior();
	void Primero();
	void Ultimo();

	bool Actual() { return plista != NULL; }
	int ValorActual() { return plista->valor; }

	
	pnodo plista;
};

lista::~lista()
{
	pnodo aux;


	while (plista) {
		aux = plista;
		plista = plista->siguiente;
		delete aux;
	}
}

void lista::Insertar(char v)
{
	pnodo nuevo;


	
	if (ListaVacia() || plista->valor > v) {
		                   
		nuevo = new nodo(v, plista);
		if (!plista) plista = nuevo;
		else plista->anterior = nuevo;
	}
	else {
		
		while (plista->siguiente && plista->siguiente->valor <= v) Siguiente();
		
		nuevo = new nodo(v, plista->siguiente, plista);
		plista->siguiente = nuevo;
		if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
	}


	// cout << "Item Actual: " << nuevo->valor << endl;

}

void lista::Borrar(char v)
{
	pnodo nodo;

	nodo = plista;
	while (nodo && nodo->valor < v) nodo = nodo->siguiente;
	while (nodo && nodo->valor > v) nodo = nodo->anterior;

	if (!nodo || nodo->valor != v) return;
	

	if (nodo->anterior) 
		nodo->anterior->siguiente = nodo->siguiente;
	if (nodo->siguiente) 
		nodo->siguiente->anterior = nodo->anterior;
	delete nodo;
}

void lista::Mostrar()
{
	pnodo nodo = plista;
	Primero();
	while (nodo) {
		cout << nodo->valor << "-> ";
		nodo = nodo->siguiente;
	}

	cout << endl;
}

void lista::Siguiente()
{
	if (plista) plista = plista->siguiente;

}

void lista::Anterior()
{
	if (plista) plista = plista->anterior;


}

void lista::Primero()
{
	while (plista && plista->anterior) plista = plista->anterior;

}

void lista::Ultimo()
{
	while (plista && plista->siguiente) plista = plista->siguiente;
}

int main()
{
	lista Lista;

	int input;
	char cosa;
	char choice;


	do {
		cout << "\nAcciones			Items" << endl;
		cout << "1.-Agregar			f.-Fusca" << endl;
		cout << "2.-Descartar			e.-Filero" << endl;
		cout << "3.-Siguiente			t.-Tirachinas" << endl;
		cout << "4.-Anterior    			m.-LA MATA PERROS" << endl;
		cout << "5.-Mostrar" << endl;


		cout << "Que accion hacer?" << endl;
		cin >> input;


		switch (input) {
		case 1:
			cout << "Item: ";
			cin >> cosa;
			Lista.Insertar(cosa);
			cout << "Se agradio item: " << cosa << endl;
			Lista.Mostrar();
			break;
		case 2:
			cout << "Item: ";
			cin >> cosa;
			Lista.Borrar(cosa);
			cout << "Se borro item: " << cosa << endl;
			Lista.Mostrar();
			break;
		case 3:

			Lista.Siguiente();

			Lista.Mostrar();
			break;

		case 4:

			Lista.Anterior();

			Lista.Mostrar();
			break;
		case 5:

			Lista.Mostrar();

			break;
		}
		choice = 'l';
	}

	while (choice != 'n');

	
	return 0;
}
