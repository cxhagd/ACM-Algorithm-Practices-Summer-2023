#include<iostream>
#include<cstring>
using namespace std;
int trie[3000000+11][70];
int cnt[3000000+11];
int id;//编号
int T; 
int n,q; 
char t[3000000+11],s[3000000+11];
int map(char x){
	if(x>='A'&&x<='Z'){
		return x-'A';
	}
	if(x>='a'&&x<='z'){
		return x-'a'+26;
	}
	if(x>='0'&&x<='9'){
		return x-'0'+52;
	}
}
void insert(char str[]){
	int p=0, len=strlen(str);
	for(int i=0;i<len;i++){
		int c=map(str[i]);
		if(!trie[p][c]){
			trie[p][c]=++id;
		}
		p=trie[p][c];
		cnt[p]++;
	}	
}

int find(char str[]){
	int p=0;
	int len=strlen(str);
	
	for(int i=0;i<len;i++){
		int c=map(str[i]);
		if(!trie[p][c]){
			return 0;
		}
		p=trie[p][c];
	}
	return cnt[p];
}

int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<=id;i++)
            for(int j=0;j<=122;j++)
                trie[i][j]=0;
        for(int i=0;i<=id;i++)
            cnt[i]=0;
        id=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        for(int i=1;i<=q;i++){
            scanf("%s",s);
            printf("%d\n",find(s));
        }
    }
    return 0;
}











