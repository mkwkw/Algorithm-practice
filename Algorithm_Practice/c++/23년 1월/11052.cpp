#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> price;

    cin>>n;

    price.assign(n+1, 0);
    vector<int> dp(n+1, 0);

    for(int i=1; i<n+1; i++){
        cin>>price[i];
    }    

    

    //1개: P1
    //2개: max(P2, (P1)+P1)
    //3개: max(P3, (P1+P1)+P1, (P2)+P1)
    //4개: max(P4, (P3)+P1, (P1+P1+P1)+P1, (P2+P1)+P1, (P2)+P2)
    //5개: max(P5, (P4)+P1, (P3+P1)+P1, (P1+P1+P1+P1)+P1, (P2+P1+P1)+P1, (P2+P2)+P1, (P3)+P2, (P1+P1+P1)+P2, (P2+P1)+P2, (P2)+P3, (P1+P1)+P3, (P1)+P4)

    dp[0]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j]+price[j]); //ex. dp[4] = dp[0]+price[4], dp[1]+price[3], dp[2]+price[2] 중에 가장 큰 값
        }
    }

    cout<<dp[n];    
    
}