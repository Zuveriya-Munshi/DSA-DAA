
#include<stdio.h>
#include<math.h>

int main()
{
    FILE *fin;
    //ofstream fout;
    int s,a[50];
    fin=fopen("file.txt","r");
    int i=0;
    while(fscanf(fin," %d ",&s)>0)
    {
        a[i]=s;
        i++;
    }
    for(int j=0;j<i;j++)
    {
        printf(" %d ",a[j]);
    }
    int sum=0;
    for(int k=0;k<i;k++)
    {
        sum+=a[k];
    }
    float mean;
    mean=sum/(float)i;
    printf("\nMean : %4.2f",mean);

    float ssd;
    for(int k=0;k<i;k++)
    {
        ssd+=((a[k]-mean)*(a[k]-mean));
    }
    ssd/=(float)i;
    printf("\nVariance  : %4.2f",ssd);
    float sd;
    sd = sqrt(ssd);
    printf("Standard Deviation : %4.2f ",sd);
    fclose(fin);




    return 0;
}
