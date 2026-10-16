#pragma once
#include <iostream>
using namespace std;
#include"职工抽象类.h"
//#include<string>

class employee : public worker
{
public:
	employee(int id, string name, int did);

	void showInfo();

	string getdeptid_name();

};
