#include"workManager.h"


//声明一个全局的workManager对象

//类外声明

workManager::workManager()
{
	//判断文件是否存在
	ifstream ifs;
	//读文件
	ifs.open(FILENAME, ios::in);


	//1、如果文件不存在情况
	if (!ifs.is_open())
	{
		//初始化
		cout << "文件不存在！" << endl;
		//员工初始化
		this->m_EmpNum = 0;
		//数组初始化
		this->m_emplyArry = NULL;
		//初始化文件是否为空
		this->file_emp = true;
		ifs.close();
		return;
	}

	//2、如果文件存在，但没有储存数据
	char ch;
	ch = NULL;
	ifs >> ch;
	//eof为文件尾部
	if (ifs.eof())
	{
		//cout << "文件存在，但为储存任何数据！" << endl;
		cout << "文件为空！" << endl;
		//员工初始化
		this->m_EmpNum = 0;
		//数组初始化
		this->m_emplyArry = NULL;
		//初始化文件是否为空
		this->file_emp = true;
		ifs.close();
		return;
	}

	//3、文件存在且保存职工数据
	int num = this->get_empnum();
	cout << "职工人数为：" << num << endl;
	//更新·m_EmpNum
	this->m_EmpNum = num;

	//分配内存
	this->m_emplyArry = new worker * [get_empnum()];
	//初始化职工
	this->init_emp();



	/*int m_EmpNum = 0;
	worker** m_emplyArry = NULL;*/
}

	
//菜单
void workManager::Show_menu()
{
		cout << "*****   *****  *****  *****   ***** " << endl;
		cout << "*****  欢迎使用职工管理系统！ ***** " << endl;
		cout << "*****     0、退出管理系统     ***** " << endl;
		cout << "*****     1、增加职工信息     ***** " << endl;
		cout << "*****     2、显示职工信息     ***** " << endl;
		cout << "*****     3、删除离职职工     ***** " << endl;
		cout << "*****     4、修改职工信息     ***** " << endl;
		cout << "*****     5、查找职工信息     ***** " << endl;
		cout << "*****     6、清除所有文档     ***** " << endl;
		cout << "*****     7、按照编号排序     ***** " << endl;
		cout << "*****   ***** ***** *****     ***** " << endl;
		cout << endl;
	
}
//退出系统函数
void workManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

////记录员工人数
//int m_EmpNum;
//
////员工数组
//worker** m_emplyArry;

//增加员工
void workManager:: Add_emp()
{
	

	cout << "请输入增加员工数量：" << endl;
	
	//记录增加员工数量
	int addnum;

	cin >> addnum;

	if (addnum > 0)
	{
		//添加
		//重新分配内存
		//计算新内存大小
		int newsize = this->m_EmpNum + addnum; //原来的员工数量+增加的数量

		//开辟新空间大小
		worker** newspace = new worker * [newsize];

		//拷贝原来的数据
		if (this->m_emplyArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_emplyArry[i];
			}	
		}
		//开始批量添加新员工
		for (int i = 0; i < addnum; i++)
		{
			int id; //编号
			string name; //姓名
			int dselect; //部门编号
			cout << "请输入第  " << i+1 << "  个新员工编号：" << endl;
			cin >> id;

			//判断是否重复
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				while (this->m_emplyArry[i]->m_id == id)
				{
					id = 0;
					cout << "员工id重复，请重新输入！" << endl;
					cin >> id;
				}
				
			}
			

			//判断是否重复
			/*for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_emplyArry[i]->m_id == id)
				{
					cout << "该编号已存在！" << endl;
				}
				else
				{
					break;
				}
			}
			*/



			cout << "请输入第  " << i + 1 << "  个新员工姓名：" << endl;
			cin >> name;

			cout << "请输新员工所属部门序号  "<< endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dselect;

			worker* worker = NULL;
			while (dselect < 1 || dselect >3)
			{
				
				cout << "输入有误，请重新输入！" << endl;
				cin >> dselect;
			}
			
				switch (dselect)
				{
				case 1:
					worker = new employee(id, name, 1);
					break;
				case 2:
					worker = new manager(id, name, 2);
					break;
				case 3:
					worker = new boss(id, name, 3);
					break;
				default:
					cout << "输入有误，请重新输入！" << endl;
					cin >> dselect;
				}
			
			//将新员工加入到数组中
			newspace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[]this->m_emplyArry;

		//更新员工数组指针
		this->m_emplyArry = newspace;

		//更新员工数量
		this->m_EmpNum = newsize;

		//更新职工不为空标志
		this->file_emp = false;

		//提示
		cout << "成功添加" << addnum << "名新员工！" << endl;
		
		//保存文件
		this-> save();
	}
	else
	{
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}

//保存文件
void workManager::save()
{
	ofstream ofs;
	//打开文件
	ofs.open(FILENAME, ios::out);

	//写文件
	//将每个文件写入
	
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (m_emplyArry[i] != NULL)
		{
			ofs << this->m_emplyArry[i]->m_id << " " << this->m_emplyArry[i]->m_name
				<< " " << this->m_emplyArry[i]->m_deptid << endl;
		}
    
	}
	//关闭文件
	ofs.close();
}

//获取人数
int workManager::get_empnum()
{
	ifstream ifs;

	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	//统计人数
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
} 

//初始化职工
void workManager::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int index = 0;
	//获取员工数量
	/*int num = this->get_empnum();
	this->m_EmpNum = num;*/
	
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* worker = NULL;

		if (did == 1)//普通职工
		{
			worker = new employee(id, name, 1);
		}
		else if (did == 2)
		{
			worker = new manager(id, name, 2);
		}
		else
		{
			worker = new boss(id, name, 3);
		}
		this->m_emplyArry[index] = worker;
		index++;
	}
	ifs.close();
}

//显示职工
void workManager :: show_emp()
{
	//检查文件是否为空
	if (this->file_emp)
	{
		cout << "文件为空！" << endl;
	}
	else
	{
    //遍历
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_emplyArry[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//删除职工
void workManager::del_emp()
{
	//判断文件是否存在
	if (this->file_emp)
	{
		cout << "文件为空或文件不存在！" << endl;
	} 
	else
	{
		//按照职工编号前移

		cout << "请输入需要删除的职工编号：" << endl;
		int id = 0;
		
		cin >> id;

		int index = this->Isexist(id);

		//if (id == this->Isexist(id)) 不正确，isexist返回为数组序列，id为输入职工序列
		//==优先级大于！
		//if（!index ==-1)   int index = this->Isexist(id); 
			if (!(this->Isexist(id) == -1))
		{
			//进行数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_emplyArry[i] = this->m_emplyArry[i + 1];
			}
			this->m_EmpNum--;

			//保存文件
			this->save();
		}
		else//if(!this->Isexist == -1)
		{
			cout << "编号不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}


//修改职工信息
void  workManager:: mod_emp()
{
	//判断文件是否存在
	if (this->file_emp)
	{
		cout << "文件为空或文件不存在！" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工的编号：" << endl;
		int id = 0;
		cin >> id;
		//判断id是否存在
		if (this->Isexist(id) == -1)
		{
			cout << "此员工id不存在！" << endl;
		}
		else
		{
			delete this->m_emplyArry[this->Isexist(id)];
			int new_id = 0;
			string new_name = "";
			int new_did = 0;
			cout << "查到职工编号：" << id << "请输入新的职工编号：" << endl;
			cin >> new_id;
			cout << "请输入新的姓名：" << endl;
			cin >> new_name;
			cout << "请输入新的部门编号：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> new_did;
			worker* worker = NULL;
			switch (new_did)
			{
			case 1:
				worker = new employee(new_id, new_name, 1);
				break;
			case 2:
				worker = new manager(new_id, new_name, 2);
				break;
			case 3:
				worker = new boss(new_id, new_name, 3);
				break;
			default:
				break;
				//cout << "输入有误，请重新输入！" << endl;
			}
			//将数据储存到数组中
			this->m_emplyArry[this->Isexist(id)] = worker;

			cout << "修改成功！" << this->m_emplyArry[this->Isexist(id)]->m_deptid << endl;

			this->save();
		}
	}
	system("pause");
	system("cls");
}

//查找员工
void workManager::find_emp()
{
	//判断文件是否存在
	if (this->file_emp)
	{
		cout << "文件为空或文件不存在！" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1、按照员工id查找。" << endl;
		cout << "2、按照姓名查找。 " << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id = 0;
			cout << "请输入需要查找的员工id：" << endl;
			cin >> id;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_emplyArry[i]->m_id == id)
				{
					this->m_emplyArry[i]->showInfo();
				}
				else
				{
					cout << "没有与此id对应的职工！" << endl;
					break;
				}
			}
		}
		else if (select == 2)
		{
			string name = "";
			cout << "请输入需要查找的员工姓名：" << endl;
			cin >> name;
			//标志是否查到
			bool flat = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_emplyArry[i]->m_name == name)
				{
					cout << "查询到员工id: " << this->m_emplyArry[i]->m_id << endl;
					flat = true;
					cout << "此员工信息如下：" << endl;
					this->m_emplyArry[i]->showInfo();
				}
				
			}
			if (flat == false)
			{
				cout << "没有与之相符的姓名！" << endl;
			}
			
		}
		else
		{
			cout <<"没有与之匹配的操作，请输入1或2！" << endl;
		}
			
	}
	system("pause");
	system("cls");
}


//按照编号排序
void workManager::sort_emp()
{
	//判断文件是否存在
	if (this->file_emp)
	{
		cout << "文件为空或文件不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << " 1、升序" << endl;
		cout << " 2、降序" << endl;

		int choice = 0;
		cin >> choice;

		if (choice != 1 || choice != 2)
		{
			cout << "输入错误！" << endl;
			system("pause");
			system("cls");
			return;
		}
		int minORmax;
       /* while(choice != 1 && choice != 2)
		{
			cout << "输入错误！" << endl;
			system("pause");
			system("cls");
		}*/
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			minORmax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{


				if (choice == 1)
				{
					if (this->m_emplyArry[j]->m_id < this->m_emplyArry[minORmax]->m_id)
					{
						minORmax = j;
					}
				}
				if (choice == 2)
				{
					if (this->m_emplyArry[j]->m_id > this->m_emplyArry[minORmax]->m_id)
					{
						minORmax = j;
					}
				}
			}

			if (i != minORmax)
			{
				worker* temp = this->m_emplyArry[i];
				this->m_emplyArry[i] = this->m_emplyArry[minORmax];
				this->m_emplyArry[minORmax] = temp;
			}
			
		}
		this->save();
		this->show_emp();
		cout << "排序完成！" << endl;
	}
			/*if (choice == 1)
			{
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (this->m_emplyArry[j]->m_id < this->m_emplyArry[minORmax]->m_id)
					{
						minORmax = j;
					}
				}
			}
			if (choice == 2)
			{
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (this->m_emplyArry[j]->m_id > this->m_emplyArry[minORmax]->m_id)
					{
						minORmax = j;
					}
				}
			}*/
		
	system("pause");
	system("cls");
}

//清空文件
void  workManager:: clean_file()
{
	cout << "你确定要删除吗？" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//文件置空
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		//数组中元素置空
		if (this->m_emplyArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_emplyArry[i];

			}
		}
		//总数置空
		this->m_EmpNum = NULL;
		//删除数组
		delete[] this->m_emplyArry;
		cout << "所有职工信息已清空！" << endl;
	}
	 if(select != 1)
	{
		 system("pause");
		 system("cls");
		return;
	}
	 system("pause");
	 system("cls");
}

//判断职工是否存在，如果存在，返回位置
int workManager::Isexist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_emplyArry[i]->m_id == id)
		{
			index = i;
			//i为索引，不是职工编号
			break;
		}
	}
	//返回为数组中序号
	return index;
}

workManager::~workManager()
{
	if (this->m_emplyArry != NULL)
	{
		delete[]this->m_emplyArry;
		this->m_emplyArry = NULL;
	}
}
