#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int M;
    string s = "";
    //Ŀ�� ���� ����, ������ ���ڸ� ���� ������ ���� ����. - pop�� ��, empty üũ �ʼ�!!
    stack<char> left; //Ŀ���� ���ʿ� �ִ� ���� ����
    stack<char> right; //Ŀ���� �����ʿ� �ִ� ���� ����

    cin >> s;

    //Ŀ���� �� �����ʿ� �����Ƿ� ���� �ԷµǴ� ���ڴ� ��� Ŀ���� ���ʿ� ��ġ�ϴ� ���ڵ�
    for (int i = 0; i < s.size(); i++)
    {
        left.push(s[i]);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd, c;
        cin >> cmd;

        //Ŀ���� �������� �̵� - left���� pop, right�� push
        if (cmd == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        //Ŀ���� ���������� �̵� - right���� pop, left�� push
        else if (cmd == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        //Ŀ�� �ٷ� ���� ���� �� �� ���� - left���� pop
        else if (cmd == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
        //Ŀ�� �ٷ� ���ʿ� ���� �߰�
        else if (cmd == 'P')
        {
            cin >> c;
            left.push(c);
        }
    }

    // left�� �ִ� ���ҵ� ��� right�� �̵�!
    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    // right�� �ִ� ���� ���
    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }
}