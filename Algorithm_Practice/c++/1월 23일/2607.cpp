//하-비슷한 단어  
#include <iostream>
#include <vector>

using namespace std;

vector<int> counting(vector<int> &alphabet, string str){ //단어의 각 알파벳의 개수 세기

    //A부터 Z 알파벳의 순서를 인덱스로 하여 단어의 각 알파벳 개수 저장 
    for(int i=0; i<str.length(); i++){
        alphabet[str[i]-'A']++;
    }

    return alphabet;
}

int solution(int n, string word){
    vector<int> first_alphabet; //비교 기준 단어의 알파벳 저장할 배열 
    vector<int> new_alphabet; //비교 대상 단어의 알파벳 저장할 배열
    int cnt=0; //다른 알파벳 개수
    int answer=0; //비슷한 단어 개수

    //첫 번째 단어의 각 알파벳 개수 저장하는 배열 초기화
    first_alphabet.assign(26,0);
    first_alphabet = counting(first_alphabet, word);

    //비교할 단어 입력 받고 판단
    for(int i=0; i<n-1; i++){
        cnt=0; //다른 알파벳 개수 저장하는 변수 초기화
        
        //비교할 단어의 알파벳 저장하는 배열 0으로 초기화
        new_alphabet.assign(26,0);

        //비교할 단어 입력받기
        string next_word; 
        cin>>next_word;

        //비교할 단어의 각 알파벳 개수 저장
        new_alphabet = counting(new_alphabet, next_word);
        
        //다른 알파벳 개수 세기
        for(int p=0; p<26; p++){
            cnt += abs(new_alphabet[p]-first_alphabet[p]);
        }
        
        //비슷한 단어의 조건에 해당되면 비슷한 단어 개수 하나씩 증가
        if(cnt==0 || cnt==1 || (cnt==2 && next_word.length()==word.length())){
            answer++;
        }
       
    }
    return answer;
}

int main(){
    
    int n, answer; //전체 단어 개수, 비슷한 단어 개수

    //전체 단어 개수 입력
    cin>>n;

    //비교 기준 단어 입력
    string word; 
    cin>>word;
    
    //비슷한 단어 개수 출력
    answer = solution(n,word);
    cout<<answer;
   
}