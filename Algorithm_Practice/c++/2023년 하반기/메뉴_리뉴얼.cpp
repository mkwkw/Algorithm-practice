#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

//정렬, 재귀
//orders의 원소 오름차순 정렬 필요
//result 배열 오름차순 정렬 필요
vector<string> answer;
vector<bool> visited;
vector<int> maxCnt; //인덱스(부분 문자열의 길이) 크기만큼의 부분 문자열 중 최대 등장 횟수
map<string, int> courseAndCnt;
//메뉴 조합 생성
void courseMenu(int idx, string order, int nowCnt, int totalCnt, string temp){
    if(idx>=order.length()){
        return;
    }
    
    if(nowCnt==totalCnt){
        //cout<<temp<<'\n';
        ++courseAndCnt[temp];
        maxCnt[totalCnt] = max(maxCnt[totalCnt], courseAndCnt[temp]);
        return;
    }
    
    visited[idx] = true;
    
    for(int i=idx; i<order.length(); i++){
        if(!visited[i]){
            visited[i] = true;
            courseMenu(i, order, nowCnt+1, totalCnt, temp+order[i]);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    maxCnt.assign(11, 0);
    
    //orders원소 오름차순 정렬
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());    
    }
    
        for(int j=0; j<orders.size(); j++){
            for(int k=2; k<=10; k++){
                if(orders[j].length()<k){
                    continue;
                }
                
                //메뉴 조합 생성
                for(int i=0; i<orders[j].length()-k+1; i++){
                    visited.assign(orders[j].length(), false);
                    courseMenu(i, orders[j], 1, k, orders[j].substr(i,1));       
                }
            }
            
        }
  
    
    //course[i]인 길이만큼의 메뉴 조합 고르기 (메뉴가 2개 이상인 조합)
    for(int i=0; i<course.size(); i++){
        for(auto m : courseAndCnt){
            //cout<<m.first<<' '<<m.second<<'\n';
            if(m.first.length()==course[i] && maxCnt[m.first.length()]==m.second && m.second>=2){
                answer.push_back(m.first);
            }
        }
    }
    
    //answer 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}