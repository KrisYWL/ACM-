/*
 *  ����set��ʹ�á� �ѵ㣺��Сд�������֣��ж��Ƿ�ͬһ�����ʡ�
 *  ������������뵽����ǰ��ÿ���ַ��ó�Сд���д��֮�����ʱҲ����ˡ�
 */
#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
    int n;
    int d;
    cin>>n;
    set<string> ss;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>d>>s;
        if(d==0)
        {
            for(auto &c:s)
                c=tolower(c);
            ss.insert(s);
        }
        if(d==1)
        {
            if(ss.count(s))
            {
                cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
        }
    }

    return 0;
}
