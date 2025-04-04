#include <iostream>
using namespace std;

class Vector3 {
public:
    int x,y,z;
    Vector3(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    Vector3 operator*(Vector3& b){
        return Vector3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
    }
};
class Matrix3 {
public:
    int v[3][3];
    Matrix3() {
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                v[i][j]=0;
    }
    Vector3 operator*(Vector3& ob) {
        int r1=v[0][0]*ob.x+v[0][1]*ob.y+v[0][2]*ob.z;
        int r2=v[1][0]*ob.x+v[1][1]*ob.y+v[1][2]*ob.z;
        int r3=v[2][0]*ob.x+v[2][1]*ob.y+v[2][2]*ob.z;
        return Vector3(r1,r2,r3);
    }
    Matrix3 operator*(Matrix3& b) {
        Matrix3 c;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++) {
                c.v[i][j]=0;
                for(int k=0;k<3;k++)
                    c.v[i][j]+=v[i][k]*b.v[k][j];
            }
        return c;
    }
};
Vector3 mul(Vector3& v, Matrix3& m) {
    int r1=v.x*m.v[0][0]+v.y*m.v[1][0]+v.z*m.v[2][0];
    int r2=v.x*m.v[0][1]+v.y*m.v[1][1]+v.z*m.v[2][1];
    int r3=v.x*m.v[0][2]+v.y*m.v[1][2]+v.z*m.v[2][2];
    return Vector3(r1, r2, r3);
}
void cout1(Vector3 v) {
    cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;
}
void cout2(Matrix3 m) {
    for(int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cout<<m.v[i][j]<<" ";
        }
    }
}
int main() {
    Vector3 v;
    cin>>v.x>>v.y>>v.z;
    Matrix3 m;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>m.v[i][j];
    cout1(v*v);      
    cout1(mul(v,m));
    cout1(m*v);       
    cout2(m*m);       
    return 0;
}
