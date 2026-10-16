#include<iostream>
using namespace std;
#include "workManager.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include"职工抽象类.h"

int main()
{
	//测试多态
	/*worker* empl = NULL;

	empl = new employee(1, "张三", 1);
	empl->showInfo();
	delete empl;

	empl = new manager(2, "李四", 2);
	empl->showInfo();
	delete empl;

	empl = new boss(3, "王五", 3);
	empl->showInfo();
	delete empl;*/


	workManager wm;

	int choice = 0;

	while (true)
	{
		wm.Show_menu();

		cin >> choice;

		switch(choice)
		{
		case 0://退出管理系统
			wm.ExitSystem();
			break;
		case 1://增加职工信息
			wm.Add_emp();
			break;
		case 2://显示职工信息 
			wm.show_emp();
			break;
		case 3://删除离职职工
			wm.del_emp();
			break;
		case 4://修改职工信息
			wm.mod_emp();
			break;
		case 5://查找职工信息 
			wm.find_emp();
			break;
		case 6://清除所有文档 
			wm.clean_file();
			break;
		case 7://按照编号排序 
			wm.sort_emp();
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}