#include <stdio.h>
#include <limits.h>
#include <float.h>
 
void drawRowFiller()
{
printf("==============================================================================================\n");
}
void drawCollumnHeader()
{
printf(" || Dolna Wartosc || Gorna Wartosc || Ziarno || Prezycja \n");
}
 
int main() {
drawCollumnHeader();
drawRowFiller();
printf("Short || %i || %i || || \n",SHRT_MIN,SHRT_MAX);
drawRowFiller();
printf("Int || %i || %i || || \n",INT_MIN,INT_MAX);
drawRowFiller();
printf("Long || %li || %li || || \n",LONG_MIN,LONG_MAX);
drawRowFiller();
printf("Long Long || %lli || %lli || || \n",LLONG_MIN,LLONG_MAX);
drawRowFiller();
printf("Float || %E || %E || %lf || %d \n",FLT_MIN,FLT_MAX,FLT_EPSILON,FLT_DIG);
drawRowFiller();
printf("Double || %E || %E || %lf || %d \n",DBL_MIN,DBL_MAX,DBL_EPSILON,DBL_DIG);
drawRowFiller();
printf("Long Double|| %Le || %Le || %Le || %d \n",LDBL_MIN,LDBL_MAX,LDBL_EPSILON,LDBL_DIG);
drawRowFiller();
 
return 0;
}
