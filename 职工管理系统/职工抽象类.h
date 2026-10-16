#pragma once
#include <iostream>
using namespace std;
#include <string>
//职工抽象类、工人、经理类继承职工抽象类
class worker
{
public:
	//虚析构

	//纯虚函数，用于定义接口

	//显示个人信息的
	virtual void showInfo() = 0;
	//获取部门id对应职位名称的函数
	virtual string getdeptid_name() = 0;

	//员工的id，姓名，部门id
		int m_id;
	string m_name;
	int m_deptid;
	

};
