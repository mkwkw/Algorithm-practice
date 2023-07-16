#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//progresses, speeds를 각각 큐에 넣고
//progresses큐의 front + speeds큐의 front*day가 100이상이 될 때까지의 day를 계산한다.
//progresses큐의 front + speeds큐의 front*day가 100이상인 경우 모두 큐에서 pop하고 그 개수를 센다. 그 개수를 answer 벡터에 넣는다.
//큐는 empty인 경우 pop하거나 front 조회하지 않도록 주의!
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progressesQue, speedsQue;
    
    int day = 0;
    
    for(int i=0; i<progresses.size(); i++){
        progressesQue.push(progresses[i]);
        speedsQue.push(speeds[i]);
    }
    
    while(!progressesQue.empty()){
        int cnt = 0;
        while(progressesQue.front()+speedsQue.front()*day<100){
            ++day;
        }
        
        while(!progressesQue.empty() && progressesQue.front()+speedsQue.front()*day>=100){
            progressesQue.pop();
            speedsQue.pop();
            ++cnt;
        }
        
        //cout<<day<<' '<<cnt<<'\n';
        answer.push_back(cnt);
    }
    
    return answer;
}