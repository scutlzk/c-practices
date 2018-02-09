#include<iostream>
#include<stack>
using namespace std;
int n;
void ready();
void hanoi_stack();
class hanoi
{
public:
	char des;
	char temp;
	char src;
	int n;//盘子数
	int number;//盘号
	hanoi(char a, char b, char c, int n, int number) { src = a; temp = b; des = c; this->n = n; this->number = number; }
};

int main() { while (1) { ready(); hanoi_stack(); } }


void ready() { cout << "请输入汉诺塔高度"; cin >> n; cout << "默认从A移动到C" << endl; }
void hanoi_stack() 
{ 
	stack<hanoi> h; 
	h.push(hanoi('A', 'B', 'C', n, n));
	while (!h.empty())
	{
		hanoi a=h.top();
		h.pop();
		if (a.n == 1) { cout << a.number << a.src << "->" << a.des << endl; }
		else 
		{
			h.push(hanoi(a.temp, a.src, a.des, a.n - 1, a.n - 1));
			h.push(hanoi(a.src, a.temp, a.des, 1, a.n));
			h.push(hanoi(a.src, a.des, a.temp, a.n - 1, a.n - 1));
		}
		
	}
}