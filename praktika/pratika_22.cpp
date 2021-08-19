#include "pratika_22.h"

int praktika22()
{
	setlocale(LC_ALL, "rus");

	double arrX[N];
	double arrY[N];
	double yn;//������� yn
	double approximation;//�����������
	int n;//���������� ��������

	//�������� ������:
	double x0;//��������� x = 0
	double y0;//��������� y = 1
	double xn;//������� �� 0 �� 1; xn = 1
	double h;//������ ���� 0.025

	cout << "������� ��������� �: ";
	cin >> x0;
	cout << "\n������� ��������� y: ";
	cin >> y0;
	cout << "\n������� �������� �: ";
	cin >> xn;
	cout << "\n������� ������ ����: ";
	cin >> h;

	n = (xn - x0) / h;
	cout << "���������� ��������: " << n << endl;
	cout << "\n\txn\t\tyn\n";
	cout << "-----------------------------------------------\n";


	//����� ������
	for (int i = 0; i < n; i++)
	{
		approximation = f(x0, y0);
		yn = y0 + h * approximation;
		cout << i << ".\t" << x0 << "\t\t" << yn << endl;
		arrX[i] = x0;
		arrY[i] = yn;
		y0 = yn;
		x0 = x0 + h;
	}

	cout << "\n�������� ��������� y ��� x = " << xn << " ��������� " << yn << endl;
	printgraphics(arrX,arrY);
	return 0;

}

void printgraphics(double Xarr[], double Yarr[])
{
	double x = 0;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 500, 500, NULL);//������� ������������ ��������� ����� ��� ��
	LineTo(hDC, 1200, 500);//����� ��� ��
	MoveToEx(hDC, 850, 150, NULL);//������� ������������ ��������� ����� ��� �y
	LineTo(hDC, 850, 850);//����� ��� ��
	for (int i = 0; i < N; i++) // O(850,500) - �����
	{
		MoveToEx(hDC, 100 * Xarr[i] + 850, -100 * Yarr[i] + 500, NULL);//100 - �������
		LineTo(hDC, 100 * Xarr[i] + 850, -100 * Yarr[i] + 500);
	}
	system("pause");
}
