#include "sylar/http/http_server.h"
#include "sylar/log.h"

sylar::Logger::ptr g_logger=SYLAR_LOG_ROOT(); 

void run(){
    sylar::Address::ptr addr = sylar::Address::LookupAnyIPAddress("0.0.0.0:8020");
    if(!addr){
        ;
    }
    sylar::http::HttpServer::ptr http_server(new sylar::http::HttpServer(true));
    while(!http_server->bind(addr)){
        sleep(1);
    }
    http_server->start();
}

int main(int argc,char **argv){
    sylar::IOManager iom(1);
    iom.schedule(run);
    return 0;

}