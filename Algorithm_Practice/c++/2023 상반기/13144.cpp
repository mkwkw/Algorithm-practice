#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> num;
    int n;
    long long answer = 0;

    cin>>n;

    num.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    //�� ������
    int low = 0;
    int high = 0;

    //�ߺ��� �߻��ϸ� low�� ����
    set<int> beforeNum;
    while(low<=high && high<n){

        //�ߺ��� �߻��� ���
        if(beforeNum.find(num[high])!=beforeNum.end()){ //num[j]�� ������ ���Դ� ������ ���
            beforeNum.erase(num[high]);
            //���ʿ��� �ߺ��Ǵ� ���� �ε����� ã�Ƽ� low�� �ߺ��ε���+1�ؼ� �־����
            for(int i=low; i<high; i++){
                if(num[i]==num[high]){
                    low = i+1;
                    break;
                }
            }
        }
        //low���� high���� ����� �� ���� 
        beforeNum.insert(num[high]);
        answer += (long long)(high-low+1);
        high++;
    }

// O(N^2) �� 10^10�̹Ƿ� ���� �ð� 1�ʸ� �Ѵ´�.
/*
    for(int i=0; i<n; i++){
        set<int> beforeNum; //j ������ ���Դ� �� ��� �뵵

        for(int j=i; j<n; j++){
            if(beforeNum.find(num[j])!=beforeNum.end()){ //num[j]�� ������ ���Դ� ������ ���
                break;
            }
            else{
                beforeNum.insert(num[j]);
                answer++;
            }
        }
    }
*/
    cout<<answer;

}