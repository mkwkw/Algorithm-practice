#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

//크기가 서로 다른 종류의 수가 가장 적도록 -> 크기별 개수 계산 후(map 이용), 내림차순 정렬
//내림차순 정렬한 벡터 앞에서부터 k개만큼 고르기
int solution(int k, vector<int> tangerine) {
    map<int, int> sizeAndCnt; //크기:개수
    vector<int> cnt; //개수
    int answer = 0;
    
    for(int i=0; i<tangerine.size(); i++){
        sizeAndCnt[tangerine[i]]++;
    }
    
    for(auto s : sizeAndCnt){
        cnt.push_back(s.second);
    }
    
    //내림차순 정렬
    sort(cnt.begin(), cnt.end(), greater<>());
    
    for(int i=0; i<cnt.size(); i++){
        if(k>0){
            answer++;
            k -= cnt[i];
        }
    }
    return answer;
}