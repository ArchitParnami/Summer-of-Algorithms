//
//  main.cpp
//  BinaryAdder
//
//  Created by archit on 6/11/17.
//  Copyright © 2017 archit. All rights reserved.
//

#include <iostream>
using namespace std;


int state_machine[4][4] = {
    //            00  01  10  11
    /*0 v=0,c=0*/ {0, 1,  1,  2},
    /*1 v=1,c=0*/ {0, 1,  1,  2},
    /*2 v=0,c=1*/ {1, 2,  2,  3},
    /*3 v=1,c=1*/ {1, 2,  2,  3}

};

char state_values[] = {'0', '1', '0', '1'};

int transition(int current_state, char a, char b, char *result) {
    
    int c = a=='0'?(b=='0'? 0 : 1) : (b=='0'? 2: 3);
    int next_state = state_machine[current_state][c];
    *result = state_values[next_state];
    
    return next_state;
}


int main(int argc, const char * argv[]) {
    
    string num1;
    string num2;
    
    cout << "Enter number 1 in binary: ";
    cin >>  num1;
    
    cout << "Enter number 2 in binary: ";
    cin >> num2;
    
    string b1 = num1;
    string b2 = num2;
    
    reverse(b1.begin(), b1.end());
    reverse(b2.begin(), b2.end());
    
    unsigned long diff = 0;
    unsigned long l1 = b1.length();
    unsigned long l2 = b2.length();
    
    if(l1 > l2) {
        
        diff = l1-l2;
        for(unsigned long i = 0; i < diff; i++) {
            b2 = b2 + '0';
        }
    }
    else  if(l2 > l1) {
        diff = l2-l1;
        for(unsigned long i = 0; i < diff; i++) {
            b1 = b1 + '0';
        }
    }
    
    unsigned long l = b1.length();
    string num3 = "";
    int current_state = 0;
    char result;
    for(unsigned long i = 0; i < l; i++) {
        current_state = transition(current_state, b1[i], b2[i], &result);
        num3 = num3 + result;
    }
    
    transition(current_state, '0', '0', &result);
    num3 = num3 + result;
    
    reverse(num3.begin(), num3.end());
    
    std::cout << "Result: " << num3 << endl;
    
    return 0;
}





