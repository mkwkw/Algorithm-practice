#include <string>
#include <vector>
#include <queue>
using namespace std;

//우선 순위 큐 - 기본적으로 오름차순
//예외처리
int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<>> pq;
    int answer = 0;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    //2개를 뽑아서 합쳐서 넣는 경우
    while(pq.size()>1 && pq.top()<K){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int newScoville = first+2*second;
        pq.push(newScoville);
        answer++;
    }
    
    //모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우: pq.size()가 1인데(끝까지 합쳤는데) 그 값이 K를 넘지 않는 경우
    if(pq.size()==1 && pq.top()<K){
        answer = -1;
    }
    
    return answer;
}