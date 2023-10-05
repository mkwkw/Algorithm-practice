#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

//힙
//우선순위 큐 - priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> - 오름차순 정렬
//작업 요청 시간, 작업 소요 시간
//1. 작업 요청 시간 순대로 정렬
//2. 작업 요청 시간에 작업중이면, 겹치는 작업 다 빼고 그 중에 소요 시간 제일 작은 것만 작업. 그리고 남은 건 다시 다 우선순위 큐에 넣기
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}


int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //오름차순 정렬
    int answer = 0;
    int endTime = -1;
    
    for(int i=0; i<jobs.size(); i++){
        pq.push({jobs[i][0], jobs[i][1]});    
    }

    //cout<<pq.top().first<<' '<<pq.top().second<<'\n';
    
    while(!pq.empty()){
        //작업 중이지 않을 때, 작업이 들어오면 바로 시행
        if(endTime<=pq.top().first){
            endTime = pq.top().first+pq.top().second;
            answer += pq.top().second;
            pq.pop();
        }
        else{ //작업 중일 때랑 작업 요청 시점이 다를 때
            vector<pair<int,int>> waiting;
            while(!pq.empty() && pq.top().first<endTime){
                waiting.push_back(pq.top());
                pq.pop();
            }
            //작업 소요시간 오름차순으로 정렬 - pq 자동 정렬
            sort(waiting.begin(), waiting.end(), comp);
            
            //작업 시간 겹치는 것 중에 작업 소요 시간 가장 작은 것 하나만 작업하고
            endTime += waiting[0].second;
            answer += endTime-waiting[0].first;
            
            //나머지 다시 pq에 넣기
            for(int i=1; i<waiting.size(); i++){
                pq.push(waiting[i]);
            }
        }
    }
    
    return answer/jobs.size();
}