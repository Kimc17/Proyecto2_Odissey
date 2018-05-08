#include <iostream>
#include <sstream>
#include "XML/pugixml.hpp"
#include "XML/XML_Editor.h"


int main() {
    XML_Editor editor;
    std::string metadata[][2] = {{"song_name", "Untitled"}, {"song_artist", "Simple plan"},
                                 {"song_album", "Untitled"}, {"song_length", "2:00"}};
    std::string songs[][3] = {{"Track 1", "unknown artist", "unknown album"},
                              {"Track 3", "unknown artist", "unknown album"},
                                      {"Track 3", "unknown artist", "unknown album"}};
    std::string song= "1010100000110010110111110";

    std::string doc = editor.writeUploadRequest(metadata, song, sizeof(metadata)/ sizeof(metadata[0]));
    std::cout << doc << std::endl;

    doc = editor.readMessage(doc.c_str());

    doc = editor.writeEditRequest("Untitled", "Simple plan");
    std::cout << doc << std::endl;

    doc = editor.writeEditResponse(metadata, sizeof(metadata)/ sizeof(metadata[0]));
    std::cout << doc << std::endl;

    doc = editor.writeAlbumSearchRequest("unknown album");
    std::cout << doc << std::endl;

    doc = editor.writeSearchResponse(songs, 3);
    std::cout << doc << std::endl;

    doc = editor.writeArtistSearchRequest("unknown artist");
    std::cout << doc << std::endl;

    doc = editor.writeSearchResponse(songs, 3);
    std::cout << doc << std::endl;

    doc = editor.writeNameSearchRequest("Track 1");
    std::cout << doc << std::endl;

    doc = editor.writeSearchResponse(songs, 3);
    std::cout << doc << std::endl;
}

