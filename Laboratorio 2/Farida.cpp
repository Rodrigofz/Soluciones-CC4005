#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    for (int i=0; i<k; i++){
        int N;
        cin>>N;
        vector<long long> oros(N);

        for(int j=0; j<N; j++){
            long long g;
            cin>>g;
            if(j==0){
                oros[j]=g;
            }
            else if(j==1){
                oros[j]=max(oros[j-1], g);
            }
            else{
                oros[j]=max(oros[j-1], oros[j-2]+g);
            }
        }
        if (N!=0){
            cout<<"Case "<<i+1<<": "<<oros[N-1]<<"\n";
        }
        else{
            cout<<"Case "<<i+1<<": "<<0<<"\n";
        }
        
    }
}