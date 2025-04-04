#include <bits/stdc++.h>
using namespace std;

class Vector3 {
    int x,y,z;
public:
    Vector3(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    int mylength() {
        return x*x+y*y+z*z;
    }
    bool operator<(Vector3& other) {
        return this->mylength()<other.mylength();
    }
    friend ostream& operator<<(ostream& out,Vector3& A) {
        out<<A.x<<" "<<A.y<<" "<<A.z;
        return out;
    }
    friend istream& operator>>(istream& in,Vector3& A) {
        in>>A.x>>A.y>>A.z;
        return in;
    }
};
class Vector3Array {
    vector<Vector3> arr;
public:
    void input(int n) {
        arr.resize(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
    }
    void mysort(){
        int n=arr.size();
        for (int i=0;i<n-1;i++) {
            int min=i;
            for (int j=i+1;j<n;j++) {
                if (arr[j]<arr[min]) {
                    min=j;
                }
            }
            Vector3 temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    void cout1() {
        for (int i=0;i<arr.size();i++) {
            cout<<arr[i]<<endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Vector3Array va;
    va.input(n);
    va.mysort();
    va.cout1();
    return 0;
}
