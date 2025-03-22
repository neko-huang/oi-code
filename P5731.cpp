#include<iostream>
using namespace std;
int maze[15][15];
int main()
{
	int n,k=1,x=1,y=0;;
	cin>>n;
	while (k<=n*n)
	{
		while(y<n&&!maze[x][y+1]){
            maze[x][++y]=k++;
        }
		while(x<n&&!maze[x+1][y]){
            maze[++x][y]=k++;
        }
		while(y>1&&!maze[x][y-1]){
            maze[x][--y]=k++;
        }
		while(x>1&&!maze[x-1][y]){
            maze[--x][y]=k++;
        }
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
            if(maze[i][j]<10){
                cout<<' ';
            }
            if(maze[i][j]<100){
                cout<<' ';
            }
            cout<<maze[i][j];
        }
		cout<<endl;	
	}	
	return 0;
}