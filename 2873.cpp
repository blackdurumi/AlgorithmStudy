#include<iostream>
#include<algorithm>
#define N 1005

using namespace std;

int map[N][N];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, m, i, j;

    cin >> n >> m;
    
    for(i=0; i<n; i++){
        for(j=0; j<m; j++)
            cin >> map[i][j];
    }

    if(n%2==1){
        for(i=0; i<n; i++){
            for(j=0; j<m-1; j++){
                if(i%2==0) cout << "R";
                else cout << "L";
            }
            if(i!=n-1) cout << "D";
        }
    }
    else if(m%2==1){
        for(i=0; i<m; i++){
            for(j=0; j<n-1; j++){
                if(i%2==0) cout << "D";
                else cout << "U";
            }
            if(i!=m-1) cout << "R";
        }
    }
    else{
        int e=map[0][1], ex=0, ey=1;
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if((i+j)%2==0) continue;
                if(i==0 && j<2) continue;
                if(i==n-1 && j==m-1) continue;
                
                if(e>map[i][j]){
                    e=map[i][j];
                    ex=i;
                    ey=j;
                }
            }
        }

        for(i=0; i<n; i++){
            if(ex==i || ex==i+1){
                for(j=0; j<m-1; j++){
                    if(ey==j){
                        cout << "R";
                        continue;
                    }

                    if((j%2==0 && j<ey) || (j%2==1 && j>=ey)) cout << "D";
                    else cout << "U";
                    cout << "R";
                }
                i++;

                if(ey!=m-1)
                    cout << "D";
                if(i!=n-1){
                    cout << "D";
                    for(j=0; j<m-1; j++) cout << "L";
                    i++;
                }
                if(i!=n-1)
                    cout << "D";
            }
            else{
                for(j=0; j<m-1; j++)
                    cout << "R";
                if(i!=n-1){
                    cout << "D";
                    i++;
                    for(j=0; j<m-1; j++)
                        cout << "L";
                    if(i!=n-1)
                        cout << "D";
                }
            }
        }
        if(i<n){
            for(j=0; j<m-1; j++)
                cout << "R";
        }
    }

    return 0;
}