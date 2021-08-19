#include "praktika_68.h"

regex regular_surname("([�-��-�]+)");//������� 
regex regular_age("(\\d\\d)");//�������
regex regular_academic("([�-��-�]+)");//�������
regex regular_subject("([�-��-�]+)");//�������
regex regular_week("(\\d){1,2}");//���������� ����� � ������

int praktika68()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Teachers Table[MAX];
	ID IndexArr[MAX];

	int N = 0;
	FileRaed(Table, N);
	PrintTabl(Table, N);

	int k = 0;
	for (int i = 0; i < N; i++)
	{
		IndexArr[k].index = i;
		IndexArr[k].key = Table[i].subject;
		k++;
	}
	SortDisciplina(Table, IndexArr, k);

	double middle = 0;
	k = 0;
	for (int i = 0; i < N; i++)
	{
		IndexArr[k].index = i;
		IndexArr[k].key = Table[i].week;
		k++;
		middle += stod(Table[i].week);
	}
	middle = middle / N;
	SortWeek(Table, IndexArr, k, middle);

	return 0;
}


void FileRaed(Teachers* pst, int& N)
{
	ifstream fin("bza.txt");
	if (!fin)
	{
		cout << "���� �� ������" << endl;
		exit(1);
	}
	int i = 0;
	int k = 0;
	while (!fin.eof())
	{
		fin >> pst[i].surname >> pst[i].age >> pst[i].academic >> pst[i].subject >> pst[i].week;
		if (!regex_match(pst[i].surname, regular_surname))
		{
			cout << "� ������ " << k + 1 << " ������������ �������, ��� ����� ���������\n";
			i--;
			N--;
		}
		else if (!regex_match(pst[i].age, regular_age))
		{
			cout << "� ������ " << k + 1 << " ������������ �������, ��� ����� ���������\n";
			i--;
			N--;
		}
		else if (!regex_match(pst[i].academic, regular_academic))
		{
			cout << "� ������ " << k + 1 << " ������������ ������������� �������, ��� ����� ���������\n";
			i--;
			N--;
		}
		else if (!regex_match(pst[i].subject, regular_subject))
		{
			cout << "� ������ " << k + 1 << " ������������ �������, ��� ����� ���������\n";
			i--;
			N--;
		}
		else if (!regex_match(pst[i].week, regular_week))
		{
			cout << "� ������ " << k + 1 << " ������������ ��������� ��������, ��� ����� ���������\n";
			i--;
			N--;
		}
		i++;
		N++;
		k++;
	}
	if (N == 0)
	{
		cout << "����������� ������ ������, ��������� ������������\n";
		exit(2);
	}
	else cout << "���������� ���������� �������:" << N << endl;
	fin.close();
}

void PrintTabl(Teachers* pSt, int N)
{
	cout << "\t�������� ������:\n";
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << " | " << pSt->surname << setw(15 - pSt->surname.size()) << " | "
			<< pSt->age << setw(6 - pSt->age.size()) << " | "
			<< pSt->academic << setw(20 - pSt->academic.size()) << " | "
			<< pSt->subject << setw(30 - pSt->subject.size()) << " | "
			<< pSt->week << setw(6 - pSt->week.size()) << " | " << endl;
		pSt++;
		cout << "--------------------------------------------------------------------------------" << endl;
	}
}

void SortDisciplina(Teachers* pSt, ID* pts, int N)
{
	string disciplina = "";
	cout << "������� ����������: ";
	cin >> disciplina;
	if (N != 0)
	{
		int schet = 0;
		cout << "\n���������� �� ��������� ����������:\n";
		cout << "--------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < N; i++)
		{
			if (pts[i].key == disciplina)
			{
				schet++;
				cout << "| " << pSt->surname << setw(15 - pSt->surname.size()) << " | "
					<< pSt->age << setw(6 - pSt->age.size()) << " | "
					<< pSt->academic << setw(20 - pSt->academic.size()) << " | "
					<< pSt->subject << setw(30 - pSt->subject.size()) << " | "
					<< pSt->week << setw(6 - pSt->week.size()) << " | " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
			}
			pSt++;
		}
		if (schet == 0)
		{
			cout << "�������������� � ��������� ����������� �� �������" << endl;
		}
	}
}

void SortWeek(Teachers* pSt, ID* pts, int N, double middlee)
{
	if (N != 0)
	{
		cout << "\n���������� �� �������� ���� " << middlee << ":\n";
		cout << "--------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < N; i++)
		{
			if (stod(pts[i].key) > middlee)
			{
				cout << "| " << pSt->surname << setw(15 - pSt->surname.size()) << " | "
					<< pSt->age << setw(6 - pSt->age.size()) << " | "
					<< pSt->academic << setw(20 - pSt->academic.size()) << " | "
					<< pSt->subject << setw(30 - pSt->subject.size()) << " | "
					<< pSt->week << setw(6 - pSt->week.size()) << " | " << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
			}
			pSt++;
		}
	}
}