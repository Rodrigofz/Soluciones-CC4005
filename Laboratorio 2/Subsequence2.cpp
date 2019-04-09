#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int> subsecuencia(k);
    vector<int> maximo(k, -1);
    vector<int> largo(k);
    int actual = 0;
    for(int i=0; i<k; i++){
        int n;
        cin>>n;
        
        if(maximo[n-1] != -1){
            subsecuencia[i] = maximo[n-1];
            largo[maximo[n-1]]++;
            maximo[n]=maximo[n-1];
            maximo[n-1]=-2;
        }
        
        else{
            subsecuencia[i] = actual;
            maximo[n] = actual;
            largo[actual] = 1;
            actual++;
        }
    }
    int maximo_largo = 0;
    int ss = -1; 
    for(int i=0; i<actual; i++){
        if(largo[i] > maximo_largo){
            maximo_largo = largo[i];
            ss = i;
        }
    }
    if(maximo_largo == 0){
        cout<<1<<"\n";
        cout<<1<<" ";
        return 1;
    }
    cout<<maximo_largo<<"\n";
    for(int i=0; i<k; i++){
        if(subsecuencia[i] == ss){
            cout<<i+1<<" ";
        }
    }
}