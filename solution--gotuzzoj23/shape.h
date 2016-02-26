//
//  shape.hpp
//  shapes 121
//
//  Created by Jose Gotuzzo, Robert Gonzalez, Griffin Yee on 2/26/16.
//  Copyright © 2016 Jose Gotuzzo. All rights reserved.//

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

#include "buffer.h"
#include "neighborhood.h"

class Neighborhood;

class Shape {
private:
    std::string type_;
    
    std::string type_art_;
    
public:
    static const unsigned int size_x = 5;
    
    static const unsigned int size_y = 3;
    
    Shape(const std::string & type="empty");
   
    ~Shape();
    
    std::string getType();
    
    void setType(const std::string & type);
    
    void drawToBuffer(Buffer & b, unsigned int x, unsigned int y) const;
   
    bool isHappy( const Neighborhood & n,
                 unsigned int x,
                 unsigned int y ) const;
    
};

#endif
