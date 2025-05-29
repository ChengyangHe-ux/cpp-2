#include <bits/stdc++.h>
using namespace std;
class Vector3{
    int x,y,z;
public:
    Vector3(int x,int y,int z):x(x),y(y),z(z){}
    Vector3 operator+(const Vector3& obj){
        return Vector3(x+obj.x,y+obj.y,z+obj.z);
    }     
    Vector3 operator-(const Vector3& obj){
        return Vector3(x-obj.x,y-obj.y,z-obj.z);
    }
    Vector3 operator*(const Vector3& obj){
        Vector3 D(y*obj.z-z*obj.y,z*obj.x-x*obj.z,x*obj.y-y*obj.x);
        return D;
    }
    Vector3 operator*(const int x){
        return Vector3(this->x*x,y*x,z*x);
    }
    ~Vector3(){}
    void Output(){
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
    Vector3& operator=(const Vector3& obj){
        x=obj.x;
        y=obj.y;
        z=obj.z;
        return *this;
    }
    bool operator<(const Vector3& obj){
        return x*x+y*y+z*z<obj.x*obj.x+obj.y*obj.y+obj.z*obj.z;
    }
};
class Vector3Array{
    vector<Vector3> T;
    int n;
public:
    Vector3Array(){n=0;}
    void add(Vector3 &v){
        T.push_back(v);
        n++;
    }
    void mysort(){
        for(int i=0;i<n;i++){
            int  min=i;
            for(int j=i+1;j<n;j++){
                if(T[j]<T[min]) min=j;
            }
            swap(T[min],T[i]);
        }
    }
    void Output(){
        for(int i=0;i<n;i++){
            T[i].Output();
        }
    }
};
int main(){
    int n;
    cin>>n;
    Vector3Array T;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        Vector3 m(x,y,z);
        T.add(m);
    }
    T.mysort();
    T.Output();
    return 0;
}