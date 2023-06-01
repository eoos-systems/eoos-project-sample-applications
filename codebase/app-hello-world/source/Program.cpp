/**
 * @file      Program.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2022-2023, Sergey Baigudin, Baigudin Software
 */
#include <Program.hpp>
#include <lib.UniquePointer.hpp>
#include <lib.String.hpp>
#include <lib.Stream.hpp>
#include <lib.ArgumentParser.hpp>

namespace eoos
{

int32_t Program::start(int32_t argc, char_t* argv[])
{
	lib::ArgumentParser<char_t,0> parser(argc, argv);
    if( !parser.isConstructed() )
    {
        return 1;
    }
    api::List<api::String<char_t>*>& args( parser.getArguments() ); 	
    if( args.getLength() > 4 )
    {
        lib::Stream::cerr() 
            << "Goodbye, World.\n"
            << "You do not want more than three God's directives given.\n";
        return 2; // This return value is checked by the sample application `Make.py` script passed with `--run` key
    }
    lib::UniquePointer< api::ListIterator<api::String<char_t>*> > it( args.getListIterator(0) );
    if( it.isNull() )
    {
        lib::Stream::cerr()
            << "World crashed.\n"
            << "God has no comment here, ask Sergey Baigudin\n";
        return 3;
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
    return 0;
}

} // namespace eoos
