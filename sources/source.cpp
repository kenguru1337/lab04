// Copyright 2021 Alexey <leo678337@gmail.com>

#include <stdexcept>

#include <header.hpp>

Broker::Broker(std::string &name, std::string &last_date, std::string &num_acc)//конструктор
    : _name(name), _date(last_date), _acc(num_acc) {}

void Broker::set_date(const std::string &date){//установка последней даты
  if (_date < date){
    _date = date;
  }
}

void Broker::operator++() {//переопределение оператора ++
  ++files;
}

void Broker::print(){ //вывод информации
  std::cout << "broker:" << _name << " account:" << _acc
            << " files:" << files << " lastdate:" << _date
            << std::endl;
}
