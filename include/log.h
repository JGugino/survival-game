#pragma once
#include <iostream>
#include <string>

class Log
{
public:
  Log();
  enum LogLevel
  {
    ERROR = 0,
    WARN = 1,
    INFO = 2
  };
  void Info(std::string message);
  void Warn(std::string message);
  void Error(std::string message);
  LogLevel SetLogLevel(LogLevel level);

private:
  int m_currentLogLevel;
};
