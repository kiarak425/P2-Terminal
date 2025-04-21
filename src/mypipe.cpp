#include "include/mypipe.h"
#include <unistd.h>
#include <sys/wait.h>

mypipe::mypipe()
{
    //From lecture slide 74
    auto status{pipe(fd)};
    if(status < 0){
        exit(1);
    }
}

mypipe::~mypipe()
{
    //From lecture slide 74
    close(fd[0]);
    close(fd[1]);
}

void mypipe::redirect()
{
    //From lecture slide 75
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
}

std::string mypipe::read()
{
    //From lecture slide 76
    std::array<char, 256> temp;
    std::size_t filesize;
    filesize = ::read(fd[0], temp.data(), temp.size());
    if(filesize > 0){
        return std::string{temp.data(), filesize};
    }
    return {};
}
