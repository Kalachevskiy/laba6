#include <iostream>
#include <locale>
#include <fstream>
using namespace std;
//Дана матрица А(nxn), все элементы которой различны. Найти
//наибольший из элементов матрицы.Произвести циклический
//сдвиг сначала строки, а затем столбца, в которых он находится так,
//чтобы переместить элемент в центр матрицы.

//Входные значения - количество строк матрицы
//Выходные значения - указатель на двумерный динамический массив
//Назначение - создать динамический двумерный массив , предварительно выделив под него память
int** CreateSqMatrix(int size)
{
	int** matrix;
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	return matrix;
}


//входные данные - указатель на двумерный динамический массив, его размер
//назначение - запись в двумерный динамический массив через консоль
void iconsole(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "Введите " << i << " элемент " << j << " строки матрицы\n";
			cin >> matrix[i][j];
		}
	}
}


//входные данные - указатель на двумерный динамический массив, его размер
//назначение - выбор способа ввода через консоль
void ask(int** matrix, int size)
{
	int choice;
	cout << "Введите 1 для ввода через консоль.\n";
	cin >> choice;
	if (choice == 1)
		iconsole(matrix, size);
}

//Входные значения - указатель на двумерный динамический массив, размер одного измерения  переданного массива,
// индекс сдвигаемой строки, индекс строки до которой происходит сдвиг
//Выходные значения отсутствуют
//Назначение - циклический сдвиг строк
void MoveRows(int** matrix, int size, int startIndex, int endIndex)
{
	int currentIndex = startIndex;
	while (currentIndex != endIndex)
	{
		int* temp = new int[size];
		temp = matrix[size - 1];
		for (int i = size - 1; i > 0; i--)
		{
			matrix[i] = matrix[i - 1];
		}
		matrix[0] = temp;
		if (currentIndex != size - 1)
			currentIndex++;
		else
			currentIndex = 0;
	}
}

//Входные значения - указатель на массив, размер переданного массива,
//индекс сдвигаемого элемента, индекс столбца до которого происходит сдвиг
//Выходные значения отсутствуют
//Назначение - циклический сдвиг элементов массива
void MoveElements(int* matrix, int size, int startIndex, int endIndex)
{
	int temp;
	int currentIndex = startIndex;

	while (currentIndex != endIndex)
	{
		temp = matrix[size - 1];
		for (int i = size - 1; i > 0; i--)
		{
			matrix[i] = matrix[i - 1];
		}
		matrix[0] = temp;
		if (currentIndex != size - 1)
			currentIndex++;
		else
			currentIndex = 0;
	}
}

//Входные значения - указатель на двумерный динамический массив, размер одного измерения  переданного массива,
//	индекс сдвигаемого столбца, индекс столбца до которого происходит сдвиг
//Выходные значения отсутствуют
//Назначение - циклический сдвиг столбцов
void MoveCol(int** matrix, int size, int startIndex, int endIndex)
{
	for (int i = 0; i < size; i++)
		MoveElements(matrix[i], size, startIndex, endIndex);
}

//Входные данные - указатель на динамический двумерный массив, его размер
//Выходные данные отсутствуют
//Назначение - поместить максимальный элемент в центр матрицы с помощью циклических сдвигов по строкам, затем по столбцам
void ChangeMatrix(int** matrix, int size)
{
	int maxElementRow = 0;
	int maxElementColumn = 0;
	int maxElement = matrix[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] > maxElement)
			{
				maxElement = matrix[i][j];
				maxElementRow = i;
				maxElementColumn = j;
			}
		}
	}
	MoveRows(matrix, size, maxElementRow, size / 2);
	MoveCol(matrix, size, maxElementColumn, size / 2);
}


//Входные данные - указатель на двумерный динамический массив, его размер
//Назначение - вывод двумерного динамического массива
void Show(int** matrix, int size)
{
	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	cout << "Введите размер одного измерения квадратной матрицы: ";
	cin >> size;
	int** matrix = CreateSqMatrix(size);
	ask(matrix, size);
	Show(matrix, size);
	ChangeMatrix(matrix, size);
	Show(matrix, size);
	//освобождение памяти
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}