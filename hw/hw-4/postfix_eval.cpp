#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluate(string exp);
int postFix(char oper, int op1, int op2);

int main()
{
    string exp;
    cout << "Enter the postfix expression: ";
    getline(cin, exp);
    int result = evaluate(exp);
    if (result == -1)
        cout << "Error division by 0 " << endl;
    else
        cout << "Result = " << result << endl;
}

int evaluate(string exp)
{
    stack<int> mystack; //creating a stack from STL
    int op1, op2, result;
    for (unsigned int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ')
            continue;

        else if (isdigit(exp[i]))
        {
            mystack.push(exp[i] - '0'); //converting to an integer
        }

        else
        {
            op2 = mystack.top();
            mystack.pop();
            op1 = mystack.top();
            mystack.pop();
            result = postFix(exp[i], op1, op2);
            mystack.push(result);
        }
    }
    return mystack.top();
}

int postFix(char oper, int op1, int op2)
{
    if (oper == '+')
        return op1 + op2;
    else if (oper == '-')
        return op1 - op2;
    else if (oper == '*')
        return op1 * op2;
    else if (oper == '/')
    {
        if (op2 == 0) //division by 0 will result in an error
        {
            return -1;
        }
        else
            return op1 / op2;
    }
    else
        return 0;
}
