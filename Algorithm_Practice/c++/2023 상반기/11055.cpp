#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, answer=0;
    vector<int> num, dp; 

    cin>>n;

    num.assign(n,0);
    dp.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = num[i]; //부분 수열 최솟값 = 자기자신
        for(int j=0; j<i; j++){ //인덱스 i 이전 숫자 및 dp 탐색
            if(num[j]<num[i] && dp[i]<dp[j]+num[i]){ //이전에 있는 숫자가 num[i]보다 작은지 (증가하는 수열) && 지금 dp[i]값이 이전 숫자까지의 dp 각각 + num[i]보다 작다면 갱신(최대 합)  
                dp[i] = dp[j]+num[i];
            }
        }
        if(answer<dp[i]){ //최대합
            answer = dp[i];
        }
    }
    cout<<answer;
}