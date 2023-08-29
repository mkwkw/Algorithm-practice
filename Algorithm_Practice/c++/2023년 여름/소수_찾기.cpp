#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//순열
//소수 찾기
int solution(string numbers) {
    int answer = 0;
    vector<char> ch;
    vector<int> result;
    vector<bool> isPrime; //소수인가 아닌가
    
    //나올 수 있는 수 범위는 0~9999999
    isPrime.assign(10000000, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i=2; i*i<10000000; i++){
        for(int j=i*i; j<10000000; j+=i){
            isPrime[j] = false;
        }
    }
    
    for(int i=0; i<numbers.length(); i++){
        ch.push_back(numbers[i]);
    }
    
    sort(ch.begin(), ch.end());
    
    //ch로 만들 수 있는 순열 구하기
    do {
        string temp = "";
        // 만들 수 있는 모든 숫자 result에 저장
        for (int i = 0; i < ch.size(); i++) {
            temp.push_back(ch[i]);
            result.push_back(stoi(temp));
        }
        
    } while (next_permutation(ch.begin(), ch.end()));
    
    // 중복 값 지우기
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    
    //소수인지 확인하기
    for(int i=0; i<result.size(); i++){
        if(isPrime[result[i]]){
            answer++;
        }
    }
    
    return answer;
}