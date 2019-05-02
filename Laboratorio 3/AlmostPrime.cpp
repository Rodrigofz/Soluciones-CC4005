#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> criba(n+1, -1);

    for(int i=2; i<=n; i++){
        if(criba[i] == -1){
            for(int j=i+i; j<=n; j+=i){
                if(criba[j]==-1){
                    criba[j] = i;
                }
            }
        }
    }

    int izq=2;
    int der=n;
    while(criba[der]!=-1){
        der--;
    }
    int counter = 0;
    while(izq < der){
        if(izq*der > n){
            der--;
            while(criba[der]!=-1){
                der--;
            }
        }
        else if(izq*der == n){
            counter++;
            der--;
            while(criba[der]!=-1){
                der--;
            }
        }
        else if(izq*der<n){
            counter++;
            izq++;
            while(criba[izq]!=-1){
                izq++;
            }
        }
        
    }
    cout<<counter;   
}