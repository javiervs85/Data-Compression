#ifndef _DISTRIBUTION_HPP
#define _DISTRIBUTION_HPP

#include <memory>
#include <valarray>

#include "file.hpp"

namespace distribution
{
    class Distribution;
}

class distribution::Distribution
{
    private:

        std::valarray <double> __distribution = std::valarray <double> (0.0f, 256);

    public:

        Distribution ( file::File const & source );
        Distribution ( std::vector <char> const & source );

        std::unique_ptr <std::valarray <double>> set ( file::File const & source );
        std::unique_ptr <std::valarray <double>> set ( std::vector <char> const & source );

        std::unique_ptr <std::valarray <double>> get () const;
};


#endif
