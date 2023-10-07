#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//정렬, XOR 연산
//정렬할 기준인 column을 전역변수로 선언
//^로 XOR 연산
int column;
bool comp(const vector<int> &a, const vector<int> &b){
    if(a[column-1]==b[column-1]){
        return a[0]>b[0];
    }
    return a[column-1]<b[column-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    column = col;
    sort(data.begin(), data.end(), comp); //col 기준 오름차순 정렬, 기본키 기준 내림차순 정렬
    
    for(int i=row_begin; i<=row_end; i++){
        int s = 0;
        for(int j=0; j<data[i-1].size(); j++){
            s += data[i-1][j]%i;
        }
        
        if(i==row_begin){
            answer = s;
        }
        else{ //XOR 연산
            answer ^= s;    
        }
    }
    
    return answer;
}