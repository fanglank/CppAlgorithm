#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int calculate(int num1, int num2, string op) {
    if(op == "+") {
        return num1 + num2;
    }
    else if(op == "-") {
        return num1 - num2;
    }
    else if(op == "*") {
        return num1 * num2;
    }else if(op == "/") {
        return num1 / num2;
    }else {
        return 0;
    }

}


int evalRPN(vector<string> tokens) {
    stack<int> stack;
    for(string token: tokens){

        if(token == "+" || token=="-" || token=="*" || token=="/") {
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();
            stack.pop();
            stack.push(calculate(num1, num2, token));
        }else {
            cout<<stoi(token)<<endl;
            stack.push(stoi(token));
        }
    }
    return stack.top();

}