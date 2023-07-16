#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//priority queue이용 pair<우선순위, 인덱스> - 큰 우선순위가 top에 가도록
//priority queue의 top보다 우선순위가 작으면 pop하고 뒤로 보내기
//priority queue의 top과 우선순위가 같으면 pop, 인덱스 넣은 idxQue에서도 pop - ++answer
//priority queue의 top의 인덱스와 location이 같다면 answer return
int solution(vector<int> priorities, int location) {
    priority_queue<pair<int,int>> priorityAndIdx;
    queue<int> idxQue;
    int answer = 0;
    
    for(int i=0; i<priorities.size(); i++){
        priorityAndIdx.push({priorities[i], i});
        idxQue.push(i);
    }
    
    while(!idxQue.empty()){
        //cout<<priorities[idxQue.front()]<<' '<<priorityAndIdx.top().first<<'\n';
        while(priorities[idxQue.front()]<priorityAndIdx.top().first){
            int f = idxQue.front();
            idxQue.pop();
            idxQue.push(f);
        }
        
        ++answer;
        
        if(idxQue.front()==location){
            break;
        }
        
        priorityAndIdx.pop();
        idxQue.pop();
        
    }
    
    return answer;
}