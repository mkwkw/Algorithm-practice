#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

//공약수, 소수
//arrayA와 arrayB 둘 중 하나만 나눠지게 해야하므로 1은 답이 될 수 없음.
//가장 큰 양의 정수 a
//만약 배열에 소수가 하나만 있다면, 나머지 수들이 해당 소수의 배수인지 확인해보아야함.
//각 배열의 공약수를 구하고, 서로 배열 원소 나눠보기

//tc 11번~18번 - 시간초과 발생!
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    //약수의 개수
    map<int, int> numAndCntA, numAndCntB;
    int a = 0, b = 0;
    
    //cout<<"A\n";
    
    for(int i=0; i<arrayA.size(); i++){
        for(int j=2; j<=(int)sqrt(arrayA[i]); j++){
            if(arrayA[i]%j==0){
                //cout<<"j"<<j<<' ';
                numAndCntA[j]++;
                if((double)j!=sqrt(arrayA[i])){
                    //cout<<arrayA[i]/j<<' ';
                    numAndCntA[arrayA[i]/j]++;
                }
            }
        }
        numAndCntA[arrayA[i]]++;
    }
    
    for(auto m : numAndCntA){
        //cout<<m.first<<' '<<m.second<<'\n';
        if(m.second==arrayA.size()){
            a = m.first;
        }
    }
    
   
    
    //cout<<"B\n";
    for(int i=0; i<arrayB.size(); i++){
        for(int j=2; j<=(int)sqrt(arrayB[i]); j++){
            if(arrayB[i]%j==0){
                //cout<<"j"<<j<<' ';
                numAndCntB[j]++;
                if((double)j!=sqrt(arrayB[i])){
                    //cout<<arrayB[i]/j<<' ';
                    numAndCntB[arrayB[i]/j]++;
                }
            }
        }
        numAndCntB[arrayB[i]]++;
    }
    
    for(auto m : numAndCntB){
        //cout<<m.first<<' '<<m.second<<'\n';
        if(m.second==arrayB.size()){
            b = m.first;
        }
    }
    
    //cout<<"a "<<a<<" b "<<b<<'\n';
    
    //a로 arrayB가 나누어지는 게 있는지 확인
    //b로 arrayA가 나누어지는 게 있는지 확인
    if(a>0 && numAndCntB[a]==0){
        answer = a;
    }
    if(b>0 && numAndCntA[b]==0){
        answer = max(answer, b);
    }
    
    return answer;
}