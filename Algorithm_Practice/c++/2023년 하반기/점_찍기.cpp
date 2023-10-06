#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

//long long -> 시간 초과 주의
//이분 탐색
//1 - 0~d/k, d/k~0 하나하나 비교? -> 시간 초과
//2 - sqrt(i*i+j*j)<d/k인 j최댓값만 구하기? -> 시간 초과
//3 - j의 최댓값만 구할거면 이분탐색으로 찾으면 되겠다!
//    sqrt(i*i+j*j)<=d/k인 동안 left = mid+1;
//    최종 j구할 때 sqrt(i*i+mid*mid)>d/k이면 j=mid-1
long long solution(int k, int d) {
    long long answer = 0;
    
    //0~d/k
    for(int i=0; i<=d/k; i++){
        
        //이분 탐색
        //sqrt(i제곱+j제곱)<=d/k 만족하는 j최댓값 찾기
        int left = 0;
        int right = d/k;
        int mid;
        
        while(left<=right){
            mid = (left+right)/2;
            if(sqrt((long long)i*i+(long long)mid*mid)<=(double)d/k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        
        if(sqrt((long long)i*i+(long long)mid*mid)>(double)d/k){
            mid -= 1;
        }
        
        //cout<<i<<' '<<mid<<'\n';
        answer += mid+1;
    }
    
    return answer;
}