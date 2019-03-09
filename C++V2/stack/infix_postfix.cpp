// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <stack>
#include <map>
#define test() freopen("in", "r", stdin)

using namespace std;
stack<char> Operand;

int main(int argc, char const *argv[])
{
    //test();
    map<char, int> priority;
    string Expr;
    cin >> Expr;
    bool flag1st = true;
    priority['-'] = 1, priority['+'] = 1;
    priority['*'] = 2, priority['/'] = 2;
    priority['('] = 0;
    for (int i = 0; i < Expr.size(); i++)
        {
            if (((i == 0 || Expr[i - 1] == '(') && (Expr[i] == '+' || Expr[i] == '-')) || (Expr[i] >= '0' && Expr[i] <= '9'))
                {
                    if (!flag1st)
                        cout << " ";
                    cout << Expr[i];
                    while (Expr[i + 1] == '.' || (Expr[i + 1] >= '0' && Expr[i + 1] <= '9'))
                        {
                            i++;
                            cout << Expr[i];
                        }
                    flag1st = false;
                }
            else if (Expr[i] == '(')
                {
                    Operand.push('(');
                }
            else if (Expr[i] == ')')
                {
                    while (Operand.top() != '(')
                        {
                            cout << ' ' << Operand.top();
                            Operand.pop();
                        }
                    Operand.pop();
                }
            else if (Operand.empty())
                Operand.push(Expr[i]);
            else if (priority[Expr[i]] > priority[Operand.top()])
                Operand.push(Expr[i]);
            else
                {
                    while (!Operand.empty() && !(priority[Expr[i]] > priority[Operand.top()]))
                        {
                            cout << " " << Operand.top();
                            Operand.pop();
                        }
                    Operand.push(Expr[i]);
                }
        }
    while (!Operand.empty())
        {
            cout << ' ' << Operand.top();
            Operand.pop();
        }
    return 0;
}