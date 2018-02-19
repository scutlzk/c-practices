/*
1+2+3+4+(5*60)*-8
1 2 + 3 + 4 + 5 60 * -8 * + 
*/
#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
string InfixToPostfix(string infix) 
{	
	stringstream a(infix);
	stack<char> op;
	string postfix;
	int n;
	char t;
	a >> n;		//Ê½×ÓµÚÒ»¸ö¿Ï¶¨ÊÇÊý×Ö

	postfix += to_string(n);
	while (a >> t)
	{
		if (op.size() && (t == '+' || t == '-'))
		{
			postfix += string(" ") + op.top();
			op.pop();
		}
		op.push(t);

		if (a >> t&&t == '(')
		{
			string x;
			a >> t;
			while (t != ')')
			{
				x += t;
				a >> t;
			}
			postfix += string(" ") + InfixToPostfix(x);
		}
		else
		{
			a.putback(t);
			a >> n;
			postfix += string(" ") + to_string(n);
		}

		if (op.size() && (op.top() == '*' || op.top() == '/'))
		{
			postfix += string(" ") + op.top();
			op.pop();

		}
	}
	while (op.size()) { postfix += string(" ") + op.top(); op.pop(); }
	return postfix;
}

int main()
{	string infix;
	while (1)
	{
		getline(cin,infix);
		cout<<InfixToPostfix(infix)<<endl;
	}
}
