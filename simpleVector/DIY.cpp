#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Book {
	string name;
	string year;
	string author;
public:
	Book(string name = "����", string year = "����", string author = "����") {
		this->name = name;
		this->year = year;
		this->author = author;
	}
	void print() {
		cout << "name: " << name << endl << "  year: " << year << endl << "  author: " << author << endl;
	}
};

int main()
{
	int num;
	string name, year, author;
	map<string, Book> book;
	bool clear = true;
	while (clear) {
		int count = 1;
		int count2 = 0;
		cout << "����� �����Ͻÿ�. (1.�߰�, 2.����, 3.���, 4. �˻�, 5.���� --> ";
		cin >> num;

		switch (num) {
		case 1:
			cin.ignore();
			cout << "å�� �̸��� ���ÿ�: ";
			getline(cin, name);
			//cin >> name;
			cout << "å�� ���ǿ����� ���ÿ�: ";
			getline(cin, year);
			//cin >> year;
			cout << "å�� �۰��� ���ÿ�: ";
			getline(cin, author);
			//cin >> author;
			break;
		case 2:
			//cout << "����" << endl;
			cout << "�����ϰ����ϴ� å�� �̸��� �Է��Ͻÿ� -> ";
			cin.ignore();
			getline(cin, name);
			//cin >> name;
			if (book.end() == book.find(name)) {
				cout << "�����ϰ����ϴ� å�� �����ϴ�!" << endl;
			}
			else {
				cout << name << "å ����------" << endl;
				book.erase(book.find(name));
			}

			break;
		case 3:
			if (book.end() == book.begin()) {
				cout << "����� ����ֽ��ϴ�! " << endl;
			}
			else {
				for (auto& data : book) {
					cout << count << ".";
					data.second.print();
					count++;
				}
			}
			break;
		case 4:
			cout << "�˻��ϰ����ϴ� å�� �̸��� �Է��Ͻÿ� -> ";
			cin.ignore();
			getline(cin, name);
			//cin >> name;
			for (auto& data : book) {
				if (name == data.first) {
					data.second.print();
					count2++;
				}
			}
			if (count2 == 0) {
				cout << "ã�����ϴ� å�� �����ϴ�! �߰����ּ���." << endl;
			}
			break;
		case 5:
			clear = false;
			break;
		}
		if (num == 1) {
			Book ib(name, year, author);
			book.insert(make_pair(name, ib));
		}
		cout << endl;
	}
	cout << "����" << endl;
}