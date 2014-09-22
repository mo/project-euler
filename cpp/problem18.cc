#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cassert>

using namespace std;

string DEMO_TRIANGLE = R"(
    3
    7 4
    2 4 6
    8 5 9 3
)";

string PROBLEM18_TRIANGLE = R"(
    75
    95 64
    17 47 82
    18 35 87 10
    20 04 82 47 65
    19 01 23 75 03 34
    88 02 77 73 07 63 67
    99 65 04 28 06 16 70 92
    41 41 26 56 83 40 80 70 33
    41 48 72 33 47 32 37 16 94 29
    53 71 44 65 25 43 91 52 97 51 14
    70 11 33 28 77 73 17 78 39 68 17 57
    91 71 52 38 17 14 91 43 58 50 27 29 48
    63 66 04 68 89 53 67 30 73 16 69 87 40 31
    04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
)";

vector<string>& split(const string& str, char delimiter, vector<string>& items) {
    string item;
    stringstream ss(str);
    while (getline(ss, item, delimiter)) {
        items.push_back(item);
    }
    return items;
}

vector<string> split(const string& str, char delimiter) {
    vector<string> items;
    split(str, delimiter, items);
    return items;
}

string trim(const string& str)
{
    ssize_t str_len = str.size();
    if (str_len == 0)
        return "";
    ssize_t first_nonspace_pos = -1;
    for (ssize_t i = 0; i < str_len; ++i) {
        if (!isspace(str[i])) {
            first_nonspace_pos = i ;
            break;
        }
    }
    if (first_nonspace_pos == -1)
        return "";
    ssize_t last_nonspace_pos = -1;
    for (ssize_t i = str_len-1 ; i >= 0; --i) {
        if (!isspace(str[i])) {
            last_nonspace_pos = i;
            break;
        }
    }
    return string(str, first_nonspace_pos, last_nonspace_pos - first_nonspace_pos + 1);
}

class Triangle {
public:
    Triangle(string& triangle_string) {
        parse_triangle_string(triangle_string, triangle_data_);
    }
    int maximum_path() {
        return maximum_path_from(0, 0);
    }
private:
    void parse_triangle_string(const string& triangle_string, vector<vector<int>>& triangle_data) {
        triangle_data.clear();
        vector<string> lines = split(trim(triangle_string), '\n');
        for(vector<string>::size_type row = 0; row != lines.size(); row++) {
            vector<string> row_data = split(trim(lines[row]), ' ');
            vector<int> row_values(row_data.size());
            transform(row_data.begin(), row_data.end(), row_values.begin(),
                    [](string str) { return stoi(str); });
            assert(row_values.size() == row + 1);
            triangle_data.push_back(row_values);
        }
    }
    int maximum_path_from(size_t row, size_t column) {
        assert(row < triangle_data_.size());
        assert(column < triangle_data_[row].size());
        if (row == triangle_data_.size() - 1) {
            return triangle_data_[row][column];
        }
        int down_left = maximum_path_from(row+1, column);
        int down_right = maximum_path_from(row+1, column+1);
        if (down_left > down_right)
            return triangle_data_[row][column] + down_left;
        else
            return triangle_data_[row][column] + down_right;
    }

    vector<vector<int>> triangle_data_;
};

int main() {
    assert(trim("") == "");
    assert(trim(" ") == "");
    assert(trim("  ") == "");
    assert(trim(" \n\n \t\t ") == "");

    Triangle demo_triangle(DEMO_TRIANGLE);
    assert(demo_triangle.maximum_path() == 23);

    Triangle problem18_triangle(PROBLEM18_TRIANGLE);
    printf("answer = %d\n", problem18_triangle.maximum_path());
    return 0;
}
