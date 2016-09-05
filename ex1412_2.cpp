#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> num[i][j];
	int direct[4][2] = {{0, 1}, {1, -1}, {1, 0}, {-1, 1}};
	int row = 0, col = 0;
	cout << num[row][col];
	num[row][col] = 0;
	while (row != n - 1 || col != n - 1) {
		for (int i = 0; i < 4; ++i) {
			int y = row + direct[i][0];
			int x = col + direct[i][1];
			if (y < n && y >= 0 && x < n && x >= 0 && num[y][x]) {
				row = y;
				col = x;
				cout << " " << num[row][col];
				num[y][x] = 0;
				if (i == 1 || i == 3)
					--i;
			}
			if (row == n - 1 && col == n - 1)
				break;
		}
	}
	return 0;
}