#include "praktika_64.h"

int praktika64()
{

	setlocale(LC_ALL, "Russian");

	int a;
	cout << "������� �����: ";
	cin >> a;
	cout << "���� �����: " << " ";

	if (a < 0) cout << "��������� �����";


	switch (a / 1000000)
	{
	case 1: cout << "���� ������� "; break;
	case 2: cout << "��� �������� "; break;
	case 3: cout << "��� �������� "; break;
	case 4: cout << "������ �������� "; break;
	case 5: cout << "���� ��������� "; break;
	case 6: cout << "����� ��������� "; break;
	case 7: cout << "���� ��������� "; break;
	case 8: cout << "������ ��������� "; break;
	case 9: cout << "������ ��������� "; break;
	}

	switch ((a % 1000000) / 100000)
	{
	case 1: cout << "��� "; break;
	case 2: cout << "������ "; break;
	case 3: cout << "������ "; break;
	case 4: cout << "��������� "; break;
	case 5: cout << "������� "; break;
	case 6: cout << "�������� "; break;
	case 7: cout << "������� "; break;
	case 8: cout << "��������� "; break;
	case 9: cout << "��������� "; break;
	}
	switch ((a % 100000) / 10000)
	{
	case 2: cout << "�������� "; break;
	case 3: cout << "�������� "; break;
	case 4: cout << "����� "; break;
	case 5: cout << "�������� "; break;
	case 6: cout << "���������� "; break;
	case 7: cout << "��������� "; break;
	case 8: cout << "����������� "; break;
	case 9: cout << "��������� "; break;
	}
	if (((a % 100000) / 1000) >= 10 & ((a % 100000) / 1000) < 20) {
		switch ((a % 100000) / 1000) {
		case 10: cout << "������ ����� "; break;
		case 11: cout << "���������� ����� "; break;
		case 12: cout << "���������� ����� "; break;
		case 13: cout << "���������� ����� "; break;
		case 14: cout << "������������ ����� "; break;
		case 15: cout << "���������� ����� "; break;
		case 16: cout << "����������� ����� "; break;
		case 17: cout << "���������� ����� "; break;
		case 18: cout << "������������ ����� "; break;
		case 19: cout << "������������ ����� "; break;
		}
	}
	else {
		switch ((a % 10000) / 1000)
		{

		case 0:
			if ((a / 1000000) == 0 && ((a % 1000000) / 100000) == 0 &&
				((a % 100000) / 10000) == 0 && ((a % 10000) / 1000) == 0)
			{
				goto link;
			}
			else if (((a % 1000000) / 100000) == 0 &&
				((a % 100000) / 10000) == 0 && ((a % 10000) / 1000) == 0) goto link;
			else cout << "����� "; break;
		case 1: cout << "���� ������ "; break;
		case 2: cout << "��� ������ "; break;
		case 3: cout << "��� ������ "; break;
		case 4: cout << "������ ������ "; break;
		case 5: cout << "���� ����� "; break;
		case 6: cout << "����� ����� "; break;
		case 7: cout << "���� ����� "; break;
		case 8: cout << "������ ����� "; break;
		case 9: cout << "������ ����� "; break;
		}
	}

link:

	switch ((a % 1000) / 100)
	{
	case 1: cout << "��� "; break;
	case 2: cout << "������ "; break;
	case 3: cout << "������ "; break;
	case 4: cout << "��������� "; break;
	case 5: cout << "������� "; break;
	case 6: cout << "�������� "; break;
	case 7: cout << "������� "; break;
	case 8: cout << "��������� "; break;
	case 9: cout << "��������� "; break;
	}
	switch ((a % 100) / 10)
	{
	case 2: cout << "�������� "; break;
	case 3: cout << "�������� "; break;
	case 4: cout << "����� "; break;
	case 5: cout << "�������� "; break;
	case 6: cout << "���������� "; break;
	case 7: cout << "��������� "; break;
	case 8: cout << "����������� "; break;
	case 9: cout << "��������� "; break;
	}
	if (a % 100 >= 10 & a % 100 < 20) {
		switch (a % 100) {
		case 10: cout << "������"; break;
		case 11: cout << "����������"; break;
		case 12: cout << "����������"; break;
		case 13: cout << "����������"; break;
		case 14: cout << "������������"; break;
		case 15: cout << "����������"; break;
		case 16: cout << "�����������"; break;
		case 17: cout << "����������"; break;
		case 18: cout << "������������"; break;
		case 19: cout << "������������"; break;
		}
	}
	else {
		switch (a % 10)
		{
		case 1: cout << "����\n"; break;
		case 2: cout << "���\n"; break;
		case 3: cout << "���\n"; break;
		case 4: cout << "������"; break;
		case 5: cout << "����"; break;
		case 6: cout << "�����"; break;
		case 7: cout << "����"; break;
		case 8: cout << "������"; break;
		case 9: cout << "������"; break;
		}
	}

	return 0;
}