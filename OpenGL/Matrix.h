#pragma once
#include <vector>
class Matrix {
private:
	std::vector<std::vector<float>> M;
public:
	Matrix(std::vector<std::vector<float>>);
	Matrix(int, std::vector<float>);
	Matrix operator *(float);
	Matrix operator+(float);
	Matrix operator-(float);
	std::vector<float> operator*(std::vector<float>);
	std::vector<std::vector<float>> operator*(std::vector<std::vector<float>>);
	Matrix summ(std::vector<std::vector<float>>, float);
	std::vector<float> prod(std::vector<std::vector<float>>, std::vector<float>);
};


