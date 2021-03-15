#include "Set.h"
#include "BitField.h"
int main(int argc, char* argv)
{
	int n, m, k, count;
	setlocale(LC_ALL, "Russian");
	cout << "������������ �������� ��������� ���������" << endl;
	cout << " ������ ����������" << endl;
	cout << "������� ������� ������� ����� �������� - ";
	cin >> n;
	BitField s;
	// ���������� ���������
	for (m = 2; m <= n; m++)
		s.getBit(m);
	// �������� �� sqrt(n) � �������� �������
	for (m = 2; m * m <= n; m++)
		// ���� � � s, �������� �������
		if (s.checkBit(m))
			for (k = 2 * m; k <= n; k += m)
				if (s.checkBit(k))
					s.clrBit(k);
	// ���������� � s �������� - ������� �����
	cout << endl << "������ ��������� ��������� �����" << endl
		<< s << endl;
	cout << endl << "������ ������� �����" << endl;
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
	cout << "� ������ " << n << " ������ " << count << " �������" << endl;
}
