
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct job{
    int p;
    int d;
};
int cmp(const void* a, const void* b){
    struct job* x = (struct job*)a;
    struct job* y = (struct job*)b;
    if(x->p < y->p){
        return 1;
    }
    else if(x->p == y->p){
        return 0;
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    printf("Enter n value:\n");
    scanf("%d", &n);
    struct job jb[n];
    printf("\nEnter profit and deadline foe every job:\n");
    for(int i = 0; i < n; i++){
        scanf("%d%d", &jb[i].p, &jb[i].d);
    }
    qsort(jb, n, sizeof(struct job), cmp);
    int mxd = INT_MIN;
    for(int i = 0; i < n; i++){
        if(jb[i].d > mxd){
            mxd = jb[i].d;
        }
    }
    int q[mxd];
    for(int j = 0; j < mxd; j++)
        q[j] = 0;
    for(int i = 0; i < n; i++){
        for(int j = jb[i].d - 1; j >= 0; j--){
            if(q[j] == 0){
                q[j] = jb[i].p;
                break;
            }
        }
    }
    int profit = 0;
    for(int i = 0; i < mxd; i++){
        if(q[i] != 0){
            profit += q[i];
        }
    }
    printf("\nProfit = %d\n", profit);
    return 0;
}

