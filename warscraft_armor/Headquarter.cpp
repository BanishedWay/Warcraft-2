#include "Headquarter.h"
#include<iostream>
#include<iomanip>

using namespace std;

Warrior::Warrior(Headquarter* p, int type, int id)
{
	pHeadquarter = p;
	this->type = type;
	this->id = id;
	this->morale = 0;
	this->loyalty = 0;
	if (warriortype[type] == "dragon") 
	{
		this->morale = (double)p->lifeValue / value[type];
		idx.push_back(id % 3);
	}
	if (warriortype[type] == "ninja")
	{
		idx.push_back(id % 3);
		idx.push_back((id + 1) % 3);
	}
	if (warriortype[type] == "iceman")
	{
		idx.push_back(id % 3);
	}
	if (warriortype[type] == "lion")
	{
		this->loyalty = p->lifeValue;
	}
}

void Warrior::Print(int Time)
{
	string color = pHeadquarter->getColor();
	cout << setw(3) << setfill('0') << Time << " " << color << " " << warriortype[type] << " " << Time + 1 << " born with strength " << value[type] << "," << pHeadquarter->warriornum[type] << " " << warriortype[type] << " in " << color << " headquarter\n\n";
	printProperty(warriortype[type]);
}

void Warrior::printProperty(std::string s)
{
	if (warriortype[type] == "dragon")
	{
		cout.setf(ios::fixed);
		cout << "It has a " << weapon[idx[0]] << ",and it’s morale is " << setprecision(3) << this->morale << endl << endl;
	}
	if (warriortype[type] == "ninja")
	{
		cout << "It has a " << weapon[idx[0]] << " and a " << weapon[idx[1]] << endl << endl;
	}
	if (warriortype[type] == "iceman")
	{
		cout << "It has a " << weapon[idx[0]] << endl << endl;
	}
	if (warriortype[type] == "lion")
	{
		cout << "It’s loyalty is " << this->loyalty << endl << endl;
	}
}

void Headquarter::InitHeadQuarter(int color, int m)
{
	this->color = color;
	lifeValue = m;
	warriorcount = 0;
	flag = 0;
	cur = 0;
	for (int i = 0; i < num; i++)
	{
		warriornum[i] = 0;
	}
}//创建司令部

int Headquarter::Birth(int Time)
{
	if (flag)
		return 0;
	int t = 0;//循环判断生命值是否已无法产出武士
	while (Warrior::value[seq[color][cur]] > lifeValue && t < num)
	{
		cur = (cur + 1) % num;
		t++;
	}
	int type = seq[color][cur];
	if (Warrior::value[type] > lifeValue)
	{
		flag = 1;
		string c = "blue";
		if (color)
			c = "red";
		cout << setw(3) << Time << " " << c << " headquarter stops making warriors\n\n";
		return 0;
	}

	lifeValue -= Warrior::value[type];
	cur = (cur + 1) % num;
	pWarrior[warriorcount] = new Warrior(this, type, warriorcount + 1);
	warriornum[type]++;
	pWarrior[warriorcount]->Print(Time);
	warriorcount++;
	return 1;
}//生产武士
string Headquarter::getColor()
{
	if (color)
		return "red";
	return "blue";
}

Headquarter::Headquarter()
{
}

Headquarter::~Headquarter()
{
}


