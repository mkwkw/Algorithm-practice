#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

//우선순위 큐
//적의 수 내림차순으로 정렬 후, 상위 k개의 라운드에 무적권 부여
//규칙대로 단계 진행 후, 끝났을 때, k개의 무적권 다 썼는지 남았는지 확인
//무적권이 남았다면, 지금까지 진행한 라운드+바로 다음 라운드 중에서 최댓값 찾아서 무적권 부여
//87.5점 - 테스트케이스 3,6,7,9 시간 초과
struct Info{
    int enemySum;
    int kCnt;
    int roundCnt;
};

Info fight(int n, vector<int> &enemy, vector<bool> &skill){
    int enemySum = 0;
    int kCnt = 0;
    int roundCnt = 0;
    for(int i=0; i<enemy.size(); i++){
        
        if(!skill[i])
            enemySum += enemy[i];
        else
            kCnt++;
        
        if(n<enemySum){
            break;
        }
        else{
            roundCnt++;
        }
    }
    
    return {enemySum, kCnt, roundCnt};
}

//적의 수가 많은 라운드에서 무적권을 쓰는 것이 좋음.
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
        
    //무적권의 개수>=라운드 수 -> 모든 라운드 통과
    if(k>=enemy.size()){
        return enemy.size();
    }
    
    //n의 수 >= enemy 총합 -> 모든 라운드 통과
    long long totalEnemy = 0;
    for(int i=0; i<enemy.size(); i++){
        totalEnemy += (long long)enemy[i];
    }
    if((long long)n >= totalEnemy){
        return enemy.size();
    }
    
    //무적권의 개수<라운드 수
    //무적권부여하기 위하여 적의 수 내림차순 정렬 필요
    priority_queue<pair<int,int>> enemyPQ;
    for(int i=0; i<enemy.size(); i++){
        enemyPQ.push({enemy[i], i});
    }
    
    vector<bool> skill; //무적권 적용할 라운드 표시
    skill.assign(enemy.size(), false);
    
    //최대 적 수 순서대로 k개 무적권 부여 표시
    for(int i=0; i<k; i++){
        int idx = enemyPQ.top().second;
        //cout<<enemyPQ.top().first<<' '<<idx<<'\n';
        skill[idx] = true;
        enemyPQ.pop();
    }
    
    // while(!enemyPQ.empty()){
    //     enemyPQ.pop();
    // }
    
    Info info = fight(n, enemy, skill);
    int enemySum = info.enemySum;
    int kCnt = info.kCnt;
    int roundCnt = info.roundCnt;
    //cout<<enemySum<<' '<<kCnt<<' '<<roundCnt<<'\n';
    if(kCnt==k){
        return roundCnt;
    }
    else{
        for(int i=roundCnt; i<enemy.size(); i++){
            if(skill[i]){
                skill[i] = false;
            }
        }
        
        while(kCnt<k){ //지금까지 도달한 구간에서 최댓값 찾아서 그 라운드에 무적권 부여하기
            priority_queue<pair<int,int>> enemyPQ1;
            for(int i=0; i<=roundCnt; i++){ //해당 구간 바로 다음 라운드에 무적권 부여되어있으면, 다음 라운드까지 넘어갈 수 있음.
                if(!skill[i]){
                    enemyPQ1.push({enemy[i], i});
                }
            }
            
            int idx1 = enemyPQ1.top().second;
            skill[idx1] = true;
            
            
            Info info1 = fight(n, enemy, skill);
            enemySum = info1.enemySum;
            roundCnt = info1.roundCnt;
            
            kCnt++;
        }
    }
    
    answer = roundCnt;
    
    return answer;
}