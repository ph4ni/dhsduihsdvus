#include<stdio.h>
int checkSorted(int [], int);
void combine(int [], int [], int, int);

int main() {
    int n,a,b;

    printf("Enter size of first array: ");
    scanf("%d",&a);
    int X[a];
    printf("Enter %d elements : ",a);
    for(int i=0;i<a;i++){
        scanf("%d", &X[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d",&b);
    int Y[b];
    printf("Enter %d elements : ",b);
    for(int i=0;i<b;i++){
        scanf("%d",&Y[i]);
    }
    
    int check1 = checkSorted (X,a);
    if(check1==0){
       printf("The first array is not sorted in increasing order\n");
    }else{
        printf("The first array is sorted in increasing order\n");
    }

    int check2 = checkSorted(Y,b);
    if(check2==0){
       printf("The second array is not sorted in increasing order\n");
    }else{
        printf("The second array is sorted in increasing order\n");
    }

    if(check1 == 1 && check2 == 1){
        combine(X,Y,a,b);
    }
    return 0;
}

int checkSorted(int *X, int sX){
    int prev = X[0];
    for(int i=0;i<sX;i++){
        if(X[i]<prev){
           return 0;
        }
        prev = X[i];
    }
    return 1;
}

void combine(int  *X, int *Y, int sX, int sY){
    int i,j,k, size = sX+sY; 
    i = j = k = 0;
    int C[size];
    for(i=0;i < sX && j < sY;){
        if (X[i] < Y[j]){
            C[k] = X[i];
            k++; i++;
        }else{
            C[k] = Y[j];
            k++;j++;
        }
    }

    
    while(i < sX){
        C[k] = X[i];
        k++;    i++;
    }

    while(j < sY){
    C[k] = Y[j];
    k++; j++;
    }
    
    for (i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
    		if(C[i] == C[j]){
    			for(k = j; k < size; k++){
    				C[k] = C[k + 1];
				}
				size--;
				j--;
			}
		}
	}

    printf("The merged array is: ");
    for(int i=0;i<size;i++){
        printf("%d ",C[i]);
    }
}   
