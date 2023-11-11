#pragma once

#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>
#include <unordered_map>
#include <map>

#include <sstream>
#include <filesystem>


inline std::string input_string(std::istream& in)
{
    in.ignore(1000000, '\n');
    in >> std::ws;
    std::string str;
    std::getline(std::cin, str);
    std::cerr << str << std::endl;
    return str;
}

template <typename T>
T CorrectNumber(T min, T max)
{
    T x;
    while ((std::cin >> x).fail()
        || std::cin.peek() != '\n'
        || x < min || x > max)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\nНеверный ввод данных!" << std::endl;
        std::cout << "Введите число от " << min << " до " << max << std::endl;
    }
    
    return x;
}




template <typename T>
std::vector<int> GetKeys(const std::unordered_map<int, T>& container)
{
    std::vector<int> keys;
    keys.reserve(container.size());
    int i = 0;
    for (auto& [id, element] : container)
        keys.push_back(id);
    return keys;
}

