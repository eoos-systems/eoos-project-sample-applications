/**
 * @file      Program.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2022, Sergey Baigudin, Baigudin Software
 */
#include <Program.hpp>
#include <lib.UniquePointer.hpp>
#include <lib.String.hpp>
#include <lib.Stream.hpp>

namespace eoos
{

int32_t Program::start(api::List<char_t*>& args)
{
    if( args.getLength() > 4 )
    {
        lib::Stream::cerr() 
            << "Goodbye, World.\n"
            << "You do not want more than three God's directive given.\n";
        return -1;
    }
    lib::UniquePointer< api::ListIterator<char_t*> > it( args.getListIterator(0) );
    if( it.isNull() )
    {
        lib::Stream::cerr()
            << "World crashed.\n"
            << "God has no comment here, ask Sergey Baigudin\n";
        return -2;
    }
    lib::Stream::cout() << "Hello, World!\n";
    lib::Stream::cout() << "Your program name is " << it->getNext() << "\n";
    if( it->hasNext() )
    {
        lib::Stream::cout() << "You've got the next directives from God:\n";
        while( it->hasNext() )
        {
            lib::String index( it->getNextIndex() );
            lib::Stream::cout() << "Directive " << index.getChar() << ": " << it->getNext() << "\n";
        }
    }
    else
    {
        lib::Stream::cout() << "God has pity on you :)";
    }
    return 0;
}

} // namespace eoos
