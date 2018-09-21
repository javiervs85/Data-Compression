#include "file.hpp"

namespace file {

    File::File ( std::string const & name )
    {
        std::ifstream input (name, std::ios::binary);
        std::copy (
                std::istreambuf_iterator <char> (input), 
                std::istreambuf_iterator <char> ( ),
                buffer.begin ());
    }

    void File::read ( std::string const & name )
    {
        std::ifstream input (name, std::ios::binary);
        std::copy (
                std::istreambuf_iterator <char> (input), 
                std::istreambuf_iterator <char> ( ),
                buffer.begin ());
    }

    void File::write ( std::string const & name )
    {
        std::ofstream output (name, std::ios::binary);
        std::copy (
                buffer.begin (),
                buffer.end (),
                std::ostreambuf_iterator <char> (output)); 
    }

    std::unique_ptr <std::vector <char>> File::get () const
    {
        std::unique_ptr <std::vector <char>> ptr (new std::vector <char> (buffer));
        return ptr;
    }

    std::vector <char>::iterator set ( std::vector <char> const & buf )
    {
        return std::copy (
                buf.begin (),
                buf.end (),
                std::vector <char>::iterator buffer (output)); 
    }

    size_t File::size () const
    {
        return buffer.size ();
    }

}
