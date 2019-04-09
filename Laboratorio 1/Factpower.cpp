#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if (n==0 || n==1){
        return n;
    }
    else{
        return n * factorial(n-1);
    }

}

int main(){
    int t, a;
    cin>>t>>a;
    
    
    int B = 100;
    int A = 0;
    int mid = A + (B - A)/2;

    cout<<mid;
    
    long long fact = factorial(mid);
    long long pot = pow(a, mid);  

    cout<<fact<<"\n"<<pot;

    /*
    int B = 10000000;
    int A = 0;

    while (A < B){
        int mid = A + (B - A)/2;
        int fact = factorial(mid);
        int pot = pow(a, mid);  
        if(fact > pot){
            B = mid;
        }
        else{
            A = mid + 1;
        }    
    }
    */
}