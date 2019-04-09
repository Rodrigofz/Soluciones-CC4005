#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for (int k=0; k<T; k++){
        int r, c;
        cin>>r>>c;
        long long camara[r][c];
        long long count = 0;
        if(c==1){
            for(int i=0; i<r; i++){
                int piedras;
                cin>>piedras;
                count += piedras;
            }
        }
        else{
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    long long piedras;
                    cin>>piedras;
                    if (i==0){
                        camara[i][j] = piedras;
                    }
                    else if(j==0){
                        camara[i][j] = max(camara[i-1][j] + piedras, camara[i-1][j+1] + piedras);
                    }
                    else if(j==c-1){
                        camara[i][j] = max(camara[i-1][j] + piedras, camara[i-1][j-1] + piedras);
                    }
                    else{
                        camara[i][j] = max(camara[i-1][j] + piedras,max(camara[i-1][j+1] + piedras, camara[i-1][j-1] + piedras));
                    }
                }
            }
        }
        
        long long stonest = 0;
        for(int i=0; i<c; i++){
            stonest = max(stonest, camara[r-1][i]);
        }
        if(c==1){
            stonest=count;
        }
        cout<<stonest<<"\n";
    }
    
    
}