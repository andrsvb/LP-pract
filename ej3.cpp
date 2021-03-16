#include <math.h>
#include <fstream>
#include <iostream>
using std::cout;
using std::cin;
#include <iomanip>

int main(void) {
	//3.1
	float fi[11][11], d_x = 0.1, d_t = 0.1, u = 1, r;
	int i, j;
	r = (u * d_t / d_x) * (u * d_t / d_x);
	std::ofstream f_out;
	f_out.open("resultados.txt", std::ios::out);
	//3.2
	for (j = 0; j <= 10; j++) {
		fi[0][j] = 0;
		fi[10][j] = 0;
	}
	//3.3
	for (i = 1; i < 10; i++)
		fi[i][0] = sin(M_PI * (i * d_x));
	//3.4
	for (i = 1; i < 10; i++)
		fi[i][1] = (1 - r) * fi[i][0] + (r / 2) * (fi[i + 1][0] + fi[i - 1][0]);
	//3.5
	for (j = 2; j <= 10; j++)
		for (i = 1; i < 10; i++)
			fi[i][j] = 2 * (1 - r) * fi[i][j - 1]
					+ r * (fi[i + 1][j - 1] + fi[i - 1][j - 1]) - fi[i][j - 2];
	//3.6
	for (i = 0; i < 11; i++) {
		for (j = 0; j < 11; j++) {
			if (j > 0)
				f_out << " ";
			if (fi[i][j] >= 0)
				f_out << "+";
			f_out << std::fixed << std::setprecision(4) << fi[i][j];
		}
		f_out << "\n";
	}
	f_out.close();
	return 0;
}
