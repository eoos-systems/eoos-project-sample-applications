/**
 * @file      Program.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2022-2026, Sergey Baigudin, Baigudin Software
 */
#include "Program.hpp"
#include <lib.UniquePointer.hpp>
#include <lib.String.hpp>
#include <lib.Stream.hpp>
#include <lib.ArgumentParser.hpp>

namespace eoos
{

Program::Program(int32_t argc, char_t** argv)
    : lib::AbstractTask<lib::NoAllocator>()
    , argc_( argc )
    , argv_( argv )
    , error_( 0 ) {
}

Program::~Program()
{
}

void Program::start()
{
    lib::ArgumentParser<char_t,0> parser(argc_, argv_);
    if( !parser.isConstructed() )
    {
        error_ = 1;
        return;
    }
    api::List<api::String<char_t>*>& args( parser.getArguments() );
    if( args.getLength() > 4 )
    {
        lib::Stream::cerr()
            << "Goodbye, World.\n"
            << "You do not want more than three God's directives given.\n";
        error_ = 2; // This return value is checked by the sample application `Make.py` script passed with `--run` key
        return;
    }
    lib::UniquePointer< api::ListIterator<api::String<char_t>*> > it( args.getListIterator(0) );
    if( it.isNull() )
    {
        lib::Stream::cerr()
            << "World crashed.\n"
            << "God has no comment here, ask Sergey Baigudin\n";
        error_ = 3;
        return;
    }
    lib::Stream::cout() << "Hello, World!\n";
    lib::Stream::cout() << "Your program name is " << it->getNext()->getChar() << "\n";
    if( it->hasNext() )
    {
        lib::Stream::cout() << "You've got the next directives from God:\n";
        while( it->hasNext() )
        {
            lib::String index( it->getNextIndex() );
            lib::Stream::cout() << "Directive " << index.getChar() << ": " << it->getNext()->getChar() << "\n";
        }
    }
    else
    {
        lib::Stream::cout() << "God has pity on you :)\n";
    }
    error_ = 0;
    return;
}

int32_t Program::getError() const
{
    return error_;
}

} // namespace eoos
