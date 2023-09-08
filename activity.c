
#include <stdio.h>
#include<stdlib.h>
struct activity{
    int s;
    int e;
}
int cmp(const void* a,const void* b){
    struct activity* x = (struct activity*)a;
    struct activity* y = (struct activity*)b;
    if(x->e >= y->e){
        return 1;
    }
    else if(x->e == y->e){
        return 0;
    }
    else{
        return -1;
    }
}

int main()
{
    int n;
    printf("Enter n value \n");
    scanf("%d",&n);
    struct activity act[n];
    for(i=0;i<n;i++){
        scanf("%d%d",&act[i].s,&act[i].e);
    }
    qsort(act,n,sizeof(struct activity),cmp);
    int i=0,c=1;
    for(int j=1;j<n;j++){
        if(act[j].s>=act[i].e){
            c++;
            i=j;
        }
    }
    printf("No of activities is: %d\n",c);
    
    return 0;
}
