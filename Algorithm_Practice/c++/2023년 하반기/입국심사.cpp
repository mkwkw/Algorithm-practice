#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

//이분 탐색
//주의! long long의 대상은 전체 소요 시간
//심사관을 이분탐색 대상으로 보지 말고, 전체 소요 시간을 이분탐색 대상으로 보기!
//mid보다 더 짧은 시간동안 n명을 입국심사할수도 있으니, 그 점도 유의하기
long long solution(int n, vector<int> times) {
    long long answer = (long long)pow(10,18);
        
    //이분 탐색 범위 -> 심사관이 걸리는 시간말고, 전체 시간!
    long long left = 1; //최소 시간
    long long right = (long long)pow(10,18); //최대 시간
    long long mid, totalCnt;
    while(left<=right){
        mid = (left+right)/2;
        
        totalCnt = 0; //mid시간에 입국 심사 받을 수 있는 전체 인원
        for(int i=0; i<times.size(); i++){
            totalCnt += (long long)mid/(long long)times[i];
        }
        
        if(totalCnt<n){
            left = mid+1;
        }
        else{
            answer = min(answer, mid); //totalCnt>=n이어도, 더 작은 mid를 찾을 수 있음.
            right = mid-1;
        }
    }
    
    return answer;
}