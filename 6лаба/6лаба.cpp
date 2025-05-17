#include<stdio.h>
#include<ctype.h>
#include<iostream>
#include<clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
	char string[255];
	char vowel[14] = "aeiouyAEIOUY";
	short int flag = 0;
	int scount = 0;
	char* ps = string;
	cout<<"начальная строка:"<<endl;
	fgets(string, 255, stdin);
	cout << endl;
	while (*ps)
	{
		if (*ps != '.')
		{
			if (isspace(*ps) && (*ps) || (*ps == ',') || (*ps == ';') || (*ps == ':'))
			{
				while (isspace(*ps) && (*ps) || (*ps == ',') || (*ps == ';') || (*ps == ':'))
					ps++;
			}
			if (!isspace(*ps) && (*ps) && (*ps != ',') && (*ps != ';') && (*ps != ':'))
			{
				scount = 0; flag = 0;
				while (!isspace(*ps) && (*ps) && (*ps != ',') && (*ps != ';') && (*ps != ':'))
				{
				    for (int i = 0; i < 14; i++)
						if (vowel[i] == *ps) flag = 1;
					ps++;
					scount++;
				}
				if (flag == 0)
				{
					ps -= scount;
					for (int i = 0; i < scount; i++)
						cout << *ps++;
					cout << " ";
				}
			}
		}
	}
	return 0;
}

