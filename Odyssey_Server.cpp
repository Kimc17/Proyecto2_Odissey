#include "Odyssey_Server.h"
#include "Base64.h"
#include ".idea/Chunk.h"


/* Pasos para la ejecucion del servidor:
 * 1. Abrir una terminal
 * 2. Cambiar el directorio con: cd C-
 * 3. Escribir el comando g++ -pthread Base64.cpp Odyssey_Server.cpp -o server


 -ljsoncpp -std=c++11

 * 4. Ingresar ./server
*/
void *manejador_conexion(void *);
int socket_desc , client_sock , c;
struct sockaddr_in server , client;

int main(){
    Chunk *nuevo = new Chunk();
    size_t hola=  nuevo->Dividir("/home/kimberlyc/Música/Believer.mp3");
    Server* server= new Server;
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
    const char *message;
    //Recibir mensajes al cliente
    while ((read_size = recv(sock, client_message, 200, 0)) > 0) {
        //Final del marcador del string respuesta
        client_message[read_size] = '\0';
        //Enviar mensaje de vuelta al cliente
        send(sock,"Bienvenido a mi servidor",32,0);
        write(sock, "Probando", 8);
        //memset(client_message, 0, 2000);
        cout << "Recibido "<< client_message<< endl;







    }

    // Si se desconecta el cliente (en este caso se cierra la terminal)
    if (read_size == 0) {
        puts("Cliente desconectado");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("Fallo");
    }

}






