#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
//�� ���迡���� solution �ڵ�� ������ �ʿ��� �Լ��� �ۼ��մϴ�.
void counting(int ar[26], char *word){  
    int i;    
    for(i=0; i<strlen(word); i++) //word���� �� ���ĺ� ���� ����
        ar[word[i]-'A']++;    
}
 
int solution(int n, char words[][11]){    //�ܾ��� �� ������ �ܾ��� �迭�� ���ڷ� �־����ϴ�.  
    int i, k;
    int diff, length; //�� �ܾ� ���� ���ĺ� �ٸ� �� ����, ù ��° �ܾ�(���� �ܾ�) ����   
    int freq_firstword[26]={0}, freq_other[26]={0}; //�� ���ĺ� �󵵸� ������ �迭
    int answer=0;
 
    length=strlen(words[0]); //ù��° �ܾ��� ���� ���   
    counting(freq_firstword, words[0]); //ù��° �ܾ��� ���ĺ� �� ���
    
    for (i = 1; i < n; i++) {
        diff = 0;
        memset(freq_other,0x0,26*sizeof(int)); //�迭 �ʱ�ȭ
        counting(freq_other, words[i]);       //������ �ܾ���� �˹ٺ� �� ���
        
        for(k=0; k<26; k++)   //���ĺ� ������ ���� ���
            diff += abs(freq_other[k]-freq_firstword[k]);
        
        //����� �ܾ��� ������ �ڵ�� ǥ��
        if(diff==0 || diff ==1 || (diff==2 && (strlen(words[i]) == length) )){ 
            answer++;
        }
    }
    return answer;
}
 
//test ����
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