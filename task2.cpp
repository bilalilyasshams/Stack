#include <iostream>
#include <stack>
using namespace std;
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtopostfix(string s)
{
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

string reverse(string str)
{
    string st;
    int i;
    for (i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '(')
        {
            st += ")";
        }
        else if (str[i] == ')')
        {
            st += "(";
        }
        else
        {
            st += str[i];
        }
    }
    return st;
}
int main()
{
    
    string str1;
    cout<<"Enter infix expression: "<<endl;
    cin>>str1;
    //cout<<"Reversed infix expression: "<<reverse(str1);
    //cout<<"Final prefix expression: "<<infixtopostfix(reverse(str1));
    //cout << infixtopostfix("(A+B)*(C+D)");
    cout <<"Final prefix expression: "<< reverse(infixtopostfix(reverse(str1)));
}