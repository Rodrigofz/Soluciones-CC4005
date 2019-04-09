#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    cin>>N>>Q;

    vector<int> ints(N);
    for(int i=0; i<N; i++){
        cin>>ints[i];
    }

    for(int i=0; i<Q; i++){
        int k;
        cin>>k;
        int A = 0;
        int B = N-1;
        while (A < B){
            int mid = A + (B - A)/2;
            if(ints[mid] >= k)
                B = mid;
            else
                A = mid + 1;
        }

        if (ints[A] != k){
            cout<<-1<<"\n";
        }
        else{
            while(ints[A-1]==k){
                A--; 
            }
            cout<<A<<"\n";
        }
        
        
    }

}

