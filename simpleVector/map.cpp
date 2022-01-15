#include <map>
#include <string>
#include <iostream>

using namespace std;
using MyMap = map<int, string>;
using MyPair = pair<int, string>;

class TreeNode
{
private:
	int m_value;

	TreeNode* m_pLeft = nullptr;
	TreeNode* m_pRight = nullptr;
public:
	TreeNode(int value) : m_value{ value } {}
	TreeNode* Find(int searchValue)
	{
		TreeNode* pResult = nullptr;
		if (m_value == searchValue)
		{
			pResult = this;
		}
		else if (m_pLeft != nullptr && m_value > searchValue)
		{
			pResult = m_pLeft->Find(searchValue);
		}
		else if (m_pRight != nullptr && m_value < searchValue)
		{
			pResult = m_pRight->Find(searchValue);
		}
		return pResult;
	}
};

void MapIterators(MyMap myMap)
{
	for (const auto& node : myMap)
	{
		cout << "First: " << node.first << " Second: " << node.second << endl;
	}

	cout << endl << endl;

	for (MyMap::iterator iter = myMap.begin(); iter != myMap.end(); ++iter) {
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	cout << endl << endl;
	for (MyMap::reverse_iterator iter = myMap.rbegin(); iter != myMap.rend(); --iter) {
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	cout << endl << endl;
}

void FindInMap(MyMap myMap) {
	cout << endl << "========== FindInMap() >>>>>" << endl;
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
		if (iter->first == 2)
		{
			cout << "Found: " << iter->second << endl;
		}
	}

	for (auto& pair : myMap) {
		if (pair.first == 2)
		{
			cout << "Found: " << pair.second << endl;
		}
	}
	MyMap::iterator objiter = find(std::begin(myMap), std::end(myMap), 2);

	MyMap::iterator found = myMap.find(2);
	if (found != myMap.end())
	{
		cout << "Found First: " << found->first << " Second: " << found->second << endl;
	}
	cout << "========== FindInMap() <<<<<" << endl;
}

int main()
{
	MyMap myMap = { {2, "Two" }, {1, "One"}, {0, "Zero"} };
	myMap.emplace(3, "Three");
	MyPair node{ 4, "Four" };
	myMap.insert(node);
	myMap.insert(make_pair(8, "eight"));
	MapIterators(myMap);
	FindInMap(myMap);
}