//封装函数显示该界面 如 void showMenu()
//在main函数中调用封装好的函数

#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1：男 2：女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人的数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人的个数
	int m_Size;
};

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

// 1、添加联系人
void addPerson(struct Addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法继续添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别 1：男 2：女
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
			}
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录中的人数
		abs->m_Size++;

		cout << "添加成功！" << endl;

		system("pause"); // 按任意键继续

		system("cls"); // 清屏
	}
}

//2、显示所有联系人
void showPerson(struct Addressbooks* abs)
{
	//判断通讯录中人数是否为零
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t"; // 括号，提高三目运算符优先级
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); // 按任意键继续
	system("cls"); // 清屏
}

//3、检测联系人是否存在，若存在，返回联系人所在数组中的下标，若不存在，返回-1
int isExist(struct Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到了用户输入的姓名
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	//遍历结束都没找到用户输入的姓名
	return -1;
}

//3、删除指定联系人
void deletePerson(struct Addressbooks* abs)
{
	cout << "请输入你要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name); // 外层的的deletePerson中传入的abs已经是指针了，故此处的abs不需要取址！
	if (ret != -1)
	{
		//找到此人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++) // 从ret开始前移
		{
			//数据前移
			abs->personArray[i].m_Name = abs->personArray[i + 1].m_Name;
		}
		abs->m_Size--; // 更新通讯录中的人员数
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
}

//4、查找指定联系人信息
void findPerson(struct Addressbooks* abs)
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//找到了用户输入的姓名
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;

	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//5、修改指定联系人的信息
void modifyPerson(struct Addressbooks* abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//找到了指定的联系人

		//姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别 1：男 2：女
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
			}
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//6、清空所有联系人
void cleanPerson(struct Addressbooks* abs)
{
	abs->m_Size = 0; // 将当前记录的联系人数量置为0，做逻辑上的清空
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}



int main()
{
	//创建通讯录结构体变量
	struct Addressbooks abs;
	//初始化通讯录中当前的人员个数
	abs.m_Size = 0;

	int select = 0; // 创建用户选择输入的变量

	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: // 1、添加联系人
			addPerson(&abs); // 利用地址传递可以修改实参
			break;

		case 2: // 2、显示联系人
			showPerson(&abs);
			break;

		case 3: // 3、删除联系人
		{
			deletePerson(&abs);
			system("pause");
			system("cls");
		}
			break;

		case 4: // 4、查找联系人
			findPerson(&abs);
			break;

		case 5: // 5、修改联系人
			modifyPerson(&abs);
			break;

		case 6: // 6、清空联系人
			cleanPerson(&abs);
			break;

		case 0: // 0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause"); // 按任意键继续
			return 0;
			break;

		default:
			break;
		}
	}

	

	system("pause");
	return 0;
}