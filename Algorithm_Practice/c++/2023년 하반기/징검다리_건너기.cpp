#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//범위 -> 최적의 값 구하기 -> 이분탐색!
//돌의 무게 == 건널 수 있는 사람 수
//돌의 무게에 따라 연속된 건널 수 없는 징검다리 수(k이하) 구하기
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = *min_element(stones.begin(), stones.end());
    int right = *max_element(stones.begin(), stones.end());
    int mid, skipCount, maxSkipCount;
    
    while(left<=right){
        mid = (left+right)/2;
        
        vector<int> tmp(stones);
        
        maxSkipCount = 0; //최대 연속 건널 수 없는 징검다리 개수 
        skipCount = 0; //연속 건널 수 없는 징검다리 개수
        //연속된 건널 수 없는 징검다리 개수 구하기
        for(int i=0; i<tmp.size(); i++){
            tmp[i] -= mid;
            if(tmp[i]<0){
                skipCount++;
            }
            else{
                skipCount = 0;
            }
            maxSkipCount = max(maxSkipCount, skipCount);
        }
        
        if(maxSkipCount<k){ //연속 최대 건널 수 없는 징검다리 수가 k보다 적다 -> 돌의 무게를 더 늘려서 사람이 더 많이 건너도록 한다.
            answer = max(answer,mid);
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    
    return answer;
}

//while+for 반복문 - 3중 반복문 - 시간초과! (정확성 테스트케이스는 다 맞음)
// int solution(vector<int> stones, int k) {
//     int answer = 0;
    
//     while(true){
//         int pos = -1; //시작 지점
//         //cout<<pos<<' '<<stones.size()<<'\n';
//         while(pos<(long long)stones.size()){
//             cout<<"pos"<<pos<<'\n';
//             bool flag = true;
//             for(int j=1; j<=k; j++){
//                 if(pos+j<stones.size() && stones[pos+j]>0){
//                     stones[pos+j] -= 1;
//                     pos = pos+j;
//                     flag = false;
//                     break;
//                 }
//                 if(pos+j>=stones.size()){ //다리를 다 건넜을 때
//                     pos = pos+j;
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag){
//                 return answer;
//             }
//         }
//         answer++;
//     }
//     return answer;
// }

int main(){
    int answer;
    vector<int> v = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    answer = solution(v,3);
    cout<<answer;
}