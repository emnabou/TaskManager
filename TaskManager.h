#ifndef TaskManager_h
#define TaskManager_h

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "task.h"

class TaskManager{
    public:
        TaskManager(const std::string& filename);
        void Addtask(const std::string& taskname,int priority);
        void ListTasks() const;
        void DeleteTask(int taskid);
        void UpdateTask(int taskid,bool completed);
        //void SearchTask(std::string taskname);
        int getnextId() const;
        void run();
        int nextId;

    private:
        std::vector<Task> tasks;
        
        std::string filename;
        void loadTasks();
        void saveTasks() const;

};








#endif // taskmanager_h