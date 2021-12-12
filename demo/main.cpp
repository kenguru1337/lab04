#include <header.hpp>

namespace fs = boost::filesystem;

int main(int argc, char* argv[]) {
  fs::path path_to_ftp;
  if (argc < 2) {
    path_to_ftp = fs::current_path();
  } else {
    path_to_ftp = argv[1];
  }

  const std::regex balance_file{"balance_[0-9]{8}_[0-9]{8}\\.txt"}; //ограничение названия файла(регулярное выражение)
  std::map<std::string, Broker> brokers; //словарь с брокерами
  for (const auto& path : fs::recursive_directory_iterator(path_to_ftp)) {//проход по вложенным директориям
    auto filename = path.path().filename();
    auto broker_name = path.path().parent_path().filename().string();
    if (fs::is_regular_file(path) &&
        std::regex_match(filename.string(), balance_file)) { //если текущий путь - файл и название удовлетворяет требованиям
      std::cout << filename.string() << std::endl;
      std::string date = filename.string();
      date.erase(0, 17); //вырезаем дату
      date.erase(8, 4);
      std::string acc = filename.string();
      acc.erase(0, 8);//вырезаем номер аккаунта
      acc.erase(8, 13);
      if (!brokers.count(broker_name)) { //если в словаре по данному ключу пусто
        Broker broker(broker_name, date, acc);//создаем объект класса broker
        brokers.insert({broker_name, broker}); //кладем его в словарь
      } else {
        brokers.at(broker_name).set_date(date); //иначе увеличиваем кол-во счетов
        ++brokers.at(broker_name);
      }
    }
  }
  for (auto &broker : brokers) {
    broker.second.print(); //печать значений
  }
  return 0;
}