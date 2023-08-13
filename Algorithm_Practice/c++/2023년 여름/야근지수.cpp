#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//최대 힙 - 우선순위 큐
//제곱의 합이 최소가 되려면, 큰 작업량에서 많이 깎아야한다. - 작은 작업량에서 많이 깎이면 안된다.
//우선순위 큐를 이용하여 가장 큰 작업량을 pop하고 1씩 뺀 다음 다시 우선순위 큐에 넣는다.
//이렇게 하면 매번 가장 큰 작업량에서 1씩 빠지게 할 수 있다. - (가장) 작은 작업량에 연산이 들어가지 않게 된다.
long long solution(int n, vector<int> works) {
    long long answer = 0, totalSum = 0;
    priority_queue<int> pq;
    
    for(int i=0; i<works.size(); i++){
        totalSum += (long long) works[i];
        pq.push(works[i]);
    }
    
    if(totalSum<=n){
        return 0;
    }
    
    //works>n
    
    for(int i=0; i<n; i++){
        int biggestNum = pq.top();
        biggestNum -= 1;
        pq.pop();
        pq.push(biggestNum);
    }
    
    while(!pq.empty()){
        answer += (long long) pq.top()*pq.top();
        pq.pop();
    }
    
    return answer;
}