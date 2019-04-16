#include <bits/stdc++.h>
using namespace std;

int main(){
    for(;;){
        int M, N;
        cin>>M>>N;
        if(M==0 and N==0){
            break;
        }
        vector<int> mejores(M+1);
        mejores[0] = 0;
        for(int i=1; i<=M; i++){
            vector<int> dpfila(N+1);
            dpfila[0]=0;
            for(int j=1; j<=N; j++){
                int candy;
                cin>>candy;
                if(j==1){
                    dpfila[j]=candy;
                }
                else{
                    dpfila[j]=max(dpfila[j-1], dpfila[j-2]+candy);
                }
            mejores[i]=dpfila[N];
            }
        }
        vector<int> dptotal(M+1);
        for(int i=1; i<=M; i++){
            if(i==1){
                dptotal[i]=mejores[i];
            }
            else{
                dptotal[i]=max(dptotal[i-1], dptotal[i-2]+mejores[i]);
            }
        }
        cout<<dptotal[M]<<"\n";

    }
}