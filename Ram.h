//
// Created by 한현민 on 2021-07-09.
//

#ifndef UNTITLED_RAM_H
#define UNTITLED_RAM_H

#define SIZE 1024*100

class Ram {
private:
    char mem[SIZE];
    int size;
public:
    Ram();
    ~Ram();
    char read(int address);
    void write(int address, char value);
};


#endif //UNTITLED_RAM_H
