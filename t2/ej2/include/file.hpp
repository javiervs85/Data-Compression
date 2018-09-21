#ifndef _FILE_HPP
#define _FILE_HPP

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace file 
{
    class File;
}

class file::File
{
    private:

        std::vector <char> buffer;

    public:
    
        File ( std::string const & name );

        void read ( std::string const & name );
        void write ( std::string const & name );

        std::unique_ptr <std::vector <char>> get () const;
        std::vector <char>::iterator set ( std::vector <char> const & buf );

        size_t size () const;
};


#endif
