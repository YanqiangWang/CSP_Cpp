#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num[n], times[n];
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		times[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (times[i] == 0) {
			int temp = 0;
			for (int j = i; j < n; ++j) {
				if (num[i] == num[j])
					times[j] = ++temp;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i)
		cout << times[i] << " ";
	cout << times[n - 1];
	return 0;
}