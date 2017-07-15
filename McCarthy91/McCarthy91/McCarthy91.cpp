//
//  main.cpp
//  McCarthy91
//
//  Created by archit on 7/15/17.
//  Copyright © 2017 archit. All rights reserved.
//

#include <iostream>
using namespace std;

long mccarthy91(long num);

int main(int argc, const char * argv[]) {
    
    cout << "Enter a number: ";
    long num;
    cin  >> num;
    long ans = mccarthy91(num);
    cout << "Mccarthy91: " << ans << endl;
    
    
    cout << "Testing McCarthy with range (0-100)" << endl;
    
    bool testPassed = true;
    
    for(int i = 0; i <= 100; i++) {
        if(mccarthy91(i) != 91) {
            cout << "Failed for input: " << i << endl;
            testPassed = false;
            break;
        }
    }
    
    if(testPassed) {
        cout << "Test passed!" << endl;
    }
    
    
    return 0;
}

long mccarthy91(long num) {
    
    long k = 1;
    while(k > 0) {
        if(num > 100) {
            num = num - 10;
            k = k - 1;
        }
        else {
            num = num + 11;
            k = k + 1;
        }
    }
    
    return num;
    
}


