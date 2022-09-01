#include <iostream>
#include <random>

#include "leveldb/db.h"

void print_status(const std::string& prefix, const leveldb::Status& status) {
  using namespace std;
  cout << prefix << " is " << status.ToString() << endl;
}

std::string random_string(size_t length) {
  static auto& chrs =
      "0123456789"
      "abcdefghijklmnopqrstuvwxyz"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  thread_local static std::mt19937 rg{std::random_device{}()};
  thread_local static std::uniform_int_distribution<std::string::size_type>
      pick(0, sizeof(chrs) - 2);

  std::string s;

  s.reserve(length);

  while (length--) s += chrs[pick(rg)];

  return s;
}