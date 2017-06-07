//
//  main.cpp
//  Postfix
//
//  Created by archit on 6/7/17.
//  Copyright © 2017 archit. All rights reserved.
//

#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;
int split(string, char, string**);
float evaluate_postfix(string);


int main(int argc, const char * argv[]) {
    string expr;
    cout << "Enter postfix expression: ";
    getline(cin, expr);
    float result = evaluate_postfix(expr);
    cout << result << endl;
    return 0;
}


float evaluate_postfix(string expr) {
    
    stack<string> stk;
    string op[] = {"+", "-", "*", "/", "^"};
    string *tokens = nullptr;
    int n = split(expr, ' ', &tokens);
    
    for(int i = 0; i <n; i++) {
        
        bool isOperator = false;
        int opType = 0;
        for(int j =0; j <5; j++) {
            if(tokens[i] == op[j]) {
                isOperator = true;
                opType = j;
                break;
            }
        }
        
        if(isOperator) {
            string second = stk.top(); stk.pop();
            string first = stk.top(); stk.pop();
            float a = stof(first);
            float b = stof(second);
            float result = 0;
            switch (opType) {
                case 0:
                    result = a+b; break;
                case 1:
                    result = a-b; break;
                case 2:
                    result = a*b; break;
                case 3:
                    result = a/b; break;
                case 4:
                    result = pow(a, b); break;
                default:
                    break;
            }
            
            stk.push(to_string(result));
        }
        
        else {
            stk.push(tokens[i]);
        }
    }
    
    float result = stof(stk.top()); stk.pop();
    
    delete [] tokens;
    
    return result;
}


int split(string expr, char del, string **result) {
    
    int n = 0;
    
    for(int i = 1; i < expr.length(); i++) {
        if(expr[i-1] != del && expr[i] == del) {
            n++;
        }
    }
    
    string *tokens = new string[n+1];
    int count = 0;
    int start = 0, end = 0;
    int i = 0;
    for(i = 0; i < expr.length(); i++) {
        if(expr[i] == del) {
            if(i > 0 && expr[i-1] != del) {
                end = i;
                tokens[count] = expr.substr(start, end-start);
                count++;
                start = i+1;
            }
            
            else {
                start++;
            }
        }
    }
    
    if(i == expr.length() && expr[i-1] != del) {
        end = i;
        tokens[count] = expr.substr(start, end-start);
    }
    
    *result = tokens;
    
    return n+1;
}
