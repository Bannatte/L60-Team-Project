#ifndef PRINT_HPP
#define PRINT_HPP
#include <iostream>
#include <string>
#include "getinput.hpp"
inline float calculateGPA (const std::string& filename)
{
  std::ifstream in File(filename);
  if (!inFile) {
    std::cerr << "Error opening" 
