/***********************************************************************
 
 Written by Leif Shackelford
 Copyright (c) 2014 Chroma.io
 All rights reserved. *
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met: *
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 * Neither the name of CHROMA GAMES nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission. *
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 OF THE POSSIBILITY OF SUCH DAMAGE. *
 ***********************************************************************/

#ifndef __Node_Kitten_X__
#define __Node_Kitten_X__

#include "NKTypes.h"

// UTIL

#include "NKStringUtil.h"
#include "format.h"
#include "NKFileSystem.h"
#include "NKTime.h"

// EVENT
#include "NKAction.h"
#include "NKEvent.h"

//// NODE

#include "NKNode.h"
#include "NKMeshNode.h"
#include "NKBatchNode.h"
#include "NKSceneNode.h"
#include "NKCamera.h"
#include "NKLightNode.h"

//// TEXTURE
#include "NKFrameBuffer.h"
#include "NKTexture.h"
#include "NKTextureManager.h"
#include "NKFrameBuffer.h"

//// SHADERS

#include "NKShaderProgram.h"
#include "NKShaderManager.h"
#include "NKShaderModule.h"
#include "NKShaderTools.h"
// ROOT VIEW
#include "NKView.h"
// OTHERS VIEWS SHOULD BE INCLUDED IN PLATFORM SPECIFIC EXAMPLES

#if (TARGET_IOS || TARGET_OSX)
#include "NKAppleDeviceTools.h"
#endif

#ifdef __OBJC__
#include "NKAppleViews.h"
#include "NKAppleEvent.h"
#endif

#endif

