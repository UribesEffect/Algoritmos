#include <iostream>
#include <vector>
#include "functions.hpp"
using namespace std;


bool is_sorted(const vector<int>& v){
  for(int i = 0; i < v.size()-1; ++i){
    if(v[i] > v[i+1])
      return false;
  }
  return true;
}

void shuffle(vector<int>& v, minstd_rand0& rng){
  //two random numbers
  int num1 = int(v.size() * ( double(rng()) / rng.max() ));
  int num2 = int(v.size() * ( double(rng()) / rng.max() ));

  //swap the elements
  swap(num1, num2, v);
}

void bogosort(vector<int>& v, minstd_rand0& rng){
  while (!is_sorted(v)){
    shuffle( v, rng);
  }
}


int main(){
  int times = 100;
  int size = 12;
  vector<int> vec;

  //random number generator
  unsigned seed = 123;
  minstd_rand0 rng(seed);
  double tot_time = 0;
  for(int n = 0; n < times; ++n){
    //Generate the random vector
    generate_vector(size, vec,  rng);//vector random
    //generate_ordered_vector(size, vec,rng, true);//de mayor a menor
    //generate_ordered_vector(size, vec,rng, false);//de menor a mayor

    //print vector
    //print_vector(vec);

    //get initial time
    double tstart = gettime();

    //Search for X in vec
    int pos = is_sorted(vec);

    //final time
    double tstop = gettime();
    tot_time += tstop-tstart;



  }
  cout << "Time taken = " << tot_time / times << endl;


  return 0;
}
