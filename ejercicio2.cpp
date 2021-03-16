#include <math.h>
#include <fstream>
#include <iostream>
using std::cout;
using std::cin;

//2.1
struct punto {
	int x, y;
	punto *sig;
};
struct lista_puntos {
	punto *primero;
	punto *ultimo;
};

//2.2
lista_puntos* newLista() {
	lista_puntos *lista = new (struct lista_puntos);
	lista->primero = NULL;
	lista->ultimo = NULL;
	return lista;
}

//2.3
void insertar(lista_puntos *lista, int new_x, int new_y) {
	punto *t = new (struct punto);
	punto *iter = lista->primero;
	t->x = new_x;
	t->y = new_y;
	t->sig = NULL;
	//2.4
	if (lista->primero == NULL) {
		lista->primero = t;
		lista->ultimo = t;
	} else {
		//2.5
		while (iter != NULL) {
			if (iter->x == new_x && iter->y == new_y)
				return;
			iter = iter->sig;
		}
		lista->ultimo->sig = t;
		lista->ultimo = t;
	}
}

//2.6
void imprimir_puntos(lista_puntos &lista) {
	if (lista.primero != NULL) {
		punto *t;
		for (t = lista.primero; t != lista.ultimo; t = t->sig)
			cout << "\n(" << t->x << ", " << t->y << ")";
		cout << "\n(" << t->x << ", " << t->y << ")";
	}
}

int main(void) {
//2.7
	float a, b, c;
	float x, y, d, dmax = 0;
	lista_puntos *lista = newLista();
	std::ifstream f_puntos;
//2.8
	f_puntos.open("puntos.txt", std::ios::in);
	if (!f_puntos) {
		cout << "\nNo se puede abrir el fichero: ";
		return 1;
	}
//2.9
	cout << "\nIntroduce el valor de a: ";
	cin >> a;
	cout << "\nIntroduce el valor de b: ";
	cin >> b;
	cout << "\nIntroduce el valor de c: ";
	cin >> c;
	if (a == b && a == 0) {
		cout << "\nTanto a como b son iguales a 0";
		return 2;
	}
//2.10
	while (!f_puntos.eof()) {
		if (!(f_puntos >> x) || !(f_puntos >> y)) {
			cout << "Error al leer del fichero";
			return 3;
		}
		//2.11
		d = abs(a * x + b * y + c) / sqrt(a * a + b * b);
		if (d > dmax) {
			dmax = d;
			lista = newLista();
			insertar(lista, x, y);
		} else if (d == dmax) {
			insertar(lista, x, y);
		}
	}
//2.12
	cout << "\nLa distancia maxima es: " << dmax << ", dada por los puntos:";
	imprimir_puntos(*lista);
	return 0;
}
