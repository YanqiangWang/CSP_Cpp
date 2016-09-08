#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

long long dist;
int rout_sum[220];
int inc_sum[220];

struct Router {
	int id;
	long long x, y;
	Router(int _id, long long _x, long long _y) : id(_id), x(_x), y(_y) {}
};

bool is_connected(Router r1, Router r2)
{
	return (r2.y - r1.y) * (r2.y - r1.y) + (r2.x - r1.x) * (r2.x - r1.x) <= dist * dist;
}

int main()
{
	int rout_n, posi_n, inc_rout_n;
	cin >> rout_n >> posi_n >> inc_rout_n >> dist;
	vector<Router> routs;
	for (int i = 0; i < 220; ++i)
		inc_sum[i] = rout_sum[i] = 120;
	for (int i = 0; i < rout_n + posi_n; ++i) {
		long long x, y;
		cin >> x >> y;
		routs.push_back(Router(i, x, y));
	}
	queue<Router> que;
	que.push(routs[0]);
	inc_sum[0] = rout_sum[0] = 0;
	while(!que.empty()) {
		Router front = que.front();
		// cout << front.id << " ";
		for (int i = 0; i < rout_n + posi_n; ++i) {
			if (front.id != i && is_connected(front, routs[i])) {
				if (inc_sum[i] == 120)
					que.push(routs[i]);
				if (i >= rout_n)
					inc_sum[i] = min(inc_sum[i], inc_sum[front.id] + 1);
				else
					inc_sum[i] = min(inc_sum[i], inc_sum[front.id]);
				if (inc_sum[i] <= inc_rout_n)
					rout_sum[i] = min(rout_sum[i], rout_sum[front.id] + 1);
			}
		}
		que.pop();
	}
	cout << rout_sum[1] - 1 << endl;
	return 0;
}