#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

//최소성 판단 기준 주의!
vector<bool> visited;
vector<int> tempCol;
vector<vector<int>> candidateList; //지금까지 선정된 후보키 리스트
int answer = 0;

//유일성 판단 - tempCol에 있는 컬럼으로 각 로우의 값들을 붙여서 유일성 판단
bool checkUnique(int rows, vector<vector<string>> relation){
    
    set<string> uniqueSet;
    for(int j=0; j<rows; j++){
        string temp = "";
        for(int i=0; i<tempCol.size(); i++){
            temp += relation[j][tempCol[i]];
        }
        uniqueSet.insert(temp);
    }
    
    if(uniqueSet.size()==rows){
        return true;
    }
    else{
        return false;
    }
}

//최소성 판단
bool checkMinimal(){
    if(tempCol.size()==1){
        return true;
    }
    
    //후보키의 컬럼이 여러 개일 경우, 컬럼이 하나만 달라도 다른 후보키가 된다. - [0,1,2] != [1,2,3]
    //하나만 달라도 flag를 true로 바꾸고 다음 후보키로 넘어가서 검사해야함.
    for(int i=0; i<candidateList.size(); i++){
        bool flag = false;
        for(int j=0; j<candidateList[i].size(); j++){
            if(find(tempCol.begin(), tempCol.end(), candidateList[i][j]) == tempCol.end()){
                flag = true;
                break;
            }
        }
        if(!flag){
            return false;
        }
    }
    
    return true;
}

bool check(int rows, vector<vector<string>> relation){
    if(checkUnique(rows, relation) && checkMinimal()){
        candidateList.push_back(tempCol);
        return true;
    }
    return false;
}
//조합 생성
void dfs(int idx, int cnt, int totalCnt, int rows, int cols, vector<vector<string>> relation){
    
    if(cnt == totalCnt){
        if(check(rows, relation)){
            answer++;
        }
        return;
    }
    
    for(int i=idx; i<cols; i++){
        if(visited[i]){
            continue;
        }
        
        visited[i] = true;
        tempCol.push_back(i);
        dfs(i, cnt+1, totalCnt, rows, cols, relation);
        tempCol.pop_back();
        visited[i] = false;
    }
}
int solution(vector<vector<string>> relation) {
    
    //1. 조합 구현 - 총 col개의 컬럼 중에 1~col개 뽑기
    for(int i=1; i<=relation[0].size(); i++){
        visited.assign(relation[0].size(), false);
        tempCol.clear();
        dfs(0,0,i, relation.size(), relation[0].size(), relation);    
    }
    return answer;
}