#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int plot[110][110];
	int sum = 0;
	memset(plot, 0, sizeof(plot));
	while(n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; ++i)
			for (int j = y1; j < y2; ++j)
				plot[i][j] = 1;
	}
	for (int i = 0; i < 110; ++i)
		for (int j = 0; j < 110; ++j)
			sum += plot[i][j];
	cout << sum << endl;
	return 0;
}