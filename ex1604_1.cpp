#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> sales;
	int count;
	int times = 0;
	int cur_sale;
	cin >> count;
	while(cin >> cur_sale)
		sales.push_back(cur_sale);
	for (int i = 1; i < count - 1; ++i) {
		if(sales[i - 1] < sales[i] && sales[i + 1] < sales[i] || sales[i - 1] > sales[i] && sales[i + 1] > sales[i])
			++times;
	}
	cout << times << endl;
	return 0;
}