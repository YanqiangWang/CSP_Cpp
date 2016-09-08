#include <iostream>
// #include <time.h>
using namespace std;
/**
 6 states:
 0: use: 2 remain: 0, 1, 3
 1: use: 0, 2 remain: 1, 3
 2: use: 2, 3 remain: 0, 1
 3: use: 0, 1, 2 remain: 3
 4: use: 0, 2, 3 remain: 1
 5: use: 0, 1, 2, 3
 */

int main()
{
	long long mod = 1000000007;
	int n;
	cin >> n;
	long long states[n + 1][6];
	// clock_t start_time = clock();
	for (int i = 0; i < 6; ++i)
		states[0][i] = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i - 1;
		states[i][0] = 1;
		states[i][1] = (states[j][0] + states[j][1] * 2) % mod;
		states[i][2] = (states[j][0] + states[j][2]) % mod;
		states[i][3] = (states[j][1] + states[j][3] * 2) % mod;
		states[i][4] = (states[j][1] + states[j][2] + states[j][4] * 2) % mod;
		states[i][5] = (states[j][3] + states[j][4] + states[j][5] * 2) % mod;
	}
	// clock_t end_time = clock();
	cout << states[n][5] << endl;
	// cout << static_cast<double> (end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	return 0;
}