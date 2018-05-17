//
// Created by bamdres16 on 15/05/18.
//

#ifndef ODISSEY_MAYUSCONVERT_H
#define ODISSEY_MAYUSCONVERT_H

#include <string>
using namespace std;
class mayusConvert {
public:
    mayusConvert (){}
    string mayus(string &str) {

        str[0] = ::toupper( str[0] );
        for ( string::iterator it = str.begin(); it != str.end(); it++ )
            if ( *it == ' ' )
                *( it+1 ) = ::toupper( *( it+1 ) );
        return str;

    }
};


#endif //ODISSEY_MAYUSCONVERT_H
