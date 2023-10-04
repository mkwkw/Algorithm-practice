#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

//최대 공약수, 소수
//주의, arrayA와 arrayB 둘 중 하나만 나눠지게 해야하므로 1은 답이 될 수 없음.
//주의, 제곱(pow)와 곱하기(*) 구분!

//각 배열의 최대 공약수를 구하고, 서로 배열 원소 나눠보기
//1. 2~10000(100000000의 제곱근)까지의 소수 구하기 - 에라토스테네스의 체
//2. 최대공약수, 배열의 각 원소를 "소수^지수*소수^지수..." 형태로 바꾸기 - 지수는 재귀를 이용하여 구하기(findExp함수)
//3. 각 배열에서 소수, {소수의 등장 횟수, 최소 지수}를 map으로 저장
//4. 등장 횟수가 배열의 크기와 같은 소수를 소수^지수해서 곱해서 최대 공약수 구하기
//5. 각 배열의 최대 공약수(0이상 이라면)로 상대 배열의 원소를 나누어떨어지게 할 수 있는지 구하기

int findExp(int num, int p, int cnt){ //지수 찾기
    if(num%p==0){
        return findExp(num/p, p, cnt+1);
    }
    else{
        return cnt;
    }
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    vector<bool> prime;
    vector<int> primeNum;
    map<int, pair<int,int>> primeAndCntAndNumA, primeAndCntAndNumB; //[소수] = {등장한 횟수, 최소 지수}
    int answer = 0, a = 1, b = 1;
    
    prime.assign(10001, true);
    
    //소수 구해놓기 - 에라토스테네스의 체
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i*i<=10000; i++){
        if(!prime[i]){
            continue;
        }

        for(int j=i+i; j<=10000; j+=i){
            prime[j] = false;
        }
    }
    
    for(int i=2; i<=10000; i++){
        if(prime[i]){
            primeNum.push_back(i);
        }
    }
    
    //cout<<primeNum.size();
    //cout<<findExp(8,2,0);
    
    //배열A의 원소의 소인수분해 정보
    for(int i=0; i<arrayA.size(); i++){
        for(int j=0; j<primeNum.size(); j++){
            if(arrayA[i]<primeNum[j]){
                break;
            }
            if(arrayA[i]%primeNum[j]==0){
                int cnt = findExp(arrayA[i], primeNum[j], 0);
                
                if(primeAndCntAndNumA.find(primeNum[j])!=primeAndCntAndNumA.end()){
                    primeAndCntAndNumA[primeNum[j]].second = min(primeAndCntAndNumA[primeNum[j]].second, cnt);   
                }
                else{
                    primeAndCntAndNumA[primeNum[j]].second = cnt;   
                }
                primeAndCntAndNumA[primeNum[j]].first++;
            }
        }
    }
    //배열 B의 원소의 소인수분해 정보
    for(int i=0; i<arrayB.size(); i++){
        for(int j=0; j<primeNum.size(); j++){
            if(arrayB[i]<primeNum[j]){
                break;
            }
            if(arrayB[i]%primeNum[j]==0){
                int cnt = findExp(arrayB[i], primeNum[j], 0);
      
                if(primeAndCntAndNumB.find(primeNum[j])!=primeAndCntAndNumB.end()){
                    primeAndCntAndNumB[primeNum[j]].second = min(primeAndCntAndNumB[primeNum[j]].second, cnt);   
                }
                else{
                    primeAndCntAndNumB[primeNum[j]].second = cnt;   
                }
                primeAndCntAndNumB[primeNum[j]].first++;
            }
        }
    }
    
    //각 배열의 최대공약수 구하기
    bool flagA = false;
    for(auto m : primeAndCntAndNumA){
       //cout<<m.first<<' '<<m.second.first<<' '<<m.second.second<<'\n';
        if(m.second.first==arrayA.size()){
            flagA = true;
            a *= (int)pow(m.first,m.second.second);       
        }
    }
    
    if(!flagA){
        a = 0;
    }
    //cout<<"a "<<a;
    
    bool flagB = false;
    for(auto m : primeAndCntAndNumB){
        //cout<<m.first<<' '<<m.second.first<<' '<<m.second.second<<'\n';
        if(m.second.first==arrayB.size()){
            flagB = true;
            b *= (int)pow(m.first,m.second.second);        
        }
    }
    
    if(!flagB){
        b = 0;
    }
    //cout<<"b "<<b;
    
    //최대공약수로 구한 것이 0이상이라면, 상대 배열의 원소를 나누어떨어뜨릴 수 있는지 확인하기
    bool flag = true;
    if(a>0){
        for(int i=0; i<arrayB.size(); i++){
            if(arrayB[i]%a==0){
                flag = false;
                break;
            }
        }
        if(flag){
            answer = a;
        }
    }
    if(b>0){
        flag = true;
        for(int i=0; i<arrayA.size(); i++){
            if(arrayA[i]%b==0){
                flag = false;
                break;
            }
        }
        if(flag){
            answer = max(answer, b);
        }
    }
    
    return answer;
}