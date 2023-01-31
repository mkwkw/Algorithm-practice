#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(30, vector<int>(30,0)); //[n][r] (nCr)

int combination(int n, int r){
    
    if(dp[n][r]>0){
        return dp[n][r];
    }
    if(r==0 || r==n){
        dp[n][r]=1;
        return dp[n][r];
    }

    //nCr = n-1Cr-1 + n-1Cr
    return combination(n-1, r-1)+combination(n-1, r);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    int t, n, m;
    
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n>>m;
        
        //m개 중에 n개 뽑기
        cout<<combination(m,n)<<'\n';
    }
}

//조합