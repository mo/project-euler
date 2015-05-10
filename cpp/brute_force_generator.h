#ifndef BRUTE_FORCE_GENERATOR_H_INCLUDE_GUARD_
#define BRUTE_FORCE_GENERATOR_H_INCLUDE_GUARD_

#include <cassert>

#include "misc.h"

class BruteForceGenerator {
  public:
    BruteForceGenerator(std::string alphabet, size_t initial_length = 1) : alphabet_(alphabet) {
      assert(!alphabet_.empty());
      assert(initial_length >= 1);
      assert(has_no_duplicate_chars(alphabet_));
      current_string_ = std::string(initial_length-1, *alphabet_.rbegin());
    }
    std::string nextString() {
      for (size_t i = current_string_.length(); i-- > 0; ) {
        size_t alphabet_index = alphabet_.find(current_string_[i]);
        if (alphabet_index < alphabet_.length()-1) {
          current_string_[i] = alphabet_[alphabet_index+1];
          return current_string_;
        }
        current_string_[i] = alphabet_[0];
      }
      current_string_ = std::string(current_string_.length()+1, alphabet_[0]);
      return current_string_;
    }
  private:
    std::string alphabet_;
    std::string current_string_;
};

#endif  // BRUTE_FORCE_GENERATOR_H_INCLUDE_GUARD_
