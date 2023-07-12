#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

//map: [도시이름] = 순서
//set: cache 역할 - 도시 이름만
//cities 돌면서 map 갱신
//캐시 히트 - answer += 1
//캐시 미스 - 캐시크기<cacheSize - set에 insert
//           캐시크기==cacheSize - set에서 erase하고 새로 넣기
//           가장 오래된 도시 찾기 - set돌면서 도시이름으로 map에서 순서 조회 - 최솟값 찾기
int solution(int cacheSize, vector<string> cities) {
    map<string, int> cityAndOrder; //도시 이름, 순서
    set<string> cache;
    
    int answer = 0;
    
    if(cacheSize==0){
        return 5*cities.size();
    }
    
    for(int i=0; i<cities.size(); i++){
        //대소문자 구분x -> 모두 소문자로 만들기
        for(int j=0; j<cities[i].length(); j++){
            cities[i][j] = tolower(cities[i][j]);
        }
        
        //시간을 최근 조회 시간으로 변경
        cityAndOrder[cities[i]] = i;
        
        if(cache.find(cities[i])!=cache.end()){//캐시 히트
            answer += 1;
        }
        else{//캐시 미스
            if(cache.size()<cacheSize){
                cache.insert(cities[i]);
            }
            else if(cache.size()==cacheSize){//캐시가 다 차있는 경우
                //가장 조회된지 오래된 도시 찾기
                int order = 100000;
                string cityName;
                
                for(auto city:cache){
                    if(cityAndOrder[city]<order){
                        order = cityAndOrder[city];
                        cityName = city;
                    }
                }
                
                cache.erase(cityName);
                cache.insert(cities[i]);
            }
            answer += 5;            
        }
        
    }
    
    return answer;
}