#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int row, col;
int cell[60][60];
int flag[60][60]; // to dest: 1, init: 0, unaccessible: -1
int flag2[60][60]; // from start: 1, init: 0, unaccessible: -1
int direct[60][60]; // left: 1, right: 2, up: 4, down: 8

struct Node {
	int r, c;
	Node(int _r, int _c) : r(_r), c(_c) {}
};

bool operator==(Node& node1, Node& node2)
{
	return node1.r == node2.r && node1.c == node2.c;
}

int main()
{
	stack<Node> stk;
	Node start = Node(0, 0);
	Node destin = Node(0, 0);
	bool stuck = true;
	cin >> row >> col;
	memset(flag, 0, sizeof(flag));
	memset(flag2, 0, sizeof(flag2));
	memset(direct, 0, sizeof(direct));
	char c;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			cin >> c;
			while(c == '\n')
				cin >> c;
			switch(c) {
			case '-':
				direct[i][j] = 3;
				break;
			case '+':
				direct[i][j] = 15;
				break;
			case '|':
				direct[i][j] = 12;
				break;
			case '.':
				direct[i][j] = 8;
				break;
			case '#':
				flag[i][j] = -1;
				flag2[i][j] = -1;
				break;
			case 'S':
				start = Node(i, j);
				direct[i][j] = 15;
				break;
			case 'T':
				destin = Node(i, j);
				direct[i][j] = 15;
				break;
			default:
				direct[i][j] = 0;
				break;
			}
		}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			if (flag[i][j] != -1) {
				if (!(direct[i][j] & 1) || j == 0 || flag[i][j - 1] == -1)
					direct[i][j] &= 14;
				if (!(direct[i][j] & 2) || j == col - 1 || flag[i][j + 1] == -1)
					direct[i][j] &= 13;
				if (!(direct[i][j] & 4) || i == 0 || flag[i - 1][j] == -1)
					direct[i][j] &= 11;
				if (!(direct[i][j] & 8) || i == row - 1 || flag[i + 1][j] == -1)
					direct[i][j] &= 7;
			}
		}
	stk.push(destin);
	while (!stk.empty()) {
		Node n = stk.top();
		flag[n.r][n.c] = 1;
		// cout << n.r << " " << n.c << endl;
		if (n == start)
			stuck = false;
		if (n.c != 0 && !flag[n.r][n.c - 1] && (direct[n.r][n.c - 1] & 2))
			stk.push(Node(n.r, n.c - 1));
		else if (n.c != col - 1 && !flag[n.r][n.c + 1] && (direct[n.r][n.c + 1] & 1))
			stk.push(Node(n.r, n.c + 1));
		else if (n.r != 0 && !flag[n.r - 1][n.c] && (direct[n.r - 1][n.c] & 8))
			stk.push(Node(n.r - 1, n.c));
		else if (n.r != row - 1 && !flag[n.r + 1][n.c] && (direct[n.r + 1][n.c] & 4))
			stk.push(Node(n.r + 1, n.c));
		else
			stk.pop();
	}
	stk.push(start);
	while (!stk.empty()) {
		Node n = stk.top();
		flag2[n.r][n.c] = 1;
		if (n.c != 0 && !flag2[n.r][n.c - 1] && (direct[n.r][n.c] & 1))
			stk.push(Node(n.r, n.c - 1));
		else if (n.c != col - 1 && !flag2[n.r][n.c + 1] && (direct[n.r][n.c] & 2))
			stk.push(Node(n.r, n.c + 1));
		else if (n.r != 0 && !flag2[n.r - 1][n.c] && (direct[n.r][n.c] & 4))
			stk.push(Node(n.r - 1, n.c));
		else if (n.r != row - 1 && !flag2[n.r + 1][n.c] && (direct[n.r][n.c] & 8))
			stk.push(Node(n.r + 1, n.c));
		else
			stk.pop();
	}
	int sum = 0;
	if (stuck)
		cout << "I'm stuck!" << endl;
	else {
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				if (!flag[i][j] && flag2[i][j] == 1)
					++sum;
		cout << sum << endl;
	}
	/* Debug
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			cout << flag[i][j] << " ";
		cout << endl;
	}
	*/
	return 0;
}