#include <iostream>
#include <ctime>

using namespace std;

size_t n = 1000000;

void PrintGistogram(double* Arr, double from, double to, double step) {
	if (from == 0) {
		for (size_t i = 0; i < n; i++)
			Arr[i] = Arr[i] / 2147483647 * to;

		unsigned int counter = 0;
		for (double i = from; i <= to - step; i += step) {
			for (size_t j = 0; j < n; j++)
				if ((Arr[j] >= i) && (Arr[j] <= i + step))
					counter++;
			cout << '[' << i << ';' << i + step << "]\t" << double(counter) / n * 100 << endl;
			counter = 0;
		}
	}
	else {

	}
}

unsigned int Random1(unsigned int seed) {
	unsigned int m = 2147483647;
	unsigned int a = 5;
	unsigned int c = 5;
	seed %= m;

	return (a * seed + c) % m;
}

unsigned int Random2(unsigned int seed) {
	unsigned int m = 2147483647;
	unsigned int c = 1000;
	unsigned int a = 498;
	unsigned int d = 4;
	seed %= m;

	return (d * seed * seed + a * seed + c) % m;
}

unsigned int Random3(unsigned int seed1, unsigned int seed2) {
	unsigned int m = 2147483647;
	seed1 %= m;
	seed2 %= m;

	return (seed1 + seed2) % m;
}



int main() {
	double* Arr = new double[n];
	Arr[0] = Random1(time(NULL));
	Arr[1] = Random1(Arr[0]);

	for (size_t i = 2; i < n; i++) {
		Arr[i] = Random3(Arr[i-2], Arr[i-1]);
		cout << Arr[i]/ 2147483647 << endl;
	}

	PrintGistogram(Arr, 0, 1, 0.1);

	delete[] Arr;

	system("pause");
	return 0;
}
