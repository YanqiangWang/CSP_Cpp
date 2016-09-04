#include <iostream>
#include <string>
using namespace std;

char to_lower(char c)
{
	if (c <= 'Z' && c >= 'A')
		c += 'a' - 'A';
	return c;
}

bool has_temp(int sen, string& temp, string& test)
{
	for (int i = 0; i <= test.size() - temp.size(); ++i)
		for (int cur = i, j = 0; cur < test.size() && j < temp.size(); ++cur, ++j) {
			if (sen && test[cur] != temp[j])
				break;
			if (!sen) {
				char c1 = to_lower(test[cur]);
				char c2 = to_lower(temp[j]);
				if (c1 != c2)
					break;
			}
			if (j == temp.size() - 1)
				return true;
		}
	return false;
}

int main()
{
	string temp;
	cin >> temp;
	int sen, n;
	cin >> sen;
	cin >> n;
	while(n--) {
		string test;
		cin >> test;
		if(has_temp(sen, temp, test)) {
			cout << test << endl;
		}
	}
	return 0;
}