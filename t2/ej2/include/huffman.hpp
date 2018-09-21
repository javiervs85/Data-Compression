#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include <functional>
#include <memory>
#include <queue>
#include <string>

#include "distribution.hpp"
#include "file.hpp"


namespace huffman
{
    class Huffman;
}

class huffman::Huffman
{
    private:

        std::unique_ptr <std::vector <char>> buffer_original;
        std::unique_ptr <std::vector <char>> buffer_compressed;

    public:

        Huffman ( std::string const & name );

        void read ( std::string const & name );
        void write ( std::string const & name );

        std::unique_ptr <std::vector <char>> get_original () const;
        std::unique_ptr <std::vector <char>> get_compressed () const;
};


#endif
