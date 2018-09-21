#include "verify_ud.hpp"

Code :: ~Code ()
{
    code.clear ();
}

std::vector <std::string> & Code :: get_data ()
{
    return code;
}

void Code :: add_code (std::string str)
{
    code.push_back (str);
}

void Code :: add_code (std::vector <std::string> str)
{
    for (auto s:str)
    {
        code.push_back (s);
    }
}

bool starts_with (std::string str1 , std::string str2)
{
    return (str1.substr (0, std::min (str2.size (), str1.size ())).compare (str2))? false : true;
}

bool Code :: uni_decode ()
{
    sort (code.begin (), code.end ());
    bool univ_decod = true;
    std::vector <std::string> new_suffix;
    for (auto s:code)
    {
        new_suffix.push_back (s);
    }
    for (int it = 0; it != new_suffix.size (); ++it)
    {
        for (int it2 = 0; it2 != new_suffix.size (); ++it2)
        {
            if (it != it2)
            {
                if (starts_with (new_suffix [it], new_suffix [it2]))
                {
                    if (std::find (code.begin (), code.end (), new_suffix [it].substr (new_suffix [it2].size ())) != code.end ())
                    {
                        univ_decod = false;
                        break;
                    }
                    if (std::find (new_suffix.begin (), new_suffix.end (), new_suffix [it].substr (new_suffix [it2].size ())) == new_suffix.end ())
                    {
                        new_suffix.push_back (new_suffix [it].substr (new_suffix [it2].size ()));
                    }
                }
            }
        }
    }
    new_suffix.clear ();
    return univ_decod;
}
