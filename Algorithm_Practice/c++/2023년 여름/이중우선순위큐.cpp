#include <string>
#include <vector>
#include <string>
#include <queue>

using namespace std;

//양 끝단에서 최솟값, 최댓값 삭제 -> 우선순위 큐 이용
//명령어(D, I)와 숫자 구분하기 -> substr 사용
//우선순위 큐 - 기본: 내림차순
//"D -1" 들어왔을 때만 tmp 우선순위 큐(오름차순 정렬)에 pq 우선순위 큐(내림차순 정렬) 원소 다 넣고 최솟값 지우고 다시 pq에 넣기
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    
    answer.assign(2,0);
    
    for(int i=0; i<operations.size(); i++){
        char cmd = operations[i][0];
        int num = stoi(operations[i].substr(2));
        
        if(cmd=='I'){
            pq.push(num);
        }
        else{
            if(pq.empty()){
                continue;
            }
            
            if(num == 1){ //최댓값 빼기
                pq.pop();
            }
            else if(num == -1){
                priority_queue<int, vector<int>, greater<int>> tmp;
                
                while(!pq.empty()){
                    tmp.push(pq.top());
                    pq.pop();
                }
                
                if(!tmp.empty()){
                    tmp.pop();
                }
                
                if(tmp.empty()){
                    while(!pq.empty()){
                        pq.pop();
                    }
                    continue;    
                }
                
                while(!tmp.empty()){
                    pq.push(tmp.top());
                    tmp.pop();
                }
                
            }
        }
    }
    
    if(!pq.empty()){
        int minNum = 1000000;
        answer[0] = pq.top();
        
        while(!pq.empty()){
            minNum = pq.top();
            pq.pop();
        }
        
        answer[1] = minNum;
    }
    
    return answer;
}