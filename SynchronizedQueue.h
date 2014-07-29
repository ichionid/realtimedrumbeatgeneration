/* 
 * File:   SynchronizedQueue.h
 * Author: Ioannis Chionidis
 *
 * Created on June 4, 2012, 11:11 PM
 */

#ifndef SYNCHRONIZEDQUEUE_H
#define	SYNCHRONIZEDQUEUE_H

#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/date_time.hpp>
#include <queue>
#include <string>
using namespace std;
// Queue class that has thread synchronisation

template <typename T>
class SynchronizedQueue {
private:
    std::queue<T> m_queue; // Use STL queue to store data
    mutable boost::mutex m_mutex; // The mutex to synchronise on
    boost::condition_variable m_cond; // The condition to wait for
    bool dead;//will be raised by the input program in order to kill MarkovEngineConsumer
public:
    
    bool check_kill(){
        return dead;
    }
    
    void kill_threads(){
        dead = true;
    }
    
    SynchronizedQueue() {
        dead = false;
        cout << "SynchronizedQueue Constructor" << endl;
    }
    // Add data to the queue and notify others

    void Enqueue(T data) {
        // Acquire lock on the queue
        boost::unique_lock<boost::mutex> lock(m_mutex);

        // Add the data to the queue
        m_queue.push(data);

        // Notify others that data is ready
        m_cond.notify_one();

    } // Lock is automatically released here

    // Get data from the queue. Wait for data if not available

    T Dequeue() {

        // Acquire lock on the queue
        boost::unique_lock<boost::mutex> lock(m_mutex);
        //lock();
        // When there is no data, wait till someone fills it.
        // Lock is automatically released in the wait and obtained 
        // again after the wait
        while (m_queue.size() == 0) m_cond.wait(lock);

        // Retrieve the data from the queue
        T result = m_queue.front();
        m_queue.pop();
        return result;
    } // Lock is automatically released here

    ~SynchronizedQueue() {
        cout << "SynchronizedQueue Destructor" << endl;
    }
};

#endif