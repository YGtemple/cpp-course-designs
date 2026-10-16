#include<iostream>
using namespace std;
#define MAX 1000
#include"person.h";


//构建通讯录·和联系人结构体
struct person

{
	string m_name;

	int m_sex;  //1=男 2=女

	int m_age;

	string m_phone;

	string m_addr; //住址
};
struct Addressbook
{
	struct person personArray[MAX];

	int m_size; //记录数量 
};
    //1、添加联系人
void addperson(Addressbook * abs)
{
	if (abs->m_size == MAX)
	{
		cout << "联系人已满，无法添加。 " << endl;
		return;
	}
	else
	{
		//姓名

		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		//性别
		int sex;
		sex = 0;
		cout << "请输入性别（1代表男，2代表女）： " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入 " << endl;
		}
		//年龄
		int age;
		age = 0;
		cout << "请输入年龄： " << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		//号码
		string phone;
		cout << "请输入电话号码： " << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//住址
		string addr;
		cout << "请输入住址： " << endl;
		cin >> addr;
		abs->personArray[abs->m_size].m_addr = addr;

	
		cout << "恭喜添加成功！ " << endl;
		//更新
		abs->m_size++;
		system("pause");
		//清平
		system("cls");   
	}
}
    //2、显示联系人
void showmenu(Addressbook* abs)
{
	if (abs->m_size == 0)
	{
		cout << "联系人为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			//为方便显示，用列表符结尾
			cout << "姓名：" << abs->personArray[i].m_name << " " << "\t";

			//利用三目运算输出文字
			cout << "性别: " << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";

			cout << "年龄：" << abs->personArray[i].m_age << " " << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << " " << "\t";
			cout << "住址：" << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	//清平
	system("cls");
}
   //3、删除联系人
   
   //搜寻联系人是否存在
int isExist(Addressbook * abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}
		return -1;
	}
}
void deleteperson(Addressbook * abs)
{
	string name;
	cout << "请输入需要删除的联系人： " << endl;
	cin >> name;
	//定义接受整形
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			//数据迁移（删除）
			abs->personArray[i] = abs->personArray[i + 1];
			abs->m_size--;
		}
		cout << "删除成功！" << endl;
	}
	system("pause");
	//清平
	system("cls");
}
    //4、查找联系人
void findperson(Addressbook * abs)
{
	string name;
	cout << "请输入需要查询联系人姓名： " << endl;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//为方便显示，用列表符结尾
		cout << "姓名：" << abs->personArray[ret].m_name << " " << "\t";

		//利用三目运算输出文字
		cout << "性别: " << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";

		cout << "年龄：" << abs->personArray[ret].m_age << " " << "\t";
		cout << "电话：" << abs->personArray[ret].m_phone << " " << "\t";
		cout << "住址：" << abs->personArray[ret].m_addr << endl;
		
	}
	else
	{
		cout << "查无此人！" << endl;
	}




	//if (ret == -1)
	//{
	//    cout << "查无此人！" << endl;
	//}
	//else
	//{
	//	//为方便显示，用列表符结尾
	//	cout << "姓名：" << abs->personArray[ret].m_name << " " << "\t";

	//	//利用三目运算输出文字
	//	cout << "性别: " << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";

	//	cout << "年龄：" << abs->personArray[ret].m_age << " " << "\t";
	//	cout << "电话：" << abs->personArray[ret].m_phone << " " << "\t";
	//	cout << "住址：" << abs->personArray[ret].m_addr << endl;
	//}
	system("pause");
	//清平
	system("cls");
}
//arr[10]= { ""}
    //5、修改联系人
void modifyperson(Addressbook * abs)
{
	string name;
	cout << "请输入需要修改的联系人姓名：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	//!=不等于
	if (ret != -1)
	{
		//进行修改

		//姓名
		cout << "请输入修改后姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_name = name;

		//性别
		int sex;
		sex = 0;
		cout << "请输入修改后的性别（1代表男，2代表女）： " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入 " << endl;
		}
		//年龄
		int age;
		age = 0;
		cout << "请输入修改后的年龄： " << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;
		//号码
		string phone;
		cout << "请输入修改后的电话号码： " << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//住址
		string addr;
		cout << "请输入修改后的住址： " << endl;
		cin >> addr;
		abs->personArray[abs->m_size].m_addr = addr;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	//清平
	system("cls");
}
//清除联系人
void cleanperson(Addressbook* abs)
{
	string choose;
	cout << "请输入是或否" << endl;
	cout << "您确定要清空联系人吗？" << endl;
	cin >> choose;
	if (choose == "是")
	{
		abs->m_size = 0;
		cout << "已清空联系人！" << endl;
	}
	else
	{
		cout << "请输入正确指令！" << endl;
	}
	system("pause");
	//清平
	system("cls");
}

//菜单
void menu()
{
	cout << "*****   ***** ***** *****   ***** " << endl;
	cout << "*****     1、添加联系人     ***** " << endl;
	cout << "*****     2、显示联系人     ***** " << endl;
	cout << "*****     3、删除联系人     ***** " << endl;
	cout << "*****     4、查找联系人     ***** " << endl;
	cout << "*****     5、修改联系人     ***** " << endl;
	cout << "*****     6、清除联系人     ***** " << endl;
	cout << "*****     0、退出联系人     ***** " << endl;
	cout << "*****   ***** ***** *****   ***** " << endl;
}

//void menu()
//{
//	cout << "*****   ***** ***** *****   ***** " << endl;
//	cout << "*****     FILE  A  CASE     ***** " << endl;
//	cout << "*****1、  EMPTY  ARCHIVE    ***** " << endl;
//	cout << "*****2、 OVREWRITE ARCHIVE  ***** " << endl;
//	cout << "*****3、  FIND  ARCHIVE     ***** " << endl;
//	cout << "*****4、 MODIFY   ARCHIVE   ***** " << endl;
//	cout << "*****5、INITIALIZE ARCHIVE  ***** " << endl;
//	cout << "*****6、 EXIT THE SYSTEM    ***** " << endl;
//	cout << "*****   ***** ***** *****   ***** " << endl;
//}



int main()
{
	//printf("ergg");
	//创建结构体
	Addressbook abs;
	abs.m_size = 0;
	int select = 0;

	//调用菜单

	while (true)
	{
		menu();
		cin >> select;

		switch (select)
		{
		case 1:   //1、添加联系人
			addperson(&abs);
			break;
		case 2:   //2、显示联系人
			showmenu(&abs);
			break;
		case 3:  // 3、删除联系人
			//测试代码
		//{
		//	cout << "请输入删除联系人姓名：" << endl;
		//	string name;
		//	cin >> name;
		//	if (isExist(&abs, name) == -1)
		//	{
		//		cout << "查无此人" << endl;
		//	}
		//	else
		//	{
		//		cout << "查有此人" << endl;
		//	}
		//	system("pause");
		//	//清平
		//	system("cls");
		//}

			deleteperson(&abs);

			break;
		case 4:   //4、查找联系人
			findperson(&abs);
			break;
		case 5:   //5、修改联系人
			modifyperson(&abs);
			break;
		case 6:   //6、清除联系人 
			cleanperson(&abs);
			break;
		case 0:   //0、退出联系人
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请输入正确指令！" << endl;
			system("pause");
				//清平
			system("cls");
			break;
		}
	}
	cout << "make sytem" << endl;
	system("pause");
	return 0;
}
