#include "UserInput.h"

int main(int argc, char* argv[])
{
    UserInput* input = new UserInput();
    input->getUserInput();
    
    delete input;

    return 0;
}