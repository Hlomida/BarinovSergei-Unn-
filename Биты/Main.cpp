#include "Set.h"
#include "BitField.h"
int main(int argc, char* argv)
{
	int n, m, k, count;
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки множества" << endl;
	cout << " Решето Эратосфена" << endl;
	cout << "Введите верхнюю границу целых значений - ";
	cin >> n;
	BitField s;
	// заполнение множества
	for (m = 2; m <= n; m++)
		s.getBit(m);
	// проверка до sqrt(n) и удаление кратных
	for (m = 2; m * m <= n; m++)
		// если м в s, удаление кратных
		if (s.checkBit(m))
			for (k = 2 * m; k <= n; k += m)
				if (s.checkBit(k))
					s.clrBit(k);
	// оставшиеся в s элементы - простые числа
	cout << endl << "Печать множества некратных чисел" << endl
		<< s << endl;
	cout << endl << "Печать простых чисел" << endl;
	count = 0;
	k = 1;
	for (m = 2; m <= n; m++)
		if (s.checkBit(m))
		{
			count++;
			cout << Set(3) << m << " ";
			if (k++ % 10 == 0)
				cout << endl;
		}
	cout << endl;
	cout << "В первых " << n << " числах " << count << " простых" << endl;
}
