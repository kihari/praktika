#include "pratika_22.h"

int praktika22()
{
	setlocale(LC_ALL, "rus");

	double arrX[N];
	double arrY[N];
	double yn;//Текущий yn
	double approximation;//Приближение
	int n;//Количество итераций

	//Исходные данные:
	double x0;//Начальный x = 0
	double y0;//Начальный y = 1
	double xn;//Отрезок от 0 до 1; xn = 1
	double h;//Размер шага 0.025

	cout << "Введите начальный х: ";
	cin >> x0;
	cout << "\nВведите начальный y: ";
	cin >> y0;
	cout << "\nВведите конечный х: ";
	cin >> xn;
	cout << "\nВведите размер шага: ";
	cin >> h;

	n = (xn - x0) / h;
	cout << "Количество итераций: " << n << endl;
	cout << "\n\txn\t\tyn\n";
	cout << "-----------------------------------------------\n";


	//Метод Эйлера
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

	cout << "\nЗначение итогового y при x = " << xn << " равняется " << yn << endl;
	printgraphics(arrX,arrY);
	return 0;

}

void printgraphics(double Xarr[], double Yarr[])
{
	double x = 0;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 500, 500, NULL);//Выбираю расположение начальной точки оси Ох
	LineTo(hDC, 1200, 500);//Рисую ось Ох
	MoveToEx(hDC, 850, 150, NULL);//Выбираю расположение начальной точки оси Оy
	LineTo(hDC, 850, 850);//Рисую ось Оу
	for (int i = 0; i < N; i++) // O(850,500) - центр
	{
		MoveToEx(hDC, 100 * Xarr[i] + 850, -100 * Yarr[i] + 500, NULL);//100 - масштаб
		LineTo(hDC, 100 * Xarr[i] + 850, -100 * Yarr[i] + 500);
	}
	system("pause");
}
