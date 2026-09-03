#include<stdio.h>
int main(){
    int n,i,j;
    int file[20];
    int count,total=0,temp;
    printf("Enter number of Files :\n");
    scanf("%d",&n);
    printf("Enter File Numbers :\n");
    //Entering the Files
    for(i=0;i<n;i++){
        scanf("%d",&file[i]);
    }
    //Arranging the Files in  order
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(file[i]>file[j]){
                temp=file[i];
                file[i]=file[j];
                file[j]=temp;
            }
        }
    }
    //for Optimal Merg Solution
    for(i=0;i<n-1;i++){
        count=file[i]+file[i+1];
        total=count+total;
        file[i+1]=count;
        // For Maintaing The Order
        for(j=i+1;j<n-1;j++){
                if(file[j]>file[j+1]){
                temp=file[j];
                file[j]=file[j+1];
                file[j+1]=temp;
            }
        }
    }
    printf("Total Optimal Merg = %d",total);
}