#include<bits/stdc++.h>
const int maxsize=100001;
int main(){
  int n,s_num,s_sum,max_num=0,max_sum=0;
  scanf("%d",&n);
  int sum[maxsize]={0};
  while(n--){
    scanf("%d%d",&s_num,&s_sum);
    sum[s_num]+=s_sum;
    if (sum[s_num]>=max_sum)
    {
      max_sum=sum[s_num];
      max_num=s_num;
    }
  }
  printf("%d %d",max_num,max_sum);
  return 0;
}