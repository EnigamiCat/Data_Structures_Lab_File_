#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfixExpression(const std::string &expression) {
    std::stack<int> operandStack;

    for (char c : expression) {
        if (isdigit(c)) {
            
            operandStack.push(c - '0'); 
        } else if (c == ' ') {
            continue; 
        } else {
            
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    throw runtime_error("Invalid operator: " + string(1, c));
            }
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    string expression ; 
    cout<<"Enter a postfix expression to evaluate : ";
    getline(cin,expression);
    int result = evaluatePostfixExpression(expression);
    cout << "Result: " << result << endl;
    return 0;
}
