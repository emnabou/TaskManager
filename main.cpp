#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "task.h"
#include "TaskManager.h"




int main()
{
    /*std::ifstream taskfile("task.txt");
    if(!taskfile.is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        return 1;
    }

    std::string line;

    while(getline(taskfile,line))
    {
        std::cout<<line<<std::endl;
    }



    taskfile.close();*/
    //TaskManager manager("task.txt");
    //manager.run();
    TaskManager manager("task.txt");
    /*manager.Addtask("Go to the gym",1);
    manager.Addtask("Buy groceries",2);
    manager.Addtask("Do homework",3);
    manager.ListTasks();
    manager.UpdateTask(1,true);
    manager.ListTasks();
    manager.DeleteTask(2);*/
    //manager.ListTasks();
    //manager.run();
    manager.getnextId();
    std::cout<<manager.getnextId()<<std::endl;
    manager.run();
    return 0;
}