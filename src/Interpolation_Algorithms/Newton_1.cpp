//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#define MAX 10
//
//using namespace std;
//
////int main()
////{
//    int number_of_points = 8;
//    int i,j,k=0,m;
//    float xvalue[MAX],yvalue[MAX],search;
//    float differ[MAX][MAX],uvalue,hvalue,product,sum;
//    //clrscr();
//
//    // Get Data from Files
//    ifstream fp;
//    fp.open ("../../test-data/True/test_1o.dat");
//    for(int i = 0; i < number_of_points; i++)
//    {
//        fp >> xvalue[i] >> yvalue[i];
//        //printf("%f\t %f\n", xvalue[i], yvalue[i]);
//    }
//    fp.close();
//
//    ofstream result;
//    result.open ("result.dat");
//    // Get Y for desired X
//    for (float m = xvalue[0] ; m < xvalue[number_of_points-1]; m++)
//    {
//    k=0;
//    search = m;
//    result << search << "\t";
//
//
//    /*printf("\nEnter any value of x for which you want to find y : ");
//    fprintf(fp,"\nEnter any value of x for which you want to find y : ");
//    scanf("%f",&search);
//    fprintf(fp,"%f",search);*/
//    if(search<xvalue[0] || search>xvalue[number_of_points-1])
//    {
//        printf("\n\nValue lies outside the given values of x ");
//        return 1;
//    }
//    else
//    {
//        // printf("\n\nNEWTON'S DIVIDED DIFFERENCE INTERPOLATION ");
//        for(j=0;j<number_of_points-1;j++)
//        {
//            for(i=0;i<number_of_points-(j+1);i++)
//            {
//                if(j==0)
//                {
//                    differ[i][j]=(yvalue[i+1]-yvalue[i])/(xvalue[i+1]-xvalue[i]);
//                }
//                else
//                {
//                    differ[i][j]=(differ[i+1][j-1]-differ[i][j-1])/(xvalue[i+(j+1)]-xvalue[i]);
//                }
//            }
//        }
//        // printf("\n\n");
//        // printf(" x       y   ");
//        // for(i=1;i<number_of_points;i++)
//        // {
//        //     printf("   d^%dy(i) ",i);
//        // }
//        // printf("\n\n");
//        // for(i=0;i<number_of_points;i++)
//        // {
//        //     // printf(" %.2f    %.2f  ",xvalue[i],yvalue[i]);
//        //     for(j=0;j<number_of_points-(i+1);j++)
//        //     {
//        //     ;// printf("  %.4f  ",differ[i][j]);
//        //     }
//        //     // printf("\n");
//        // }
//        for(i=0;i<number_of_points;i++)
//        {
//            if(search>xvalue[i])
//            {
//                k=k+1;
//            }
//        }
//        k=k-1;
//        sum=yvalue[k];
//        for(i=0;i<number_of_points-(k+1);i++)
//        {
//            product=1;
//            for(j=0;j<=i;j++)
//            {
//                product=product*(search-xvalue[j+k]);
//            }
//            sum=sum+(differ[k][i]*product);
//
//        }
//        // printf("\n\n");
//        // printf("Interpolated value is  :  %f  ",sum);
//    }
//    result << sum <<"\n";
//}
//    result.close();
//    //getch();
////    return 0;
////}
