#include "huffman.hpp"

namespace huffman
{
    struct __object
    {
        double freq;
        std::string item;
        std::string representation = "";
    };

    std::unique_ptr <std::vector <char>> compress ( std::unique_ptr <std::vector <char>> data )
    {
        std::auto_ptr <std::vector <__object>> ptr_obj (new std::vector <__object> (256));
        distribution::Distribution __distribution (data);
        auto dist = __distribution.get ();
        for (int i=0; i<0xff; ++i)
        {
            ptr_obj[i].freq = dist[i];
            ptr_obj[i].item = std::string ((char)i);
        }
        auto cmp = [](__object left, __object right) { return left.freq < right.freq;};
        std::priority_queue <__object, std::vector<__object>, dcltype(cmp)> huffman_encoding (*ptr_obj);
        while (!huffman_encoding.empty ())
        {
            auto h1 = huffman_encoding.pop ();
            auto h2 = huffman_encoding.pop ();
            h1.representation += "0";
            h1.representation += "1";
            std::auto_ptr <__object> ptr (new __object);
            ptr->freq = h1.freq + h2.freq;
            ptr->item = "";
            ptr->representation = "";
            huffman_encoding.push (*ptr);
        }
    }

    Huffman::Huffman ( std::string const & name )
    {
        file::File input (name);
        buffer_original = input.get ();
    }

    void Huffman::read ( std::string const & name )
    {
        file::File input (name);
        buffer_original = input.get ();
    }

    void Huffman::write ( std::string const & name )
    {
        file::File output ();
        output.set (*buffer_compressed);
        output.write (name);
    }

    std::unique_ptr <std::vector <char>> Huffman::get_original () const
    {
        std::unique_ptr <std::vector <char>> ptr (new std::vector <char> (*buffer_original));
        return ptr;
    }

    std::unique_ptr <std::vector <char>> Huffman::get_compressed () const
    {
        std::unique_ptr <std::vector <char>> ptr (new std::vector <char> (*buffer_compressed));
        return ptr;
    }
}
