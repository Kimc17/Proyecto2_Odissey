//
// Created by karina on 05/05/18.
//

#ifndef PROYECTO2_ODISSEY_XMLEDITOR_H
#define PROYECTO2_ODISSEY_XMLEDITOR_H

#include "pugixml.hpp"
class XML_Editor {
public:
    std::string readMessage(const char xml[]);
    std::string readDoc();
    std::string writeEditRequest(std::string name, std::string artist);
    std::string writeDeleteRequest(std::string name, std::string artist);
    std::string writeNameSearchRequest(std::string name);
    std::string writeArtistSearchRequest(std::string artist);
    std::string writeAlbumSearchRequest(std::string albumName);
    std::string writeLyricSearchRequest(std::string lyric);
    std::string writeEditResponse(std::string metadata[][2], int rows);
    std::string writeSearchResponse(std::string songs[][3], int rows);
    std::string writeUploadRequest(std::string metadata[][2], std::string song, int rows);
};


#endif //PROYECTO2_ODISSEY_XMLEDITOR_H
