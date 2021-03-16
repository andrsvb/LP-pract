#include <string.h>
#include <iostream>
using std::cout;
using std::cin;

//4.1
struct elemento {
	int a;
	int n;
	elemento *sig;
	elemento *ant;
};
typedef struct elemento *polinomio;

//4.2
void insertar(polinomio &poli, elemento *nuevo) {
	elemento *t = poli;
	//4.3
	if (poli == NULL) {
		poli = nuevo;
	} else if (poli->n > nuevo->n) {
		t->ant = nuevo;
		nuevo->sig = t;
		poli = nuevo;
	} else {
		//4.4
		while (t->sig != NULL) {
			if (t->n == nuevo->n) {
				t->a += nuevo->a;
				return;
			} else if (t->sig->n > nuevo->n) {
				t->sig->ant = nuevo;
				nuevo->sig = t->sig;
				t->sig = nuevo;
				nuevo->ant = t;
				return;
			} else
				t = t->sig;
		}
		//4.5
		if (t->n == nuevo->n) {
			t->a += nuevo->a;
			return;
		} else {
			nuevo->ant = t;
			t->sig = nuevo;
		}
	}
}
/*
//4.6
void imprimir(polinomio &poli){
	elemento *t = poli;
	cout << "\nimprimir";
	while(t!=NULL) {
		cout << "\n a: " << t->a << ", n: " << t->n;
		t = t->sig;
	}
}
*/

//4.7
int main(void) {
	std::string str;
	int i, signo;
	float resul, x = 1.5;
	polinomio poli = NULL;
	elemento *aux;
	//4.8
	cout << "\n Introduce el polinomio: ";
	cin >> str;
	//4.9
	i = 0;
	while (i < (int) str.size()) {
		aux = new (struct elemento);
		aux->a = 0;
		aux->n = 0;
		aux->ant = NULL;
		aux->sig = NULL;
		//4.10
		if (str[i] == '+')
			signo = 1;
		else if (str[i] == '-')
			signo = -1;
		else {
			cout << "\nError de formato";
			return 1;
		}
		i++;
		//4.11
		if (str[i] >= 'x')
			aux->a = 1;
		while (str[i] >= '0' && str[i] <= '9') {
			aux->a = 10 * aux->a + str[i] - '0';
			i++;
		}
		aux->a *= signo;
		//4.12
		if (str[i] == 'x') {
			i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
				aux->n = 1;
			while (str[i] >= '0' && str[i] <= '9') {
				aux->n = 10 * aux->n + str[i] - '0';
				i++;
			}
		}
		insertar(poli, aux);
	}
	//4.13
	i = 0;
	aux = poli;
	while (aux->sig != NULL) {
		if (aux->a != 0) {
			cout << "\na" << aux->n << " = " << aux->a;
			i++;
		}
		aux = aux->sig;
	}
	if (aux->a != 0) {
		cout << "\na" << aux->n << " = " << aux->a;
		i++;
	}
	if (i == 0) {
		cout << "\nNo hay ningun coeficiente distinto de 0";
		return 2;
	}
	//4.14
	resul = aux->a;
	i = aux->n;
	aux = aux->ant;
	while (aux->ant != NULL) {
		i--;
		while (i > aux->n) {
			resul = resul * x;
			i--;
		}
		resul = resul * x + aux->a;
		aux = aux->ant;
	}
	i--;
	while (i > aux->n) {
		resul = resul * x;
		i--;
	}
	resul = resul * x + aux->a;
	i--;
	while (i > -1) {
		resul = resul * x;
		i--;
	}
	cout << "\np(" << x << ") = " << resul;
	return 0;
}
