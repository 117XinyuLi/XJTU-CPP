#include<iostream>

using namespace std;

void matrix_transpose(int** matrix)
{
	int temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

}

int main()
{
	int** matrix = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		matrix[i] = new int[3];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> matrix[i][j];
		}
	}

	matrix_transpose(matrix);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete[] matrix[i];
		matrix[i] = NULL;
	}
	delete[] matrix;
	matrix = NULL;
	
	return 0;
}