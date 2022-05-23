#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool printFile(string(path));
//������� 1
bool fileInput(string path, int pos, string str);
//������ 1
string subFile(string path,int pos);
//������ 3
bool iofstream(string path,bool n);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	string path = "file.txt";

	/*fstream fs;
	fs.open(path, ios::in | ios::app);

	if (fs.is_open()){
		cout << "���� ������.\n";
		string str;
		//������ � ����
		cout << "������� ������:\n";
		getline(cin, str);
		fs << str + "\n";
		cout << "������ ��������� � ������.\n";
		//���������� �����
		fs.seekg(0, ios::beg);
		char sym;
		cout << "���������� �����:\n";
		while (fs.get(sym))
			cout << sym;
	}
	else
		cout << "������ �������� �����.\n";
	
	fs.close();*/

	//������� 1
	/*cout << "������ 1.\n������� ������:\n";
	string str;
	getline(cin, str);
	if (fileInput(path, 5, str))
		cout << "������ �������� � ����.\n";
	else
		cout << "������ ���������� �������.\n";
	cout << "\n���������� �����:\n";
	printFile(path);*/

	//������ 1
	/*cout << "������ 1.\n������� �������: ";
	cin >> n;
	cin.ignore();
	cout << "���������� ����� � �������  " << n << ":\n";
	cout << subFile(path, n) << endl;*/

	//������ 2
	/*cout << "������ 2.\n";

	int day = 0, month = 0, year = 0;

	ifstream in;
	in.open("date.txt");

	if (in.is_open())
	{
		string date;
		in >> date;

		day = stoi(date);
		cout << "���� = " << day << endl;
		month = stoi(date.substr(date.find(".") + 1));
		cout << "����� = " << month << endl;
		year = stoi(date.substr(date.rfind(".") + 1));
		cout << "��� = " << year << "\n\n";
	}
	else
		cout << "������ �������� �����:\n";*/

	//������ 3
	cout << "������ 3.\n";
	

	return 0;
}

bool printFile(string(path)) {
	ifstream in;
	in.open(path);

	if (in.is_open())
	{
		char sym;
		while (in.get(sym))
			cout << sym;
		in.close();
		return true;
	}
	in.close();
	return false;
}

//������� 1
bool fileInput(string path, int pos, string str) {
	string newFile;

	ifstream copy;
	copy.open(path);

	if (!copy.is_open()){
		copy.close();
		return false;
	}

	char sym;
	while (copy.get(sym))
		newFile += sym;
	copy.close();

	newFile.insert(pos, str);

	ofstream out;
	out.open(path);

	if (!out.is_open()){
		out.close();
		return false;
	}
	out << newFile;
	out.close();
	return true;
}

//������ 1
string subFile(string path, int pos) {
	ifstream in;
	in.open(path);
	if (in.is_open()){
		string res;
		char sym;
		in.seekg(pos, ios::beg);
		while (in.get(sym))
			res += sym;
		in.close();
		return res;
	}
	in.close();
	return "";
}

//������ 3
bool iofstream(string path,bool n) {
	fstream fs;
	fs.open(path,ios::in|ios::app);
	if (fs.is_open())
	{
		if (n)
		{
			ofstream out;
			out.open(path);
			cout << "������� ������:\n";
			string str;
			getline(cin, str);
			out << str << endl;
			out.close();
		}
		else
			if (n == false)
			{
				ifstream in;
				in.open(path);
			}
	}
	else
		cout << "������ �������� �����.\n";
}


// seekg - seek get pointer.�����, ������� ���������� ������ ���������� � ����� ������� �����
// seekp - seek put pointer.�����, ������� ���������� ������ ������ � ����� ������� �����