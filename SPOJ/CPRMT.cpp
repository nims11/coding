/*
 * Problem is to find the common characters between the two strings and print them alphabetically
 */
#include<cstdio>
int main()
{
    char a[1001],b[1001];
    while(scanf("%s%s",a,b)!=EOF)
    {
        int counta[26]={0};
        int countb[26]={0};

        for(int i=0;a[i]!=0;i++)
        counta[a[i]-'a']++;

        for(int i=0;b[i]!=0;i++)
        countb[b[i]-'a']++;

        for(int i=0;i<26;i++)
        {
            int lt=counta[i]>countb[i]?countb[i]:counta[i];
            while(lt--)
            printf("%c",i+'a');
        }
        printf("\n");
    }
}
