// lib/include/calculator.hpp
#pragma once

#ifdef _WIN32
    #ifdef CALCULATOR_EXPORTS
        #define CALCULATOR_API __declspec(dllexport)
    #else
        #define CALCULATOR_API __declspec(dllimport)
    #endif
#else
    #define CALCULATOR_API
#endif

class CALCULATOR_API Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
};
