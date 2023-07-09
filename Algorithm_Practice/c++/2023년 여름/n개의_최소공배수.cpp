#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

//1. 100 이하의 소수 구하기
//2. 소수, 지수 구하기 -> map 이용 
int solution(vector<int> arr) {
    int answer = 1;
    vector<int> prime; //소수
    map<int, int> num; //소수, 지수
    
    for(int i=2; i<100; i++){
        bool flag = true;
        for(int j=2; j<=(int)sqrt(i); j++){
            if(i!=j && i%j==0){
                flag = false;
                break;
            }
        }
        if(flag){
            prime.push_back(i);
        }
    }
    
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<prime.size(); j++){
            if(arr[i]==0){
                break;
            }
            
            if(arr[i]%prime[j]==0){
                int cnt = 0;
                while(arr[i]>0 && arr[i]%prime[j]==0){
                    arr[i] /= prime[j];
                    cnt++;
                }
                num[prime[j]] = max(num[prime[j]],cnt); //최대 공배수 특성
            }
        }
    }
    
    for(auto pn : num){
        //cout<<pn.first<<' '<<pn.second<<'\n';
        answer *= pow(pn.first, pn.second);
    }
    
    return answer;
}