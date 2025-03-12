# TaskManager

This is a simple a project that put in practice clean C++ design, file handling, and practical usage of OOP and STL
It aims at creating an interactive CL task manager that allows :
  1. add new task
  2. delete task
  3. update task to completed
  4. List the tasks
  5. save task when exiting the app
  6. Loading the previous task when starting the app
There are two main classes: task and TaskManager
A task is characterized by an id, description, completed(bool) and priority
The task Manager plays as the controller for the app as it implements the functions:
AddTask, deleteTask, updateTask, ListTasks, saveTasks and Loadtasks.
The run() function is the command loop allowing to enter command until "exit" is typed

