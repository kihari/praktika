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

void FileRaed(Teachers* pst, int& n);//�������� �����
void PrintTabl(Teachers* pSt, int n);//������ �������� ������
void SortDisciplina(Teachers* pSt, ID* pts, int n);//���������� �� ����������
void SortWeek(Teachers* pSt, ID* pts, int n, double middlee);//���������� �� ��������� �������������
int praktika68();