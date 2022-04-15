//В матрицы A (m, n) каждый элемент aij заменить минимальным среди элементов подматрицы A (i, j), 
//которая расположена в верхнем левом углу матрицы A
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


class Matrix {
private:
	int min = 0;
public:
	void MatrixFilling(int** Mtx, int size1, int size2);
	void Print(int** Mtx, int size1, int size2);
	void Min(int** Mtx, int min, int size1, int size2, int size3, int size4);
};

void Matrix::MatrixFilling(int** Mtx, int size1, int size2)
{
	srand(time(0));
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			Mtx[i][j] = 1 + rand() % 9;
		}
	}
}
void Matrix::Print(int** Mtx, int size1, int size2)
{
	cout << endl;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			cout << Mtx[i][j] << " ";
		}
		cout << endl;
	}
}
void Matrix::Min(int** Mtx, int min, int size1, int size2, int size3, int size4) {
	min = Mtx[0][0];
	for (int i = 0; i < size3; i++) {
		for (int j = 0; j < size4; j++) {
			cout << Mtx[i][j] << " ";
			if (min > Mtx[i][j]) {
				min = Mtx[i][j];
			}
		}
	}
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			Mtx[i][j] = min;
		}
	}
}

int main() {

	setlocale(LC_ALL, "RUS");

	Matrix x;
	int size1, size2, size3, size4;
	int min = 0;

	cout << "Введите размеры прямоугольной матрицы через пробел: " << endl;
	cin >> size1 >> size2;

	int** Mtx = new int* [size1];
	for (int i = 0; i < size1; i++)
	{
		Mtx[i] = new int[size2];
	}
	x.MatrixFilling(Mtx, size1, size2);
	cout << "\nМатрица:\n";
	x.Print(Mtx, size1, size2);

	cout << "\nВведите размеры подматрицы через пробел: \n";
	cin >> size3 >> size4;

	cout << "\nПодматрица: \n";
	x.Min(Mtx, min, size1, size2, size3, size4);
	cout << "\nМатрица\n";
	x.Print(Mtx, size1, size2);
	return 0;
}