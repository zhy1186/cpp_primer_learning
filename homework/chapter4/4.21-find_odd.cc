#include <iostream>
#include <vector>
int main(){
  std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (auto& i : test){
    std::cout << ((i % 2 == 1 ? (i *= 2) : (i)) )<< std::endl;
  }
  return 0;
}
