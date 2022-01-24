//��-����� �ܾ�  
#include <iostream>
#include <vector>

using namespace std;

vector<int> counting(vector<int> &alphabet, string str){ //�ܾ��� �� ���ĺ��� ���� ����

    //A���� Z ���ĺ��� ������ �ε����� �Ͽ� �ܾ��� �� ���ĺ� ���� ���� 
    for(int i=0; i<str.length(); i++){
        alphabet[str[i]-'A']++;
    }

    return alphabet;
}

int solution(int n, string word){
    vector<int> first_alphabet; //�� ���� �ܾ��� ���ĺ� ������ �迭 
    vector<int> new_alphabet; //�� ��� �ܾ��� ���ĺ� ������ �迭
    int cnt=0; //�ٸ� ���ĺ� ����
    int answer=0; //����� �ܾ� ����

    //ù ��° �ܾ��� �� ���ĺ� ���� �����ϴ� �迭 �ʱ�ȭ
    first_alphabet.assign(26,0);
    first_alphabet = counting(first_alphabet, word);

    //���� �ܾ� �Է� �ް� �Ǵ�
    for(int i=0; i<n-1; i++){
        cnt=0; //�ٸ� ���ĺ� ���� �����ϴ� ���� �ʱ�ȭ
        
        //���� �ܾ��� ���ĺ� �����ϴ� �迭 0���� �ʱ�ȭ
        new_alphabet.assign(26,0);

        //���� �ܾ� �Է¹ޱ�
        string next_word; 
        cin>>next_word;

        //���� �ܾ��� �� ���ĺ� ���� ����
        new_alphabet = counting(new_alphabet, next_word);
        
        //�ٸ� ���ĺ� ���� ����
        for(int p=0; p<26; p++){
            cnt += abs(new_alphabet[p]-first_alphabet[p]);
        }
        
        //����� �ܾ��� ���ǿ� �ش�Ǹ� ����� �ܾ� ���� �ϳ��� ����
        if(cnt==0 || cnt==1 || (cnt==2 && next_word.length()==word.length())){
            answer++;
        }
       
    }
    return answer;
}

int main(){
    
    int n, answer; //��ü �ܾ� ����, ����� �ܾ� ����

    //��ü �ܾ� ���� �Է�
    cin>>n;

    //�� ���� �ܾ� �Է�
    string word; 
    cin>>word;
    
    //����� �ܾ� ���� ���
    answer = solution(n,word);
    cout<<answer;
   
}