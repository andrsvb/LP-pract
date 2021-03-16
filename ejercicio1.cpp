#include <math.h>
#include <iostream>
using std::cout;
using std::cin;

int main() {
	float n1, n2, o1, omax, o2;
	//1.1
	cout << "\nIntroduce el valor del indice de refracción del primer medio: ";
	cin >> n1;
	cout << "\nIntroduce el valor del indice de refracción del segundo medio: ";
	cin >> n2;
	cout << "\nIntroduce el valor del angulo de incidencia: ";
	cin >> o1;
	//1.2
	if(n1 < 1 || n2 < 1 || o1 < 0 || o1 > M_PI / 2){
		cout << "\nLos datos introducidos no son validos";
		return 1;
	}
	//1.3
	omax = asin(n2 / n1);
	if (o1 >= omax)
		cout << "\nNo se produce refracción";
	else {
		o2 = asin(n1 * sin(o1) / n2);
		cout << "El angulo de refraccion es " << o2;
	}
	return 0;
}

