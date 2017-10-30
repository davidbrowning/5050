#include<iostream>
#include<unordered_map>
#include<cstdlib>
#include<vector>
#include<utility>


void print_a(std::vector<int> a){
  for (int i : a){
    std::cout << i <<", ";  
  }
  std::cout << std::endl;
return;
}

void print_p(std::vector<std::vector<int>> p){
  for (auto i : p){
    for (auto j : i){
      std::cout << j << "\t"; 
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
return;
}

int max(int a, int b){
  if (a > b)
    return a;
  else
    return b;
}


int main() {

  std::vector<int> a{2, 6, 3, 5, 7};
  int m = 11;
  int n = a.size()-1;
  std::vector<std::vector<int>> p;

  for (int i = 0; i < n+1; ++i){
    std::vector<int> v;
      for (int k = 0; k < m; ++k){
        v.push_back(-1);
      }
    p.push_back(v);
      for (int k = 0; k < m; ++k){
        if(i == 0){
          p[i][k] = 0;
        }
        if(k == 0){
          p[i][k] = 1;
        } 
      }
  }
  print_p(p);

  for (int i = 1; i <= n; ++i){
    std::cout << i << ": "; 
    for (int k = 1; k <= m; ++k){
      int response = -1;
      if(k >= a[i]){
        response = max(p[i-1][k],p[i-1][k-a[i]]);
      }
      else
      {
        response = p[i-1][k];
      }
      std::cout << "response: " << response << std::endl;
      std::cout << " p[" << i << "][" << k << "]:";
      p[i][k] = response;
      std::cout << p[i][k] << std::endl;
    }
    std::cout << std::endl;
  }

  print_p(p);

  std::cout << " p[" << n << "][" << m << "]:";
  std::cout << p[n][m] << std::endl;

return EXIT_SUCCESS;
}
