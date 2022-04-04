#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, answer=0;
    vector<int> dp(11);
    
    cin>>n;

    dp[0]=0;
    dp[1]=0;
    for(int i=2; i<=10; i++){
        dp[i]=i;
    }

    for(int i=2; i<=10; i++){
        dp[i]=(i/2)*(i-i/2);
        dp[i]+=dp[i/2]+dp[i-i/2];
    }

    cout<<dp[n];
}

//만약 n=5 이면 2와 3으로 나누어 2*3을 한다음, dp[5]에 dp[2]+dp[3]을 더한다.