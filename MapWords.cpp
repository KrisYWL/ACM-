/*
 *  集合set的使用。 难点：大小写单词区分，判断是否同一个单词。
 *  解决方法：插入到集合前先每个字符置成小写或大写。之后查找时也是如此。
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
