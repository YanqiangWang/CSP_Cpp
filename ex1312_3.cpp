#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int height[n];
	int max = 0;
	for (int i = 0; i < n; ++i)
		cin >> height[i];
	for (int i = 0; i < n; ++i) {
		int min = height[i];
		for (int j = i; j < n; ++j) {
			if (height[j] < min)
				min = height[j];
			int temp_sum = min * (j - i + 1);
			if (temp_sum > max)
				max = temp_sum;
		}
	}
	cout << max << endl;
	return 0;
}