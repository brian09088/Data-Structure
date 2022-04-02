#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>

//HW1 sparse matrix

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    char buff[1000][1000];
    int number[100][1000];//save number
    int count=0;//counter
    int sum=0;
    bool y=true;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            number[i][j]=0;
        }
    }
    int k=0;
    int countrow=0;
  	if(m!=n){
    	y=false;
    }
    while(true)
    {
        int sum=0;
        int count=0;
        setbuf(stdin,NULL);
        fgets(buff[k],1000,stdin);
        int c=0;
        if(buff[k][0]=='\n')
        {
            break;
        }
        for(int i=0;i<strlen(buff[k]);i++){
            if(buff[k][i]==' ' || buff[k][i]=='\n')
            {
                c++;
            }

            if(buff[k][i]==' ' || buff[k][i]=='\n'){
                number[k][count]=sum;
                count=count+1;
                sum=0;
            }//next number
            else if(buff[k][i]=='-'){
                sum=(-1)*(buff[k][i+1]-'0');
                i=i+1;
            }//minor
            else{
                if(sum<0){
                    sum=sum*10-(buff[k][i]-'0');
                }
                else{
                    sum=sum*10+(buff[k][i]-'0');
                }
            }//count number
        }
        countrow++;
        k++;
        if(c != m)
        {
           y=false;
        }
    }
    if(countrow != m)
    {
         y=false;
    }
    if(y==false)
    {
        printf("Input matrix has wrong size. Please input again.");
    }
    else{
    int cal=0;
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(number[k][i]!=0)
            {
                cal++;
            }
        }
    }
    printf("Sparse matrix by triplet form:\n");
    printf("%d %d %d\n",m,n,cal);
    bool one=true;
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(number[k][i]!=0)
            {
                if(one==true){
                	printf("%d %d %d",k,i,number[k][i]);
                  	one=false;
                }
              	else{
                	printf("\n%d %d %d",k,i,number[k][i]);
                }
            }
        }
    }
    one=true;
    printf("\nTranspose of the sparse matrix:\n");
    printf("%d %d %d\n",m,n,cal);
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<n;k++)
        {
            if(number[k][i]!=0)
            {
                if(one==true){
                	printf("%d %d %d",i,k,number[k][i]);
                  	one=false;
                }
              	else{
                	printf("\n%d %d %d",i,k,number[k][i]);
                }
            }
        }
    }

    }
    return 0;
}


