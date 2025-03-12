#ifndef TASK_H
#define TASK_H
#include "task.h"
#include <string>

Task::Task(int taskid,const std::string& taskdesc,bool completed,int priority):taskid(taskid),taskname(taskdesc),completed(completed),priority(priority)
{
    
}

void Task::print() const
{
    std::cout<<taskid<<" "<<taskname<<" "<<completed<<" "<<priority<<std::endl;
}

void Task::setCompleted(bool completed)
{
    this->completed=completed;
}

void Task::setPriority(int priority)
{
    this->priority=priority;
}

int Task::getTaskId() const
{
    return taskid;
}

std::string Task::getTaskName() const
{
    return taskname;
}
int Task::getTaskPriority()  const
{
    return priority;
}

std::string Task::toString() const {
    return std::to_string(taskid) + " " + taskname + " " +
           (completed ? "1" : "0") + " " + std::to_string(priority);
}


#endif // task_h