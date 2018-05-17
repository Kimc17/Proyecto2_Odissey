//
// Created by bamdres16 on 28/04/18.
//

#ifndef ODISSEY_SPOTIFY_SERVICE_H
#define ODISSEY_SPOTIFY_SERVICE_H


#include <iostream>
#include <string>
#include <curl/curl.h>
#include <cstdint>
#include <stdio.h>
#include <memory>
using namespace std;



class Spotify_Service {
public:
    Spotify_Service ();
    void Authorize ();

    string token_access ();


private:
    string access_token;
    string id_client = "cd1eab1c082d4cad9d492adcea7acd89";
    string url = "https://accounts.spotify.com/authorize/?client_id=cd1eab1c082d4cad9d492adcea7acd89&response_type=token&redirect_uri=http://redirectcheck.com&scope=user-read-private%20user-read-email&state=34fFs29kd09";


};


#endif //ODISSEY_SPOTIFY_SERVICE_H
