#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<int> num, res;
vector<bool> check;

int cal(int n){
    int result = 0;

    for(int i=0; i<n-1; i++){
        result += abs(res[i]-res[i+1]);
    }

    return result;
}

void dfs(int cnt, int n){

    // cout<<"cnt: "<<cnt<<" n: "<<n<<'\n';
    // for(int i=0; i<n; i++){
    //     cout<<res[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=0; i<n; i++){
    //     cout<<check[i]<<' ';
    // }
    // cout<<'\n';


    if(cnt == n){
        answer = max(answer, cal(n));
        return;
    }

    for(int i=0; i<n; i++){
        if(check[i]){
            continue;
        }

        res[cnt] = num[i];
        check[i] = true;
        dfs(cnt+1, n);
        check[i] = false;
    }
}

int main(){
    int n;

    cin>>n;

    num.assign(n, 0);
    res.assign(n, 0);
    check.assign(n, false);
    
    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    //��Ʈ��ŷ
    //dfs(cnt) if(cnt==n){ ��� ���, return}

    for(int i=0; i<n; i++){
        check[i] = true;
        res[0] = num[i];
        dfs(1, n);
        check[i] = false; 
    }

    cout<<answer;

}

/**
 * ���� �����ϱ� ���Ͽ�
 * ���� �Է���
 * 3
 * 20 1 15 �̷��Զ�� �����ϸ�
 * 
 * ���� ù ��°�� ��ġ�� ���ڸ� �����ְ� check[0]�� üũ�� �Ѵ�.
 * k=0
 * 20
 * dfs �Լ��� �Ѿ��. cnt=1, n=3
 *      for
 *      20�� üũ�� �Ǿ������Ƿ�(check[0]) �ǳʶٰ�
 *      i=1
 *      üũ�� �Ǿ����� ���� 1�� res[1]�� �����Ѵ�. check[1]���� üũ�� �Ѵ�.
 *      ���� dfs �Լ��� �Ѿ��. cnt=2, n=3
 *          for
 *          20, 1�� üũ�� �Ǿ������Ƿ� �ǳʶٰ�
 *          j=2
 *          üũ�� �Ǿ����� ���� 15�� res[2]�� �����Ѵ�. check[2]���� üũ�� �Ѵ�.
 *          ���� dfs �Լ��� �Ѿ��. cnt=3, n=3 (res={20,1,15})
 *              if���� �ɷ��� answer�� ���(33)�ϰ� �� dfs�� ������.
 *          check[j] = check[2] = false
 *          j<3�̹Ƿ� for���� ������.
 *      check[i] = check[1] = false
 *      i=2
 *      üũ�� �Ǿ����� ���� 15�� res[1]�� �����Ѵ�. check[2]���� üũ�� �Ѵ�.
 *      ���� dfs �Լ��� �Ѿ��. cnt=2, n=3
 *          for
 *          20�� üũ�� �Ǿ������Ƿ� �ǳʶٰ�
 *          j=1
 *          üũ�� �Ǿ����� ���� 1�� res[2]�� �����Ѵ�. check[1]���� üũ�� �Ѵ�.
 *          ���� dfs �Լ��� �Ѿ��. cnt=3, n=3 (res={20,15,1})
 *              if���� �ɷ��� answer�� ���(29<33, answer=33)�ϰ� �� dfs�� ������.
 *          check[j] = check[1] = false
 *          j=2
 *          check[j] = check[2] = false
 *          j<3�̹Ƿ� for���� ������.
 *      check[i] = check[2] = false;
 *      i<3�̹Ƿ� for���� ������.
 * k=1
 * ù ��° ���ڰ� 1�� �ٲ��.
 * ������ �帧���� ����ȴ�.
 * {1,20,15}
 * {1,15,20}
 * k=2
 * ù ��° ���ڰ� 15�� �ٲ��.
 * ������ �帧���� ����ȴ�.
 * {15,1,20}
 * {15,20,1} 
*/