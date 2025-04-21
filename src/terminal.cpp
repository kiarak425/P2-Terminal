#include "terminal.h"
#include <iostream>
#include "include/mypipe.h"
#include <process.h>
#include "utility.h"
#include <unistd.h>
#include <sys/wait.h>


// run_cmd:
// Takes a vector of C-style strings (char*), representing the command and its arguments.
// Forks a child process, redirects its standard output (this means use my pipe method redirect),
// and executes the command (use execvp from lecture).
// Captures the output using a custom pipe (mypipe) and prints it to the terminal.
// Returns 0 on success, non-zero on failure.
int run_cmd(std::vector<char *> argv)
{
    //used the lecture code as a structure for the run_cmd
    if(argv.size() == 0){
        std::cerr << "Error: No command\n";
        return -1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return -1;
    }

    mypipe cmd_pipe;

    if(pid == 0){
        //child process from lecture
        cmd_pipe.redirect();
        execvp(argv[0], argv.data());
        perror("Execute Failed");
        exit(127); //from lecture;
    }

    int status{0};
    if(waitpid(pid, &status, 0) == -1){
        perror("Wait Failed");
        return -1;
    }

    std::cout << cmd_pipe.read();
    
    return status;
}

// terminal_app:
// Implements a simple interactive terminal loop.
// Continuously prompts the user for input, parses it into command and arguments,
// and executes the command using run_cmd().
// Exits the loop when the user types "exit".
void terminal_app()
{
    bool not_exit = true;
    std::string userinput;
    while(not_exit){
        std::getline(std::cin, userinput);
        std::vector<std::string> vs_input = cmd2vec(userinput);
        
        if(vs_input[0] == "exit"){
            exit(1);
        }

        std::vector<char *> vc_input = castArgs(vs_input);
        run_cmd(vc_input);

    }
}
