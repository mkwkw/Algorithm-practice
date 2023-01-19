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

//�ڱ� �ڽ�(blocks[i])�� �������� �ؼ� ���ʿ��� ���� ū block ��, �����ʿ��� ���� ū block �� ���ϰ�
//min(���ʿ��� ���� ū ��, �����ʿ��� ���� ū ��) - blocks[i]�� ���Ѵ�.(������ ���̴� ��) �̶�, �ش� ������ ������ ������ �ʴ´ٸ� ���� 0�̳� ������ ���´�.
//���� max(0, min(���ʿ��� ���� ū ��, �����ʿ��� ���� ū ��)-blocks[i])�� ���ؾ��Ѵ�.
