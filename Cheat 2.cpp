#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include <random>
#include <iomanip>

using vec = std::vector<int>;
using mat = std::vector<vec>;

void print_mat(const mat &m)
{
	for (int i = 0; i < m.size(); ++i)
	{
		bool first = true;
		for (int j = 0; j < m.size(); ++j)
		{
			std::cout << std::right << std::setw(4) << m[i][j];
			first = false;
		}
		std::cout << "\n\n";
	}
}
int main()
{
	srand(time(nullptr));
	int n = rand() % 6 + 5; 
	mat m;
	for (int i = 0; i < n; ++i)
	{
		vec v;
		for (int j = 0; j < n; ++j)
			v.push_back(rand() % 42 - 23);
		m.push_back(v);
	}
	int sum = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = n - 1; j >= n - i; --j)
			if (m[i][j] % 3 == 0)
				sum += m[i][j];
	}
	print_mat(m);
	std::cout << '\n';
	std::cout << "sum = " << sum;
}