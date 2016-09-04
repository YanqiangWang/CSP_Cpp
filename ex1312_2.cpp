#include <iostream>
#include <string>
using namespace std;

int main()
{
	string isbn;
	cin >> isbn;
	int sum = 0;
	for (int i = 0, cnt = 1; i < 11; ++i) {
		if (isbn[i] == '-')
			continue;
		sum += (isbn[i] - '0') * cnt;
		++cnt;
		// cout << "cnt: " << cnt << " sum: " << sum << endl;
	}
	if (sum % 11 == 10 && isbn[12] == 'X' || sum % 11 != 10 && sum % 11 == isbn[12] - '0')
		cout << "Right" << endl;
	else {
		if (sum % 11 != 10)
			isbn[12] = char(sum % 11 + '0');
		else
			isbn[12] = 'X';
		cout << isbn << endl;
	}
	return 0;
}