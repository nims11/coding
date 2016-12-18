#include <stdio.h>
char mat[100][101],twoParents[100][100];
int a[100][100],pi[100][100],pj[100][100],n,m,i,j,t,min_mice,temp,infi=100000;

int min(int x,int y)
{
    return x<y?x:y;
}

int abs(int x)
{
    return x<0?-x:x;
}

int parent(int parents[][2],int ti,int tj)
{
    if(ti==0 && tj==0)
        return 0;
    
    int p1=infi,p2=infi;
    if(ti)
    {
        p1 = a[ti-1][tj];
        if(tj)
            p1 += (mat[ti][tj-1]-'0');
    }
    
    if(tj)
    {
        p2 = a[ti][tj-1];
        if(ti)
            p2 += (mat[ti-1][tj]-'0');
    }
    
    
    if(p1 == p2)
    {
        return 2;
    }
    else if(p1<p2)
    {
        parents[0][0] = ti-1; parents[0][1]=tj;
    }
    else
    {
         parents[0][0] = ti; parents[0][1]=tj-1;
    }
    return 1;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",mat[i]);
        
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                twoParents[i][j] = a[i][j] = 0;
        
        a[0][0]=mat[0][0]-'0';
        pi[0][0]=pj[0][0]=-3;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                temp = min_mice = infi;
                if(i !=  0)
                {
                    min_mice = a[i-1][j] ;
                    if(j!=0 && (mat[i][j-1]-'0') )//( (abs(pi[i-1][j]-i) +abs(pj[i-1][j]-(j-1))) >1 ) )
                    {
                      if(!twoParents[i-1][j])
                      {
                       // int parents[2][2];
                        //int np = parent(parents, i-1, j);
                        if( ( (abs(pi[i-1][j]-i) +abs(pj[i-1][j]-(j-1))) >1 ) )
                            min_mice++;
                      }
                    }
                    //pi[i][j]=i-1;pj[i][j]=j;
                }
                if(j !=  0)
                {
                    temp = a[i][j-1] ;
                    if(i!=0 &&  (mat[i-1][j]-'0') )//(( abs(pi[i][j-1]-(i-1)) +abs(pj[i][j-1]-j) ) >1) )
                    {
                        if(!twoParents[i][j-1])
                        {
                        
                            //int parents[2][2];
                        
                            //parent(parents, i, j-1);
                            if( (( abs(pi[i][j-1]-(i-1)) +abs(pj[i][j-1]-j) ) >1) )
                                temp++;
                        }
                        
                    }
                    
                    if(temp<min_mice)
                    {
                        min_mice = temp;
                        pi[i][j]=i;pj[i][j]=j-1;
                    }
                    else if(temp>min_mice)
                    {
                        pi[i][j] = i-1; pj[i][j]=j;
                    }
                    else
                        twoParents[i][j] = 1;
                }
                
                if(min_mice != infi)
                    a[i][j] = min_mice;
                
                if(i<n-1)
                {
                    a[i][j] += (mat[i+1][j]-'0');
                }
                
                if(j<m-1)
                {
                    a[i][j]+=(mat[i][j+1]-'0');
                }
            }
//        for(i=0;i<n;i++)
//         {
//         for(j=0;j<m;j++)
//         printf("%d ",a[i][j]);
//         printf("\n");
//         }
        printf("%d\n",a[n-1][m-1]);
    }
    return 0;
}
