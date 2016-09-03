#include <iostream>
using namespace std;

int main()
{
	int row, col;
	cin >> row >> col;
	int num[row][col];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> num[i][j];
	for (int i = col - 1; i >= 0; --i) {
		for (int j = 0; j < row - 1; ++j) {
			cout << num[j][i] << " ";
		}
		cout << num[row - 1][i] << endl;
	}
	return 0;
}