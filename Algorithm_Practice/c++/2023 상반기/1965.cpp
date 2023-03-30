#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, answer=0;
    vector<int> box, dp;

    cin>>n;

    box.assign(n, 0);
    dp.assign(n, 0); //해당 인덱스까지 상자 개수

    for(int i=0; i<n; i++){
        cin>>box[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(box[j]<box[i] && dp[j]+1>dp[i]){ //이전 상자 크기 비교 및 이전 상자 개수 비교
                dp[i] = dp[j]+1;
            }
        }
        answer = max(answer, dp[i]); 
    }

    cout<<answer; //그냥 dp[n-1] 값을 출력하면 {1,2,3,1} 이런 식으로 주어질 때 정답인 3이 아니라 1로 출력됨.

}