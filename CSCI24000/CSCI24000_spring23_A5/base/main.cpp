#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
  std::ifstream inputF("input.txt");
  std::ofstream outputF("output.txt");
  std::string status;

  while(std::getline(inputF, status)) {
    std::istringstream ss(status);
    int plus = 0;
    std::string value;
    for (int x = 0; x < 3; x++) {
      std::getline(ss, value, ',');
      plus += atoi(value.c_str());
    }

    std::string data;
    std::getline(inputF, status);
    for (int x = 0; x < plus; x++) {
      outputF << status ;
      if (x < plus - 1) {
        outputF << ',';
      }
    }
    outputF << "\n";
  }
  outputF.close();
  inputF.close();
  return 0;
}
