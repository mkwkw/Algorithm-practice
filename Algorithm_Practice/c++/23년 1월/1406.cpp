#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int M;
    string s = "";
    //커서 기준 왼쪽, 오른쪽 문자를 각각 스택을 만들어서 담음. - pop할 때, empty 체크 필수!!
    stack<char> left; //커서의 왼쪽에 있는 문자 담음
    stack<char> right; //커서의 오른쪽에 있는 문자 담음

    cin >> s;

    //커서가 맨 오른쪽에 있으므로 지금 입력되는 문자는 모두 커서의 왼쪽에 위치하는 문자들
    for (int i = 0; i < s.size(); i++)
    {
        left.push(s[i]);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd, c;
        cin >> cmd;

        //커서가 왼쪽으로 이동 - left에서 pop, right에 push
        if (cmd == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        //커서가 오른쪽으로 이동 - right에서 pop, left에 push
        else if (cmd == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        //커서 바로 왼쪽 문자 한 개 지움 - left에서 pop
        else if (cmd == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
        //커서 바로 왼쪽에 문자 추가
        else if (cmd == 'P')
        {
            cin >> c;
            left.push(c);
        }
    }

    // left에 있는 원소들 모두 right로 이동!
    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    // right에 있는 원소 출력
    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }
}