#include "crow.h"
#include <cstdlib>
#include <stdlib.h>

int main()
{
    crow::SimpleApp server;

    const char *HOST = std::getenv("HOST");
    const int PORT = std::atoi(std::getenv("PORT"));

    CROW_ROUTE(server, "/healthcheck")([](){
        return "Status: Healthy";
    });

    server.bindaddr(HOST).port(PORT).multithreaded().run();
}