//
// Created by Work on 4/6/2026.
//

#pragma once
#include <ostream>

namespace Logger {
    inline void LogError(const std::string& message) {
        std::cout.flush();
        std::cerr << message << std::endl;
    }

    inline void LogInfo(const std::string& message) {
        std::cout << message << std::endl;
    }
} // Logger
