#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "task.h"
#include "TaskManager.h"




int main()
{
    TaskManager manager("task.txt");
    manager.run();
    return 0;
}
