#include <cstring>
#include "XML.h"


using namespace std;


pugi::xml_node XML:: Cargar(char name[]){
    pugi::xml_document doc;

// Para cargar el documento
    pugi::xml_parse_result result = doc.load_file(name);
    std::cout << "Parseado con éxito: " << result.description() << std::endl;
//Asignar el primer nodo a una variable
    pugi::xml_node players = doc.first_child();
    return players;
}
bool buscanombre(pugi::xml_node node, char name[])
{
    return (!strcmp(node.name(), name));
}

string nombreNodo(pugi::xml_node nodo){
    return nodo.name();
}
string valorHijo(pugi::xml_node nodo){
    return nodo.child_value();
}
pugi::xml_node IralHijo(pugi::xml_node nodo){
    return  nodo.next_sibling();
}
/*
pugi::xml_document XML::AgregarNodo(pugi::xml_document doc, char nombre[], char descripcion[], char valor[] ) {
    pugi::xml_node node = doc.append_child(nombre);
    pugi::xml_node descr = node.append_child(descripcion);
    descr.append_child(pugi::node_pcdata).set_value(valor);
    return doc;
}

pugi::xml_document XML::RemoverDescripNodo(pugi::xml_document doc, char nombre[],char descripcion[]) {

    pugi::xml_node node = doc.child(nombre);
    node.remove_child(descripcion);
}
pugi::xml_document XML::RemoverValorNodo(pugi::xml_document doc, char nombre[], char* param[],char valor[]) {

    pugi::xml_node param = doc.child(nombre).child(*param);
    param.remove_attribute(valor);
}
*/
