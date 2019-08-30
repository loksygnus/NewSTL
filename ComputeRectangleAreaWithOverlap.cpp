#include <iostream>

using namespace std;
   
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {   
        
         int overlap_w = 0;
        int overlap_h = 0;
        int overlap_Area = 0;
        
        long long int  Total_Area;
        
        long double temp = 0.0;
        
        if ( abs(C - A) > INT_MAX - abs(D - B) )
        {
            return INT_MAX;
        }
 
        if ( abs(G - E) > INT_MAX - abs(H - F) )
        {
            return INT_MAX;
        }
        
        int Area1 = abs((C - A) * (D - B));
        int Area2 = abs((G - E) * (H - F));
        
        if ((A == E) && (B == F) && (C == G) && (D == H))
        {
            return Area1;
        }
        
        if (((E >= C) || (A >= G)) || ((F >= D) || (B >= H)))
        {
            /*No overlap*/
            return Area1 + Area2;
        }
        
        if ( abs(min(C, G)) > INT_MAX - abs(max(A, E)) )
        {
            return INT_MAX;
        }
        
        if ( abs(min(D, H)) > INT_MAX - abs(max(B, F)) )
        {
            return INT_MAX;
        }
        
        overlap_w = abs( min(C, G) - max(A, E) );
        overlap_h = abs( min(D, H) - max(B, F) );
        
        overlap_Area = overlap_w * overlap_h;
        
        temp = (double)Area1 + (double)Area2;
        
        Total_Area = (int) temp;
        
        if (Total_Area > INT_MAX)
        {
            return INT_MAX;
        }
        else
        {
            
            return Total_Area - overlap_Area;
        }
     
    }

int main()
{
    cout<<"Given two rectangles may or may-not overlap , then calculate the total area (rectlinear)"<<endl;
    cout<<computeArea(-2, -2, 2, 2, 3, 3, 4, 4)<<endl;

    return 0;
}