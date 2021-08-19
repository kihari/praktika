#include "praktika_51.h"

int praktika51()
{
	setlocale(LC_ALL, "rus");

	const int size = 9;//������ �������
	int arr[size][size];//�������

	//srand(time(NULL));
	////��������� ������� ���������� ����������
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
		cout << "���� �� �����������" << endl;
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
	showArr(arr, size);//������ �������
	minb(arr, size);//������ b
	diag(arr, size);//�����...
	chislo(arr, size);//�������� ����� 
	return 0;
}

//������ ������� 
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

//������ b �� ����������� ��������� ������� ������� �������
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
	cout << "������ b:     ";
	for (int j = 0; j < size; j++)
	{
		cout << b[j] << "  ";
	}
	cout << endl;
}
//�����
void diag(int arr[9][9], int size)
{
	int summa = 0;
	int bigger = arr[1][0];//���������� ������� �������, ����������� ���� ������� ���������

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (bigger < arr[i][j]) bigger = arr[i][j];
		}
	}

	cout << "\n\n���������� ������� �������, ����������� ���� ������� ���������: " << bigger;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i <= j && bigger < arr[i][j]) summa += arr[i][j];
		}
	}
	if (summa != 0)  cout << "\n\n�����: " << summa;
	else cout << "\n\n���������� �� ������� ��������� ���" << endl;
}
void chislo(int arr[9][9], int size)
{
	int number;
	int flag = 0;
	cout << "\n\n������� �����, ����� ���������, ��������� �� ��� �� ������� ���������: ";
	cin >> number;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j && number == arr[i][j]) flag++;
		}
	}
	if (flag != 0) cout << "\n\n����� ��������� �� ������� ���������" << endl;
	else cout << "\n\n����� �� ��������� �� ������� ���������" << endl;
}