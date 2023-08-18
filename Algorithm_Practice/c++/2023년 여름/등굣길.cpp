#include <string>
#include <vector>
#include <iostream>

using namespace std;

//dp
//dp[i][j]=dp[i-1][j]+dp[i][j-1]
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp;
    
    dp.assign(n, vector<int>(m,0));

    for(int i=0; i<puddles.size(); i++){
        dp[puddles[i][1]-1][puddles[i][0]-1] = -1; //puddle 표시    
    }
    
    for(int i=1; i<m; i++){
        if(dp[0][i]!=-1){
            dp[0][i]=1;
        }
        else{
            break;
        }
    }
    
    for(int i=1; i<n; i++){
        if(dp[i][0]!=-1){
            dp[i][0]=1;
        }
        else{
            break;
        }
    }
    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(dp[i][j]==-1){
                continue;
            }
            
            int up = max(0, dp[i-1][j]);
            int left = max(0, dp[i][j-1]);
            
            dp[i][j] = (up+left)%1000000007;
        }
    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    answer = dp[n-1][m-1];
    
    return answer;
}