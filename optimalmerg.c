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
    //Arranging the Files in  order    // 10 20 30 40
    for(i=0;i<n-1;i++){                // initialy file[i]= 10 file[i+1] =20
        for(j=i+1;j<n;j++){            // count = 10+20 = 30               
            if(file[i]>file[j]){       // total = total+count = 0+30 =30
                temp=file[i];          // file[i+1]= count =30
                file[i]=file[j];      // 10 30 30 40   
                file[j]=temp;         // count = 30+30 =60
            }                         // total = 30+60 = 90
        }                             // 10 30 60 40
    }                                 // Rearrangeing in order 
    //for Optimal Merg Solution       // 10 30 40 60
    for(i=0;i<n-1;i++){              // count = 40 +60 = 100  
        count=file[i]+file[i+1];     // total = 90+100 =190 
        total=count+total;           // total optimal merg = 190
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