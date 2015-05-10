#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

#include "utils.h"
#include "brute_force_generator.h"

using namespace std;

namespace {

bool is_plausible_given_verification_keylog(
    string candidate, vector<string> verification_keylog) {
  for (auto reply : verification_keylog) {
    assert(reply.length() == 3);
    size_t first, second;
    if ((first = candidate.find(reply[0])) == string::npos)
      return false;
    if ((second = candidate.find(reply[1], first+1)) == string::npos)
      return false;
    if (candidate.find(reply[2], second) == string::npos)
      return false;
  }
  return true;
}

string shortest_possible_passcode(vector<string> verification_keylog) {
  string digits = drop_duplicates(join(verification_keylog, ""));
  // Using two observations here:
  // * None of the "verification replies" provided in problem 79 contains
  //   the digits 4 and 5, because of this we can exclude them for the
  //   brute force alphabet.
  // * All digits that appear in at least one "verification reply" must also
  //   be in the shortest passcode, therefore any passcode candidate must be
  //   as long as the number of such digits.
  BruteForceGenerator gen(digits, digits.length());
  while (true) {
    string candidate = gen.nextString();

    static int cnt = 0;
    if (cnt++ % 100000 == 0)
      printf("%s\n", candidate.c_str());

    if (is_plausible_given_verification_keylog(candidate, verification_keylog))
      return candidate;
  }
}

}  // namespace

int main(int argc UNUSED, char* argv[] UNUSED) {
  vector<string> keylog = split(readfile("../data/p079_keylog.txt"), '\n');
  keylog = drop_duplicates(keylog);
  string passcode = shortest_possible_passcode(keylog);
  printf("answer = %s\n", passcode.c_str());
  return 0;
}
