#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int qx, qy;
    int kx, ky;
    int fx, fy;

    cin>>N>>qx>>qy>>kx>>ky>>fx>>fy;

    if((kx<qx && fx<qx) || (kx>qx && fx>qx)){
        if((ky<qy && fy<qy) || (ky>qy && fy>qy)){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}