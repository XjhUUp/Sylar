/**
 * @file daemon.h
 * @brief 守护进程启动
 * @version 0.1
 * @date 2021-12-09
 */

#ifndef __SYLAR_DAEMON_H__
#define __SYLAR_DAEMON_H__

#include <unistd.h>
#include <functional>
#include "singleton.h"

namespace sylar {
struct ProcessInfo {
    /// 父进程id
    pid_t parent_id = 0;
    /// 主进程id
    pid_t main_id = 0;
    /// 父进程启动时间
    uint64_t parent_start_time = 0;
    /// 主进程启动时间
    uint64_t main_start_time = 0;
    /// 主进程重启的次数
    uint32_t restart_count = 0;

    std::string toString() const;
};




}