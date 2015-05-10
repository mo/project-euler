#include "misc.h"

#include <algorithm>

using namespace std;

bool has_no_duplicate_chars(string str) {
  sort(str.begin(), str.end());
  return adjacent_find(str.begin(), str.end()) == str.end();
}
