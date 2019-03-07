#include<stdio.h>
#include<time.h>  /// srand(), clock()
#define Size 100000
///took 9.18s to sort 100000 elements O(n^2)

int main()
{
    FILE *file;
    int x,i,A[Size],j,temp;
    int time1,time2;
    float T1,T2,T;

    file = fopen("input1.txt","w");
    if(file==NULL)
    {
        printf("Couldn't open Input File.\n");
        return;
    }

    srand(time(0));//to seed rand fn
    for(i=0;i<Size;i++)
    {
        x=rand();
        fprintf(file, "%d\n",x);
    }
    fclose(file);

    ///Scan from input file
    file = fopen("input1.txt", "r");
    if(file==NULL)
    {
        printf("Couldn't open Input File.\n");
        return;
    }

    for(i=0;i<Size;i++)
    {
        fscanf(file, "%d", &A[i]);
    }
    fclose(file);

    ///initial time before insertion sort
    time1 =clock();
    T1 = (float)time1/CLOCKS_PER_SEC;

    ///insertion Sort
    for(i=1;i<Size;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0 && A[j]>temp)
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=temp;
    }

    ///time from start to after insertion sort
    time2 = clock();
    T2= (float) time2/CLOCKS_PER_SEC;

    T=T2-T1; ///Taken time to perform insertion sort

    ///output in Output file
    file = fopen("output1.txt","w");
    if(file==NULL)
    {
        printf("Couldn't open output File.\n");
        return;
    }

    for(i=0;i<Size;i++)
    {
        fprintf(file, "%d\n", A[i]);
    }
    fclose(file);

    printf("Insertion Sort Took %f sec to Sort %d item\n",T,Size);

    return 0;
}

