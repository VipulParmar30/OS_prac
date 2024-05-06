#include <stdio.h>
#include <unistd.h>

int main(){
    int i,temp[10],NOP,y,at[10],bt[10],wt,tat,quant,sum,count;
    float avg_tat,avg_wt;
    printf("Total number of processes:");
    scanf("%d",&NOP);
    y=NOP;
    
    for(i=0;i<NOP;i++){
        printf("\n Enter arrival time and burst time of the process[%d]:",i+1);
        printf("Arrival time is:");
        scanf("%d",&at[i]);
        
        printf("Burst time is:");
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    printf("Enter the time quantum of the process:");
    scanf("%d",&quant);
    printf("Process No \t\tBurst time\t\tTAT\t\tWaiting time\n");
    
    for(sum=0,i=0;y!=0;){
        if(temp[i]<=quant && temp[i]>0){
            sum+=temp[i];
            temp[i]=0;
            count=1;
        }
        else if(temp[i]>0){
            temp[i]=temp[i]-quant;
            sum=sum+quant;
        }
        if(temp[i]==0 && count==1){
            y--;
            printf("\nProcess No[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
            wt=wt+sum-at[i]-bt[i];
            tat=tat+sum-at[i];
            count=0;
        }
        if(i==NOP-1){
            i=0;
        }
        else if(at[i+1]<=sum){
            i++;
        }
        else{
            i=0;
        }
        
    }
    avg_wt=(float)wt/NOP;
    avg_tat=(float)tat/NOP;
    printf("\nAVG WAITING TIME %d:",avg_wt);
    printf("\nAVG TAT %d:",avg_tat);
    return 0;
}