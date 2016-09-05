// score: 40
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Trans {
	int id;
	int oper;
	double price;
	long amount;
	
	Trans(int _id, int _oper, double _price, long _amount) : id(_id), oper(_oper), price(_price), amount(_amount) {}
};

bool operator<(const Trans& trans1, const Trans& trans2)
{
	return trans1.price < trans2.price;
}

int main()
{
	vector<Trans> deal;
	string temp;
	int cnt = 0;
	vector<pair<int, int> > cancel_store;
	deal.push_back(Trans(0, 0, 0, 0));
	while(cin >> temp) {
		++cnt;
		if (temp == "cancel") {
			int line;
			cin >> line;
			cancel_store.push_back(make_pair(line, cnt));
			continue;
		}
		int oper;
		if (temp == "buy")
			oper = 0;
		else
			oper = 1;
		double price;
		long amount;
		cin >> price >> amount;
		deal.push_back(Trans(cnt, oper, price, amount));
	}
	for (int i = 0; i < cancel_store.size(); ++i) {
		for (int j = 0; j < cancel_store.size(); ++j) {
			if (i != j && cancel_store[i].first == cancel_store[j].second)
				cancel_store[j].first = 0;
		}
	}
	for (int i = 0; i < cancel_store.size(); ++i)
		for (int j = 0; j < deal.size(); ++j)
			if (cancel_store[i].first == deal[j].id)
				deal[j].amount = 0;
	sort(deal.begin(), deal.end());
	long max = 0;
	double max_price = 0.0;
	for (int i = 0; i < deal.size(); ++i) {
		// cout << "debug: " << deal[i].price << " " << deal[i].amount << endl;
		long sell_amount = 0, buy_amount = 0;
		for (int j = 0; j < deal.size(); ++j) {
			if (deal[j].oper && deal[j].price <= deal[i].price)
				sell_amount += deal[j].amount;
			if (!deal[j].oper && deal[j].price >= deal[i].price)
				buy_amount += deal[j].amount;
		}
		if (max <= min(sell_amount, buy_amount)) {
			max = min(sell_amount, buy_amount);
			max_price = deal[i].price;
			// cout << "max: " << max_price << " " << max << endl;
		}
	}
	cout << setprecision(2) << fixed << max_price << " " << max << endl;
	return 0;
}