#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    bool arr[3];
    int result=0;
    vector<int> v[13];

    for (int i = 0; i < 12; i++) {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);

    }



    for (int i = 1; i <= 12; i++) {
        for (int k = 0; k < 3; k++) {
            arr[k] = false;
        }

        if (v[i].size() == 3) {
            for (int j = 0; j < 3; j++) {
                if (v[v[i].at(j)].size() == 1)
                    arr[0] = true;
                if (v[v[i].at(j)].size() == 2)
                    arr[1] = true;
                if (v[v[i].at(j)].size() == 3)
                    arr[2] = true;
            }

            if (arr[0] && arr[1] && arr[2]) {
                result = i;
                break;
            }

        }
    }

    cout << result;

}