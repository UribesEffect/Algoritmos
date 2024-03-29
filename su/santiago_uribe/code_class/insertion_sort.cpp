#include <iostream>
#include <vector>
#include "functions.hpp"
using namespace std;


void insertion_sort(vector<int>& v){
  for(int i = 1; i < v.size(); ++i){
    int a = i;
    int b = i-1;
    while(v[b] > v[a]){
      swap(a,b,v);
      a--;
      b = a-1;
    }
  }
}


int main(){
  int times = 100;
  int size = 1e3;
  vector<int> vec;

  //random number generator
  unsigned seed = 123;
  minstd_rand0 rng(seed);

  double tot_time = 0;
  for(int n = 0; n < times; ++n){
    //generate_vector(size, vec,  rng);//vector random
    //generate_ordered_vector(size, vec,rng, true);//de mayor a menor
    generate_ordered_vector(size, vec,rng, false);//de menor a mayor

    //print vector
    //print_vector(vec);

    //get initial time
    double tstart = gettime();

    //Search for X in vec
    insertion_sort(vec);

    //final time
    double tstop = gettime();
    tot_time += tstop-tstart;
    //print_vector(vec);


  }
  cout << "Time taken = " << tot_time / times << endl;


  return 0;
}
