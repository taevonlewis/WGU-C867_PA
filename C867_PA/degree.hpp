//
//  degree.cpp
//  C867_PA
//
//  Copyright © 2024 TaeVon Lewis. All rights reserved.
//


#pragma once
#include <string>

enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE, UNKNOWN };

inline std::string degreeProgramToString(DegreeProgram dp) {
    switch(dp) {
        case DegreeProgram::SECURITY: return "Security";
        case DegreeProgram::NETWORK: return "Network";
        case DegreeProgram::SOFTWARE: return "Software";
        default: return "Unknown";
    }
}
