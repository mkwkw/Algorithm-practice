#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> dp;
    int t, n, answer = 0;

    cin>>t;

    //dp[i][1]: i를 표현하는 방식 중에 1로 끝나는 가짓수
    //dp[i][2]: i를 표현하는 방식 중에 2로 끝나는 가짓수
    //dp[i][3]: i를 표현하는 방식 중에 3로 끝나는 가짓수
    dp.assign(10001, vector<int>(4,0)); //

    dp[1][1] = 1; //1
    dp[2][1] = 1; //1+1 -> dp[1][1]
    dp[2][2] = 1; //2
    dp[3][1] = 1; //1+1+1 -> dp[2][1]
    dp[3][2] = 1; //1+2 -> dp[1][1]
    dp[3][3] = 1; //3 
    //dp[4][1] = 1; //1+1+1+1 -> dp[3][1]
    //dp[4][2] = 2; //1+1+2, 2+2 -> dp[2][1]+dp[2][2]
    //dp[4][3] = 1; //1+3 -> dp[1][1]
    
    
    for(int i=4; i<=10000; i++){
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1]+dp[i-2][2];
        dp[i][3] = dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
    }

    for(int i=0; i<t; i++){
        cin>>n;

        answer = 0;

        for(int j=1; j<=3; j++){
            answer += dp[n][j];
        }

        cout<<answer<<'\n';

    }
}