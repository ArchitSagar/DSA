#include <iostream>
using namespace std;

int passThePillow(int n, int time){
    int div = time / (n-1);
    int rem = time % (n-1);
    if(div % 2 == 0) return(rem + 1);
    else return(n - rem);
}

int main(){
    int n,t;
    cout << "enter n and time " << endl;
    cin >> n >> t;
    int ans = passThePillow(n,t);
    cout << "ans = " << ans << endl;
}