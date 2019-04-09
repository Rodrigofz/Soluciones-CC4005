#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int> largos(k);
    int maximo[k];
    int indices[k][k];
    for(int i=0; i<k; i++){
        int n;
        cin>>n;
        int potencial_lista=-1;
        int potencial_largo=0;
        for(int j=0; j<i; j++){
            if(maximo[j]+1 == n){
                if(largos[j]>=potencial_largo){
                    potencial_largo = largos[j];
                    potencial_lista = j;
                }
            }
        }
        if(potencial_lista!=-1){
            largos[i] = potencial_largo + 1;
            maximo[i] = n;
            for(int j=0; j<potencial_largo; j++){
                indices[i][j] = indices[potencial_lista][j];
            }
            indices[i][potencial_largo] = i;
        }
        else{
            maximo[i] = n;
            indices[i][0] = i;
            largos[i] = 1;
        }
    }
    int largo_maximo = 0;
    int indice_elegido = -1;
    for(int i=0; i<k; i++){
        if(largos[i] > largo_maximo){
            largo_maximo = largos[i];
            indice_elegido = i;
        }
    }
    cout<<largo_maximo<<"\n";
    for(int i=0; i<largo_maximo; i++){
        cout<<indices[indice_elegido][i]+1<<" ";
    }
}