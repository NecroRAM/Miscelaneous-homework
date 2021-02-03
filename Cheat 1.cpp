#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <random>

int main()
{
	//legacy rand
	srand(time(nullptr));
	int n = rand() % 6 + 5;

	//std::vector<int> x{ 1, 2, 3, 4, 3, 6, 7, 1, 9 }, y;

	std::vector<int> x, y, w, z;	
	for (int i = 0; i < n; ++i)
		x.push_back(rand() % 14 - 10);
	for (int i = 0; i < n; ++i)//(int i = 0; i < x.size(); ++i)
	{
		std::cout << x[i] << ' ';
		if (x[i] - i < 0)
			y.push_back(x[i]);
	}
	std::cout << '\n';
	for (int i = 0; i < y.size(); ++i)
		std::cout << y[i] << ' ';
	std::cout << '\n';

	//modern rand
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution distr(-10, 3);
	for (int i = 0; i < n; ++i)
		w.push_back(distr(gen));
	std::cout << '\n';
	for (int i = 0; i < n; ++i)//(int i = 0; i < x.size(); ++i)
	{
		std::cout << w[i] << ' ';
		if (x[i] - i < 0)
			z.push_back(x[i]);
	}
	std::cout << '\n';
	for (int i = 0; i < y.size(); ++i)
		std::cout << z[i] << ' ';
}