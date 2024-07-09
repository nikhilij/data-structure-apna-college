// wap to balance Parenthesis in cpp

#include <iostream>
#include <stack>

using namespace std;

int isvalid(string s)
{
    stack<char> st;
    int ans = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = 0;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = 0;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = 0;
                break;
            }
        }
    }
    return ans && st.empty();
}

int main()
{
    string s = "{([])}";

    if (isvalid(s))
    {
        cout << "Yes";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
