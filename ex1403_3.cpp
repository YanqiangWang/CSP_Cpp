#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define NO_PARAM false
#define HAS_PARAM true

template <typename T>
void sort(vector<pair<char, T> >& vec)
{
	for (int i = 0;vec.size() > 0 && i < vec.size() - 1; ++i)
		for (int j = 0; j < vec.size() - i - 1; ++j)
			if (vec[j].first > vec[j + 1].first) {
				pair<char, T> temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
}

int param_index(vector<pair<char, bool> >& params, char c)
{
	for (int i = 0; i < params.size(); ++i) {
		if (params[i].first == c)
			return i;
	}
	return -1;
}

void save(vector<pair<char, string> >& saved, pair<char, string> pr)
{
	vector<pair<char, string> >::iterator itr;
	for (itr = saved.begin(); itr != saved.end(); ++itr) {
		if ((*itr).first == pr.first)
			break;
	}
	if (itr != saved.end()) {
		saved.erase(itr);
	}
	saved.push_back(pr);
}

void get_param_list(vector<pair<char, bool> >& params, vector<pair<char, string> >& saved, string& command)
{
	int cur = 0;
	while (cur < command.size()) {
		if (command[cur++] == ' ')
			if (command[cur++] == '-') {
				int index = param_index(params, command[cur++]);
				if (index != -1) {
					if (params[index].second) {
						if (command[cur++] == ' ') {
							string temp_s;
							while(command[cur++] != ' ' && cur <= command.size())
								temp_s += command[cur - 1];
							save(saved, make_pair(params[index].first, temp_s));
							cur--;
						}else
							return;
					}else
						save(saved, make_pair(params[index].first, ""));
				}else
					return;
			}else
				return;
	}
}

int main()
{
	string temp;
	getline(cin, temp);
	int n;
	cin >> n;
	string ignore;
	getline(cin, ignore);
	vector<pair<char, bool> > params;
	for (int i = 0; i < temp.size() - 1; ++i) {
		if (temp[i + 1] != ':')
			params.push_back(make_pair(temp[i], NO_PARAM));
		else {
			params.push_back(make_pair(temp[i], HAS_PARAM));
			++i;
		}
	}
	if (temp[temp.size() - 1] != ':')
		params.push_back(make_pair(temp[temp.size() - 1], NO_PARAM));
	sort(params);
	// cout << "params size: " << params.size() << endl;
	for (int cnt = 1; cnt <= n; ++cnt) {
		string command;
		getline(cin, command);
		cout << "Case " << cnt << ":";
		vector<pair<char, string> > saved;
		get_param_list(params, saved, command);
		sort(saved);
		// for (int i = 0; i < saved.size(); ++i)
			// cout << "first: " << saved[i].first << " second: " << saved[i].second << endl;
		for (int i = 0; i < saved.size(); ++i) {
			cout << " -" << saved[i].first;
			if (saved[i].second != "")
				cout << " " << saved[i].second;
		}
		cout << endl;
	}
	return 0;
}