#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//정렬, 투 포인터
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    //0점인 경우 - A보다 큰 수가 하나도 없을 때
    //아닌 경우 나누기
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    //0점인 경우 - A의 최댓값이 B의 최솟값보다 같거나 작은 경우
    if(A[A.size()-1]<=B[0]){
        return 0;
    }
    
    int AIdx = 0, BIdx = 0; //투 포인터
    while(AIdx<A.size() && BIdx<B.size()){
        if(A[AIdx]>=B[BIdx]){
            BIdx++;
        }
        else{
            AIdx++;
            BIdx++;
            answer++;
        }
    }
    
    return answer;
}