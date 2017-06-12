//
//  main.cpp
//  MonteCarloPie
//
//  Created by archit on 6/12/17.
//  Copyright © 2017 archit. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

double pie(unsigned long);

int main(int argc, const char * argv[]) {

    time_t t;
    srand((unsigned)time(&t));
    unsigned long n;
    std::cout << "Enter n: ";
    std::cin >> n;
    
    double value = pie(n);
    std :: cout << "Value: " << value << std::endl;
    
    return 0;
}

double pie(unsigned long n) {
    
    double result = 0;
    double t = 0;
    double x, y;
    for(unsigned long i = 0; i < n; i++) {
        x = (double)rand() / (double) RAND_MAX;
        y = (double)rand() / (double) RAND_MAX;
        
        x = x*x;
        y = y*y;
            
        if(x+y <= 1) {
            t++;
        }
    }
    
    result = 4 * t/(double)n;
    return result;
}






