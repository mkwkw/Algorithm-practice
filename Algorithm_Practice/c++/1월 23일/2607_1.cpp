#include <iostream>
#include <vector>
#include <cstring>
 
using namespace std;
//�� ���迡���� solution �ڵ�� ������ �ʿ��� �Լ��� �ۼ��մϴ�.
void counting(int ar[26], string word){  
    int i;    
    for(i=0; i<word.length(); i++) //word���� �� alphabet��������
        ar[word[i]-'A']++;    
}
 
int solution(int n, vector<string>words){//�ܾ��� �� ������ �ܾ��� �迭�� ���ڷ� �־����ϴ�.     
    int i, k;
    int diff, length; //�� �ܾ� ���� ���ĺ� �ٸ� �� ����, ù ��° �ܾ�(���� �ܾ�) ����   
    int freq_firstword[26]={0}, freq_other[26]={0}; //�� ���ĺ� �󵵸� ������ �迭
    int answer=0;

    length = words[0].length(); //ù��° �ܾ��� ���� ��� 
    counting(freq_firstword, words[0]); //ù��° �ܾ��� ���ĺ� �� ���
    
    for (i = 1; i < n; i++) {
        diff = 0;
        memset(freq_other,0x0,26*sizeof(int)); //�迭 �ʱ�ȭ
        counting(freq_other, words[i]);       //������ �ܾ���� ���ĺ� �� ���
        
        for(k=0; k<26; k++)   //���ĺ� ������ ���̸� ����Ѵ�.
            diff += abs(freq_other[k]-freq_firstword[k]);
        
        //����� �ܾ��� ������ �ڵ�� ǥ��
        if(diff==0 || diff ==1 || (diff==2 && (words[i].length() == length) )){
            answer++;
        }
    }
    return answer;
}
 
//test ����
int main(void) {
    int n,i;
   
    int answer=0;
    
    cin >> n;
    vector<string> words(n);
    for (i = 0; i < n; i++)
       cin >> words[i];
    
    answer = solution(n,words);    
    printf("%d", answer);
}