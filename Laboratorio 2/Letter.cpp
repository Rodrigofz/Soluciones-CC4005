#include <bits/stdc++.h>
using namespace std;

int main(){
    string letters;
    getline(cin, letters);
    vector<int> bloques(letters.length());

    int f=1;
    if(islower(letters[0])){
        f=0;
    }

    int sum=0;
    int k=0;
    for(int i=0; i<letters.length(); i++){
        sum++;
        if((islower(letters[i]) && isupper(letters[i+1])) || (isupper(letters[i]) && islower(letters[i+1]))){
            bloques[k] = sum;
            k++;
            sum=0;
        }
    }
    bloques[k] = sum;
    k++;
    sum=0;

    int costos[2][k+1];
    for(int i=0; i<k; i++){
        if(i==0){
            costos[0][i]=bloques[i];
            costos[1][i]=0;
        }
        else if(i==1){
            costos[0][i]=bloques[i];
            if(f==0){
               costos[1][i] = costos[0][i-1];
            }
            else{
                costos[1][i] = 0;
            }
        }
        else{
            if((f==0 && i%2==0) or (f==1 && i%2==1)){
                costos[0][i]=max(costos[0][i-2], costos[1][i-2]) + bloques[i];
                costos[1][i]=min(costos[0][i-1], costos[1][i-1]);
            }
            else{
                costos[0][i]=min(costos[0][i-2], costos[1][i-2]) + bloques[i];
                costos[1][i]=max(costos[0][i-1], costos[1][i-1]);
            }
        }
    }
    cout<<min(costos[0][k-1], costos[1][k-1]);
}