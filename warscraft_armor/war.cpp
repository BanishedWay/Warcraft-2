#include<iostream>
#include<iomanip>
#include"Headquarter.h"

using namespace std;

string Warrior::weapon[3]{ "sword","bomb","arrow" };
string Warrior::warriortype[num] = { "dragon","ninja","iceman","lion","wolf" };
int Headquarter::seq[2][num] = { {3,0,1,2,4},{ 2,3,4,1,0 } };
int Warrior::value[num];

int main()
{
	int count, m;
	cin >> count;
	int _case = 1;
	int n = 1;
	Headquarter RED, BLUE;
	while (n <= count)
	{
		cin >> m;
		for (int i = 0; i < num; i++)
		{
			cin >> Warrior::value[i];
		}
		cout << "case:" << n << endl << endl;
		n++;
		RED.InitHeadQuarter(1, m);
		BLUE.InitHeadQuarter(0, m);
		int Time = 0;
		while (1)
		{
			int t1 = RED.Birth(Time);
			int t2 = BLUE.Birth(Time);
			if (t1 == t2 && t1 == 0)
			{
				break;
			}
			Time++;
		}
	}
	return 0;
}


