#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ��������� ���� S � ���� N
void add(vector<vector<string>>& v, int& n, string& s)
{
	v[n - 1].push_back(s);
}

// ������� ���� S � ���� N
//void empity(vector<vector<string>>& v, int& n)
//{
//	v[n - 1].pop_back();
//}

// ������� ���-�� ��� � �� �������� � ���� N �������� ������
void dump(vector<vector<string>>& v, int& n)
{
	int counter = 0; // ���� ���� 
	for (auto s : v[n - 1])
	{
		counter++;
	}
	cout << counter << " "; // ����� ����������� ��� 
	for (auto s : v[n - 1])
	{
		cout << s << " "; // ����� ��� � ����������� ���� N �������� ������
	}
	cout << endl;
}

void empity(int day, vector<vector<string>>& days, string task)  //������� ���� S � ���� N
{
	for (int i = 0; i < days[day - 1].size(); i++)
	{
		if (days[day - 1][i] == task)
		{
			days[day - 1].erase(days[day - 1].begin() + i);
		}
	}
}


// ����������� ���������� ������
void nextmonth(vector<vector<string>>& v, const vector<int>& month, int& current_month)
{
	// ���� ���������� ����� - ������� (������ = 11), �� ������ �� ������ (������ = 0)
	if (current_month == 12)
		current_month = 0;
	// ������� ��������� ������, ��� ����� ������� �� ����, ������� ���� � ���, �������������� � ������� ������
	vector <string> tmp;
	// ������� ��� ���� � ��������� ��, �������� �� ��������� �������� ������
	for (int i = month[current_month] - 1; i < month[current_month ]; i++)
	{
		for (auto s : v[i])
		{
			tmp.push_back(s);
		}
	}
	// ������ ���-�� ���� � ������
	v.resize(month[current_month]); // ����������� �������
									// ��������� ��� ��������� ���� ���� �� ������� ������ �� ��������� ���� ��������
	for (auto s : tmp)
	{
		v[month[current_month] - 1].push_back(s);
	}
	// ���������� ����� ������
	
}

int main()
{

	int Q;
	cin >> Q; // ���-�� ��������
	const vector <int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // ������ �� ������� �� �������
	vector <vector<string>> actions(31); //������ ��������.
	int current_month = 0; // ������(��� ������ �����)
	for (int i = 0; i < Q; i++)
	{
		string tmp_action;
		cin >> tmp_action;
		if (tmp_action == "NEXT")
		{
			current_month++;
			nextmonth(actions, months, current_month);
		}
		else if (tmp_action == "DUMP")
		{
			int tmp; //����
			cin >> tmp;
			if (tmp > months[current_month]) continue;

			dump(actions, tmp);
		}
		else if (tmp_action == "ADD")
		{
			string tmp_name;
			int tmp;
			cin >> tmp >> tmp_name;
			if (tmp > months[current_month]) continue;
			add(actions, tmp, tmp_name);
		}
		else if (tmp_action == "REMOVE")
		{
			string tmp_name;
			int tmp;
			cin >> tmp >> tmp_name;
			if (tmp > months[current_month]) continue;
			empity(tmp, actions, tmp_name);
		}
	}
	system("pause");
	return 0;
}