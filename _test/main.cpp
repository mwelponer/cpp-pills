#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_map>

int search(std::vector<int>& nums, int target) 
{
  int l = 0;
  int r = nums.size()-1;

  while(l <= r)
  {
      int mid = l + (r-l)/2;
      if(nums.at(mid) == target) 
          return mid;

      if(target > nums.at(mid))
          l = mid+1;
      else
          r = mid-1;
      
  }

  return -1;
}

void search(int k, int n) {
  static std::vector<int> subset;
  if (k == n){
    std::cout << "subset: ";
    for (int v : subset)
      std::cout << v << " ";
    std::cout << "\n";
  }else{
    search(k+1, n);
    subset.push_back(k);
    search(k+1, n);
    subset.pop_back();
  }
}

bool validateString(const std::string& str)
{
  std::stack<char> s;
  
  for(int i=0; i<str.length(); i++)
  {
    char c = str[i];
    std::cout << c << std::endl;
    
    if(c == '(')
      s.push(c);
    else{
      s.pop();
    }
  }
  
  return (s.size() == 0);
}

class Entity {
private:
  std::string m_name;
  int m_age;
public:
  Entity()
    : m_name("Unknown"), m_age(-1){}
  Entity(const std::string& name)
    : m_name(name), m_age(-1){}
  Entity(const int age)
    : m_age(age), m_name("Unknown"){}
  
  const std::string& getName(){return m_name;}
  const int getAge(){return m_age;}
	void setName(const std::string& name) {m_name = name;}
	void setAge(const int& age) {m_age = age;}  
};

int main()
{
  // std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
  // int target = 9;
  // std::cout << "res: " << search(nums, target) << std::endl;

  /*
  const std::string str = "(()())";
  std::cout << validateString(str) << std::endl;
  */

  /*
  Entity e;
  std::cout << e.getName() << ", " << e.getAge() << std::endl;

  Entity e1("pippo");
  //Entity e1 = std::string("pippo");
  std::cout << e1.getName() << ", " << e1.getAge() << std::endl;

  Entity e2(34);
  std::cout << e2.getName() << ", " << e2.getAge() << std::endl;

  e2.setAge(45);
  e2.setName("Ermenegildo");
  std::cout << e2.getName() << ", " << e2.getAge() << std::endl;
  */

  /*
  int arr[] = {1, 2, 3, 5};
  int size = sizeof(arr)/sizeof(int);
  auto k = std::lower_bound(arr, arr + size, 3) - arr;
  if (k < size)
    std::cout << "index: " << k << std::endl;

  std::reverse(arr, arr + size);
  std::random_shuffle(arr, arr + size);
  for (int i : arr)
    std::cout << i << std::endl;
  */

  /*
  std::bitset<10> s(std::string("0010011010")); // from right to left
  std::cout << "s:" << s << std::endl;
  */

  /*
  std::set<int> se{3, 47, 1, 3};
  // auto it = se.find(46);
  // if (it != se.end())
  //   std::cout << "found" << std::endl;

  auto it = std::find(se.begin(), se.end(), 2);
  if( it != se.end() ){
    std::cout << "found!" << std::endl;
  }
  */

  /*
  std::deque<int> d;
  d.push_back(5); // [5]
  d.push_back(2); // [5,2]
  d.push_front(3); // [3,5,2]
  d.pop_back(); // [3,5]
  //d.pop_front(); // [5]
  std::cout << d.front() << std::endl;
  std::cout << d.back() << std::endl;
  */

  search(0, 3);
}