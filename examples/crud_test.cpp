#include <iostream>
#include <string>

#include "leveldb/db.h"

#include "helpers.h"

const std::string db_path = "/home/eric/Playground/leveldb_examples";

int main(int argc, char** argv) {
  using namespace leveldb;
  Options options = Options();
  options.create_if_missing = true;
  DB* db;
  Status status = DB::Open(options, db_path, &db);
  print_status("Open db", status);
  db->Put(WriteOptions(), random_string(10), random_string(10));
  Iterator* itr = db->NewIterator(ReadOptions());
  for (itr->SeekToFirst(); itr->Valid(); itr->Next()) {
    std::cout << itr->key().ToString() << ": " << itr->value().ToString()
              << std::endl;
  }

  return 0;
}
