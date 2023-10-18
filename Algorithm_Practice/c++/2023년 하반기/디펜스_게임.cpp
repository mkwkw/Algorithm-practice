#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    //무적권의 개수>=라운드 수 -> 모든 라운드 통과
    if(k>=enemy.size()){
        return enemy.size();
    }
    
    //무적권의 개수<라운드 수
    //1라운드에서 무적권을 썼을 때, 안 썼을 때
    //2라운드에서 무적권을 썼을 때, 안 썼을 때 등등
    //next_permutation -> k개의 무적권을 어떻게 배치하느냐 -> 시간 초과
    vector<bool> skill;
    for(int i=0; i<k; i++){
        skill.push_back(false);
    }
    for(int i=0; i<enemy.size()-k; i++){
        skill.push_back(true);
    }
    
    do{
        int cnt = 0;
        int soldiers = n;
        for(int i=0; i<skill.size(); i++){
            //cout<<skill[i]<<' ';
            if(!skill[i]){
                ++cnt;
                continue;
            }
            
            if(soldiers>=enemy[i]){
                ++cnt;
                soldiers -= enemy[i];
            }
            else{
                answer = max(answer, cnt);
                continue;
            }
        }
        //cout<<'\n';
    }
    while(next_permutation(skill.begin(), skill.end()));
    
    return answer;
}