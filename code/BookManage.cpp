#include"pch.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

class User
{
public:
	void account();
	User() {}
	User(string r, string b, string p, string ad) :rnum(r), birth(b), phone(p), address(ad) {}
	string rnum;
	string birth;
	string phone;
	string address;
}u;

class Reader :virtual public User
{
public:
	void account();
	void info();
	void BR();
	void borr();
	void back();
	void codechange();
	Reader() {}
	Reader(string r, string b, string p, string ad) : User(r, b, p, ad) {}


protected:

	char code[10];


}r;

class Administrator :virtual public User
{
public:
	void account();
	void rec();
	void BR();
	void codechange();
	Administrator() {}
	Administrator(string r, string b, string p, string ad) : User(r, b, p, ad) {}
protected:
	string anum;
	char code[10];
}ad;

class Visitor
{
public:
	void choose();
	void Ncheck();
	void Acheck();
	void Pcheck();
	void Dcheck();
	void Bcheck();

}v;

class Book
{
public:
	void test();
	friend Visitor;
protected:
	int property;
	char type;
	string name;
	string author;
	string publish;
	string barcode;
	int amount;
	int left;
	int hborrow;
};


void Reader::account()
{
	char passWord[10], usersname[10];
	int i;
	system("cls");
	cout << setw(5) << " ===========欢迎使用图书查询检索系统============= " << endl;

	for (i = 1; i <= 3; i++)
	{
		cout << "请输入读者账号和密码." << endl;
		cout << "账号：";
		cin >> usersname;
		cout << "密码：";
		cin >> passWord;
		if (strcmp(usersname, "rea111") == 0 && strcmp(passWord, "01234") == 0)

		{

			{
				cout << setw(5) << "*********************************" << endl;
				cout << endl;
				cout << setw(5) << "请选择你需要的操作：" << endl;
				cout << setw(5) << "1.读者个人信息查询" << endl;
				cout << setw(5) << "2.个人书籍借阅情况查询" << endl;
				cout << setw(5) << "3.密码修改" << endl;
				cout << setw(5) << "0.返回上一页菜单" << endl;
				cout << endl;
				cout << setw(5) << "*********************************" << endl;
				int a;
				cin >> a;
				if (a != 0 && a != 1 && a != 2 && a != 3)
				{
					cout << "Error!\n输入有误！\n";
					getchar();
					return;
				}
				switch (a)
				{
				case 1:r.info(); break;
				case 2:r.BR(); break;
				case 3:r.codechange(); break;
				case 0:u.account(); break;
				}
			}getchar();
			break;
		}

		else
			cout << "账号或密码错误，请重新输入！" << endl;
	}
	if (i > 3)
	{
		cout << "账号或密码已输错三次，您无权使用，请退出！" << endl;
		getchar();
		exit(0);
	}
}

void Reader::info()
{
	User re[4];

	string nam;
	cout << "请输入读者账号：" << endl;
	cin >> nam;
	ifstream infile("D:/Readers.txt", ios::binary);

	if (!infile)
	{
		cerr << "Open error!" << endl;
		return;
	}
	for (int i = 0; i < 4; i++)
		if (nam == re[i].rnum)
			cout << setw(5) << re[i].rnum
			<< setw(5) << re[i].birth
			<< setw(5) << re[i].phone
			<< setw(5) << re[i].address;
	cout << endl;


	cout << setw(5) << "请选择你需要的操作：" << endl;
	cout << setw(5) << "2.个人书籍借阅情况查询" << endl;
	cout << setw(5) << "3.密码修改" << endl;
	cout << setw(5) << "0.返回上一页菜单" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 2:r.BR(); break;
	case 3:r.codechange(); break;
	case 0:u.account(); break;
	}
}
void Reader::BR()
{
	cout << setw(5) << "*********************************" << endl;
	cout << endl;
	cout << setw(5) << "请选择你需要的操作：" << endl;
	cout << setw(5) << "1.借阅查询：" << endl;
	cout << setw(5) << "2.归还查询：" << endl;
	cout << setw(5) << "0.返回上一页菜单" << endl;
	cout << endl;
	cout << setw(5) << "*********************************" << endl;
	int a;
	cin >> a;
	if (a != 0 && a != 1 && a != 2 && a != 3)
	{
		cout << "Error!\n输入有误！\n";
		getchar();
		return;
	}
	switch (a)
	{
	case 1:borr(); break;
	case 2:back(); break;
	case 0:u.account(); break;
	}
}
void Reader::borr()
{
	ifstream infile("D:/Readerb.txt", ios::in);
	if (!infile)
	{
		cerr << "open error!" << endl;
	}
	char ch;
	while (infile.get(ch))
		cout.put(ch);
	cout << endl;
	infile.close();
	r.BR();
}
void Reader::back()
{
	ifstream infile("D:/Readerr.txt", ios::in);
	if (!infile)
	{
		cerr << "open error!" << endl;
	}
	char ch;
	while (infile.get(ch))
		cout.put(ch);
	cout << endl;
	infile.close();
	r.BR();
}
void Reader::codechange()
{
	char r[10];
	cout << "请输入新的密码：";
	cin >> r;
	strcpy_s(code, r);
	cout << "密码 :" << code << endl;
	u.account();
}
void Administrator::account()/*管理员身份验证*/
{
	char passWord[10], usersname[10];
	int i;
	system("cls");
	cout << setw(5) << " ===========欢迎使用图书查询检索系统============= " << endl;
	for (i = 1; i <= 3; i++)
	{
		cout << "请输入管理员账号和密码." << endl;
		cout << "账号：";
		cin >> usersname;
		cout << "密码：";
		cin >> passWord;
		if (strcmp(usersname, "ad111") == 0 && strcmp(passWord, "98765") == 0)

		{

			{
				cout << setw(5) << "*********************************" << endl;
				cout << endl;
				cout << setw(5) << "请选择你需要的操作：" << endl;
				cout << setw(5) << "1.读者信息查询" << endl;
				cout << setw(5) << "2.图书馆书籍借阅情况查询" << endl;
				cout << setw(5) << "3.密码修改" << endl;
				cout << setw(5) << "0.返回上一页菜单" << endl;
				cout << endl;
				cout << setw(5) << "*********************************" << endl;
				int a;
				cin >> a;
				if (a != 0 && a != 1 && a != 2 && a != 3)
				{
					cout << "Error!\n输入有误！\n";
					getchar();
					return;
				}
				switch (a)
				{
				case 1:Administrator::rec(); break;
				case 2:Administrator::BR(); break;
				case 3:Administrator::codechange(); break;
				case 0:u.account(); break;
				}

			}getchar();
			break;
		}

		else
			cout << "账号或密码错误，请重新输入！" << endl;
	}
	if (i > 3)
	{
		cout << "账号或密码已输错三次，您无权使用，请退出！" << endl;
		getchar();
		exit(0);
	}
}
void Administrator::rec()
{
	User use[4] = {
			User("rea111","19980101","1413567","HappyStreet1001"),
			User("1220wt","19991021","1083867","HaiwanStreet111"),
			User("13b541","19960304","1363948","QueenStreet7"),
			User("1789u1","19970423","1865722","WananStreet5")
	};

	ofstream outfile("D:/Readers.txt", ios::binary);
	if (!outfile)
	{
		cerr << "Open error!" << endl;
		abort();
	}
	for (int i = 0; i < 4; i++)
		outfile.write((char*)&use[i], sizeof(use[i]));
	outfile.close();

	ifstream infile("D:/Readers.txt", ios::binary);

	if (!infile)
	{
		cerr << "Open error!" << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
		infile.read((char*)&use[i], sizeof(use[i]));
	infile.close();
	for (int i = 0; i < 4; i++)
	{
		cout << "NO." << i + 1 << endl;
		cout << "Readernumber:" << use[i].rnum << endl;
		cout << "Birth:" << use[i].birth << endl;
		cout << "Phone:" << use[i].phone << endl;
		cout << "Address:" << use[i].address << endl;
	}
	cout << endl;
	cout << setw(5) << "请选择你需要的操作：" << endl;
	cout << setw(5) << "2.图书馆书籍借阅情况查询" << endl;
	cout << setw(5) << "3.密码修改" << endl;
	cout << setw(5) << "0.返回上一页菜单" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 2:Administrator::BR(); break;
	case 3:Administrator::codechange(); break;
	case 0:u.account(); break;
	}
}
void Administrator::BR()
{
	ifstream infile("D:/book.txt", ios::in);
	if (!infile)
	{
		cerr << "open error!" << endl;
	}
	char ch;
	while (infile.get(ch))
		cout.put(ch);
	cout << endl;
	infile.close();

	cout << endl;
	cout << setw(5) << "请选择你需要的操作：" << endl;
	cout << setw(5) << "3.密码修改" << endl;
	cout << setw(5) << "0.返回上一页菜单" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 3:Administrator::codechange(); break;
	case 0:u.account(); break;
	}
}
void Administrator::codechange() {
	{
		char r[10];
		cout << "请输入新的密码：";
		cin >> r;
		strcpy_s(code, r);
		cout << "新密码 :" << code << endl;
		getchar();
		u.account();
	}
}
void menu1()
{
	cout << setw(5) << "*********************************" << endl;
	cout << setw(5) << "*                               *" << endl;
	cout << setw(5) << "*                               *" << endl;
	cout << setw(5) << "*   欢迎使用图书查询检索系统    *" << endl;
	cout << setw(5) << "*                               *" << endl;
	cout << setw(5) << "*                               *" << endl;
	cout << setw(5) << "*********************************" << endl;
	getchar();
}
void menu2()

{
	cout << setw(5) << "*********************************" << endl;
	cout << endl;
	cout << setw(5) << "请选择你需要的操作" << endl;
	cout << setw(5) << "1.用户登陆" << endl;
	cout << setw(5) << "2.访客查询" << endl;
	cout << setw(5) << "0.退出" << endl;
	cout << endl;
	cout << setw(5) << "*********************************" << endl;
	int a;
	cin >> a;
	if (a != 0 && a != 1 && a != 2)
	{
		cout << "Error!\n输入有误！\n";
		getchar();
		return;
	}

	switch (a)
	{
	case 1:u.account(); break;
	case 2:v.choose(); break;
	case 0:return; break;
	}
}
void User::account()
{
	cout << setw(5) << "*********************************" << endl;
	cout << endl;
	cout << setw(5) << "请选择你需要的操作" << endl;
	cout << setw(5) << "1.管理员登陆" << endl;
	cout << setw(5) << "2.读者登陆" << endl;
	cout << setw(5) << "3.返回上一页菜单" << endl;
	cout << setw(5) << "0.退出" << endl;
	cout << endl;
	cout << setw(5) << "*********************************" << endl;
	int a;
	cin >> a;
	if (a != 0 && a != 1 && a != 2 && a != 3)
	{
		cout << "Error!\n输入有误！\n";
		getchar();
		return;
	}
	switch (a)
	{
	case 1:ad.account(); break;
	case 2:r.account(); break;
	case 3:menu2(); break;
	case 0:return; break;
	}
}
void Visitor::choose()
{
	cout << setw(5) << "*********************************" << endl;
	cout << endl;
	cout << setw(5) << "请选择你需要的操作" << endl;
	cout << setw(5) << "1.按题名检索" << endl;
	cout << setw(5) << "2.按作者检索" << endl;
	cout << setw(5) << "3.按出版社检索" << endl;
	cout << setw(5) << "4.按分类检索" << endl;
	cout << setw(5) << "5.按条形码检索" << endl;
	cout << setw(5) << "6.返回上一页菜单" << endl;
	cout << setw(5) << "0.退出" << endl;
	cout << endl;
	cout << setw(5) << "*********************************" << endl;
	int a;
	cin >> a;
	if (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6)
	{
		cout << "Error!\n输入有误！\n";
		getchar();
		return;
	}
	switch (a)
	{
	case 1:v.Ncheck(); break;
	case 2:v.Acheck(); break;
	case 3:v.Pcheck(); break;
	case 4:v.Dcheck(); break;
	case 5:v.Bcheck(); break;
	case 6:menu2(); break;
	case 0:return; break;
	}
}
void Visitor::Ncheck()
{
	Book b[3];
	string nam;
	cout << "请输入题名：" << endl;
	cin >> nam;
	ifstream infile("D:/book.txt", ios::binary);

	if (!infile)
	{
		cerr << "Open error!" << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
		infile.read((char*)&b[i], sizeof(b[i]));
	infile.close();
	for (int i = 0; i < 4; i++)
		if (nam == b[i].name)
			cout << setw(5) << b[i].type
			<< setw(5) << b[i].property
			<< setw(5) << b[i].name
			<< setw(5) << b[i].author
			<< setw(5) << b[i].publish
			<< setw(5) << b[i].barcode
			<< setw(5) << b[i].amount
			<< setw(5) << b[i].hborrow
			<< setw(5) << b[i].left;
	cout << endl;
	v.choose();
}
void Visitor::Acheck()
{
	Book b[3];
	string nam;
	cout << "请输入作者名：" << endl;
	cin >> nam;
	ifstream infile("D:/book.txt", ios::binary);

	if (!infile)
	{
		cerr << "Open error!" << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
		infile.read((char*)&b[i], sizeof(b[i]));
	infile.close();
	for (int i = 0; i < 4; i++)
		if (nam == b[i].author)
			cout << setw(5) << b[i].type
			<< setw(5) << b[i].property
			<< setw(5) << b[i].name
			<< setw(5) << b[i].author
			<< setw(5) << b[i].publish
			<< setw(5) << b[i].barcode
			<< setw(5) << b[i].amount
			<< setw(5) << b[i].hborrow
			<< setw(5) << b[i].left;
	cout << endl;
	v.choose();
}
void Visitor::Pcheck()
{
	Book b[3];
	string nam;
	cout << "请输入出版社名：" << endl;
	cin >> nam;
	ifstream infile("D:/book.txt", ios::binary);

	if (!infile)
	{
		cerr << "Open error!" << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
		infile.read((char*)&b[i], sizeof(b[i]));
	infile.close();
	for (int i = 0; i < 4; i++)
		if (nam == b[i].publish)
			cout << setw(5) << b[i].type
			<< setw(5) << b[i].property
			<< setw(5) << b[i].name
			<< setw(5) << b[i].author
			<< setw(5) << b[i].publish
			<< setw(5) << b[i].barcode
			<< setw(5) << b[i].amount
			<< setw(5) << b[i].hborrow
			<< setw(5) << b[i].left;
	cout << endl;
	v.choose();
}
void Visitor::Dcheck()
{
	Book b[3];
	char nam;
	cout << "请输入分类名：" << endl;
	cin >> nam;
	ifstream infile("D:/book.txt", ios::binary);

	if (!infile)
	{
		cerr << "Open error!" << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
		infile.read((char*)&b[i], sizeof(b[i]));
	infile.close();
	for (int i = 0; i < 4; i++)
		if (nam == b[i].property)
			cout << setw(5) << b[i].type
			<< setw(5) << b[i].property
			<< setw(5) << b[i].name
			<< setw(5) << b[i].author
			<< setw(5) << b[i].publish
			<< setw(5) << b[i].barcode
			<< setw(5) << b[i].amount
			<< setw(5) << b[i].hborrow
			<< setw(5) << b[i].left;
	cout << endl;
	v.choose();
}
void Visitor::Bcheck()
{
	Book b[3];
	string nam;
	cout << "请输入条码：" << endl;
	cin >> nam;
	ifstream infile("D:/book.txt", ios::binary);

	if (!infile)
	{
		cerr << "Open error!" << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
		infile.read((char*)&b[i], sizeof(b[i]));
	infile.close();
	for (int i = 0; i < 4; i++)
		if (nam == b[i].barcode)
			cout << setw(5) << b[i].type
			<< setw(5) << b[i].property
			<< setw(5) << b[i].name
			<< setw(5) << b[i].author
			<< setw(5) << b[i].publish
			<< setw(5) << b[i].barcode
			<< setw(5) << b[i].amount
			<< setw(5) << b[i].hborrow
			<< setw(5) << b[i].left;
	cout << endl;
	v.choose();
}

int main()
{
	menu1();
	menu2();
	return 0;
}