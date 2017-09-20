#include<iostream>
#include<stack>
using namespace std;
stack<char> s;
stack<int> num;
int a[50000];
int main()
{
    string ss;
    cin>>ss;
    int j=1;
    for(int i=0;i<ss.size();i++){
        if(ss[i]=='('){             //如果为‘(’，压入stack
            s.push('(');
            int c=i+1;
            num.push(c);
        }
        if(ss[i]==')'){             //如果为‘)’，stack弹出
            if(s.empty()){
                s.push(')');
                break;
            }
            s.pop();
            a[j]=num.top();
            num.pop();
            a[j-1]=i+1;
            j+=2;
        }

    }
    if(s.empty()){                  //如果最后stack为空，即为括号全部匹配成功
        cout<<"Yes"<<endl;
        int i=ss.size()-1;
        while(i>0){                 //以两个元素为一个单位排序
            int j=i;
            while(j>0){
                if(a[i]>a[j]){
                    int temp1=a[i];
                    int temp2=a[i-1];
                    a[i]=a[j];
                    a[i-1]=a[j-1];
                    a[j]=temp1;
                    a[j-1]=temp2;
                }
                j-=2;
            }
            i-=2;
        }
        int p=ss.size()-1;
        while(p>0){
            cout<<a[p]<<' '<<a[p-1]<<endl;
            p-=2;
        }
    }
    else
        cout<<"No"<<endl;

    return 0;
}
