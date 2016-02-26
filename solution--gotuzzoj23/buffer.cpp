//
//  buffer.cpp
//  shapes 121
//
//  Created by Jose Gotuzzo, Robert Gonzalez, Griffin Yee on 2/26/16.
//  Copyright © 2016 Jose Gotuzzo. All rights reserved.
//

/**
 * Implements `buffer.h`.
 */
// TODO: `#include`s for system headers, if necessary

#include<iostream>
#include<cstdlib>
#include "buffer.h"
using std::cout;
using std::cin;
using std::endl;

// TODO: `#include`s for other local headers, if necessary

// ----------------------------------------------------------------------------

Buffer::Buffer(unsigned int size_x, unsigned int size_y) : size_x(size_x), size_y(size_y)
{
    data_ = new char[size_x*size_y];
    clear();
}
/**
 * The constructor.
 *
 * Must initialize `size_x` and `size_y`, and allocate memory for (and
 * initialize) `data_`.
 *
 * Notes:
 * - Since `size_x` and `size_y` are constant, they must be initialized
 *   in the initialization list, rather than set in the constructor
 *   body.
 * - You may assume that the dynamic memory allocation succeeds.
 */

Buffer::~Buffer() {
    delete[] data_;
}
/**
 * The destructor.
 *
 * Must free the memory that the constructor allocated to `data_`.
 */


char Buffer::get(unsigned int x, unsigned int y) const {
    
    if (x >= size_x || y >= size_y) {
        std::cerr << "ERROR: `Buffer::get`: index out of bounds\n";
        exit(1);
    }
    return data_[y * size_x + x];
}

/**
 * Return the character at `data_[ y * size_x + x ]`.
 *
 * If `x` or `y` is out of bounds, should write
 * ```
 * "ERROR: `Buffer::get`: index out of bounds\n"
 * ```
 * to `cerr` and `exit(1)`.
 */

void Buffer::set(unsigned int x, unsigned int y, char c) {
    
    if (x >= size_x || y >= size_y)
    {
        std::cerr << "ERROR: `Buffer::get`: index out of bounds\n";
        exit(1);
    }
    data_[y * size_x + x] = c;
}
/**
 * Set the character at `data_[ y * size_x + x ]` to `c`.
 *
 * If `x` or `y` is out of bounds, should write
 * ```
 * "ERROR: `Buffer::set`: index out of bounds\n"
 * ```
 * to `cerr` and `exit(1)`.
 */

void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s)
{
    for (int i = 0, a = pos_x, b = pos_y; i < s.length(); i++)
    {
        if (s[i] == '\n')
        {
            b++;
            a = pos_x;
        }
        else
        {
            set(a++, b, s[i]);
        }
    }
}

/**
 * Overlay `s` onto `data_`.
 *
 * For example, if this buffer is representing an array that looks like
 * ```
 * *******
 * *******
 * *******
 * *******
 * *******
 * ```
 * and we call `set(1, 2, "hello\nworld")`, the buffer's contents
 * should now be
 * ```
 * *******
 * *******
 * *hello*
 * *world*
 * *******
 * ```
 *
 * Notes:
 * - This function may call the other `set` (which takes a `char` as
 *   its last argument), if you like.  In that case, you may leave the
 *   index error checking to the other `set`.  Otherwise, you should
 *   have checks in this function to make sure you're not putting
 *   characters where they don't belong.
 * - This function will be useful when implementing the `Shape` class.
 * - If you can't think of a way to do this, see
 *   `hint--implementation-of-Buffer-set.md`.
 */


void Buffer::draw() const
{
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
            cout << get(x, y);
    }
    cout << endl;
}



/*OUTPUT THE CONTENTS OF THE BUFFER TO 'COUT'.
 *[Feb 17] I have no idea if this is right, if you guys could, correct it,
 * i may look online, dont know, but yea
 */




void Buffer::clear()
{
    for (unsigned int z = 0; z < size_x*size_y; z++)
        data_[z] = ' ';
    
};

/*seT each element data_ " "*/

/*Robert(Feb 9,16)- So, not sure what to do for the "void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s)"
 *funciton, so i decided to do this one real quick. Go ahead and check if it's right, please*/