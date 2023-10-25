#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePrefixExpression(const std::string &expression) {
    std::stack<int> operandStack;

    for (int i = expression.size() - 1; i >= 0; --i) {
        char c = expression[i];
        if (isdigit(c)) {
            operandStack.push(c - '0'); 
        } else if (c == ' ') {
            continue; 
        } else {
            
            int operand1 = operandStack.top();
            operandStack.pop();
            int operand2 = operandStack.top();
            operandStack.pop();

            if (c == '+') {
                operandStack.push(operand1 + operand2);
            } else if (c == '-') {
                operandStack.push(operand1 - operand2);
            } else if (c == '*') {
                operandStack.push(operand1 * operand2);
            } else if (c == '/') {
                operandStack.push(operand1 / operand2);
            }
        }
    }

    return operandStack.top();
}

int main() {
    string expression; 
   cout<<"Enter the prefix expression : ";
    getline(cin,expression);
    int result = evaluatePrefixExpression(expression);
    cout << "Result: " << result << std::endl;
    return 0;
}
