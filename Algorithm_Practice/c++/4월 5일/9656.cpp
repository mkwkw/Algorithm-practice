#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    vector<int> dp(1001); //인덱스를 만드는데 필요한 돌 개수
    cin>>n;

    /* 이런 식의 dp 활용을 의도한 것 같음. 
    i-1까지하고 1개 더 가져가는 것과 i-3까지하고 3개 더 가져가는 것 비교
    dp[0]=0;
    dp[1]=1; //1
    dp[2]=2; //1+1
    dp[3]=1; //3
    for(int i=4; i<1001; i++){
        dp[i] = min(dp[i-1]+dp[1], dp[i-3]+dp[3]);
    }*/

    //하지만 1,3의 합이므로 짝수개 더하면 짝수, 홀수개 더하면 홀수이다.
    //즉, n이 홀수일때는 CY, 짝수일땐는 SK 번갈아서 나온다. 
    if(n%2==0){
        cout<<"SK";
    }
    else{
        cout<<"CY";
    }

}