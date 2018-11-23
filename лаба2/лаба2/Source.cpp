#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ƒобавл€ем дело S в день N
void add(vector<vector<string>>& v, int& n, string& s)
{
	v[n - 1].push_back(s);
}

// ”дал€ем дело S в день N
//void empity(vector<vector<string>>& v, int& n)
//{
//	v[n - 1].pop_back();
//}

// ¬ыводим кол-во дел и их названи€ в день N текущего мес€ца
void dump(vector<vector<string>>& v, int& n)
{
	int counter = 0; // наше дело 
	for (auto s : v[n - 1])
	{
		counter++;
	}
	cout << counter << " "; // вывод колличества дел 
	for (auto s : v[n - 1])
	{
		cout << s << " "; // вывод дел в определЄнный день N т€кущего мес€ца
	}
	cout << endl;
}

void empity(int day, vector<vector<string>>& days, string task)  //”дал€ем дело S в день N
{
	for (int i = 0; i < days[day - 1].size(); i++)
	{
		if (days[day - 1][i] == task)
		{
			days[day - 1].erase(days[day - 1].begin() + i);
		}
	}
}


// Ќаступление следующего мес€ца
void nextmonth(vector<vector<string>>& v, const vector<int>& month, int& current_month)
{
	// ≈сли предыдущий мес€ц - декабрь (индекс = 11), то мен€ем на январь (индекс = 0)
	if (current_month == 12)
		current_month = 0;
	// «аводим временный вектор, где будем хранить те дела, которые были в дни, несуществующие в текущем мес€це
	vector <string> tmp;
	// Ќаходим эти дела и добавл€ем их, пробега€ по значени€м прошлого мес€ца
	for (int i = month[current_month] - 1; i < month[current_month ]; i++)
	{
		for (auto s : v[i])
		{
			tmp.push_back(s);
		}
	}
	// ћен€ем кол-во дней в мес€це
	v.resize(month[current_month]); // размерность вектора
									// ƒобавл€ем все найденные нами дела из прошлго мес€ца на последний день текущего
	for (auto s : tmp)
	{
		v[month[current_month] - 1].push_back(s);
	}
	// ¬озвращаем новый вектор
	
}

int main()
{

	int Q;
	cin >> Q; //  ол-во запросов
	const vector <int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // вектор из мес€цов по пор€дку
	vector <vector<string>> actions(31); //массив векторов.
	int current_month = 0; // январь(наш первый мес€ц)
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
			int tmp; //день
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