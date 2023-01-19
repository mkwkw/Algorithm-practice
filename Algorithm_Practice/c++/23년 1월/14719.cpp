#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> blocks;
    int h, w, answer=0;
    cin>>h>>w;

    blocks.assign(w, 0);

    for(int i=0; i<w; i++){
        cin>>blocks[i];
    }

    for(int i=1; i<w-1; i++){
        int left = 0, right = 0;

        for(int j=0; j<i; j++){
            left = max(left, blocks[j]);
        }

        for(int j=w-1; j>i; j--){
            right = max(right, blocks[j]);
        }

        answer += max(0, min(left, right) - blocks[i]);
    }

    cout<<answer;

}

//자기 자신(blocks[i])를 기준으로 해서 왼쪽에서 가장 큰 block 값, 오른쪽에서 가장 큰 block 값 구하고
//min(왼쪽에서 가장 큰 값, 오른쪽에서 가장 큰 값) - blocks[i]를 구한다.(빗물이 고이는 양) 이때, 해당 구간에 빗물이 고이지 않는다면 값이 0이나 음수가 나온다.
//따라서 max(0, min(왼쪽에서 가장 큰 값, 오른쪽에서 가장 큰 값)-blocks[i])를 구해야한다.
