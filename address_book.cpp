//封装函数显示主界面，
//在main函数中调用

#include<iostream>
#include <string>
#define MAX 1000
using namespace std;

struct person
{
	string m_name;
	int m_sex;/*通过数字来说明性别*/
	int m_age;
	string m_phone;
	string m_addr;

};
struct Addressbooks
{
	//通讯录能容纳的人员个数,素组的类型是struct类型
	struct person personArray[MAX];
	//已经有的人员数目
	int m_size;

};


void showMenu() {
	cout << "*********************************************" << endl;
	cout << "*****		1、添加联系人		*****" << endl;
	cout << "*****		2、显示联系人		*****" << endl;
	cout << "*****		3、删除联系人		*****" << endl;
	cout << "*****		4、查找联系人		*****" << endl;
	cout << "*****		5、修改联系人		*****" << endl;
	cout << "*****		6、清空联系人		*****" << endl;
	cout << "*****		0、退出通讯录		*****" << endl;
	cout << "*********************************************" << endl;
}

void addPerson(Addressbooks *abs) {
	//判断通讯录是否已经满了
	if (abs->m_size == MAX)
	{
		cout << "通讯录的已满，无法添加" << endl;
		return ;
	}
	else
	{
		//添加具体的联系人
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		//输入的性别

		cout << "请输入性别：其中1代表男性，2代表女性" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;//退出循环
			}
			else
			{
				cout << "输入的性别有误，请重新输入" << endl;
			}

		}
		//输入年龄
		cout << "请输入年龄" << endl;
		int  age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		//联系电话
		cout << "请输入电话\n";
		string phone_number;
		cin >> phone_number;
		abs->personArray[abs->m_size].m_phone = phone_number;


		//输入家庭住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;
		abs->m_size++;
		cout << "信息添加成功" << endl;
		system("pause");
		system("cls");
	}


}

  
void showPeson(Addressbooks *abs) {
	if (abs->m_size == 0)
	{
		cout << "通讯录的内容为空，请添加联系人后输出\n";

	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名:" << abs->personArray[i].m_name << "\t";
			cout <<"性别:" << (abs->personArray[i].m_sex ==1 ?"男":"女" )<< "\t";
			cout <<"年龄：" << abs->personArray[i].m_age << "\t";
			cout <<"联系方式：" << abs->personArray[i].m_phone << "\t";
			cout <<"家庭住址：" << abs->personArray[i].m_addr << "\n";
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks *abs,string name) {
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}

	}
	return -1;

}

void delete_name(Addressbooks* abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	
	int res = isExist(abs, name);
	if (res != -1) {
		//查到此人，进行删除操作
		for (int  i = res; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "联系人删除成功" << endl;
	}
	else {
		cout << "查无此人，无法进行删除操作" << endl;
	}
	system("pause");
	system("cls");
	
}

void findPerson(Addressbooks *abs) {
	cout << "请输入你要查找的联系人：" << endl;
	while (true)
	{
		string name;
		cin >> name;
		int res = isExist(abs, name);
		if (res != -1)
		{
			//查找联系人成功，输出此人的信息
			cout << "姓名:" << abs->personArray[res].m_name << "\t";
			cout << "性别:" << (abs->personArray[res].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[res].m_age << "\t";
			cout << "联系方式：" << abs->personArray[res].m_phone << "\t";
			cout << "家庭住址：" << abs->personArray[res].m_addr << "\n";
			break;
		}
		else
		{
			cout << "查无此人，请再次输入姓名进行查找\n";
		}
	}

	system("pause");
	system("cls");



}

void chagePerson(Addressbooks *abs) {
	cout << "请输入你要修改的联系人的姓名：\n";
	while (true)
	{
		string name;
		cin >> name;
		int res = isExist(abs, name);
		if (res != -1)
		{
			//查找联系人成功，
			//修改姓名
			cout << "修改后的名字为：" << endl;
			string name1;
			cin >> name1;
			abs->personArray[res].m_name = name1;



			//修改年龄
			cout << "修改后年龄为：" << endl;
			int age;
			cin >> age;
			abs->personArray[res].m_age = age;
			



			
			//修改性别
			cout << "修改后的性别为：" << endl;
			int sex;
			cin >> sex;
			abs->personArray[res].m_sex = sex;
		
			//修改电话
			cout << "修改后的电话为：" << endl;
			string phone;
			cin >> phone;
			abs->personArray[res].m_phone = phone;
			

			//修改地址
			cout << "修改后的地址为：" << endl;
			string address;
			cin >> address;
			abs->personArray[res].m_addr = address;
			

			//打印输出，修改后的信息
			cout << "姓名:" << abs->personArray[res].m_name << "\t";
			cout << "性别:" << (abs->personArray[res].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[res].m_age << "\t";
			cout << "联系方式：" << abs->personArray[res].m_phone << "\t";
			cout << "家庭住址：" << abs->personArray[res].m_addr << "\n";
			break;
		}
		else
		{
			cout << "查无此人，请再次输入姓名进行修改\n";
		}
	}

	system("pause");
	system("cls");
}

void allOut(Addressbooks *abs) {
	cout << "清空无法恢复，是否清空通讯录？\n ";
	cout << "确认清空请输入Y，\n";
	string info;
	cin >> info;
	if (info == "Y")
	{
		abs->m_size = 0;
		cout << "通讯录清空成功" << endl;
	}
	else 
	{
		cout << "通讯录未删除" << endl;
	}

	system("pause");
	system("cls");
	
}
int main() {

	//创建结构体的变量
	Addressbooks abs;
	abs.m_size = 0;





	while (true) {
		showMenu();
		int select = 0;
		cout << "请输入对0应的功能前面的数字即可实现相应的功能" << endl;
		cin >> select;
		switch (select) {
		case 1://1、添加联系人
			addPerson(&abs);
			break;
		case 2:
			showPeson(&abs);
			break;
		case 3:
			/*
			{cout << "请输入联系人的姓名：" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1) {
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
			}
			}*/
			delete_name(&abs);

			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			chagePerson(&abs);
			break;
		case 6:
			allOut(&abs);
			break;
		case 0://0、退出通讯录
			cout << "系统已经退出，欢迎下次使用" << endl;
			return 0;
			break;
		}

	}
	
	
	return 0;
}
