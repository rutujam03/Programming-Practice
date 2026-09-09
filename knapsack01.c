#include<stdio.h>
int main(){
    int weg[10], pro[10],item;
    int temp =0,i,j,sack=50;
    int profit=0,weight=0;
    float ratio[10],temp_ratio;
    // Entering item data
    printf("Enter Number Of items :\n");
    scanf("%d",&item);
    printf("Enter Weight Of items : \n");
    for(i=0;i<item;i++){
        scanf("%d",&weg[i]);
    }
    printf("Enter Profit Of Items : \n");
    for(i=0;i<item;i++){
        scanf("%d",&pro[i]);
    }
    // to calculate ratio
    for(i=0;i<item;i++){
        ratio[i]=(float)pro[i]/weg[i];
    }
   // to arrange in desending order
   for(i=0;i<item-1;i++){
    for(j=+1;j<item;j++){
if(ratio[i] < ratio[j])
            {
                // Swap ratio
                temp_ratio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp_ratio;

                // Swap weight
                temp = weg[i];
                weg[i] = weg[j];
                weg[j] = temp;

                // Swap profit
                temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
    }
   }
   // Entering item in sack
   for(i=0;i<item;i++){
    if(sack>=weg[i]){
      printf("Taking item of Weigth = %d And Profit = %d\n",weg[i],pro[i]);
      profit= profit+pro[i];
      weight=weight+weg[i];
      sack= sack-weg[i];
    }
   }
   printf("Total Weight in sack %d:\n",weight);
   printf("Total Profit :%d \n",profit);
   return 0;
}