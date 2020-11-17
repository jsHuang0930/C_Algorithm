#include <cstdio>
int main(){
  int n;
  int count=0;
  scanf("%d",&n);
  while (n!=1)
  {
    if(n%2){
      n=(3*n+1)/2;
    }
    else
    {
      n=n/2;
    }
    count++;
  }
  printf("%d",count);
}