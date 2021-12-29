#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci; //인덱스, 진도
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<ci> q;
  
    int n = progresses.size();
    
    for(int i=0; i<n; i++){
        q.push({i,progresses[i]});
    }
   
    while(!q.empty()){
        
        int res=0;
        ci pro;
        
        for(int i=0; i<n; i++){
            pro = q.front();
            q.pop();
            pro.second += speeds[pro.first];
            q.push(pro);
            //cout<<"큐에 있는 진도: "<<pro.second<<'\n';
        }
              
        
        pro = q.front();
        while(pro.second>=100){
            q.pop();
            n--;
            res++;
            //cout<<"나가는 진도: "<<pro.second<<'\n';
            if(q.empty()){
                break;
            }
            pro = q.front();
            
            
        }
        
        if(res!=0){
            //cout<<res<<'\n';
            answer.push_back(res);
            
            
        }
 
    }
    return answer;
}

int main(){
    vector<int> progresses = {93,30,55};
    vector<int> speeds = {1,30,5};

    vector<int> answer = solution(progresses, speeds);
    //cout<<answer.size();
    //cout<<"답\n";
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<< " ";
    }
}

/* 순서를 지켜서 진행하는 것이 중요하다. 앞의 것부터 먼저 내보내야하므로 큐를 사용한다.
1. 큐의 원소를 하나씩 pop하고 각 원소에 맞는 speeds를 더하고 다시 push한다. 
-> 100이 되어서 나갔을 때, 다음 턴을 돌 때 조건을 정하기 애매하다.

2. 큐의 원소를 for문을 이용해서 큐에 있는 원소의 총 개수(n)만큼 pop하고
speeds를 더하고 다시 큐에 push한다. n개를 묶어서 pop하고 push하는 느낌
장점: n개씩 묶어서 돌기 때문에 q.front()가 현재 있는 큐의 맨 앞 원소가 된다.
순서에 대한 조건을 걸지 않아도 자동으로 순서가 맞는다. 100이상이면 큐에서 나가며
나갈 때는 n의 개수를 하나 줄이고, 이번에 answer에 들어가는 개수를 나타내는 res를 하나씩 늘린다.  

*/