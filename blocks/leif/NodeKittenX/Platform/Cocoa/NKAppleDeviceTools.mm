//
//  NKAppleDeviceTools.m
//  NodeKittenX
//
//  Created by Leif Shackelford on 1/18/15.
//  Copyright (c) 2015 structuresound. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "NKAppleDeviceTools.h"

namespace NKApple {
    
    string NSToCppString(NSString *s){
        
        return string([s cStringUsingEncoding:NSUTF8StringEncoding]);
        
    }
    
    
    NSString* cppToNSString(string str){
        return [NSString stringWithUTF8String:str.c_str()];
    }
    
    string appDirectory(){
#if TARGET_OSX
        return NSToCppString([[NSBundle mainBundle] bundlePath]) + "/Contents/Resources/";
#elif TARGET_IOS
        return NSToCppString([[NSBundle mainBundle] bundlePath]) + "/";
#endif
        
    }
    
    string pathForResource(string name, string ext) {
        return NSToCppString([[NSBundle mainBundle] pathForResource:cppToNSString(name) ofType:cppToNSString(ext)]);
    }
    
}