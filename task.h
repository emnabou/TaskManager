#ifndef _TASK_H_
#define _TASK_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Task{
    public:
        Task(int taskid,const std::string& taskdesc,bool completed,int priority);
        void print() const;
        void setCompleted(bool completed);
        void setPriority(int priority);
        int getTaskId() const;
        std::string getTaskName() const;
        int getTaskPriority()  const;
        void getTaskCompleted()  const;
        std::string toString() const;

    private:
        std::string taskname;
        int taskid;
        int priority;
        bool completed;
        std::vector<std::string> lines;
};



#endif // _TASK_H_