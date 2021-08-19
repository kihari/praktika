#include "praktika_68.h"

regex regular_surname("([А-Яа-я]+)");//Фамилия 
regex regular_age("(\\d\\d)");//Возраст
regex regular_academic("([А-Яа-я]+)");//Степень
regex regular_subject("([А-Яа-я]+)");//Предмет
regex regular_week("(\\d){1,2}");//Количество часов в неделю

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
		cout << "Файл не открыт" << endl;
		exit(1);
	}
	int i = 0;
	int k = 0;
	while (!fin.eof())
	{
		fin >> pst[i].surname >> pst[i].age >> pst[i].academic >> pst[i].subject >> pst[i].week;
		if (!regex_match(pst[i].surname, regular_surname))
		{
			cout << "В строке " << k + 1 << " неправильная фамилия, она будет пропущена\n";
			i--;
			N--;
		}
		else if (!regex_match(pst[i].age, regular_age))
		{
			cout << "В строке " << k + 1 << " неправильный возраст, она будет пропущена\n";
			i--;
			N--;
		}
		else if (!regex_match(pst[i].academic, regular_academic))
		{
			cout << "В строке " << k + 1 << " неправильная академическая степень, она будет пропущена\n";
			i--;
			N--;
		}
		else if (!regex_match(pst[i].subject, regular_subject))
		{
			cout << "В строке " << k + 1 << " неправильный предмет, она будет пропущена\n";
			i--;
			N--;
		}
		else if (!regex_match(pst[i].week, regular_week))
		{
			cout << "В строке " << k + 1 << " неправильная недельная нагрузка, она будет пропущена\n";
			i--;
			N--;
		}
		i++;
		N++;
		k++;
	}
	if (N == 0)
	{
		cout << "Отсутствуют верные записи, программа прекращается\n";
		exit(2);
	}
	else cout << "Количество правильных записей:" << N << endl;
	fin.close();
}

void PrintTabl(Teachers* pSt, int N)
{
	cout << "\tИсходные данные:\n";
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
	cout << "Введите дисциплину: ";
	cin >> disciplina;
	if (N != 0)
	{
		int schet = 0;
		cout << "\nСортировка по выбранной дисциплине:\n";
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
			cout << "Преподавателей с выбранной дисциплиной не найдено" << endl;
		}
	}
}

void SortWeek(Teachers* pSt, ID* pts, int N, double middlee)
{
	if (N != 0)
	{
		cout << "\nСортировка по нагрузке выше " << middlee << ":\n";
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