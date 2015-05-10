#ifndef UTILS_H_INCLUDE_GUARD_
#define UTILS_H_INCLUDE_GUARD_

#include <vector>
#include <string>

#define UNUSED __attribute__((unused))

std::vector<std::string> split(const std::string& str, char delimiter = ' ');
std::string join(const std::vector<std::string>& strings, const std::string& delimiter);
std::string trim(const std::string& str);
std::string readfile(const std::string &filepath);

template<typename C>
C drop_duplicates(const C& container) {
  C container_copy(container);
  sort(container_copy.begin(), container_copy.end());
  typename C::iterator new_end = unique(container_copy.begin(), container_copy.end());
  container_copy.erase(new_end, container_copy.end());
  return container_copy;
}

#endif  // UTILS_H_INCLUDE_GUARD_
