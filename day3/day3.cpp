#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

int determine_item_priority_day1(int item) {
  if (item == 0) {
    return 0;
  } else if (item >= 'a' && item <= 'z') {
    return item - 'a' + 1;
  } else if (item >= 'A' && item <= 'Z') {
    return item - 'A' + 27;
  } else {
    return -1;
  }
}

int find_wrongly_placed_item_day1(std::string &line) {
  // TODO version with map
  int line_size = line.size();
  int line_center = line_size / 2;
  for (int i = 0; i < line_center; ++i) {
    for (int j = line_center; j < line_size; ++j) {
      if (line[i] == line[j]) {
        int line_nmb = line[i];
        return line_nmb;
      }
    }
  }
  return 0;
}

void day3_1() {
  int result{};
  std::fstream file;
  file.open("input_day3.txt", std::ios::in);
  if (file.is_open()) {
    std::string line;

    while (getline(file, line)) {
      // std::cout << line << "\n";

      int item = find_wrongly_placed_item_day1(line);
      result += determine_item_priority_day1(item);
    }
  }
  std::cout << result << "\n";
}

/////////////////////////////////////////////////////////////
//////////////   DAY2   /////////////////////////////////////
////////////////////////////////////////////////////////////

// int determine_priority_day2(int item) {}

int find_badge(std::string &line1, std::string &line2, std::string &line3) {
  // std::cout << line1 << '\n' << line2 << '\n' << line3 << "\n\n";
  for (int i = 0; i < line1.size(); ++i) {
    for (int j = 0; j < line2.size(); ++j) {
      if (line1[i] == line2[j]) {
        for (int k = 0; k < line3.size(); ++k) {
          if (line1[i] == line3[k]) {
            return line3[k];
          }
        }
      }
    }
  }
  return 0;
}

void day3_2() {
  int result{};
  std::fstream file;
  file.open("input_day3.txt", std::ios::in);
  if (file.is_open()) {
    std::string line, line1, line2, line3;
    int counter{1};
    while (getline(file, line)) {
      // std::cout << line << "\n";
      if (counter == 1) {
        line1 = line;
      }
      if (counter == 2) {
        line2 = line;
      }
      if (counter == 3) {
        line3 = line;
        counter = 0;
        int badge = find_badge(line1, line2, line3);
        result += determine_item_priority_day1(badge);
      }
      counter++;
    }
  }
  std::cout << result << "\n\n";
}

int main() {

  std::cout << "day1: " << '\n';
  day3_1();
  std::cout << "\n";
  std::cout << "day2: " << '\n';
  day3_2();
}