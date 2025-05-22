#include <iostream>
#include <cstring>
using namespace std;
#define N 10000
int wordscount(char *text,char *word) {
    int cnt=0;
    int wlen=strlen(word);
    char *p=text;
    char *pos;
    while((pos=strstr(p,word))!=NULL) {
        cnt++;
        p=pos+wlen; 
    }
    return cnt;
}
int* wordfind(char *text,char *word){
    int wlen=strlen(word);
    char *p=text;
    char *pos;
    static int temp[1000];
    int cnt=0;
    while ((pos=strstr(p,word))!=NULL) {
        temp[cnt++]=int(pos-text);  
        p = pos+wlen;        
    }
    temp[cnt]=-1;                     
    return temp;                        
}

int main(){
    char text[1000];
    char word[1000];
    cin>>text;
    cin>>word;

    int res=wordscount(text,word);
    int *p=wordfind(text,word);
    
    for(int i=0;p[i]!=-1;i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<res<<endl;
    return 0;
}