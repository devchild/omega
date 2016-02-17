/*
 * File:   linker.hh
 * Author: mario
 *
 * Created on June 24, 2014, 11:11 PM
 */

#ifndef LINKER_HH
#define LINKER_HH

#include <string>
#include <vector>

class Linker {
 public:
  int createExecutable(std::vector<std::string> &fileNames, std::string output);

 private:
  int execute(const std::string &exe, std::vector<std::string> const &args,
              bool verbose);
};

#endif
