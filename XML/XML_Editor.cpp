//
// Created by karina on 05/05/18.
//

#include <iostream>
#include <sstream>
#include "XML_Editor.h"

std::string XML_Editor::writeUploadRequest(std::string metadata[][2], std::string song, int rows) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("02");
    auto data = root.append_child("data");
    for(int i = 0; i < rows; ++i){
        auto song_data = data.append_child(metadata[i][0].c_str());
        song_data.append_child(pugi::node_pcdata).set_value(metadata[i][1].c_str());
    }
    auto song_bytes = data.append_child("song");
    song_bytes.append_child(pugi::node_pcdata).set_value(song.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::readMessage(const char xml[]) {
    pugi::xml_document doc;
    doc.load_string(xml);
    std::string subject = doc.child("root").child("subject").text().get();
    if(subject == "01"){

    }
}

std::string XML_Editor::readDoc() {
    return std::__cxx11::string();
}

std::string XML_Editor::writeEditRequest(std::string name, std::string artist) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("03");
    auto data = root.append_child("data");

    auto song_name = data.append_child("song");
    song_name.append_child(pugi::node_pcdata).set_value(name.c_str());

    auto song_artist = data.append_child("artist");
    song_artist.append_child(pugi::node_pcdata).set_value(artist.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeDeleteRequest(std::string name, std::string artist) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("05");
    auto data = root.append_child("data");

    auto song_name = data.append_child("song");
    song_name.append_child(pugi::node_pcdata).set_value(name.c_str());

    auto song_artist = data.append_child("artist");
    song_artist.append_child(pugi::node_pcdata).set_value(artist.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeNameSearchRequest(std::string name) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("08");
    auto data = root.append_child("data");
    auto song_bytes = data.append_child("song_name");
    song_bytes.append_child(pugi::node_pcdata).set_value(name.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeArtistSearchRequest(std::string artist) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("09");
    auto data = root.append_child("data");
    auto song_bytes = data.append_child("song_artist");
    song_bytes.append_child(pugi::node_pcdata).set_value(artist.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeAlbumSearchRequest(std::string albumName) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("07");
    auto data = root.append_child("data");
    auto song_bytes = data.append_child("song_album");
    song_bytes.append_child(pugi::node_pcdata).set_value(albumName.c_str());

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeLyricSearchRequest(std::string lyric) {
    return std::__cxx11::string();
}

std::string XML_Editor::writeEditResponse(std::string metadata[][2], int rows) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("14");
    auto data = root.append_child("data");
    for(int i = 0; i < rows; ++i){
        auto song_data = data.append_child(metadata[i][0].c_str());
        song_data.append_child(pugi::node_pcdata).set_value(metadata[i][1].c_str());
    }

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}

std::string XML_Editor::writeSearchResponse(std::string songs[][3], int rows) {
    pugi::xml_document doc;
    // Generate XML declaration
    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version")    = "1.0";
    // A valid XML doc must contain a single root node of any name
    auto root = doc.append_child("root");
    auto subject = root.append_child("subject");
    subject.append_child(pugi::node_pcdata).set_value("04");
    auto data = root.append_child("data");
    for(int i = 0; i < rows; ++i){
        auto song_data = data.append_child("song");
        song_data.append_child(pugi::node_pcdata).set_value(songs[i][0].c_str());
        song_data.append_child(pugi::node_pcdata).set_value(songs[i][1].c_str());
        song_data.append_child(pugi::node_pcdata).set_value(songs[i][2].c_str());
    }

    // Write complete xml document to string stream
    std::stringstream ss;
    doc.save(ss,"  ");

    return ss.str();
}
