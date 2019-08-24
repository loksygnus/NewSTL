//
//  main.cpp
//  CPPPractice
//
//  Created by Lok……The Invincible…. on 11/08/19.
//  Copyright © 2019 Lokesh. All rights reserved.
//

#include <iostream>
// #include <cstdlib>
#include <sstream>
// #include <bits/stdc++.h>
#include <vector>

using namespace std;

double find_median(vector<int>& A, vector<int>& B)
{
    unsigned int min_index, max_index, i, j, m, n;
    int left_val = 0, right_val = 0, total_size;
    bool is_deduced = 0;
    
    m = (unsigned)A.size();
    n = (unsigned)B.size();
    
    if (m > n)
    {
        return find_median(B, A);
    }

    if ((m == 0) && (n == 0))
    {
        return 0.0;
    }
    
    min_index = 0;
    max_index = m;
    
    i = (min_index + max_index)/2;
    j = (m + n + 1)/2 - i;
    
    total_size = m + n;
    
    if (m == 0)
    {
        left_val  = B[j-1];
        right_val = B[j];
    }
    
    while(min_index < max_index)
    {
        if ((i > 1) && (A[i - 1] > B[j]))
        {
            max_index = i;
            i = (min_index + max_index)/2;
            j = (m + n + 1)/2 - i;
            continue;
        }
        else if (B[j - 1] > A[i])
        {
            min_index = i + 1;
            i = (min_index + max_index)/2;
            j = (m + n + 1)/2 - i;
            continue;
        }
        else
        {
            left_val = max(A[i - 1], B[j - 1]);
            right_val = min(A[i], B[j]);
            is_deduced = 1;
            break;
        }
    }
    
    if (is_deduced == 0)
    {
        if ((i >= 1) && (j >= 1))
        {
           left_val = max(A[i - 1], B[j - 1]);
        }
        if ((i < max_index) && (j >= 0))
        {
            right_val = min(A[i], B[j]);
        }
        else
        {
            right_val = B[j];
        }
    }
    
    if (total_size & 1)
    {
        return (double)left_val;
    }
    else
    {
        return (double)(left_val + right_val)/2.0;
    }
    
    return 0.0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World! , this is my first xcode program...\n";
    vector <int> listA{1, 3}; //{ 67}; //, 98, 100, 113, 280, 980};
    vector <int> listB{2}; //{ 4, 59, 76, 84, 105, 124, 139, 156, 292}; //, 1240};
    
    double median = find_median(listB, listA);
    
    cout<<"Calculated median: "<<median<<endl;
    
    // string digit("345783");
    // stringstream num(digit);
    
    
    
    
    return 0;
}
