#include "utils.h"

#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

namespace {

vector<string>& split(const string& str, char delimiter,
                      vector<string>& items) {
  string item;
  stringstream ss(str);
  while (getline(ss, item, delimiter)) {
    if (!item.empty())
      items.push_back(item);
  }
  return items;
}
}

vector<string> split(const string& str, char delimiter) {
  vector<string> items;
  split(str, delimiter, items);
  return items;
}

string join(const vector<string>& strings, const std::string& delimiter) {
  ostringstream os;
  if (strings.begin() == strings.end())
    return "";
  copy(strings.begin(), strings.end() - 1,
       ostream_iterator<string>(os, delimiter.c_str()));
  os << *strings.rbegin();
  return os.str();
}

string trim(const string& str) {
  auto start = str.find_first_not_of(" \t\n");
  if (start == string::npos)
    return string();
  auto stop = str.find_last_not_of(" \t\n");
  return string(str, start, stop - start + 1);
}

string readfile(const string& filepath) {
  string str;
  std::ifstream fin(filepath.c_str());
  getline(fin, str, char(-1));
  fin.close();
  return str;
}
