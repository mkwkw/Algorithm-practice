#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    
    if(a.second==b.second){ //재생 횟수가 같은 노래 중에서는
        return a.first<b.first; //고유 번호가 낮은 노래를 먼저 수록
    }
    return a.second>b.second; //재생 횟수가 많은 노래 먼저 수록
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int,int>>> jenreAndPlayList; //장르, {인덱스, 재생 수} 리스트
    vector<pair<int, string>> jenreAndPlayV; //{총 재생 수, 장르} 리스트
    
    //장르별 곡 정보를 map에 저장
    for(int i=0; i<genres.size(); i++){
        jenreAndPlayList[genres[i]].push_back({i,plays[i]});
    }
    //장르별 총 재생수를 vector에 저장
    for(auto m : jenreAndPlayList){
        int totalCnt = 0;
        for(int i=0; i<m.second.size(); i++){
            totalCnt += m.second[i].second;
        }
        jenreAndPlayV.push_back({totalCnt, m.first});
    }
    //장르별 총 재생수 내림차순으로 정렬
    sort(jenreAndPlayV.begin(), jenreAndPlayV.end(), greater<>());
    
    for(int i=0; i<jenreAndPlayV.size(); i++){
        
        sort(jenreAndPlayList[jenreAndPlayV[i].second].begin(), jenreAndPlayList[jenreAndPlayV[i].second].end(), comp); //map의 value 값({곡의 인덱스, 재생 횟수}) 지정된 기준으로 정렬
        
        //한 장르에 노래가 2곡 이상이라면 2곡 수록
        if(jenreAndPlayList[jenreAndPlayV[i].second].size()>=2){
            answer.push_back(jenreAndPlayList[jenreAndPlayV[i].second][0].first);
            answer.push_back(jenreAndPlayList[jenreAndPlayV[i].second][1].first);
        }
        else{ //한 장르에 노래가 1곡이라면 1곡만 수록
            answer.push_back(jenreAndPlayList[jenreAndPlayV[i].second][0].first);
        }
        
    }
    
    return answer;
}