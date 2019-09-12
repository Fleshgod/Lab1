#include <iostream>
#include <ctime>

using namespace std;

size_t n = 100000;

void PrintGistogram(double* Arr, double from, double to, double step, unsigned int m) {
	if (from == 0) {
		for (size_t i = 0; i < n; i++)
			Arr[i] = Arr[i] / m * to;

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

unsigned int findReversal(unsigned int x, unsigned int m) {
	unsigned int i = 1;
	if (x == 0) x += 1;
	while (((x*i) % m != 1) && (x < m))
		i++;
	return i;
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

unsigned int Random4(unsigned int seed) {
	unsigned int m = 10007;
	unsigned int c = 382;
	unsigned int a = 1025;
	seed %= m;

	return (a*findReversal(seed, m) + c) % m;
}

unsigned int Random5(unsigned int x, unsigned int y) {
	unsigned int m = 2147483647;
	
	return (x - y) % m;
}

int main() {
	double* Arr = new double[n];
	srand(time(NULL));
	unsigned int x = rand();
	unsigned int y = rand();

	for (size_t i = 0; i < n; i++) {
		Arr[i] = Random5(x, y);
		x = Random1(x);
		y = Random2(y);
	}

	PrintGistogram(Arr, 0, 1, 0.1, 2147483647);

	system("pause");
	return 0;
}
