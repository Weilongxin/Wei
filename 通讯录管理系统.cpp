#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

//������ϵ�˽ṹ��
struct Person {
	string m_name;//����
	int m_sex = 0;//�Ա�  1  ��  2  Ů
	int m_age = 0;//����
	string m_phone;//��ϵ�绰
	string m_address;//��ͥסַ
};

//����ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX];//ͨѶ¼�б������ϵ������
	int m_Size = 0;//ͨѶ¼�е�ǰ��¼����ϵ�˸���
};

//1�������ϵ��
void addPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�����Ƿ�����
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼���������޷����������ϵ��!" << endl;
	}
	else {
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "������������������!" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 0) {
				abs->personArray[abs->m_Size].m_age = age;
				break;
			}
			cout << "������������������!" << endl;
		}
		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_address = address;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ϲ����ӳɹ���" << endl;
		//����
		system("pause");
		system("cls");
	}
}

//2����ʾ��ϵ��
void showPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "��ϵ��" << i + 1 << "��" << "\t";
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_age << "\t";
			cout << "�绰��" << abs->personArray[i].m_phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_address << endl;
		}
	}
	//����
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڷ�����ϵ�����������еľ���λ�ã���֮����-1
int isExistPerson(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		//�Ѿ��ҵ��û���������
		if (abs->personArray[i].m_name == name) {
			return i;//�ҵ����������ϵ�����������е��±���
		}
		return -1;//δ�ҵ�����-1
	}
}

//3��ɾ����ϵ��
void deletePerson(Addressbooks* abs) {
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int locate = isExistPerson(abs, name);
	//�ж�
	if (locate != -1) {//�ҵ���ϵ��
		for (int i = locate; i < abs->m_Size; i++) {
			//����ǰ��ʵ��ɾ���ض���ϵ��
			abs->personArray[i] = abs->personArray[i+1];
		}
		abs->m_Size--;//����ͨѶ¼������ϵ��
		cout << "ɾ���ɹ�" << endl;
	}
	else {//δ�ҵ���ϵ��
		cout << "���޴���" << endl;
	}
	//����
	system("pause");
	system("cls");
}

//4��������ϵ��
void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int locate = isExistPerson(abs, name);
	//�ж�
	if (locate != -1) {//�ҵ���ϵ��
		cout << "��ϵ��" << locate + 1 << "��" << "\t";
		cout << "������" << abs->personArray[locate].m_name << "\t";
		cout << "�Ա�" << (abs->personArray[locate].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[locate].m_age << "\t";
		cout << "�绰��" << abs->personArray[locate].m_phone << "\t";
		cout << "סַ��" << abs->personArray[locate].m_address << endl;
	}
	else {//δ�ҵ���ϵ��
		cout << "���޴���" << endl;
	}
	//����
	system("pause");
	system("cls");
}

//5���޸���ϵ��
void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int locate = isExistPerson(abs, name);
	//�ж�,��ϵ����Ϣ���������൱���޸���ϵ����Ϣ
	if (locate != -1) {//�ҵ���ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[locate].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[locate].m_sex = sex;
				break;
			}
			cout << "������������������!" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 0) {
				abs->personArray[locate].m_age = age;
				break;
			}
			cout << "������������������!" << endl;
		}
		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[locate].m_phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[locate].m_address = address;
		//�޸ĳɹ�
		cout << "�޸ĳɹ�" << endl;
	}
	else {//δ�ҵ���ϵ��
		cout << "���޴���" << endl;
	}
	//����
	system("pause");
	system("cls");
}

//6�������ϵ��
void cleanPerson(Addressbooks* abs) {
	cout << "���Ƿ�ȷ�����ͨѶ¼��" << endl;
	cout << "�����գ���ѡ��1����֮����ѡ��2��" << endl;
	cout << "1 --- ���ͨѶ¼" << endl;
	cout << "2 --- �������˵�" << endl;
	int number;
	while (true) {
		cin >> number;
		if (number == 1) {
			abs->m_Size = 0;
			cout << "ͨѶ¼�����" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (number == 2) {
			system("pause");
			system("cls");
			break;
		}
		else {
			cout << "������������������!" << endl;
		}
	}
}

//�˵�����
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

//������
int main() {
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼���е�ǰ��Ա����
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1://�����ϵ��
			addPerson(&abs);//���õ�ַ���ݿ����޸��β�
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�����ϵ��
			cout << "*****  ��ӭ�´�ʹ��!  *****" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}