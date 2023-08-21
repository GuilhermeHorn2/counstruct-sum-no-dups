
#include <iostream>
#include <vector>
#include <algorithm>

void construct_sum(std::vector<int> &v, int k, int s, std::vector<int> &curr);

void construct_sum(std::vector<int> &v, int s);

int main()
{
 std::vector<int> v = {1, 1, 1, 2, 2};
 int s = 4;
 construct_sum(v, s);

 return 0;
}

void print_list(std::vector<int> &v)
{
 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i];
 }
 std::cout << '\n';
}

void construct_sum(std::vector<int> &v, int k, int s, std::vector<int> &curr)
{
 // no duplicates,only use each element once and assuming that v is sorted
 if (s == 0)
 {
  print_list(curr);
  return;
 }
 if (k == v.size() || s < 0)
 {
  return;
 }

 int prev = -1;
 for (int i = k; i < v.size(); i++)
 {

  if (prev != v[i])
  {
   curr.push_back(v[i]);
   construct_sum(v, i + 1, s - v[i], curr);
   curr.pop_back();
   prev = v[i];
  }
 }
}

void construct_sum(std::vector<int> &v, int s)
{
 std::sort(v.begin(), v.end());
 std::vector<int> curr;
 construct_sum(v, 0, s, curr);
}
