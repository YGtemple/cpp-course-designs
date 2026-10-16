#pragma once
using namespace std;
#include <iostream>
#include"职工抽象类.h"

class manager : public worker
{
public:
	manager(int id, string name, int did);

	void showInfo();

	string getdeptid_name();

};
