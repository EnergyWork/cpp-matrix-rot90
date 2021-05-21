#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef vector<vector<uint32_t>> Matrix;

void print_matrix(Matrix matrix)
{
	cout << setw(4);
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix.size(); j++)
		{
			cout << matrix[i][j] << setw(4);
		}
		cout << endl;
	}
	cout << endl;
}
Matrix create_maxtrix(int N)
{
	Matrix matrix;
	vector<uint32_t> row;
	for (uint32_t i = 0; i < N; i++)
	{
		for (uint32_t j = 0; j < N; j++)
		{
			row.emplace_back(i+1);
		}
		matrix.emplace_back(row);
		row.clear();
	}
	return matrix;
}
void create_and_rotate90(int N)
{
	Matrix matrix = create_maxtrix(N);
	print_matrix(matrix);
	Matrix rotated_matrix;
	for (uint32_t i = 0; i < N; i++)
		rotated_matrix.emplace_back(vector<uint32_t>(N));
	
	for (uint32_t i = 0; i < N; i++)
	{
		for (uint32_t j = 0; j < N; j++)
		{
			rotated_matrix[N - j - 1][i] = matrix[i][j]; // turn 90 left
			//rotated_matrix[i][j] = matrix[N - j - 1][i]; // turn 90 right
		}
	}
	print_matrix(rotated_matrix);
}
int main()
{
	uint32_t N = 10;
	create_and_rotate90(N);
}