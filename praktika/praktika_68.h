#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<regex>
#include<fstream>
#include<Windows.h>

using namespace std;



const int MAX = 15;



struct Teachers
{
	string surname;
	string age;//int
	string academic;
	string subject;
	string week;//int
};

struct ID
{
	int index;
	string key;
};

void FileRaed(Teachers* pst, int& n);//Проверка файла
void PrintTabl(Teachers* pSt, int n);//Печать исходных данных
void SortDisciplina(Teachers* pSt, ID* pts, int n);//Сортировки по дисциплине
void SortWeek(Teachers* pSt, ID* pts, int n, double middlee);//Сортировка по недельной загруженности
int praktika68();