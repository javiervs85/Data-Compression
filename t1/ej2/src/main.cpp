/*  Ejercicio 2 : Tarea 1 - Image Compression
 *  autor       : José Joaquín Zubieta Rico
 *  date        : 08-30-2018
 *  subject     : Is it for some subject?
 *  description : Ejercicio uno de la primer tarea de compresión de imágenes, verificar si un código es unívocamente decodificable o no.
 #  license     : GPL v3 (https://www.gnu.org/licenses/gpl-3.0.en.html)
 */

#include "verify_ud.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main ( int argc , char * const argv [] )
{
    std::vector <std::string> code = {"0", "01", "11"};
    std::vector <std::string> code2 = {"0", "01", "10"};
    //std::vector <std::string> code2 = {"0", "01", "11", "111"};

    Code vcode, vcode2;

    vcode.add_code (code);
    vcode2.add_code (code2);

    std::cerr << vcode.uni_decode () << std::endl;
    std::cerr << "cosa!!!\n" << std::endl;
    std::cerr << vcode2.uni_decode () << std::endl;

    return 0;
}
