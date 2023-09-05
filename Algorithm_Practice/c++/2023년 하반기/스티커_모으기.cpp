#include <iostream>
#include <vector>
using namespace std;

//dp
//점화식
//max(이전 값, 전전 값+나)
int solution(vector<int> sticker)
{
    int answer =0;
    vector<int> dp, dp1;
    
    //0번째 스티커 선택 -> 마지막 스티커 선택 불가
    dp.assign(sticker.size(), 0);
    
    dp[0] = sticker[0];
    if(sticker.size()==1){
        return dp[0];
    }
    
    dp[1] = max(dp[0], sticker[1]);
    for(int i=2; i<sticker.size()-1; i++){
        dp[i] = max(dp[i-1], dp[i-2]+sticker[i]);
    }
    
    //1번째 스티커 선택 -> 마지막 스티커 선택 가능
    dp1.assign(sticker.size(), 0);
    dp1[1] = sticker[1];
    for(int i=2; i<sticker.size(); i++){
        dp1[i] = max(dp1[i-1], dp1[i-2]+sticker[i]);
    }

    //0번째 스티커 선택한 경우의 마지막 값과 1번째 스티커 선택한 경우의 마지막 값 중에 큰 값 고르기
    answer = max(dp[sticker.size()-2], dp1[sticker.size()-1]);
    
    return answer;
}