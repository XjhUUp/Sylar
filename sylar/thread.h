#ifndef __SYLAR_THREAD_H__
#define __SYLAR_THREAD_H__

#include "mutex.h"

namespace sylar{

class Thread:Noncopyable{
public:
    //线程智能指针类型
    typedef std::shared_ptr<Thread>ptr;

    //构造函数
    Thread(std::function<void()> cb, const std::string &name);

    //析构函数
    ~Thread();

    //线程ID
    pid_t getId() const {return m_id;}

    //线程名称
    const std::string &getName() const { return m_name; }

    //等待线程执行完成
    void join();

    //霍去病当前线程指针
    static Thread *GetThis();

    static const std::string &GetName();


    static void SetName(const std::string &name);


private:
    //线程id
    pid_t m_id=-1;
    //线程结构
    pthread_t m_thread=0;
    //线程执行函数
    std::function<void()> m_cb;
    //线程名称
    std::string m_name;
    /// 信号量
    Semaphore m_semaphore;
}

}
#endif