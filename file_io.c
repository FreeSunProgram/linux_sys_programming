//
// Created by 孙逍 on 2022/12/5.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd = open("../CMakeLists.txt", O_RDONLY);

    char buffer[130];
    ssize_t rl = read(fd, &buffer, sizeof(buffer));

    printf("size of read: %d\n", rl);
//    printf(buffer);

    fd = open("../output.txt", O_WRONLY | O_CREAT, S_IRWXU);
    rl = write(fd, &buffer, sizeof(buffer));
    printf("size of write : %d\n", rl);

    return 0;
}