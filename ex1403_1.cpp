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
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (num[i] && num[i] + num[j] == 0) {
				num[i] = num[j] = 0;
				++sum;
			}
		}
	}
	cout << sum << endl;
	return 0;
}