#include "hook.h"
#include <dlfcn.h>

#include "config.h"
#include "log.h"
#include "fiber.h"
#include "iomanager.h"
#include "fd_manager.h"
#include "macro.h"

sylar::Logger::ptr g_logger = SYLAR_LOG_NAME("system");
namespace sylar{

static sylar::ConfigVar<int>::ptr g_tcp_connect_timeout =
    sylar::Config::Lookup("tcp.connect.timeout", 5000, "tcp connect timeout"); 

static thread_local bool t_hook_enable = false;

#define HOOK_FUN(XX) \
    XX(sleep) \
    XX(usleep) \
    XX(nanosleep) \
    XX(socket) \
    XX(connect) \
    XX(accept) \
    XX(read) \
    XX(readv) \
    XX(recv) \
    XX(recvfrom) \
    XX(recvmsg) \
    XX(write) \
    XX(writev) \
    XX(send) \
    XX(sendto) \
    XX(sendmsg) \
    XX(close) \
    XX(fcntl) \
    XX(ioctl) \
    XX(getsockopt) \
    XX(setsockopt)

    void hook_init(){
        static bool is_inited = false;
        if(is_inited) {
            return;
        }
#define XX(name) name ## _f = (name ## _fun)dlsym(RTLD_NEXT, #name);
    HOOK_FUN(XX);
#undef XX
    }

}