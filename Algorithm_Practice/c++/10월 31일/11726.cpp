#include <iostream>
#include <vector>

using namespace std;

int main(){
    //팩토리얼 이용하는 방법 - error - 10007으로 나누는 것 때문에 오류 발생
    
    // vector<long long> factorial(1005); //팩토리얼 때문에 dp 이용
    // int n;
    // long long result = 0;
    // factorial[0]=1;
    // factorial[1]=1;

    // for(int i=2; i<=1004; i++){
    //     if((factorial[i-1]*i)%10007!=0){
    //         factorial[i] = (factorial[i-1]*i)%10007; //여기에서 10007로 나누면 8! 값이 0이 뜸. 
    //     }
    //     else{
    //         factorial[i] = (factorial[i-1]*i);
    //     }
    // }
    // cout<<factorial[8]<<'\n';
    // cin>>n;

    // //result = 1;

    // for(int i=n; i>=0; i-=2){
    //     //2*1: i개, 1*2: (n-i)/2개 
    //     result += factorial[(n-i)/2+i]/(factorial[(n-i)/2]*factorial[i])%10007;
    //     result %= 10007;
    // }

    // cout<<result;

    vector<int> dp(1005);
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=n; i++){ //(n-1까지 있는 배열에 2*1 하나 추가= n-1까지의 배열 만드는 경우의 수) + (n-2까지 있는 배열에 1*2 두 개 추가 = n-2까지의 배열 만드는 경우의 수) 
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    }
    cout<<dp[n];
}