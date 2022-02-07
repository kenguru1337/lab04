// Copyright 2021 Alexey <leo678337@gmail.com>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <iostream>
#include <regex>
#include <string>
#include "boost/filesystem.hpp"

class Broker{
 private:
  std::string _name;
  std::string _date;
  std::string _acc;
  int files = 0;

 public:
  Broker(std::string& name, std::string& last_date, std::string& num_acc);
  void set_date(const std::string &date);
  void operator++();
  void print();
};

#endif // INCLUDE_HEADER_HPP_
