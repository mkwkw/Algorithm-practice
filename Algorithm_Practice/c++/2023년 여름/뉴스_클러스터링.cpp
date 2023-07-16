#include <string>
#include <map>
#include <iostream>

using namespace std;

//map
//1. 대소문자 구분X, 알파벳만 거르기
//2. 교집합 및 교집합 원소 개수 구하기 - 크기가 작은 map 기준 비교 
//  - 합집합 원소 개수도 일부 구하기(교집합에 해당되는 부분)
//3. 합집합 원소 개수 구하기 - 차집합에서
//4. 자카드 유사도 계산
int solution(string str1, string str2) {
    int answer = 0;
    double similarity = 0.0;
    int unionCnt = 0, interSectionCnt = 0;
    map<string, int> strAndCnt1, strAndCnt2, interSectionWords;
    
    //알파벳이 아닌 것 거르기 & 소문자로 바꾸기(대소문자 구분하지 않기 때문)
    for(int i=0; i<str1.length()-1; i++){
        if(((str1[i]>='a' && str1[i]<='z') || (str1[i]>='A' && str1[i]<='Z'))
          && ((str1[i+1]>='a' && str1[i+1]<='z') || (str1[i+1]>='A' && str1[i+1]<='Z'))){        
            str1[i] = tolower(str1[i]);
            str1[i+1] = tolower(str1[i+1]);
            string word = str1.substr(i,2);
            strAndCnt1[word]++;
        }
    }
    for(int i=0; i<str2.length(); i++){
        if(((str2[i]>='a' && str2[i]<='z') || (str2[i]>='A' && str2[i]<='Z'))
          && ((str2[i+1]>='a' && str2[i+1]<='z') || (str2[i+1]>='A' && str2[i+1]<='Z'))){        
            str2[i] = tolower(str2[i]);
            str2[i+1] = tolower(str2[i+1]);
            string word = str2.substr(i,2);
            strAndCnt2[word]++;
        }
    }
    /*
    for(auto m : strAndCnt1){
        cout<<m.first<<' '<<m.second<<'\n';
    }
    cout<<'\n';
    for(auto m : strAndCnt2){
        cout<<m.first<<' '<<m.second<<'\n';
    }
    */
    
    //둘 다 공집합인 경우
    if(strAndCnt1.size()==0 && strAndCnt2.size()==0){
      return 65536;  
    }
    
    if(strAndCnt1.size()<strAndCnt2.size()){
        swap(strAndCnt1, strAndCnt2); //strAndCnt1이 strAndCnt2보다 크기가 크도록
    }
    
    //교집합 구하기 (+합집합에 들어갈 교집합 원소 개수 구하기)
    for(auto m : strAndCnt2){
        if(strAndCnt1[m.first]>0){
            interSectionWords[m.first] = min(strAndCnt1[m.first], m.second);
            unionCnt += max(strAndCnt1[m.first], m.second);
            interSectionCnt += min(strAndCnt1[m.first], m.second);
        }
    }
    
    //차집합에 해당하는 원소 개수 구하기
    for(auto m : strAndCnt1){
        if(interSectionWords.find(m.first)==interSectionWords.end()){
            unionCnt += m.second;
        }
    }
    for(auto m : strAndCnt2){
        if(interSectionWords.find(m.first)==interSectionWords.end()){
            unionCnt += m.second;
        }
    }
    
    //자카드 유사도
    similarity = (double)interSectionCnt/(double)unionCnt;
    
    return (int)(similarity*65536);
}