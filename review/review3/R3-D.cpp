#include <bits/stdc++.h>
using namespace std;

class Matrix;  // ǰ������

class Vector3{
    int x,y,z;
public:
    Vector3(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    int operator[](int i){
        if (i == 0) return x;
        if (i == 1) return y;
        if (i == 2) return z;
        return 0;  // ���Ĭ�Ϸ���ֵ����ֹδ������Ϊ
    }
    Vector3 operator+(const Vector3& obj){
        return Vector3(x+obj.x,y+obj.y,z+obj.z);
    }     
    Vector3 operator-(const Vector3& obj){
        return Vector3(x-obj.x,y-obj.y,z-obj.z);
    }
    Vector3 operator*(const Matrix& mat);  // �������������ٶ���
    
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

class Matrix{
    int v[3][3];
public:
    Matrix(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                v[i][j]=0;
            }
        }
    }
    int* operator[](int i){return v[i];}
    const int* operator[](int i)const{return v[i];}  // ���const�汾
 
    Matrix(int b[9]){
        v[0][0]=b[0],v[0][1]=b[1],v[0][2]=b[2];
        v[1][0]=b[3],v[1][1]=b[4],v[1][2]=b[5];
        v[2][0]=b[6],v[2][1]=b[7],v[2][2]=b[8];
    }
    Matrix operator+(const Matrix& obj){
        Matrix a;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a.v[i][j]=v[i][j]+obj.v[i][j];
            }
        }
        return a;
    }
    Matrix operator-(const Matrix& obj){
        Matrix a;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a.v[i][j]=v[i][j]-obj.v[i][j];
            }
        }
        return a;
    }
    Matrix& operator=(const Matrix& obj){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                v[i][j]=obj.v[i][j];
            }
        }
        return *this;
    }
    Matrix operator*(const Matrix& obj){
        Matrix a;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    a.v[i][j] += v[i][k] * obj.v[k][j];
        return a;
    }
    // �޸�Ϊ�����¾�������޸�����
    Matrix operator*(const int k) const {
        Matrix result = *this;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                result.v[i][j]*=k;
            }
        }
        return result;
    }
    friend istream& operator>>(istream& in,Matrix& m){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                in>>m.v[i][j];
            }
        }
        return in;
    }
    // �޸�Ϊʹ��const����
    friend ostream& operator<<(ostream& out,const Matrix& m){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                out<<m.v[i][j]<<" ";
            }
        }
        out<<endl;
        return out;
    }
};

// ��Matrix�������ʵ��Vector3�ķ���
Vector3 Vector3::operator*(const Matrix& mat){
    return Vector3(
        x * mat[0][0] + y * mat[1][0] + z * mat[2][0],
        x * mat[0][1] + y * mat[1][1] + z * mat[2][1],
        x * mat[0][2] + y * mat[1][2] + z * mat[2][2]
    );
}

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    Vector3 v(x,y,z);
    Matrix m;
    cin>>m;
    Vector3 v1=v*v;
    v1.Output();

    return 0;
}