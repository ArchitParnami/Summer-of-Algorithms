//
//  main.cpp
//  NextPermutation
//
//  Created by archit on 6/4/17.
//  Copyright © 2017 archit. All rights reserved.
//

#include <iostream>
using namespace std;

int* permute(int*, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char str[26];
    cout << "Enter the sequence[A-Z] MAX LEN 26: ";
    cin >> str;
    int len = 0;
    char min = 120;
    
    while(str[len] != '\0') {
        
        if(str[len] < min) {
            min = str[len];
        }
        
        len++;
        
    }
    
    int* ordering = new int[len];
    
    for(int i = 0; i <len; i++) {
        ordering[i] = str[i] - min;
    }
    
    int* result = permute(ordering, len);
    
    if( result == NULL) {
        cout << "No Next permutation!" << endl;
    }
    
    else {
        cout << endl;
        for(int i = 0; i< len; i++) {
            cout << (char)(result[i] + min);
        }
    }
    cout << endl;
    return 0;
}

int* permute(int* ordering, int size) {
    
    int startPos = size-1;
    int pivotPos = -1, endPos = 0;
    
    for(int i = size-1; i >= 0; i--) {
        
        if(ordering[i] < ordering[i-1]) {
            continue;
        }
        else {
            pivotPos = i-1;
            endPos = i;
            break;
        }
    }
   
    if(pivotPos == -1) {
        //No next permutation
        return NULL;
    }
    
    //swap pivot with smallest higher item than pivot
    int nextHighPos = -1;
    for(int k = startPos; k >= endPos; k--) {
        if(ordering[k] > ordering[pivotPos]) {
            nextHighPos = k;
            break;
        }
    }
    
    int temp = ordering[nextHighPos];
    ordering[nextHighPos] = ordering[pivotPos];
    ordering[pivotPos] = temp;
    
    //reverse start to end
    
    int l = startPos - endPos;
    for(int i = 0; i <= l/2; i++) {
        int a = endPos + i;
        int b = startPos - i;
        
        if(a != b) {
           
            //swap pos a with pos b
            int temp = ordering[b];
            ordering[b]= ordering[a];
            ordering[a] = temp;
        }
    }
   
    return ordering;
    
}
