#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//주의: 암호문->평문으로 해독하는 것
int main(){
    vector<pair<char, int>> front; //key의 글자와 그 글자의 인덱스 저장
    vector<vector<char>> v;
    map<int, int> idx_pair; //원래 인덱스, 정렬된 상태의 인덱스
    string key, code;
    int n, idx, h;

    cin>>key>>code;

    n = key.length();
    h = code.length()/n;
    v.assign(n, vector<char>(1,' '));

    for(int i=0; i<n; i++){
        front.push_back({key[i], i});
    }

    sort(front.begin(), front.end()); //키 정렬

    for(int i=0; i<n; i++){
        v[i][0]=front[i].first;
        idx_pair[front[i].second]= i; // D는 3:0
    }

    //code를 n개씩 끊어서 v[idx]에 저장
    for(int i=0; i<code.length(); i++){
        if(i>0 && i%h==0){
            idx++;
        }
        v[idx].push_back(code[i]);
    }

    for(int i=1; i<h+1; i++){
        for(auto iter: idx_pair){
            cout<<v[iter.second][i];
        }
    }
    

}