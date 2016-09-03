#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num[n];
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	int max_value, max_times = 0;
	int value, times;
	for (int i = 0; i < n; ++i) {
		times = 0;
		value = num[i];
		for (int j = i; j < n; ++j)
			if (value == num[j])
				++times;
		if (times > max_times || times == max_times && max_value > value) {
			max_times = times;
			max_value = value;
		}
	}
	cout << max_value << endl;
	return 0;
}