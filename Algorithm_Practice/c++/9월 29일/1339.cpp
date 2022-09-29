#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second>b.second;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, maxLength=0, num=9, answer=0;
    vector<string> word;
    vector<char> digit[9];
    vector<pair<int,int>> alphabet(26);

    cin>>n;

    word.assign(n,"");

    for(int i=0; i<n; i++){
        cin>>word[i];
        int l = word[i].length();
        maxLength = max(maxLength, l);
    }

    for(int i=0; i<26; i++){
        alphabet[i] = {i,-1};
    }

    //���� �ڸ������� ���ĺ��� digit[(10^)i]�� �ֱ�.
    for(int i=0; i<n; i++){
        for(int j=0; j<word[i].length(); j++){
            digit[word[i].length()-j].push_back(word[i][j]);
        }
    }
    

    //�ڸ����� ū ������ Ž��
    for(int i=maxLength; i>=0; i--){
        for(int j=0; j<digit[i].size(); j++){
            if(alphabet[digit[i][j]-'A'].second==-1){
                alphabet[digit[i][j]-'A'].second+=pow(10, i)+1;
            }
            else{
                alphabet[digit[i][j]-'A'].second+=pow(10, i);
            }
        }
    }

    sort(alphabet.begin(), alphabet.end(), cmp);

    for(int i=0; i<26; i++){
        if(alphabet[i].second==-1){
            break;
        }

        alphabet[i].second=num;
        num--;
    }
    
    //���
    for(int i=0; i<n; i++){
        int result=0;
        for(int j=0; j<word[i].length(); j++){
            for(int k=0; k<26; k++){
                if(alphabet[k].first == word[i][j]-'A'){
                    result += alphabet[k].second*pow(10, (word[i].length()-j-1));
                }
            }
        }
        answer += result;
    }

    cout<<answer;

}
//ó��: �ڸ� �� ū ���ĺ����� ū ����(9)���� ������ �ǰڴ�.
//ū �ڸ� �� -> ū ���� - �ݷ�
    /*
    10
    ABB
    BB
    BB
    BB
    BB
    BB
    BB
    BB
    BB
    BB

    ���䰪: 1790
    ��°�: 1780
    **/
//�ڸ��� �� ���� ���� ���� �ڸ��� �� ���� ������ Ŀ���� ���

//���: �� ���ĺ��� �ڸ����� ���ؼ� �������� ���ĺ��� �ڸ����� �������� �����ؼ� ����(9����) �ο�