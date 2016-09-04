#include <iostream>
#include <list>
using namespace std;

struct Window {
	int id;
	int x1, y1, x2, y2;
	Window(int _id, int _x1, int _y1, int _x2, int _y2) : id(_id), x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

int main()
{
	int n, m;
	cin >> n >> m;
	list<Window> windows;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		windows.push_front(Window(i + 1, x1, y1, x2, y2));
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		int temp = 0;
		for (list<Window>::iterator itr = windows.begin(); itr != windows.end(); ++itr) {
			if ((*itr).x1 <= x && (*itr).y1 <= y && (*itr).x2 >= x && (*itr).y2 >= y) {
				temp = (*itr).id;
				Window temp_win = *itr;
				windows.erase(itr);
				windows.push_front(temp_win);
				break;
			}
		}
		if (temp != 0)
			cout << temp << endl;
		else
			cout << "IGNORED" << endl;
	}

	return 0;
}