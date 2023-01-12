#include <iostream>

using namespace std;

int main(){
    string word;
    int aCnt=0, answer=0;
    cin>>word;

    int wordSize = word.size();
    
    //a개수 구하기 - a개수가 슬라이딩 윈도우 크기가 됨.
    for(int i=0; i<wordSize; i++){
        if(word[i]=='a'){
            aCnt++;
        }    
    }

    //a가 없는 경우, 0 출력하고 끝
    if(aCnt==0){
        cout<<answer;
        return 0;
    }
    
    //a가 있는 경우, 원형이라고 하였으므로, 인덱스 i는 0부터 word끝까지 슬라이딩 윈도우 이동해야함. 인덱스 i부터 i+aCnt-1(%wordSize)까지 슬라이딩윈도우 하나로 지정 - 슬라이딩 윈도우에 들어있는 b의 최소 개수 찾기
    answer=aCnt;
    for(int i=0; i<wordSize; i++){
        int bCnt=0;
        for(int j=i; j<i+aCnt; j++){
            if(word[j%wordSize]=='b'){ //원형이므로 % 이용
                bCnt++;
            }
        }

        //슬라이딩윈도우 내 b 최소개수
        if(answer>bCnt){
            answer = bCnt;
        }
    }

    cout<<answer;

}