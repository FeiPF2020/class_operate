//��װ������ʾ�����棬
//��main�����е���

#include<iostream>
#include <string>
#define MAX 1000
using namespace std;

struct person
{
	string m_name;
	int m_sex;/*ͨ��������˵���Ա�*/
	int m_age;
	string m_phone;
	string m_addr;

};
struct Addressbooks
{
	//ͨѶ¼�����ɵ���Ա����,�����������struct����
	struct person personArray[MAX];
	//�Ѿ��е���Ա��Ŀ
	int m_size;

};


void showMenu() {
	cout << "*********************************************" << endl;
	cout << "*****		1�������ϵ��		*****" << endl;
	cout << "*****		2����ʾ��ϵ��		*****" << endl;
	cout << "*****		3��ɾ����ϵ��		*****" << endl;
	cout << "*****		4��������ϵ��		*****" << endl;
	cout << "*****		5���޸���ϵ��		*****" << endl;
	cout << "*****		6�������ϵ��		*****" << endl;
	cout << "*****		0���˳�ͨѶ¼		*****" << endl;
	cout << "*********************************************" << endl;
}

void addPerson(Addressbooks *abs) {
	//�ж�ͨѶ¼�Ƿ��Ѿ�����
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼���������޷����" << endl;
		return ;
	}
	else
	{
		//��Ӿ������ϵ��
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		//������Ա�

		cout << "�������Ա�����1�������ԣ�2����Ů��" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;//�˳�ѭ��
			}
			else
			{
				cout << "������Ա���������������" << endl;
			}

		}
		//��������
		cout << "����������" << endl;
		int  age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		//��ϵ�绰
		cout << "������绰\n";
		string phone_number;
		cin >> phone_number;
		abs->personArray[abs->m_size].m_phone = phone_number;


		//�����ͥסַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;
		abs->m_size++;
		cout << "��Ϣ��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}


}

  
void showPeson(Addressbooks *abs) {
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼������Ϊ�գ��������ϵ�˺����\n";

	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "����:" << abs->personArray[i].m_name << "\t";
			cout <<"�Ա�:" << (abs->personArray[i].m_sex ==1 ?"��":"Ů" )<< "\t";
			cout <<"���䣺" << abs->personArray[i].m_age << "\t";
			cout <<"��ϵ��ʽ��" << abs->personArray[i].m_phone << "\t";
			cout <<"��ͥסַ��" << abs->personArray[i].m_addr << "\n";
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
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	
	int res = isExist(abs, name);
	if (res != -1) {
		//�鵽���ˣ�����ɾ������
		for (int  i = res; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "��ϵ��ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴��ˣ��޷�����ɾ������" << endl;
	}
	system("pause");
	system("cls");
	
}

void findPerson(Addressbooks *abs) {
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	while (true)
	{
		string name;
		cin >> name;
		int res = isExist(abs, name);
		if (res != -1)
		{
			//������ϵ�˳ɹ���������˵���Ϣ
			cout << "����:" << abs->personArray[res].m_name << "\t";
			cout << "�Ա�:" << (abs->personArray[res].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[res].m_age << "\t";
			cout << "��ϵ��ʽ��" << abs->personArray[res].m_phone << "\t";
			cout << "��ͥסַ��" << abs->personArray[res].m_addr << "\n";
			break;
		}
		else
		{
			cout << "���޴��ˣ����ٴ������������в���\n";
		}
	}

	system("pause");
	system("cls");



}

void chagePerson(Addressbooks *abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�˵�������\n";
	while (true)
	{
		string name;
		cin >> name;
		int res = isExist(abs, name);
		if (res != -1)
		{
			//������ϵ�˳ɹ���
			//�޸�����
			cout << "�޸ĺ������Ϊ��" << endl;
			string name1;
			cin >> name1;
			abs->personArray[res].m_name = name1;



			//�޸�����
			cout << "�޸ĺ�����Ϊ��" << endl;
			int age;
			cin >> age;
			abs->personArray[res].m_age = age;
			



			
			//�޸��Ա�
			cout << "�޸ĺ���Ա�Ϊ��" << endl;
			int sex;
			cin >> sex;
			abs->personArray[res].m_sex = sex;
		
			//�޸ĵ绰
			cout << "�޸ĺ�ĵ绰Ϊ��" << endl;
			string phone;
			cin >> phone;
			abs->personArray[res].m_phone = phone;
			

			//�޸ĵ�ַ
			cout << "�޸ĺ�ĵ�ַΪ��" << endl;
			string address;
			cin >> address;
			abs->personArray[res].m_addr = address;
			

			//��ӡ������޸ĺ����Ϣ
			cout << "����:" << abs->personArray[res].m_name << "\t";
			cout << "�Ա�:" << (abs->personArray[res].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[res].m_age << "\t";
			cout << "��ϵ��ʽ��" << abs->personArray[res].m_phone << "\t";
			cout << "��ͥסַ��" << abs->personArray[res].m_addr << "\n";
			break;
		}
		else
		{
			cout << "���޴��ˣ����ٴ��������������޸�\n";
		}
	}

	system("pause");
	system("cls");
}

void allOut(Addressbooks *abs) {
	cout << "����޷��ָ����Ƿ����ͨѶ¼��\n ";
	cout << "ȷ�����������Y��\n";
	string info;
	cin >> info;
	if (info == "Y")
	{
		abs->m_size = 0;
		cout << "ͨѶ¼��ճɹ�" << endl;
	}
	else 
	{
		cout << "ͨѶ¼δɾ��" << endl;
	}

	system("pause");
	system("cls");
	
}
int main() {

	//�����ṹ��ı���
	Addressbooks abs;
	abs.m_size = 0;





	while (true) {
		showMenu();
		int select = 0;
		cout << "�������0Ӧ�Ĺ���ǰ������ּ���ʵ����Ӧ�Ĺ���" << endl;
		cin >> select;
		switch (select) {
		case 1://1�������ϵ��
			addPerson(&abs);
			break;
		case 2:
			showPeson(&abs);
			break;
		case 3:
			/*
			{cout << "��������ϵ�˵�������" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1) {
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
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
		case 0://0���˳�ͨѶ¼
			cout << "ϵͳ�Ѿ��˳�����ӭ�´�ʹ��" << endl;
			return 0;
			break;
		}

	}
	
	
	return 0;
}
