//
//  main.cpp
//  CountingOneBits
//
//  Created by archit on 6/5/17.
//  Copyright © 2017 archit. All rights reserved.
//

#include <iostream>
#include <bitset>
using namespace std;

int count1Bits(int);
int count1BitsRecursive(int);
int count1BitsRightShift(int);

int main(int argc, const char * argv[]) {
    int num;
    cout << "Enter 32 bit number: ";
    cin >> num;
    cout << "Binary Reperesentaion: " << bitset<32>(num).to_string() << endl;
    cout << "Number of Ones: " << count1Bits(num) << endl;
    cout << "Number of Ones(Recursive): " << count1BitsRecursive(num) << endl;
    cout << "Number of Ones(RightShift): " << count1BitsRightShift(num) << endl;
    
    return 0;
}

int count1Bits(int num)
{
    int n = 0;
    while(num != 0)
    {
        num &= num - 1;
        n++;
    }
    return n;
}

int count1BitsRecursive(int num) {
    
    return num == 0? 0 : (num % 2? (1 + count1Bits(num/2)): count1Bits(num/2));
}

int count1BitsRightShift(int num) {
    int n = 0;
    while(num != 0) {
        if(num % 2 == 1) {
            n++;
        }
        num = num >> 1;
    }
    
    return n;
}
