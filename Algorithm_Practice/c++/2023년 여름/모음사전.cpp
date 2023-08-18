#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//구현, 정렬
//바로 전에 생긴 단어들에 A, E, I, O, U 하나씩 붙이기
//A, E, I, O, U -> AA, AE, AI, AO, AU, EA, EE, EI, EO, EU ,, 
int solution(string word) {
    vector<string> words;
    string ch[5] = {"A","E","I","O","U"};
    
    int answer = 0, beforeSize = 0;
    
    for(int i=0; i<5; i++){
        words.push_back(ch[i]);
    }
    
    //바로 전에 생긴 단어들에 A, E, I, O, U 하나씩 붙이기
    for(int k=0; k<4; k++){
        int wordsSize = words.size();
        for(int i=beforeSize; i<wordsSize; i++){
            for(int j=0; j<5; j++){
                words.push_back(words[i]+ch[j]);
            }
        }
        beforeSize = wordsSize;
    }
    
    //A, AA, AAA, AAAA, AAAAA, AAAAE ,, 순서대로 정렬
    sort(words.begin(), words.end());
    
    for(int i=0; i<words.size(); i++){
        if(words[i]==word){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}