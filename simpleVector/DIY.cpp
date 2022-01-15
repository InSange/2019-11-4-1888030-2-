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
	Book(string name = "없음", string year = "없음", string author = "없음") {
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
		cout << "기능을 선택하시오. (1.추가, 2.삭제, 3.목록, 4. 검색, 5.종료 --> ";
		cin >> num;

		switch (num) {
		case 1:
			cin.ignore();
			cout << "책의 이름을 쓰시오: ";
			getline(cin, name);
			//cin >> name;
			cout << "책의 출판연도를 쓰시오: ";
			getline(cin, year);
			//cin >> year;
			cout << "책의 작가를 쓰시오: ";
			getline(cin, author);
			//cin >> author;
			break;
		case 2:
			//cout << "삭제" << endl;
			cout << "삭제하고자하는 책의 이름을 입력하시오 -> ";
			cin.ignore();
			getline(cin, name);
			//cin >> name;
			if (book.end() == book.find(name)) {
				cout << "삭제하고자하는 책이 없습니다!" << endl;
			}
			else {
				cout << name << "책 삭제------" << endl;
				book.erase(book.find(name));
			}

			break;
		case 3:
			if (book.end() == book.begin()) {
				cout << "목록이 비어있습니다! " << endl;
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
			cout << "검색하고자하는 책의 이름을 입력하시오 -> ";
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
				cout << "찾고자하는 책은 없습니다! 추가해주세요." << endl;
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
	cout << "종료" << endl;
}