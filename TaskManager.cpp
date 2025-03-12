#include "TaskManager.h"
#include "task.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>

TaskManager::TaskManager(const std::string& filename):filename(filename),nextId(1)
{
    loadTasks();
}

void TaskManager::Addtask(const std::string& taskname,int priority)
{
    Task task(nextId,taskname,false,priority);
    tasks.push_back(task);
    nextId++;
    std::cout<<"Task added successfully"<<std::endl;
}
void TaskManager::ListTasks() const
{
    for(const Task& task:tasks)
    {
        task.print();
    }
}

void TaskManager::DeleteTask(int taskid)
{
    auto it=std::find_if(tasks.begin(),tasks.end(),[taskid](const Task& task){return task.getTaskId()==taskid;});
    if(it!=tasks.end())
    {
        tasks.erase(it);
        std::cout<<"Task deleted successfully"<<std::endl;
    }
    else
    {
        std::cout<<"Task not found"<<std::endl;
    }
}
void TaskManager::UpdateTask(int taskid,bool completed)
{
    //auto it=std::find_if(tasks.begin(),tasks.end(),[taskid](const Task& task){return task.getTaskId()==taskid;});
    for (auto& task : tasks) {
        if (task.getTaskId() == taskid) {
            task.setCompleted(completed);
            std::cout << "Task updated successfully" << std::endl;
            return;
        }
    }   	

}
    
void TaskManager::loadTasks()
{
    std::ifstream taskfile(filename);
    if(!taskfile.is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        return;
    }
    std::string line;
    while(getline(taskfile,line))
    {
        std::stringstream ss(line);
        std::string taskname;
        int taskid;
        int priority;
        bool completed;
        int leng = line.size();
        //ss>>taskid>>taskname>>completed>>priority;
        taskid=line[0]-'0';
        taskname=line.substr(2,line.size()-6);
        completed=line[line.size()-3]-'0';
        priority=line[line.size()-1]-'0';
        Task task(taskid,taskname,completed,priority);
        tasks.push_back(task);
        if(taskid>=nextId)
        {
            nextId=taskid+1;
        }
    }
    taskfile.close();
    
}
void TaskManager::saveTasks() const {
    std::ofstream file(filename);  // Open file for writing (overwrites existing content)
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for saving tasks.\n";
        return;
    }

    for (const auto& task : tasks) {
        file << task.toString() << "\n";  // Convert each task to a string and write to file
    }

    file.close();  // Close file when done
}

int TaskManager::getnextId() const
{
    return nextId;
}


void TaskManager::run(){

    std::string command;

    std::cout<< "=== Welcome to C++ CLI Task Manager ==="<<std::endl;
    std::cout<< "Type 'help' to see the list of commands"<<std::endl;

    while (true) 
    {
        std::cout<<"\n >";
        std::getline(std::cin,command);
        std::stringstream ss(command);
        std::string action;
        ss>>action;

        if(action=="add")
        {
            std::string taskname;
            int priority;
            int leng = command.size();
            int actlen = action.size();
            taskname = command.substr(actlen+1,leng-actlen-3);
            priority=command[command.size()-1]-'0';
            Addtask(taskname,priority);
        }
        else if(action=="list")
        {
            ListTasks();
        }
        else if(action=="delete")
        {
            int taskid;
            ss>>taskid;
            DeleteTask(taskid);
        }
        else if(action=="update")
        {
            int taskid;
            bool completed;
            ss>>taskid>>completed;
            UpdateTask(taskid,completed);
        }
        /*else if(action=="search")
        {
            std::string taskname;
            ss>>taskname;
            SearchTask(taskname);
        }*/
        else if(action=="exit")
        {
            saveTasks();
            break;
        }
        else if(action=="help")
        {
            std::cout<<"Commands: "<<std::endl;
            std::cout<<"add <taskname> <priority> - Add a new task"<<std::endl;
            std::cout<<"list - List all tasks"<<std::endl;
            std::cout<<"delete <taskid> - Delete a task"<<std::endl;
            std::cout<<"update <taskid> <completed> - Update a task"<<std::endl;
            std::cout<<"search <taskname> - Search for a task"<<std::endl;
            std::cout<<"exit - Exit the program"<<std::endl;
        }
        else
        {
            std::cout<<"Invalid command. Type 'help' to see the list of commands"<<std::endl;
        }

    }
}