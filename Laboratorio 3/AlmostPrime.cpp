#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> criba(n+1, -1);

    for(int i=2; i<=n; i++){
        if(criba[i] == -1){
            for(int j=i+i; j<=n; j+=i){
                if(criba[j]==-1)
                    criba[j] = i;
            }
        }
    }

    int looked = n;
    int count = 0;

    while(looked >= 2){
        int pot_factor = looked;
        vector<int> factors(3,-1);
        while(pot_factor >= 1){
            int val_to_save = criba[pot_factor];
            if(val_to_save==-1){
                val_to_save = pot_factor;
            }

            for(int i=0; i<3; i++){
                if(factors[i] == val_to_save){
                    break;
                }
                if(factors[i]==-1){
                    factors[i] = val_to_save;
                    break;
                }
            }
            if(criba[pot_factor] == -1)
                break;
            pot_factor = pot_factor/criba[pot_factor];
        }
        if(factors[1]!=-1 && factors[2]==-1)
            count++;
        looked--;
    }
    cout<<count;
}