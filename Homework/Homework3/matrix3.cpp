#include <bits/stdc++.h>
using namespace std;

class Vector3 {
public:
    int x,y,z;
    Vector3(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    Vector3 operator*(Vector3& b){
        return Vector3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
    }
    Vector3 operator*(int k) {
        return Vector3(x*k,y*k,z*k);
    }
};
class Matrix3 {
public:
    int v[3][3];
    Matrix3() {memset(v,0,sizeof(v));}
    Matrix3 operator+(Matrix3& b) {
        Matrix3 a;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                a.v[i][j]=v[i][j]+b.v[i][j];
        return a;
    }
    Matrix3 operator-(Matrix3& b) {
        Matrix3 a;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                a.v[i][j]=v[i][j]-b.v[i][j];
        return a;
    }
    Matrix3 operator*(int k) {
        Matrix3 a;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                a.v[i][j]=v[i][j]*k;
        return a;
    }
    Matrix3 operator*(Matrix3& b) {
        Matrix3 a;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    a.v[i][j] += v[i][k] * b.v[k][j];
        return a;
    }
    friend istream& operator>>(istream& in,Matrix3& m) {
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                in>>m.v[i][j];
        return in;
    }
    void cout1(){
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                cout<<v[i][j]<<" ";
        cout<<endl;
    }
};
int main() {
    int k;
    cin>>k;
    Matrix3 m1,m2,m3;
    cin>>m1>>m2>>m3;
    Matrix3 res1=(m1+m2-m3)*k;
    Matrix3 temp=m1*m2;
    Matrix3 res2=(temp*m3)*k;
    res1.cout1();
    res2.cout1();
    return 0;
}
