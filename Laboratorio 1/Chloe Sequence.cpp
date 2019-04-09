#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long k;

    cin>>n>>k;

    int max = n;
    long long l = pow(2, n) - 1;

    long long A, B;
    
    A = 0; 
    B = l;
    
    long long pos = (B-A+1)/2;
    
    while(pos!=k){
        if(pos < k){
            A = pos + 1;
        }
        else{
            B = pos - 1;
        }
        max--;
        pos = A + (B-A+1)/2;
    }

    cout<<max;  
}

