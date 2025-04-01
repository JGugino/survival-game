#include "../include/log.h"

Log::Log()
{
    m_currentLogLevel = Log::LogLevel::INFO;
}

void Log::Info(std::string message)
{
    if (m_currentLogLevel >= Log::LogLevel::INFO)
    {
        std::cout << "INFO: " << message << "\n";
    }
}

void Log::Warn(std::string message)
{
    if (m_currentLogLevel >= Log::LogLevel::WARN)
    {
        std::cout << "WARN: " << message << "\n";
    }
}

void Log::Error(std::string message)
{
    if (m_currentLogLevel >= Log::LogLevel::ERROR)
    {
        std::cout << "ERROR: " << message << "\n";
    }
}

Log::LogLevel Log::SetLogLevel(Log::LogLevel level)
{
    m_currentLogLevel = level;
    return level;
}
