#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
//본 시험에서는 solution 코드와 별도로 필요한 함수만 작성합니다.
void counting(int ar[26], char *word){  
    int i;    
    for(i=0; i<strlen(word); i++) //word마다 각 알파벳 개수 세기
        ar[word[i]-'A']++;    
}
 
int solution(int n, char words[][11]){    //단어의 총 개수와 단어의 배열이 인자로 주어집니다.  
    int i, k;
    int diff, length; //두 단어 간의 알파벳 다른 것 개수, 첫 번째 단어(기준 단어) 길이   
    int freq_firstword[26]={0}, freq_other[26]={0}; //각 알파벳 빈도를 저장할 배열
    int answer=0;
 
    length=strlen(words[0]); //첫번째 단어의 길이 계산   
    counting(freq_firstword, words[0]); //첫번째 단어의 알파벳 빈도 계산
    
    for (i = 1; i < n; i++) {
        diff = 0;
        memset(freq_other,0x0,26*sizeof(int)); //배열 초기화
        counting(freq_other, words[i]);       //나머지 단어들의 알바벳 빈도 계산
        
        for(k=0; k<26; k++)   //알파벳 개수의 차이 계산
            diff += abs(freq_other[k]-freq_firstword[k]);
        
        //비슷한 단어의 조건을 코드로 표현
        if(diff==0 || diff ==1 || (diff==2 && (strlen(words[i]) == length) )){ 
            answer++;
        }
    }
    return answer;
}
 
//test 메인
int main(void) {
    int n,i;
    char words[100][11]={""};
    int answer=0;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
       scanf("%s", words[i]);
    
    answer = solution(n,words);    
    printf("%d", answer);
}