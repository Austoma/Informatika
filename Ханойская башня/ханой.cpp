#include <iostream>
using namespace std;
void h(int q, int f, int t, int b)
//q-число колец, f-начальное положение колец(1-3),t-конечное положение колец(1-3),b - промежуточный колышек(1-3)
{
	if (q != 0)
	{
		h(q - 1, f, b, t);

		cout << f << " -> " << t << endl;

		h(q - 1, b, t, f);
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int s=1, d=3, b=2, p;
	cout << "Количество дисков:" << endl;
	cin >> p;
	h(p, s, d, b);
	return 0;
}
