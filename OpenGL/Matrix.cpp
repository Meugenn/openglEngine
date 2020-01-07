#include "Matrix.h"
#include <vector>
#include <iostream>
#include <cmath>
using std::cos;
using std::sin;

Matrix::Matrix(std::vector<std::vector<float>> M) {
	this->M = M;
}
Matrix::Matrix(int type, std::vector<float> params) {
	if (type == 1) {//rotate
		float rad = params[0];
		if (rad >= 0) {
			this->M = {
				{cos((float)rad), sin((float)rad), 0},
				{-sin((float)rad), cos((float)rad), 0},
				{0, 0, 1}
			};
		}
		else {
			this->M = {
				{cos((float)rad), -sin((float)rad), 0},
				{sin((float)rad), cos((float)rad), 0},
				{0, 0, 1}
			};
		}
	}
	if (type == 2) {//scale
		float scal_x = params[0], scal_y = 1, scal_z = 1;
		if (params.size() >= 2) scal_y = params[1];
		else scal_y = scal_x;
		if (params.size() >= 3) scal_z = params[2];
		this->M = {
			{scal_x, 0, 0},
			{0, scal_y, 0},
			{0, 0, scal_z}
		};
	}
	if (type == 3) {//translate
		float trans_x = params[0], trans_y = 1;
		if (params.size() >= 2) trans_y = params[1];
		else trans_y = trans_x;
		this->M = {
			{1, 0, trans_x},
			{0, 1, trans_y},
			{0, 0, 1}
		};
	}
}
Matrix Matrix::operator*(float k) {
	std::vector<std::vector<float>> M1 = this->M;
	for (int i = 0; i < this->M.size(); i++)for (int j = 0; j < this->M[0].size(); j++) {
		M1[i][j] *= k;
	}
	return Matrix(M1);
}
Matrix Matrix::operator+(float k) {
	return summ(this->M, k);
}
Matrix Matrix::operator-(float k) {
	return summ(this->M, -k);
}
std::vector<float> Matrix::operator*(std::vector<float> v)
{
	return prod(this->M, v);
}
std::vector<std::vector<float>> Matrix::operator*(std::vector<std::vector<float>> vect) {
	std::vector<std::vector<float>> new_vect(vect.size());
	for (int i = 0; i < vect.size(); i++) {
		new_vect[i] = prod(this->M, vect[i]);

	}
	return new_vect;
}
std::vector<float> Matrix::prod(std::vector<std::vector<float>> M, std::vector<float> v) {
	std::vector<float> v1(v.size());
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++) {
			v1[i] += v[j] * M[i][j];
		}
	}
	return v1;

}
Matrix Matrix::summ(std::vector<std::vector<float>> M, float k) {
	for (int i = 0; i < this->M.size(); i++)for (int j = 0; j < this->M[0].size(); j++) {
		M[i][j] += k;
	}
	return Matrix(M);
}