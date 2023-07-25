#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool> visited;
int answer = 0;

//재귀 - 완전 탐색
//던전이 최대 8개이므로 재귀 사용
//방문 배열 사용
//던전을 탐색하는 순서가 정해져 있지 않으므로 재귀함수에서도 던전 배열을 처음부터 탐색하도록 함.
void findPossibleDungeon(int nowExhaust, int cnt, vector<vector<int>> dungeons){
    if(cnt>answer) answer = cnt; //최대로 던전 방문한 개수 구하기
    
    for(int i=0; i<dungeons.size(); i++){
        if(!visited[i] && nowExhaust>=dungeons[i][0]){
            visited[i] = true;
            findPossibleDungeon(nowExhaust-dungeons[i][1], cnt+1, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    visited.assign(dungeons.size(), false);
    
    for(int i=0; i<dungeons.size(); i++){
        if(k>=dungeons[i][0]){
            visited[i] = true;
            findPossibleDungeon(k-dungeons[i][1], 1, dungeons);
            visited[i] = false;
        }
    }
    
    return answer;
}