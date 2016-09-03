#include <iostream>
using namespace std;

int main()
{
	int n;
	int saved;
	int sum = 1;
	cin >> n >> saved;
	for (int i = 1; i < n; ++i) {
		int temp;
		cin >> temp;
		if (temp != saved) {
			++sum;
			saved = temp;
		}
	}
	cout << sum << endl;
	return 0;
}