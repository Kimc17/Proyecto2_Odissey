//
// Created by bamdres16 on 28/04/18.
//

#include "Spotify_Service.h"
Spotify_Service ::Spotify_Service() {

}
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

static void
print_cookies(CURL *curl)
{
    CURLcode res;
    struct curl_slist *cookies;
    struct curl_slist *nc;
    int i;

    printf("Cookies, curl knows:\n");
    res = curl_easy_getinfo(curl, CURLINFO_COOKIELIST, &cookies);
    if(res != CURLE_OK) {
        fprintf(stderr, "Curl curl_easy_getinfo failed: %s\n",
                curl_easy_strerror(res));
        exit(1);
    }
    nc = cookies;
    i = 1;
    while(nc) {
        printf("[%d]: %s\n", i, nc->data);
        nc = nc->next;
        i++;
    }
    if(i == 1) {
        printf("(none)\n");
    }
    curl_slist_free_all(cookies);
}
void Spotify_Service ::Authorize() {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,
                         "https://accounts.spotify.com/authorize/?client_id=cd1eab1c082d4cad9d492adcea7acd89&response_type=token&redirect_uri=http://redirectcheck.com");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);



        char *url;
        cout << readBuffer << endl;
        curl_easy_cleanup(curl);

    }


}
string Spotify_Service ::token_access() {
    CURL *curl;
    struct curl_slist *headers = NULL;
    string rescode;
    curl = curl_easy_init();
    if (curl) {
    }

}