#include <iostream>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}
int main(int argc, const char * argv[]) {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(max(a,b),max(b,c))<<endl;
    return 0;
}
