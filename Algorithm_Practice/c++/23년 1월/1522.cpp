#include <iostream>

using namespace std;

int main(){
    string word;
    int aCnt=0, answer=0;
    cin>>word;

    int wordSize = word.size();
    
    //a���� ���ϱ� - a������ �����̵� ������ ũ�Ⱑ ��.
    for(int i=0; i<wordSize; i++){
        if(word[i]=='a'){
            aCnt++;
        }    
    }

    //a�� ���� ���, 0 ����ϰ� ��
    if(aCnt==0){
        cout<<answer;
        return 0;
    }
    
    //a�� �ִ� ���, �����̶�� �Ͽ����Ƿ�, �ε��� i�� 0���� word������ �����̵� ������ �̵��ؾ���. �ε��� i���� i+aCnt-1(%wordSize)���� �����̵������� �ϳ��� ���� - �����̵� �����쿡 ����ִ� b�� �ּ� ���� ã��
    answer=aCnt;
    for(int i=0; i<wordSize; i++){
        int bCnt=0;
        for(int j=i; j<i+aCnt; j++){
            if(word[j%wordSize]=='b'){ //�����̹Ƿ� % �̿�
                bCnt++;
            }
        }

        //�����̵������� �� b �ּҰ���
        if(answer>bCnt){
            answer = bCnt;
        }
    }

    cout<<answer;

}