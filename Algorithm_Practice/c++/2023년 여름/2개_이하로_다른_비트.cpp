#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

//수학, 문자열, 구현
//이진수로 변환
//홀짝 나누기
//2개 이하로 다른 비트 찾는 경우의 수 나누기
string makeBinary(long long num){
    string numberStr = "";
    
    while(num>0){
        if(num%2==0){
            numberStr += '0';
        }
        else{
            numberStr += '1';
        }
        num /= 2;
    }
            
    reverse(numberStr.begin(), numberStr.end());
    
    return numberStr;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    //이진수의 끝자리가 1인가 0인가
    //끝자리: 0 -> 짝수
    //끝자리: 1 -> 홀수
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]%2==0){
            answer.push_back(numbers[i]+1);
        }
        else{
            //주어진 수 -> 이진수
            long long result=0;
            string numberStr = makeBinary(numbers[i]);
            bool flag = false; //주어진 수를 이진수로 바꾼 것에 0이 있는가
            for(int j=numberStr.length()-2; j>=0; j--){
                if(numberStr[j]=='0'){ //ex. 1001 -> 1010
                    flag = true;
                    numberStr[j]='1';
                    numberStr[j+1]='0';
                    break;
                }
            }
            
            if(!flag){//주어진 수를 이진수로 바꾼 것에 0이 없는 경우
                //111->1011
                numberStr.insert(0,"1");
                numberStr[1]='0';
            }
            
            //cout<<numberStr;
            
            //이진수 -> 십진수
            for(int j=0; j<numberStr.length(); j++){
                if(numberStr[j]=='1'){
                    result += (long long) pow(2,numberStr.length()-1-j);
                }
            }
            
            answer.push_back(result);
        }
    }
    
    return answer;
}