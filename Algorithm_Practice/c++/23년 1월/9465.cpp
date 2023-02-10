#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n;
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n;
        vector<vector<int>> stickers, dp;

        stickers.assign(2, vector<int>(n,0));
        dp.assign(2, vector<int>(n,0));
        
        for(int j=0; j<2; j++){
            for(int k=0; k<n; k++){
                cin>>stickers[j][k];
            }
        }

        dp[0][0] = stickers[0][0];
        dp[1][0] = stickers[1][0];

        if(n>1){
            dp[0][1] = dp[1][0]+stickers[0][1];
            dp[1][1] = dp[0][0]+stickers[1][1];
        }

        for(int j=2; j<n; j++){
            dp[0][j] = max(dp[1][j-1]+stickers[0][j], dp[1][j-2]+stickers[0][j]); 
            dp[1][j] = max(dp[0][j-1]+stickers[1][j], dp[0][j-2]+stickers[1][j]);
        }

        cout<<max(dp[0][n-1], dp[1][n-1])<<'\n';

    }

}

//dp
//max(대각선 한 개 위/아래(이전 값) + sticker, 대각선 두 개 위/아래(이전 값) + sticker) 