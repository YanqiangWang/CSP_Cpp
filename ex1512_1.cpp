#include <iostream>
using namespace std;

int main()
{
	char c;
	int sum = 0;
	while(cin >> c) {
		sum += c - '0';
	}
	cout << sum;
	return 0;
}