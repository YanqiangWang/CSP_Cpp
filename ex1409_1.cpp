#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num[n];
	int sum = 0;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (num[i] + 1 == num[j])
				++sum;
	cout << sum << endl;
	return 0;
}