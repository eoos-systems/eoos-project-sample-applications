/**
 * @file      main.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2022, Sergey Baigudin, Baigudin Software
 */
#include <iostream>
#include <string>
#include <lib.Align.hpp>

int main()
{
    eoos::lib::Align<int32_t> year(2022);
    std::cout << "Hello, World from " << std::to_string(year) << std::endl;
}
