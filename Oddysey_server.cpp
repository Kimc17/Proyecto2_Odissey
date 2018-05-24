#include <fstream>
#include "Oddysey_server.h"
#define SIZE 2048*100
#include "pugixml.hpp"
#include "List.h"
#include "Chunk.h"

/* Pasos para la ejecucion del servidor:
 * 1. Abrir una terminal
 * 2. Cambiar el directorio con: cd C-
 * 3. Escribir el comando: g++ Base64.cpp Chunk.cpp pugixml.cpp  Odyssey_Server.cpp -o server
a-ljsoncpp -std=c++11

 * 4. Ingresar ./server
*/

void *manejador_conexion(void *);

List<char *> Chunks();
long tam();
pugi::xml_document XML(int codigo);

int socket_desc , client_sock , c;
struct sockaddr_in server , client;

int main() {
    Server *server = new Server;
    server->crear();
    }


int Server::crear() {
    //Crea el socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("No se pudo crear el socket");
    }
    puts("\n\n                           ********SERVER********                 ");
    puts("\n\nEscuchando en el puerto 8888\n ");

    //Prepara el socket(esto es definido)
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    //Enlazar el servidor
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("Enlace fallido");
        return 1;
    }


    //Escuhar si llegan conexiones
    listen(socket_desc , 3);




    //Se aceptan y  esperan las conexiones
    puts("Esperando por conexiones...");
    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;

    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Conexion aceptada");

        //Creacion del hilo para mas de un cliente
        if( pthread_create( &thread_id , NULL ,  manejador_conexion, (void*) &client_sock) < 0)
        {
            perror("No se pudo crear el thread");
            return 1;
        }

        //pthread_join( thread_id , NULL); // Esta es la base del Thread
    }

    if (client_sock < 0)
    {
        perror("Fallo aceptado");
        return 1;
    }
}







using namespace std;
void *manejador_conexion(void *socket_desc) {
    //Se obtiene el descriptor del socket
    int sock = *(int *) socket_desc;
    int read_size;
    char client_message[200];




    //Recibir mensajes del cliente
    while ((read_size = recv(sock, client_message, 300, 0)) > 0) {
        client_message[read_size] = '\0';

        // Enviar mensaje de vuelta al cliente
        pugi::xml_document doc = XML(00);
        //pugi::xml_document doc;
       // pugi::xml_parse_result result = doc.load_file("ejemplo.xml");
        // Escribe un documento xml completo en stdout
        //std :: cout << "\nchar:" << std :: endl;
        //doc.save (std :: cout, "" );


        // Escribe un documento xml completo en la secuencia de cadenas
        std::cout << "\nEscribe el documento xml en stringstream:" << std::endl;
        std::stringstream ss;
        doc.save(ss, "");
        std::cout << "El XML es: \n" << ss.str() << std::endl;
        ss.str() += "+";


        send(sock, ss.str().c_str(), ss.str().length(), 0);
        //memset(client_message, 0, 2000);

        //Mensaje recibido por el cliente
        cout << "Recibido " << client_message << endl;

    }

    // Si se desconecta el cliente
    if (read_size == 0) {
        puts("Cliente desconectado");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("Fallo");
    }
}




List<char*> Chunks() {
   cout <<"hola";
    List<char *>* ListaChunks= new List<char *>();
    FILE *fichero, *fichDest; /* ficheros para pobar*/
    char *buffer; /* El buffer para guardar los datos leidos */
    /* Los nombres de los ficheros */
    char nombreDest[80]= "ejemplo.mp3", nombreDest1[80],partes[80];
    long longitud; /* Tamaño del fichero */
    long cantidad; /* El número de bytes leídos */
   int i,num_partes=4;
    /* Acceder al fichero de origen */
    char nombreOrg[]= "/home/kimberlyc/CLionProjects/Main/mp3/ejemplo.mp3";
    if ((fichero = fopen(nombreOrg, "rb")) == NULL)  {
        printf("No existe el fichero\n");
        exit(1);
    }

    if ((fichDest = fopen(nombreDest, "wb")) == NULL)  {
        printf("No se ha podido crear el fichero destino!\n");
        exit(2);
    }
    /* Se clacula la longitud del archivo */
    fseek(fichero, 0, SEEK_END);
    longitud = ftell(fichero);
    fseek(fichero, 0, SEEK_SET);
    if ((fichDest = fopen(nombreDest, "wb")) == NULL)  {
        printf("No se ha podido crear el fichero de destino\n");
        exit(2);
    }
    /* Buffer de memoria para leer todo */
    buffer = (char *) malloc (longitud);
    if (buffer == NULL)  {
        printf("No se pudo reservar\n");
        exit(3);
    }

    for(i=0; i <num_partes; i++) {
        sprintf(partes, "00%i_", i);
        strcat(partes,nombreDest1 );
        if ((fichDest = fopen(partes, "wb")) == NULL)  {
            printf("No se ha podido crear el fichero de destino\n");
            exit(4);
        }
        /* Se lee por partes */
        fseek(fichero, i*longitud/num_partes, SEEK_SET);
        cantidad = fread( buffer, 1, longitud/num_partes, fichero);
       /*Se guarda cada parte*/
        fwrite(buffer, 1, cantidad, fichDest);
        if (cantidad != longitud/num_partes)
            printf("No se han generado todos los archivos\n");
        strcpy(nombreDest1, nombreDest);
        ListaChunks->Insert(buffer);
    }
    /* Ceerrar ficheros*/
    fclose(fichero);
    fclose(fichDest);
    cout <<"holaaaaa";
    return *ListaChunks;

}
long tam(){
    char nombreOrg[]= "/home/kimberlyc/CLionProjects/untitled/mp3/ejemplo.mp3";
    FILE *fichero;
    fichero = fopen(nombreOrg, "rb");
    fseek(fichero, 0, SEEK_END);
    long longitud = ftell(fichero);
    fseek(fichero, 0, SEEK_SET);
    return longitud;

}




pugi::xml_document XML(int codigo) {
    // codigo leido del xml en el cliente
    pugi::xml_document doc;
    List<char *> ListaChunks = Chunks();

    //cout << "El tamaño de la lista es " << ListaChunks.length()<<"\n";

    if (codigo == 00) {
        pugi::xml_node node = doc.append_child("comunicacion");
        pugi::xml_node descr0 = node.append_child("codigo");
        descr0.append_child(pugi::node_pcdata).set_value("00");

            std::string ss = std::to_string(0); //Aqui va el numero de chunk pedido
            char const *num = ss.c_str();
            std::string s = std::to_string(ListaChunks.length());
            char const *cantChunks = s.c_str();


            pugi::xml_node descr3 = node.append_child("offset");
            descr3.append_child(pugi::node_pcdata).set_value(num);
            pugi::xml_node descr4 = node.append_child("limite");
            descr4.append_child(pugi::node_pcdata).set_value(cantChunks);

            pugi::xml_node descr5 = node.append_child("Data");
            descr5.append_child(pugi::node_pcdata).set_value("Para el Json");

            std::ostringstream oss;
            oss << ListaChunks.Get(0);
            std::string buffer = oss.str();

           char const *buff = buffer.c_str();

            pugi::xml_node descr6 = node.append_child("mBytes");
            descr6.append_child(pugi::node_pcdata).set_value(buff);

            pugi::xml_node param = node.insert_child_after("param", descr5);


            //long tamanio = tam();

            param.append_attribute("nombre") = "Sutra";
            //param.append_attribute("tamaño") = tamanio;
            param.insert_attribute_after("path", param.attribute("nombre")) = "/home/kimberlyc/CLionProjects/Main/mp3/ejemplo.mp3";

        }
    return doc;
    }



