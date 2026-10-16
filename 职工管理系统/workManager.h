#pragma once //防止头文件重复包含
using namespace std;
//.h文件声明类不做实现,.cpp文件实现类
#include<iostream>
#include"职工抽象类.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
//包含文件头文件
#include <fstream>
#define FILENAME "empfile.txt"

class workManager
{
public:
	//构造函数
	workManager();

	//菜单
	void Show_menu();

	//退出系统
	void ExitSystem();

	//记录员工人数
	int m_EmpNum;

	//员工数组
	worker**m_emplyArry;

	//增加员工
	void Add_emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool file_emp;

	//统计人数
	int get_empnum();

	//初始化职工
	void init_emp();

	//显示职工
	void show_emp();

	//删除职工
	void del_emp();

	//修改职工信息
	void mod_emp();

	//查找员工
	void find_emp();

	//按照编号排序
	void sort_emp();

	//清空文件
	void clean_file();

	//判断职工是否存在，如果存在，返回位置
	int Isexist(int id);


	//析构函数
	~workManager();
}; 
