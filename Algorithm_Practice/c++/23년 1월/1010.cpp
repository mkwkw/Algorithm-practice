#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(30, vector<int>(30,0)); //[n][r] (nCr)

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;
    
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n>>m;
        
        //m개 중에 n개 뽑기
        
        //j개 중에 1개 뽑기 - 경우의 수:j
        for(int j=1; j<=m; j++){
            dp[j][1] = j;
        }

        //k개 중에 j개 뽑기 - nCr = n-1Cr-1+n-1Cr
        for(int j=2; j<=n; j++){
            for(int k=2; k<=m; k++){
                dp[k][j] = dp[k-1][j-1] + dp[k-1][j];
            }
        }

        cout<<dp[m][n]<<'\n';
    }
}

//조합, 시간초과 주의