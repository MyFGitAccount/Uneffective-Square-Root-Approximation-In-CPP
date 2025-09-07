#include <iostream>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <chrono>
#include <iomanip>

inline long double square_root(long int num)
{
 long double answer;
  for(int i=1;i<num/2+1;i++)
     {
       if(i*i<=num) answer=(num-i*i)/(long double)(i*2)+i;
     }

  while(answer*answer>num)
  {
     if(answer/1.00012*answer/1.00012>num){answer=answer/1.0001;}
     if(answer*answer*1.0000025*1.0000025>num)answer=answer/1.0000001;
  }
  return answer;
}

int main()
{// clock_t t=clock();
  std::ios_base::sync_with_stdio(false);

  long int num;
  std::cout<<"enter a number:";
  std::cin>>num;
  auto start = std::chrono::high_resolution_clock::now();
  long double answer=square_root(num);
  std::cout<<"The square root of "<<num<<" is: "<<std::fixed<<std::setprecision(12)<<answer<<"\n";
  std::cout<<"The actual square root of "<<num<<" is: "<<std::fixed<<std::setprecision(12)<<sqrt(num)<<"\n";
  //t=clock()-t;
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  //printf("It took %ld clicks (%f seconds) to excute. \n",t,((float)t/CLOCKS_PER_SEC));
  std::cout << "It took " << elapsed.count() << " seconds to execute.\n";
}
