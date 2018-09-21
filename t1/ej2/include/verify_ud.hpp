#ifndef _VERIFY_UD_H
#define _VERIFY_UD_H

#include <algorithm>
#include <string>
#include <vector>

class Code
{
    private:

        std::vector <std::string> code;

    public:

        ~Code ();

        std::vector <std::string> & get_data ();

        void add_code (std::string str);
        void add_code (std::vector <std::string> str);

        bool uni_decode ();
};


#endif
