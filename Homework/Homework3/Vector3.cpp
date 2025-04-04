#include <bits/stdc++.h>
using namespace std;

class Vector3{
    int x,y,z;
public:
    Vector3(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    friend Vector3 operator+(const Vector3 &A,const Vector3 &B){
        return Vector3(A.x+B.x,A.y+B.y,A.z+B.z);
    }
    friend Vector3 operator-(const Vector3 &A,const Vector3 &B){
        return Vector3(A.x-B.x,A.y-B.y,A.z-B.z);
    }
    friend Vector3 operator*(const Vector3 &A,const Vector3 &B){
        return Vector3(A.y*B.z-A.z*B.y,-A.x*B.z+A.z*B.x,A.x*B.y-B.x*A.y);
    }
    friend Vector3 operator*(const Vector3 &A,int k){
        return Vector3(k*A.x,k*A.y,k*A.z);
    }
    friend ostream& operator<<(ostream &out,Vector3 &A){
        out<<A.x<<" "<<A.y<<" "<<A.z<<endl;
        return out;
    }
    
};
int main(){
    int k;
    cin>>k;
    int a1,a2,a3,b1,b2,b3,c1,c2,c3;
    cin>>a1>>a2>>a3>>b1>>b2>>b3>>c1>>c2>>c3;
    Vector3 v1(a1,a2,a3);
    Vector3 v2(b1,b2,b3);
    Vector3 v3(c1,c2,c3);
    Vector3 v4,v5;
    v4=v1+v2-v3;
    v4=v4*k;
    v5=v1*v2;
    v5=v5*v3;
    v5=v5*k;
    cout<<v4;
    cout<<v5;
    return 0;
}