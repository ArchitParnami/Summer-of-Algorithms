//
//  main.cpp
//  SieveOfEratosthenes
//
//  Created by archit on 6/6/17.
//  Copyright © 2017 archit. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int* Sieve(int);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    int* nums = Sieve(n);
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] == 1) {
            cout << i + 1 << " ";
            count++;
        }
    }
    
    cout << endl << "Number of Primes: " << count << endl;
    
    
    return 0;
}

int* Sieve(int n) {
    int* nums = new int[n];
    int upper = sqrt(n);
    
    nums[0] = 0; // 1 is Not prime
    // umarked all
    for(int i = 1; i <n ; i++) {
        nums[i] = 1;
    }
    
    for(int i = 2; i <= upper; i++) {
        if(nums[i-1] == 0) {
            continue;
        }
        //mark
        for(int j = i*i; j <= n; j = j+i) {
            nums[j-1] = 0;
        }
    }
    
    return nums;
    
}
