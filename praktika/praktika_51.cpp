#include "praktika_51.h"

int praktika51()
{
	setlocale(LC_ALL, "rus");

	const int size = 9;//Размер матрицы
	int arr[size][size];//Матрица

	//srand(time(NULL));
	////Заполение матрицы случайными элементами
	//for (int i = 0; i < size; i++)
	//{
	//	for (int j = 0; j < size; j++)
	//	{
	//		arr[i][j] = rand() % 100;
	//	}
	//}
	ifstream f("rr.txt");
	if (!f.is_open())
	{
		cout << "Файл не открывается" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				f >> arr[i][j];
			}
		}
		f.close();
	}
	showArr(arr, size);//Печать массива
	minb(arr, size);//Вектор b
	diag(arr, size);//Сумма...
	chislo(arr, size);//Проверка числа 
	return 0;
}

//Печать массива 
void showArr(int arr[9][9], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(2) << arr[i][j] << "  ";
		}
		cout << endl;
	}
}

//Вектор b из минимальных элементов каждого столбца матрицы
void minb(int arr[9][9], int size)
{
	int b[9];
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		int min = arr[0][i];
		for (int j = 0; j < size; j++)
		{
			if (arr[j][i] < min)
			{
				min = arr[j][i];

			}
		}
		b[i] = min;
	}
	cout << "Вектор b:     ";
	for (int j = 0; j < size; j++)
	{
		cout << b[j] << "  ";
	}
	cout << endl;
}
//Сумма
void diag(int arr[9][9], int size)
{
	int summa = 0;
	int bigger = arr[1][0];//Наибольший элемент матрицы, находящийся ниже главной диагонали

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (bigger < arr[i][j]) bigger = arr[i][j];
		}
	}

	cout << "\n\nНаибольший элемент матрицы, находящийся ниже главной диагонали: " << bigger;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i <= j && bigger < arr[i][j]) summa += arr[i][j];
		}
	}
	if (summa != 0)  cout << "\n\nСумма: " << summa;
	else cout << "\n\nПодходящих по условию элементов нет" << endl;
}
void chislo(int arr[9][9], int size)
{
	int number;
	int flag = 0;
	cout << "\n\nВведите число, чтобы проверить, находится ли оно на главной диагонали: ";
	cin >> number;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j && number == arr[i][j]) flag++;
		}
	}
	if (flag != 0) cout << "\n\nЧисло находится на главной диагонали" << endl;
	else cout << "\n\nЧисло НЕ находится на главной диагонали" << endl;
}