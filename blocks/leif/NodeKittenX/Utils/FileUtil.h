//
//  FileUtil.h
//  NodeKittenX
//
//  Created by Leif Shackelford on 2/1/15.
//  Copyright (c) 2015 structuresound. All rights reserved.
//

#ifndef __NodeKittenX__FileSystem__
#define __NodeKittenX__FileSystem__

#include "CommonTypes.h"

//! Structure that allows you to manipulate memory stream.
class File
{
    //! The filename used by the MEMORY structure.
    string			_filename;
    
    //! The file size in bytes.
    unsigned long	_size {0};
    
    //! The position of the cursor within the memory buffer.
    unsigned long	_position {0};
    
    //! The memory buffer.
    unsigned char	*_buffer {nullptr};
    
public:
    
    static string appDirectory();
    static string pathForFileNamed(string name);
    
    File(string& filename, bool relative_path);
    ~File();
    
    unsigned long size(){return _size;};
    string filename(){return _filename;};
    unsigned char	*data(){return _buffer;};
    
    unsigned long read(void *dst, unsigned long size );
    void insert(char *str, unsigned long position );
    
};


#endif /* defined(__NodeKittenX__FileSystem__) */
