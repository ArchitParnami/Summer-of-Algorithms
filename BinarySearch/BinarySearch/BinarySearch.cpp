//
//
//  BinarySearch
//
//  Created by archit on 6/12/17.
//  Copyright © 2017 archit. All rights reserved.
//

#include <iostream>

using namespace std;
int search(int* data, int size, int item);

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int* nums = new int[n];
    cout << "Enter numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter number to search: ";
    int item;
    cin >> item;
    
    int result = search(nums,n,item);
    if(result == -1) {
        cout << "Number not found!" << endl;
    }
    else {
        cout << "Number found at position: " << result + 1 << endl;
    }
    
    return 0;
}

int search(int* data, int size, int item) {
    
    int left  = 0;
    int right = size -1;
    
    while(left <= right) {
        int middle = (left + right) / 2;
        if(item < data[middle]) {
            right = middle - 1;
        }
        else if(item > data[middle]) {
            left = middle + 1;
        }
        else {
            return middle;
        }
    }
    
    return -1;
    
}


