#include "distribution.hpp"

namespace distribution
{
    Distribution::Distribution ( file::File const & source )
    {
        for (auto &c:*source.get ())
        {
            __distribution [c] += 1.0;
        }
        __distribution /= source.size ();
    }

    std::unique_ptr <std::valarray <double>> Distribution::set ( file::File const & source )
    {
        for (auto &c:*source.get ())
        {
            __distribution[c] += 1.0;
        }
        __distribution /= source.size ();
        std::unique_ptr <std::valarray <double>> ptr (new std::valarray <double> (__distribution));
        return ptr;
    }

    std::unique_ptr <std::valarray <double>> Distribution::get ()
    {
        std::unique_ptr <std::valarray <double>> ptr (new std::valarray <double> (__distribution));
        return ptr;
    }
}
