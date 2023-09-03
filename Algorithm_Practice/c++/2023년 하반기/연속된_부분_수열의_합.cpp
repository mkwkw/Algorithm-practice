#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//정렬 기준
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second-a.first==b.second-b.first){
        return a.first<b.first; //길이가 같다면 시작 인덱스가 작은 것이 앞으로 오도록 정렬
    }
    return a.second-a.first<b.second-b.first; //길이가 다르다면 길이가 짧은 것이 앞으로 오도록 정렬
}

//투 포인터
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int,int>> pos; //가능한 인덱스 쌍 후보 배열 - 나중에 정렬
    int left = 0, right = 0, partSum = sequence[0]; // partSum: 부분 수열
    
    answer.assign(2,0);
    
    while(true){
        if(partSum==k){ //가능한 인덱스 쌍 후보 저장
            pos.push_back({left, right});
        }
        
        //left와 right가 모두 마지막 인덱스에 도달하면 break
        if(left==sequence.size()-1 && right==sequence.size()-1){
            break;
        }
        
        //partSum이 k보다 작고 right가 마지막 인덱스에 도달하지 않았다면 right 증가
        if(partSum<k && right<sequence.size()-1){
            partSum += sequence[++right];
        }
        else{ 
            if(left<sequence.size()-1){ //left가 마지막 인덱스에 도달하지 않았다면 left 증가
                partSum -= sequence[left++];
            }
        }
    }
    
    sort(pos.begin(), pos.end(), comp); //길이, 인덱스 기준 정렬
    
    answer[0] = pos[0].first;
    answer[1] = pos[0].second;
    
    return answer;
}