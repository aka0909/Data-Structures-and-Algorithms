#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_LEN 500

bool isredundant(string& str)
{
    stack<char> st;
    for (auto& ch : str) {
        if (ch == ')') {
            char top = st.top();
            st.pop();
            bool flag = true;
            while (!st.empty() and top != '(') {
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;
                top = st.top();
                st.pop();
            }
            if (flag == true)
                return true;
        }

        else
            st.push(ch);
    }
    return false;
}

void solve(string& str)
{
    bool ans = isredundant(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    string str = "((a+b))";
    solve(str);

    str = "(a+(b)/c)";
    solve(str);

    str = "(a+b*(c-d))";
    solve(str);

    return 0;


}
