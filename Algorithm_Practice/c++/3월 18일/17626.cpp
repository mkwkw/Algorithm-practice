#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> dp;
    int n, cnt=0;

    cin>>n;
    
    dp.assign(n+1,50000);

    dp[0]=0;
    dp[1]=1;

    for(int i=1; i<=n; i++){
        dp[i]=dp[1]+dp[i-1]; //하나 이전의 dp 값 +1

        for(int j=2; j*j<=i; j++){ //i보다 작은 제곱수가 있을 때
            dp[i]=min(dp[i], 1+dp[i-j*j]); //제곱수는 dp값이 1 + i에서 제곱수 뺀 dp값
        }
    }

    cout<<dp[n];

}