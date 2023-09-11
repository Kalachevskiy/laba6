#include <iostream>
#include <locale>
#include <fstream>
using namespace std;
//���� ������� �(nxn), ��� �������� ������� ��������. �����
//���������� �� ��������� �������.���������� �����������
//����� ������� ������, � ����� �������, � ������� �� ��������� ���,
//����� ����������� ������� � ����� �������.

//������� �������� - ���������� ����� �������
//�������� �������� - ��������� �� ��������� ������������ ������
//���������� - ������� ������������ ��������� ������ , �������������� ������� ��� ���� ������
int** CreateSqMatrix(int size)
{
	int** matrix;
	matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	return matrix;
}


//������� ������ - ��������� �� ��������� ������������ ������, ��� ������
//���������� - ������ � ��������� ������������ ������ ����� �������
void iconsole(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "������� " << i << " ������� " << j << " ������ �������\n";
			cin >> matrix[i][j];
		}
	}
}


//������� ������ - ��������� �� ��������� ������������ ������, ��� ������
//���������� - ����� ������� ����� ����� �������
void ask(int** matrix, int size)
{
	int choice;
	cout << "������� 1 ��� ����� ����� �������.\n";
	cin >> choice;
	if (choice == 1)
		iconsole(matrix, size);
}

//������� �������� - ��������� �� ��������� ������������ ������, ������ ������ ���������  ����������� �������,
// ������ ���������� ������, ������ ������ �� ������� ���������� �����
//�������� �������� �����������
//���������� - ����������� ����� �����
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

//������� �������� - ��������� �� ������, ������ ����������� �������,
//������ ����������� ��������, ������ ������� �� �������� ���������� �����
//�������� �������� �����������
//���������� - ����������� ����� ��������� �������
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

//������� �������� - ��������� �� ��������� ������������ ������, ������ ������ ���������  ����������� �������,
//	������ ����������� �������, ������ ������� �� �������� ���������� �����
//�������� �������� �����������
//���������� - ����������� ����� ��������
void MoveCol(int** matrix, int size, int startIndex, int endIndex)
{
	for (int i = 0; i < size; i++)
		MoveElements(matrix[i], size, startIndex, endIndex);
}

//������� ������ - ��������� �� ������������ ��������� ������, ��� ������
//�������� ������ �����������
//���������� - ��������� ������������ ������� � ����� ������� � ������� ����������� ������� �� �������, ����� �� ��������
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


//������� ������ - ��������� �� ��������� ������������ ������, ��� ������
//���������� - ����� ���������� ������������� �������
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
	cout << "������� ������ ������ ��������� ���������� �������: ";
	cin >> size;
	int** matrix = CreateSqMatrix(size);
	ask(matrix, size);
	Show(matrix, size);
	ChangeMatrix(matrix, size);
	Show(matrix, size);
	//������������ ������
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}