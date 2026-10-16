#include"employee.h"

employee::employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did ;
}

void employee::showInfo()
{
	cout << "员工编号：" << this->m_id << "  员工姓名：" << this->m_name << "  员工部门编号：" << this->m_deptid << " 岗位："
		<< getdeptid_name() << "  职责：" << "完成经理下发任务" << endl;
}

string employee:: getdeptid_name()
{
	//return "员工";
	return string("员工");
}