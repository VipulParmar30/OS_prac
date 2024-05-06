#include <unistd.h>
#include <stdio.h>
void waiting_time(int processes[],int n,int wt[],int bt[]);
void tat_time(int processes[],int n,int wt[],int bt[],int tat[]);
void avg_time(int processes[],int n,int bt[]);
int main(){
    int processes[]={1,2,3};
    
    int n=sizeof processes/sizeof processes[0];
    
    int burst_time[]={12,16,20};
    
    avg_time(processes,n,burst_time);
    return 0;
}

void avg_time(int processes[],int n,int bt[]){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    
    waiting_time(processes,n,wt,bt);
    tat_time(processes,n,wt,bt,tat);
    
    printf("\nProcesses\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        total_wt=total_wt+wt[i];
        total_tat=total_tat+tat[i];
        printf("%d",i+1);
        printf("\t\t\t%d",bt[i]);
        printf("\t%d",wt[i]);
        printf("\t%d\n",tat[i]);
    }
    float avg_wt=(float)total_wt/n;
    float avg_tat=(float)total_tat/n;
    printf("Avg waiting time :%f\n",avg_wt);
    printf("Avg Turn around time: %f",avg_tat);
}
void waiting_time(int processes[],int n,int wt[],int bt[]){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
}

void tat_time(int processes[],int n,int wt[],int bt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
}
