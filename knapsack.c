

#include <stdio.h>
#include <stdlib.h>
struct obj{
    int p;
    int w;
    double r;
};
int cmp(const void* a, const void* b){
    struct obj* x = (struct obj*)a;
    struct obj* y = (struct obj*)b;
    if(x->r < y->r)
        return 1;
    else if(x->r == y->r)
        return 0;
    else
        return -1;
}
int main(){
    int n, i;
    printf("Enter n value:\n");
    scanf("%d", &n);
    struct obj ob[n];
    printf("\nEnter profit and weight for every object:\n");
    for(i = 0; i < n; i++){
        scanf("%d%d", &ob[i].p, &ob[i].w);
    }
    for(i = 0; i < n; i++){
        ob[i].r = (double)ob[i].p/ob[i].w;
    }
    qsort(ob, n, sizeof(struct obj), cmp);
    int m;
    printf("\nEnter capacity of Knapsack:\n");
    scanf("%d", &m);
    double profit = 0.0;
    for(i = 0; i < n; i++){
        if(ob[i].w <= m){
            profit += ob[i].p;
            m -= ob[i].w;
        }
        else{
            break;
        }
    }
    if(i != n && m > 0){
        profit += (m * ob[i].r);
    }
    printf("\nProfit = %lf\n", profit);
    return 0;
}

