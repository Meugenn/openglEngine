#define _USE_MATH_DEFINES
#include <vector>
#include "Drawing.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Matrix.h"
#include <cmath>
using std::vector;
using std::cos;
using std::sin;
int InitApp(std::vector<float>, std::vector<float>, std::vector<int>, std::vector<int>);
template <typename T>
void add_vector_data(std::vector<T>&, std::vector< std::vector<T>>);

int main() {
	vector<float> t_r = { 0.25f,  0.25f, 1 };
	vector<float> b_r = { 0.25f, -0.25f, 1 };
	vector<float> b_l = { -0.25f, -0.25f, 1 };
	vector<float> t_l = { -0.25f,  0.25f, 1 };
	vector<vector<float>> square = { t_r, b_r, b_l, t_l };
	vector<float> vertices;
	add_vector_data(vertices, square);
	vector<int> indices = {
	  0, 1, 3,
	  1, 2, 3
	};
	vector<int> texture_indicies = {
		0, 1, 
		0, 0, 
		1, 1, 
		1, 0
	};
	vector<float> colors{
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1
	};
	InitApp(vertices, colors, indices, texture_indicies);
	return 0;
}

template <typename T>
void add_vector_data(std::vector<T>& main_vect, std::vector<std::vector<T>> extend_vect) {
	for (vector<T> vect : extend_vect) {
		std::cout << vect.size() << '\n';
		for (T i : vect) {
			main_vect.push_back(i);
		}
	}
}