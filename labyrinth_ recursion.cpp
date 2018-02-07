/*
请输入迷宫宽再输入迷宫长3 3
1 0 1
1 1 1
0 0 1
*
* * *
    *

*/

#include<iostream>
using namespace std;
int l, w;
int **t;
char **path;
char **mark;
int ldes, wdes;
void ready() {
	cout << "请输入迷宫宽再输入迷宫长";
	cin >> l >> w;
	ldes = l - 1; wdes = w - 1;//默认迷宫出口 ，右下角 
	t = new int*[l];
	path = new char*[l];
	mark = new char*[l];
	for (int i = 0; i < l; i++) { t[i] = new int[w]; path[i] = new char[w]; mark[i] = new char[w]; }
	for (int i = 0; i<l; i++)for (int j = 0; j<w; j++) { cin >> t[i][j]; path[i][j] = ' '; mark[i][j] = ' ';}
}
bool compute(int i, int j) {
	mark[i][j] = '0';
	if ((i == ldes)&&(j == wdes)) { path[i][j] = '*'; return 1; }
	if (i != (l - 1) && t[i + 1][j] == 1&&mark[i+1][j] != '0')if (compute(i + 1, j)) { path[i][j] = '*'; return 1; }
	if (i != (0) && t[i - 1][j] == 1&&mark[i-1][j] != '0')if (compute(i - 1, j)) { path[i][j] = '*'; return 1; }
	if (j != (0) && t[i][j - 1] == 1&&mark[i][j-1] != '0')if (compute(i, j - 1)) { path[i][j] = '*'; return 1; }
	if (j != (w - 1) && t[i][j + 1] == 1&&mark[i][j+1] != '0')if (compute(i, j + 1)) { path[i][j] = '*'; return 1; }
	return 0;
}
void output() { for (int i = 0; i<l; i++) { for (int j = 0; j<w; j++)cout << path[i][j]<<" "; cout << endl; } }

int main() {
	while (1) { ready(); compute(0, 0);output(); }
}
