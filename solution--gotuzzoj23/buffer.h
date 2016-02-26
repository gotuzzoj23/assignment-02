//
//  buffer.hpp
//  shapes 121
//
//  Created by Jose Gotuzzo, Robert Gonzalez, Griffin Yee on 2/26/16.
//  Copyright © 2016 Jose Gotuzzo. All rights reserved.//


#ifndef BUFFER_H
#define BUFFER_H

#include <string>

class Buffer {
private:
    char * data_;
    
public:
    const unsigned int size_x;
    
    const unsigned int size_y;
   
    Buffer(unsigned int size_x, unsigned int size_y);
    
    ~Buffer();
    
    char get(unsigned int x, unsigned int y) const;
    
    void set(unsigned int x, unsigned int y, char c);
    
    void set(unsigned int pos_x, unsigned int pos_y, std::string s);
    
    
    void draw() const;
    
    
    
    void clear();
   
};

#endif
