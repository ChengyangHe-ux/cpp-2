#include <bits/stdc++.h>
using namespace std;
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
    Matrix& operator*(const int k){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                v[i][j]*=k;
            }
        }
        return *this;
    }
    friend istream& operator>>(istream& in,Matrix& m){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                in>>m.v[i][j];
            }
        }
        return in;
    }
    friend ostream& operator<<(ostream& out,Matrix& m){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                out<<m.v[i][j]<<" ";
            }
        }
        out<<endl;
        return out;
    }
};
int main(){
    int n;
    cin>>n;
    Matrix m1,m2,m3;
    cin>>m1>>m2>>m3;
    Matrix m4=(m1+m2-m3)*n;
    Matrix m5=(m1*m2*m3)*n;
    cout<<m4<<m5;
    return 0;
}