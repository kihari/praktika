#include <iostream>
#include "pratika_22.h"
#include "praktika_51.h"
#include "praktika_64.h"
#include "praktika_68.h"

int main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	int choice;
	bool flag = true;
	while (flag == true)
	{
		cout << "\n\n�������� �������: ";
		cout << "\n22. ����� ������";
		cout << "\n51. �������";
		cout << "\n64. ����� ��������";
		cout << "\n68. ���� ������";
		cout << "\n0. �����\n\n";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 22: praktika22();
			break;
		case 51:praktika51();
			break;
		case 64:praktika64();
			break;
		case 68:praktika68();
			break;
		case 0: flag = false;
			break;
		}
	}
	
	cout << endl;
	
	return 0;
}