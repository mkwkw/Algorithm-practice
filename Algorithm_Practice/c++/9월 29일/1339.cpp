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

    //수의 자릿수별로 알파벳을 digit[(10^)i]에 넣기.
    for(int i=0; i<n; i++){
        for(int j=0; j<word[i].length(); j++){
            digit[word[i].length()-j].push_back(word[i][j]);
        }
    }
    

    //자릿수가 큰 곳부터 탐색
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
    
    //계산
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
//처음: 자릿 수 큰 알파벳부터 큰 숫자(9)부터 넣으면 되겠다.
//큰 자리 수 -> 큰 숫자 - 반례
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

    정답값: 1790
    출력값: 1780
    **/
//자릿수 더 적은 수의 합이 자릿수 더 많은 수보다 커지는 경우

//대안: 각 알파벳의 자릿수를 더해서 마지막에 알파벳의 자릿수로 내림차순 정렬해서 숫자(9부터) 부여