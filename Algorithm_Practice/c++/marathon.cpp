#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer="";
    int n = participant.size();
    queue<string> q;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<n; i++){
        q.push(participant[i]);
    }
    
    for(int i=0; i<n-1; i++){
        if(completion[i]==q.front()){
            q.pop();
        }
        else{
            break;
        }
    }
    answer = q.front();  
    
    
    return answer;
}

/* 프로그래머스- 고득점kit - 해시 - 완주하지 못한 선수-Level1
1. 처음엔 키가 문자열이면 될 것 같아서 map을 생각하였으나 참가자 중에 동명이인이 있을 수 있으므로
map 사용은 안된다는 것을 알았다. map은 중복이 안된다.
2. 벡터를 사용하려고 시도했더니 역시나 우려했던대로 시간초과가 나서 효율성에서 실패가 떴다.
3. 어떻게 하면 빠르게 할 수 있을까 생각을 해봤다. 이 문제의 특성상 participant 벡터의 크기와 completion 벡터의 크기 차이가 1이고
answer값도 하나이므로 알파벳 순서대로 각 벡터를 정렬하고 participant벡터에 있던 것을 큐에 push하여
completion벡터를 순차적으로 탐색하면서 해당 인덱스의 값이 큐의 맨앞의 원소와 같은지 비교하였다.
같으면 pop한다. 같지 않으면 바로 이 선수가 completion에 없는 선수이므로 답이다. 
answer에 이 선수 이름 저장하고 바로 break하고 answer를 리턴한다.

*/