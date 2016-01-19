#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
	stack<char> st;
	string bracket;
	cin>>bracket;

	int multiple = 1;
	int score = 0;
	for (int i = 0; i < bracket.length(); i++)
	{
		if (bracket.at(i) == '(')
		{
			st.push(bracket.at(i));
			multiple *= 2;
		}
		else if (bracket.at(i) == '[')
		{
			st.push(bracket.at(i));
			multiple *= 3;
		}
		else if (bracket.at(i) == ')' && st.top() == '(')
		{
			if(bracket.at(i-1) == '(')
				score += multiple;
			multiple /= 2;
			st.pop();
		}
		else if (bracket.at(i) == ']' && st.top() == '[')
		{
			if (bracket.at(i-1) == '[')
				score += multiple;
			multiple /= 3;
			st.pop();
		}
		else
			break;
	}
	if (!st.empty())
		cout<<0<<endl;
	else
		cout<<score<<endl;

	return 0;
}