
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,j,k,t,s[512][2]={0},e[512]={0},n=1;
    while(scanf("%d%d",&s[i][0],&e[i])!=EOF)
    {
       i++;
    }

//排序
    for(i=0;s[i][0]!=0;i++){
        for(j=0;j<i;j++){
            if(s[j][0]>s[j+1][0]){
                t=s[j][0];
                s[j][0]=s[j+1][0];
                s[j][0]=t;
                t=e[j];
                e[j]=e[j+1];
                e[j]=t;
            }
        }
    }

    //找空閒司機+排班
    s[0][1]=1;
    for(i=1;s[i][0]!=0;i++){
        if(s[i][1]==0){
            for(j=0;j<i;j++){
                int b=0;
                for(k=j+1;k<i;k++){
                    if(s[j][1]==s[k][1]){
                        b=1;
                        break;
                    }
                }
                if(e[j]<=s[i][0]&&b==0){
                    s[i][1]=s[j][1];
                    break;
                }
            }
            if(s[i][1]==0){
                n++;
                s[i][1]=n;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("\nDriver %d's schedule is ",i+1);
        for(j=0;s[j][0]!=0;j++){
            if(s[j][1]==i+1){
                printf("%d %d ",s[j][0],e[j]);
            }
        }
    }

}
