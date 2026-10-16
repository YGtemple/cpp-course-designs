#include"boss.h"

boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void boss::showInfo()
{
	cout << "员工编号：" << this->m_id << " 员工姓名：" << this->m_name << " 员工部门编号：" << this->m_deptid << " 岗位："
		<< getdeptid_name() << "  职责：" << "管理公司所有事务" << endl;
}

string boss::getdeptid_name()
{
	return "总裁";
}