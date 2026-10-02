#include "RedisServer.h"
#include "RedisDatabse.h"

#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char* argv[]){
    int port = 6379; //default
    if(argc >=2) port = std::stoi(argv[1]);

    // Background persistance: dump the database every 300 secs ( 5 * 60 save database)
    RedisServer server(port);
    std::thread persistanceThread([](){
        while (true){
            std::this_thread::sleep_for(std::chrono::seconds(300));
            if(!RedisDatabase::getInstance().dump("dump.my_rdb"))
                std::cerr << "Error Dumping Database\n";
            else
                std::cout << "Database dumped to dump.my_rdb\n";

        }
    });

    persistanceThread.detach();

    server.run();

    return 0;
}
