#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <iostream>

using namespace std;

int n = 10000;
double a = 5;
double b = 12;
const int real = -108407;

double f(double& x) {
	return sin(x)*exp(x);
}

double simpsonIntegral(double a, double b, int n) {
	const double width = (b - a) / n;

	double simpson_integral = 0;
	for (int step = 0; step < n; step++) {
		double x1 = a + step * width;
		double x2 = a + (step + 1)*width;
		double hi = 0.5*(x1 + x2);
		simpson_integral += (x2 - x1) / 6.0*(f(x1) + 4.0*f(hi) + f(x2));
	}

	return simpson_integral;
}

int main() {
	double E = a;
	double h = (b - a) / n;
	double I = 0, f1 = 0,I1;
	cout << "Function:\tx * exp(sin(x))" <<endl;
	cout << "a = 5\tb = 12" << endl;
	cout << "Real:\t" << real << endl;
	while (E <= b) {
		I += h * f(E);
		E += h;
		f1 += f(E);
	}
	I1 = h * (((f(a) + f(b)) / 2) + f1);
	cout << "Rectangle method:\t" << I << endl;
	cout << "Trapezoid method:\t" << I1 << endl;
	cout << "Simpson method:\t" << simpsonIntegral(a, b, n) << endl;

	system("pause");
	return 0;
}