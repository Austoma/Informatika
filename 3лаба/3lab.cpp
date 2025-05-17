#include<iostream>
using namespace std;

class money
{
private:
	double sum;
	long rub;
	int kop;
	void split(double sum)
	{
		rub = (int)sum;
		kop = abs(((sum - (int)sum) * 100));
	}

public:
	money()
	{
		cout << "Вызвался крнструктор без параметров " << this << endl;
		this->sum = 0.0;
		this->rub = 0;
		this->kop = 0;
	};
	money(double sum)
	{
		cout << "\nВызвался крнструктор c параметрами " << this << endl;
		this->sum = sum;
		split(sum);
	}

	friend ostream& operator<<(ostream& stream, const money& m);

	money operator-(const double& sub)
	{
		return (this->sum - sub);
	}

	bool operator==(const money& other)
	{
		if (this->sum == other.sum)
			return true;
		else
			return false;
	}

	bool operator!=(const money& other)
	{
		return !(this->sum == other.sum);
	}

	void print()
	{
		cout << "\nСумма: " << rub << "," << kop << endl;
	}

	~money()
	{
		cout << "\nВызвался деструктор " << this;
		cout << endl;
	}
};

ostream& operator<<(ostream& stream, const money& m)
{
	stream <<"\nРубли: " << m.rub << "\nКопейки: " << m.kop;
	return stream;
};

int main()
{
	system("chcp 1251 >> null");

	double sub,sum;
	money one;
	one.print();

	cout << "\n\nВведите сумму(double): ";
	cin >> sum;
	money two(sum);
	two.print();

	cout << "\nВведите дробное число, которое нужно вычесть из суммы: ";
	cin >> sub;

	money tre = sum - sub;
	tre.print();

	bool res = two == tre;
	cout << "\nРезультат сравнения сумм ==(1 - равны; 0 - неравны): " << res << endl;

	bool res2 = two != tre;
	cout << "\nРезультат сравнения сумм !=(0 - равны; 1 - неравны): " << res2 << endl;

	cout << two;

	return 0;
}
