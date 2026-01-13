/**
 * @file      Main.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2020-2026, Sergey Baigudin, Baigudin Software
 *
 * @brief Unit of `main`.
 */
#include <sys.Call.hpp>
#include "Program.hpp"

/**
 * @brief The main function.
 *
 * This function starts all the testsuites and is defined here as the EOOS library may have
 * its own main() function defined and this definition will make a linker link the main().
 *
 * @param argc  The number of arguments passed to the program.
 * @param argv  An array of c-string of arguments where the last one - argc + 1 is null.
 * @return Error code or zero.
 */
int main(int argc, char** argv)
{
    ::eoos::Program program(argc, argv);
    ::eoos::int32_t const error( ::eoos::sys::Call::run(program) );
    return static_cast<int>( ( error == 0 ) ? program.getError() : error ); ///< SCA MISRA-C++:2008 Justified Rule 3-9-2
}
