#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<long long> dp(5001, 0);
    int t = 0;
    int l = 0;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for(int i=4; i<=5000; i+=2)
    {
        dp[i] = dp[2]*dp[i-2];
        //cout<<"dp["<<i<<"]="<<dp[i]<<"="<<dp[2]<<' '<<dp[i-2]<<'\n';
        
        for(int j=2; j<=i-2; j+=2)
        {
            dp[i] += dp[j]*dp[i-(j+2)];
            //cout<<"dp["<<i<<"]="<<dp[i]<<'\n';
            dp[i] = (dp[i])%1000000007;
        }
        
    }

    cin>>t;
    for(int k=0; k<t; k++){
        cin>>l;

        cout<<dp[l]<<'\n';
    }

}