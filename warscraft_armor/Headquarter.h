#include<string>
#include<vector>

const int num = 5;//定义常量武士种类数目

class Headquarter;//司令部类
class Warrior//武士类
{
private:
	int id;
	Headquarter* pHeadquarter;
	int type;
	double morale;
	int loyalty;
	std::vector<int> idx;
public:
	static std::string weapon[3];
	static int value[num];
	static std::string warriortype[num];
	Warrior(Headquarter* p, int type, int id);
	void Print(int Time);
	void printProperty(std::string s);
};
class Headquarter
{
private:
	int lifeValue;
	int color;
	int warriorcount;//武士总数量
	int flag;
	int cur;
	Warrior* pWarrior[1000];
	int warriornum[num];//司令部内某一武士数量
	static int seq[2][num];
public:
	friend class Warrior;//定义友元类访问私有成员变量
	void InitHeadQuarter(int color, int m);
	int Birth(int Time);
	std::string getColor();
	Headquarter();
	~Headquarter();
};