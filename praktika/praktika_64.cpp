#include "praktika_64.h"

int praktika64()
{

	setlocale(LC_ALL, "Russian");

	int a;
	cout << "¬ведите число: ";
	cin >> a;
	cout << "¬аше число: " << " ";

	if (a < 0) cout << "ћинусовое число";


	switch (a / 1000000)
	{
	case 1: cout << "один миллион "; break;
	case 2: cout << "два миллиона "; break;
	case 3: cout << "три миллиона "; break;
	case 4: cout << "четыре миллиона "; break;
	case 5: cout << "п€ть миллионов "; break;
	case 6: cout << "шесть миллионов "; break;
	case 7: cout << "семь миллионов "; break;
	case 8: cout << "восемь миллионов "; break;
	case 9: cout << "дев€ть миллионов "; break;
	}

	switch ((a % 1000000) / 100000)
	{
	case 1: cout << "сто "; break;
	case 2: cout << "двести "; break;
	case 3: cout << "триста "; break;
	case 4: cout << "четыреста "; break;
	case 5: cout << "п€тьсот "; break;
	case 6: cout << "шестьсот "; break;
	case 7: cout << "семьсот "; break;
	case 8: cout << "восемьсот "; break;
	case 9: cout << "дев€тьсот "; break;
	}
	switch ((a % 100000) / 10000)
	{
	case 2: cout << "двадцать "; break;
	case 3: cout << "тридцать "; break;
	case 4: cout << "сорок "; break;
	case 5: cout << "п€тдес€т "; break;
	case 6: cout << "шестьдес€т "; break;
	case 7: cout << "семьдес€т "; break;
	case 8: cout << "восемьдес€т "; break;
	case 9: cout << "дев€носто "; break;
	}
	if (((a % 100000) / 1000) >= 10 & ((a % 100000) / 1000) < 20) {
		switch ((a % 100000) / 1000) {
		case 10: cout << "дес€ть тыс€ч "; break;
		case 11: cout << "одинадцать тыс€ч "; break;
		case 12: cout << "двенадцать тыс€ч "; break;
		case 13: cout << "тринадцать тыс€ч "; break;
		case 14: cout << "четырнадцать тыс€ч "; break;
		case 15: cout << "п€тнадцать тыс€ч "; break;
		case 16: cout << "шестнадцать тыс€ч "; break;
		case 17: cout << "семнадцать тыс€ч "; break;
		case 18: cout << "восемнадцать тыс€ч "; break;
		case 19: cout << "дев€тнадцать тыс€ч "; break;
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
			else cout << "тыс€ч "; break;
		case 1: cout << "одна тыс€ча "; break;
		case 2: cout << "две тыс€чи "; break;
		case 3: cout << "три тыс€чи "; break;
		case 4: cout << "четыре тыс€чи "; break;
		case 5: cout << "п€ть тыс€ч "; break;
		case 6: cout << "шесть тыс€ч "; break;
		case 7: cout << "семь тыс€ч "; break;
		case 8: cout << "восемь тыс€ч "; break;
		case 9: cout << "дев€ть тыс€ч "; break;
		}
	}

link:

	switch ((a % 1000) / 100)
	{
	case 1: cout << "сто "; break;
	case 2: cout << "двести "; break;
	case 3: cout << "триста "; break;
	case 4: cout << "четыреста "; break;
	case 5: cout << "п€тьсот "; break;
	case 6: cout << "шестьсот "; break;
	case 7: cout << "семьсот "; break;
	case 8: cout << "восемьсот "; break;
	case 9: cout << "дев€тьсот "; break;
	}
	switch ((a % 100) / 10)
	{
	case 2: cout << "двадцать "; break;
	case 3: cout << "тридцать "; break;
	case 4: cout << "сорок "; break;
	case 5: cout << "п€тдес€т "; break;
	case 6: cout << "шестьдес€т "; break;
	case 7: cout << "семьдес€т "; break;
	case 8: cout << "восемьдес€т "; break;
	case 9: cout << "дев€носто "; break;
	}
	if (a % 100 >= 10 & a % 100 < 20) {
		switch (a % 100) {
		case 10: cout << "дес€ть"; break;
		case 11: cout << "одинадцать"; break;
		case 12: cout << "двенадцать"; break;
		case 13: cout << "тринадцать"; break;
		case 14: cout << "четырнадцать"; break;
		case 15: cout << "п€тнадцать"; break;
		case 16: cout << "шестнадцать"; break;
		case 17: cout << "семнадцать"; break;
		case 18: cout << "восемнадцать"; break;
		case 19: cout << "дев€тнадцать"; break;
		}
	}
	else {
		switch (a % 10)
		{
		case 1: cout << "один\n"; break;
		case 2: cout << "два\n"; break;
		case 3: cout << "три\n"; break;
		case 4: cout << "четыре"; break;
		case 5: cout << "п€ть"; break;
		case 6: cout << "шесть"; break;
		case 7: cout << "семь"; break;
		case 8: cout << "восемь"; break;
		case 9: cout << "дев€ть"; break;
		}
	}

	return 0;
}