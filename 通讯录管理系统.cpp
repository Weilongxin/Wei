#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

//定义联系人结构体
struct Person {
	string m_name;//姓名
	int m_sex = 0;//性别  1  男  2  女
	int m_age = 0;//年龄
	string m_phone;//联系电话
	string m_address;//家庭住址
};

//定义通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];//通讯录中保存的联系人数组
	int m_Size = 0;//通讯录中当前记录的联系人个数
};

//1、添加联系人
void addPerson(Addressbooks* abs) {
	//判断通讯录容量是否已满
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，已无法继续添加联系人!" << endl;
	}
	else {
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入!" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 0) {
				abs->personArray[abs->m_Size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入!" << endl;
		}
		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_address = address;
		//更新通讯录人数
		abs->m_Size++;
		cout << "恭喜您添加成功！" << endl;
		//清屏
		system("pause");
		system("cls");
	}
}

//2、显示联系人
void showPerson(Addressbooks* abs) {
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "联系人" << i + 1 << "：" << "\t";
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t";
			cout << "住址：" << abs->personArray[i].m_address << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在返回联系人所在数组中的具体位置，反之返回-1
int isExistPerson(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		//已经找到用户输入姓名
		if (abs->personArray[i].m_name == name) {
			return i;//找到返回这个联系人所在数组中的下标编号
		}
		return -1;//未找到返回-1
	}
}

//3、删除联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;
	int locate = isExistPerson(abs, name);
	//判断
	if (locate != -1) {//找到联系人
		for (int i = locate; i < abs->m_Size; i++) {
			//数据前移实现删除特定联系人
			abs->personArray[i] = abs->personArray[i+1];
		}
		abs->m_Size--;//更新通讯录里面联系人
		cout << "删除成功" << endl;
	}
	else {//未找到联系人
		cout << "查无此人" << endl;
	}
	//清屏
	system("pause");
	system("cls");
}

//4、查找联系人
void findPerson(Addressbooks* abs) {
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int locate = isExistPerson(abs, name);
	//判断
	if (locate != -1) {//找到联系人
		cout << "联系人" << locate + 1 << "：" << "\t";
		cout << "姓名：" << abs->personArray[locate].m_name << "\t";
		cout << "性别：" << (abs->personArray[locate].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[locate].m_age << "\t";
		cout << "电话：" << abs->personArray[locate].m_phone << "\t";
		cout << "住址：" << abs->personArray[locate].m_address << endl;
	}
	else {//未找到联系人
		cout << "查无此人" << endl;
	}
	//清屏
	system("pause");
	system("cls");
}

//5、修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int locate = isExistPerson(abs, name);
	//判断,联系人信息重新输入相当于修改联系人信息
	if (locate != -1) {//找到联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[locate].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[locate].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入!" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 0) {
				abs->personArray[locate].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入!" << endl;
		}
		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[locate].m_phone = phone;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[locate].m_address = address;
		//修改成功
		cout << "修改成功" << endl;
	}
	else {//未找到联系人
		cout << "查无此人" << endl;
	}
	//清屏
	system("pause");
	system("cls");
}

//6、清空联系人
void cleanPerson(Addressbooks* abs) {
	cout << "您是否确定清空通讯录？" << endl;
	cout << "如果清空，请选择1；反之，请选择2。" << endl;
	cout << "1 --- 清空通讯录" << endl;
	cout << "2 --- 返回主菜单" << endl;
	int number;
	while (true) {
		cin >> number;
		if (number == 1) {
			abs->m_Size = 0;
			cout << "通讯录已清空" << endl;
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
			cout << "输入有误，请重新输入!" << endl;
		}
	}
}

//菜单界面
void showMenu() {
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

//主程序
int main() {
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录当中当前人员个数
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1://添加联系人
			addPerson(&abs);//利用地址传递可以修改形参
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3: //删除联系人
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://结束
			cout << "*****  欢迎下次使用!  *****" << endl;
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
