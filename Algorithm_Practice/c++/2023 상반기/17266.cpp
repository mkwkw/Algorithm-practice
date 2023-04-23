#include <iostream>
#include <vector>

using namespace std;

bool allLightOn(vector<bool> &road){
    for(int i=0; i<road.size(); i++){
        if(!road[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> road;
    vector<int> pos; //���ε���ġ

    int n, m, x, h=100000, maxDist = 100000, prevPos = 0;

    cin>>n>>m;

    road.assign(n, false);
    pos.assign(m, 0);

    for(int i=0; i<m; i++){
        cin>>pos[i];
        //maxDist = max(maxDist, pos[i]-prevPos);
        //prevPos = pos[i];
    }

    int minH = 1;
    int maxH = maxDist;
    int midH = 0;
    
    //�̺�Ž��
    while(minH<=maxH){
        midH = (minH+maxH)/2;

        bool canCover = true;

        //�� ���� ���ε� ���� Ŀ�� ���� ����
        if(pos[0]>midH){
            canCover = false;
        }
        if(n-pos[m-1]>midH){
            canCover = false;
        }

        for(int i=0; i<m-1; i++){
            if(pos[i+1]-pos[i]>midH*2){
                canCover = false;
                break;
            }
        }

        //�� ���� �ִٸ� h���� �ʿ�
        if(!canCover){
            minH = midH+1;
        }
        else{ //�� ���� ���ٸ� h�ٿ��� �Ǵ��� ���� �ʿ�
            h = min(h, midH);
            maxH = midH-1;
        }
    }
    
    cout<<h;


}