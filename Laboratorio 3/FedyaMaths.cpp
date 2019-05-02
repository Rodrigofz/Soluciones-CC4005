#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    getline(cin, n);
    int x = 1; //Resto de 2
    int y = 1; //Resto de 3
    int z = 1; //Resto de 4
    for(int i=0; i<n.length(); i++){
        x = ((int)pow(x,10)%5 * (int)pow(2, n[i] - '0')%5)%5;
        y = ((int)pow(y, 10)%5 * (int)pow(3, n[i] - '0')%5)%5;
        z = ((int)pow(z, 10)%5 * (int)pow(4, n[i] - '0')%5)%5;
    }
    int r = (1 + x + y + z)%5;
    cout<<r;
}
