//
//  Scene.m
//  example-ofxTableView
//
//  Created by Chroma Developer on 2/17/14.
//
//

#include "Scene.h"
#include "FrameBuffer.h"
#include "SceneController.h"
#include "Camera.h"
#include "TimeUtil.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Light.h"
#include "Label.h"
#include "Action.h"
#include "CollectionView.h"

#if NK_LOG_METRICS
unsigned int Scene::draws {0};
unsigned int Scene::fps {0};
#endif

Scene* Scene::activeScene = nullptr;

Scene::Scene(S2t size) : View(size){
    
#if NK_USE_MIDI
    [[NKMidiManager sharedInstance] setDelegate:self];
    _midiReceivedBlocks = [[NSMutableDictionary alloc]init];
#endif
    
#if NK_GL_DEBUG
    // Obtain iOS version
    int OSVersion_ = 0;
    
#if (TARGET_IOS || TARGET_OSX)
#if TARGET_IOS
    NSString *OSVer = [[UIDevice currentDevice] systemVersion];
#elif TARGET_OSX
    SInt32 versionMajor, versionMinor, versionBugFix;
    Gestalt(gestaltSystemVersionMajor, &versionMajor);
    Gestalt(gestaltSystemVersionMinor, &versionMinor);
    Gestalt(gestaltSystemVersionBugFix, &versionBugFix);
    
    NSString *OSVer = [NSString stringWithFormat:@"%d.%d.%d", versionMajor, versionMinor, versionBugFix];
#endif
    NSArray *arr = [OSVer componentsSeparatedByString:@"."];
    int idx = 0x01000000;
    for( NSString *str in arr ) {
        int value = [str intValue];
        OSVersion_ += value * idx;
        idx = idx >> 8;
    }
    NSLog(@"OS version: %@ (0x%08x)", OSVer, OSVersion_);
    //char* glExtensions = (char*)glGetString(GL_EXTENSIONS);
    //NSLog(@"GL EXT: %@",[NSString stringWithCString:glExtensions encoding: NSASCIIStringEncoding]);
#endif
    nkLog("GL_VENDOR:   %s", glGetString(GL_VENDOR) );
    nkLog("GL_RENDERER: %s", glGetString ( GL_RENDERER   ) );
    nkLog("GL_VERSION:  %s", glGetString ( GL_VERSION    ) );
#endif
    
    name = "scene";
    
    backgroundColor = {.2, .2, .2, 1.0};
    _userInteractionEnabled = true;
    
    _blendMode = GLBlendModeNone;
    _cullFace = GLCullFaceNone;
    _usesDepth = false;
    _scene = this;
    
    camera = make_shared<Camera>(this);
    camera->setPosition({0,0,1});
    
    useColorDetection = true;
    
    hitDetectBuffer = make_shared<FrameBuffer>(size.width, size.height);
    
    hitDetectShader = Shader::shaderNamed("hitShaderSingle",NKS_COLOR_MODE_UNIFORM,0,0,0);
    
    afterSetSize();
    
    printf("init scene with size, %f %f \n", size.width, size.height);
    
    GetGLError();
    
}

void Scene::afterSetSize(){
    camera->aspect = _size.width / _size.height;
#if !NK_USE_WEBGL
    framebuffer = make_shared<FrameBuffer>(_size.width, _size.height);
#endif
}

void Scene::logMetrics() {
#if NK_LOG_METRICS
    printf("fps %d : frametime: %1.3f nodes: %lu : textures: %lu : bBodies %lu : lights %lu", fps, (frameTime / frames), allChildren().size(), (unsigned long)666, (unsigned long)666, (unsigned long)lights.size());
#endif
}

void Scene::updateWithTimeSinceLast(F1t dt){
    
    if (!loaded){
        loaded = true;
        moveToView();
    }
    
    frames++;
    
    
#warning  UPDATE SOUND GL ETC
    //    [NKSoundManager updateWithTimeSinceLast:dt];
    //    [NKGLManager updateWithTimeSinceLast:dt];
    //    [[NKBulletWorld sharedInstance] updateWithTimeSinceLast:dt];
    
    framesToRender += dt*frameRate;
    
    if (!framesToRender) {
        framesToRender = 1.0;
    }
    
    while (framesToRender >= 1.0) {
        Node::updateWithTimeSinceLast(dt/framesToRender);
        camera->setDirty(true);
        camera->updateCameraWithTimeSinceLast(dt/framesToRender);
        framesToRender -= 1.0;
    }
    
    if (_updateBlock){
        _updateBlock(dt);
    }
    
#if NK_LOG_METRICS
    currentFrameTime = Time::getCurrentTime();
    
    if (!metrics) {
        auto size = V2(_size.x*.125, _size.y*.25);
        
        metrics = CollectionView::viewWithSize(size);
        metrics->setScene(this);
        metrics->backgroundColor = Color(1.0,.5);
        
        metrics->setOrthographic();
        metrics->setIgnoresLights();
        auto fontSize = 16.0;
        
        auto label = make_shared<Label>("Vera.ttf", fontSize);
        label->setColor(BLACK);
        label->setPosition(size*V2t{.49,.4});
        label->setTextAlignment(NKTextAlignmentRight);
        label->setOrthographic(true);
        metrics->addChild(label);
        
        auto fbo = make_shared<Label>("Vera.ttf", fontSize);
        fbo->setColor(BLACK);
        fbo->setPosition(size*V2t{.49,.3});
        fbo->setTextAlignment(NKTextAlignmentRight);
        fbo->setOrthographic(true);
        metrics->addChild(fbo);
        
        auto events = make_shared<Label>("Vera.ttf", fontSize);
        events->setColor(BLACK);
        events->setPosition(size*V2t{.49,.2});
        events->setTextAlignment(NKTextAlignmentRight);
        events->setOrthographic(true);
        metrics->addChild(events);
        
        auto actions = make_shared<Label>("Vera.ttf", fontSize);
        actions->setColor(BLACK);
        actions->setPosition(size*V2t{.49,.1});
        actions->setTextAlignment(NKTextAlignmentRight);
        actions->setOrthographic(true);
        metrics->addChild(actions);
        
        auto dlabel = make_shared<Label>("Vera.ttf", fontSize);
        dlabel->setColor(BLACK);
        dlabel->setPosition(size*V2t{.49,0});
        dlabel->setTextAlignment(NKTextAlignmentRight);
        dlabel->setOrthographic(true);
        metrics->addChild(dlabel);
        
        auto fLabel = make_shared<Label>("Vera.ttf", fontSize);
        fLabel->setColor(BLACK);
        fLabel->setPosition(size*V2t{.49,-.1});
        fLabel->setTextAlignment(NKTextAlignmentRight);
        fLabel->setOrthographic(true);
        metrics->addChild(fLabel);
        
        
        metrics->setUpdateBlock([label, dlabel, fLabel, events, fbo, actions, this](float dt){
            fLabel->setText(nksf("%d fps", fps));
            dlabel->setText(nksf("%d draws", draws));
            label->setText(nksf("%d nodes", Node::liveObjects()));
            events->setText(nksf("%d events", UXEvent::liveObjects()));
            fbo->setText(nksf("%d fbos", FrameBuffer::liveObjects()));
            actions->setText(nksf("%d actions", Action::liveObjects()));
        });
    }
    
    metrics->setSize(V2(_size.x*0.125f, _size.y*0.25f));
    metrics->setPosition(_size.x*0.4375f, _size.y * -0.375f);
    
    metrics->updateWithTimeSinceLast(dt);
    
    timer += dt;
    if (timer > 1.0f) {
        fps = (int)frames;
        frames = 0;
        timer -= 1.0f;
    }
    draws = 0;
#endif
}

void Scene::setDirty(bool dirty){
    Node::setDirty(dirty);
    
    if (dirty) {
        for (auto n : lights) {
            n->setDirty(dirty);
        }
    }
}

void Scene::drawHitBuffer() {
    
    nkGetGLError();
    
    _blendMode = GLBlendModeNone;
    glDisable(GL_BLEND);
    
    nkGetGLError();
    
    Node::drawWithHitShader();
    camera->drawWithHitShader();
    
    nkGetGLError();
}

void Scene::processHitBuffer() {
    
    hitDetectBuffer->bind();
    
    glViewport(0, 0, _size.width, _size.height);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    drawHitBuffer();
    
    while (hitQueue.size()) {
        hitQueue.front()();
        hitQueue.pop();
    }
}


//void Scene::bindMainFrameBuffer(Node *sender){
//
//    if (sender != this && framebuffer != nullptr) {
//        framebuffer->bind();
//    }
//    else {
//#if TARGET_IOS
//        view->framebuffer->bind();
//#elif (TARGET_OSX || NK_USE_WEBGL)
//        glBindFramebuffer(GL_FRAMEBUFFER, 0);
//#endif
//    }
//    //NSLog(@"bind fb %@ %@", view, view.framebuffer);
//}

void Scene::draw() {
    
    clear();
    
    if (backgroundColor.alpha > 0) {
        glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    }
    
#if DRAW_HIT_BUFFER
    drawHitBuffer();
#else
    Node::draw();
#endif
    
#if NK_LOG_METRICS
    if (metrics){
        metrics->draw();
    }
#endif
    
    frameTime += Time::getCurrentTime() - currentFrameTime;
}

void Scene::customDraw() {
    if (drawAxes) {
        if (!axes) {
            axes = Mesh::nodeWithPrimitive(NKPrimitiveAxes, nullptr, Color(1.0, 0,0,1.0), V3(100));
            axes->shader = Shader::shaderNamed("vertexColor",NKS_COLOR_MODE_VERTEX,0,0,0);
        }
        if (!_c::contains(_children, axes)) {
            nkLog("add axes to scene");
            addChild(axes);
        }
    }
    if (drawCamera) {
        camera->draw();
    }
}
//void Scene::drawStereo() {
//    glClearColor(0, 0, 0, 0);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//
//    for(int eye = 0; eye < 2; eye++){  // 0 = left , 1 = right
//
//        camera->fovVertRadians = 120;
//        camera->aspect = _size.width / _size.height;
//
//
//        if(eye == 0){
//            glRotatef(-oculusRift.IPD*100.0, 0.0f, 1.0f, 0.0f);
//            //            glTranslatef(oculusRift.IPD, 0.0f, 0.0f);
//        }
//        else if (eye == 1){
//            glRotatef(oculusRift.IPD*100.0, 0.0f, 1.0f, 0.0f);
//            //            glTranslatef(-oculusRift.IPD, 0.0f, 0.0f);
//        }
//        glPushMatrix();
//
//        // apply headset orientation
//        glMultMatrixf(oculusRift.orientation);
//        // mouse rotation
//        glRotatef(mouseRotation.y, 1, 0, 0);
//        glRotatef(mouseRotation.x, 0, 1, 0);
//        // draw scene
//        //-------------------------
//        // keyboard translation
//        scene.render(walkPosition.x, walkPosition.y);  // place for custom scene
//        //-------------------------
//        glPopMatrix();
//        // unbind framebuffer, now render to screen
//        glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//        glBindTexture(GL_TEXTURE_2D, textureId);
//        glGenerateMipmap(GL_TEXTURE_2D);
//        glBindTexture(GL_TEXTURE_2D, 0);
//
//        if(eye == 0)                        // left screen
//            glViewport (0, 0, w/2., h);
//        else if (eye == 1)                  // right screen
//            glViewport (w/2., 0, w/2., h);
//
//        glMatrixMode (GL_PROJECTION);
//        glLoadIdentity ();
//        [self glPerspective:90.0f Aspect:(GLfloat)(w/2.0f)/(GLfloat)(h) Near:.1f Far:10.0f];
//        glMatrixMode (GL_MODELVIEW);
//
//        glLoadIdentity();
//        glPushMatrix();
//
//        if(warping){
//            glUseProgram(_program);
//            // preset suggestions from http://www.mtbs3d.com/phpbb/viewtopic.php?f=140&t=17081
//            const float Scale[2] = {0.1469278, 0.2350845};
//            const float ScaleIn[2] = {2, 2.5};
//            const float HmdWarpParam[4] = {1, 0.22, 0.24, 0};
//            const float LeftLensCenter[2] = {0.2863248*2.0, 0.5};
//            const float LeftScreenCenter[2] = {0.55, 0.5};
//            const float RightLensCenter[2] = {(0.7136753-.5) * 2.0, 0.5};
//            const float RightScreenCenter[2] = {0.45, 0.5};
//            // apply shader uniforms
//            glUniform2fv(uniforms[3], 1, Scale);
//            glUniform2fv(uniforms[4], 1, ScaleIn);
//            glUniform4fv(uniforms[5], 1, HmdWarpParam);
//            if(eye == 0){
//                glUniform2fv(uniforms[1], 1, LeftLensCenter);
//                glUniform2fv(uniforms[2], 1, LeftScreenCenter);
//            }
//            else{
//                glUniform2fv(uniforms[1], 1, RightLensCenter);
//                glUniform2fv(uniforms[2], 1, RightScreenCenter);
//            }
//        }
//        else{  // no warp, closer to fill screen
//            glTranslatef(0, 0, -1.0);
//        }
//        // draw scene on a quad for each side
//        glBindTexture(GL_TEXTURE_2D, textureId);
//        [self drawQuad];
//        glBindTexture(GL_TEXTURE_2D, 0);
//
//        if(warping)
//            glUseProgram(0);
//
//        glPopMatrix();
//    }
//    glFlush();
//}

void Scene::clear() {
    Shader::activeShader = nullptr;
    glUseProgram(0);
    
    if (boundTexture){
        boundTexture->unbind();
        boundTexture = nullptr;
    }
    if (VertexBuffer::activeVBO){
        VertexBuffer::activeVBO->unbind();
        VertexBuffer::activeVBO = nullptr;
    }
}

//void Scene::setUniformIdentity() {
//    NKS_SCALAR s;
//
//    s.I1[0] = 0;
//    _activeShader->uniformNamed(NKS_INT_NUM_TEXTURES).pushValue(s);
//
//    s.M16 = M16IdentityMake();
//    _activeShader->uniformNamed(NKS_INT_NUM_TEXTURES).pushValue(s);
//
//}



void Scene::addChild(shared_ptr<Node> child) {
    // SCENE DOES NOT TRANSFORM CHILDREN
    //_children.push_back(child);
    
    // SCENE DOES TRANSFORM
    Node::addChild(child);
}

M16t Scene::globalTransform() {
    return M16IdentityMake();
}

V3t Scene::globalPosition() {
    return V3(0, 0, 0);
}

void Scene::alertDidSelectOption(int option) {
    if (option == 0) {
        alertDidCancel();
    }
    // OVERRIDE IN SUBCLASS FOR OTHER OPTIONS
}

void Scene::alertDidCancel() {
    dismissAlertAnimated(true);
}

void Scene::presentAlert(NKAlertSprite* alert, bool animated) {
#warning ALERT SPRITE
    //    _alertSprite = alert;
    //    alert.delegate = self;
    //    [self addChild:alert];
    //
    //    if (animated) {
    //
    //        [_alertSprite setPosition2d:V2(0, -self.size.height)];
    //        [_alertSprite runAction:[Action move2dTo:V2(0, 0) duration:.3]];
    //    }
}


void Scene::dismissAlertAnimated(bool animated){
#warning ALERT SPRITE
    //    if (animated) {
    //        [_alertSprite runAction:[Action move2dTo:V2(0, -self.size.height) duration:.3] completion:^{
    //         [self removeChild:_alertSprite];
    //         _alertSprite = nil;
    //         }];
    //    }
    //    else {
    //        [self removeChild:_alertSprite];
    //        _alertSprite = nil;
    //    }
}

void Scene::pushMultiplyMatrix(M16t matrix) {
    stack.pushMultiply(matrix);
}

void Scene::pushScale(V3t scale) {
    stack.pushScale(scale);
}

void Scene::pushStyle(){
    
}

void Scene::bindLights() {
    Shader::activeShader->uniformNamed(NKS_I1_NUM_LIGHTS).bindI1((int)lights.size());
    nkGetGLError();
    if (lights.size() != 0) {
        for (int i = 0; i < lights.size(); i++) {
            Shader::activeShader->uniformNamed(NKS_LIGHT).bindLightProperties(lights[i]->properties, i);
            nkGetGLError();
        }
    }
}
//void Scene::keyDown(U1t key) {
//
//    printf("key down %d \n", key);
//
//    V3t p = _position;
//
//    switch (key) {
//
//        case 123:
//            setPosition(V3(p.x-1, p.y, p.z));
//            break;
//        case 124:
//
//            setPosition(V3(p.x+1, p.y, p.z));
//            break;
//
//        case 126: //up arrow
//
//            setPosition(V3(p.x, p.y, p.z+1)));
//            break;
//
//        case 125: // down arrow
//            setPosition(V3(p.x, p.y, p.z-1));
//            break;
//
//        default:
//            break;
//    }
//}

void Scene::dispatchUXEvent(UXEvent& event) {
    //NSLog(@"dispatch event for location %f %f",location.x, location.y);
    
#warning dispatchUXEvent
    //
    //    if (useColorDetection) {
    //
    //        HitCallback callBack = [this, event]{
    //            UB4t hc;
    //            glReadPixels(event.screenLocation.x, event.screenLocation.y,
    //                         1, 1,
    //                         GL_RGBA, GL_UNSIGNED_BYTE, &hc);
    //#warning do Shader Manager
    //           Node *hit = [ShaderManager nodeForColor:hc];
    //
    //            if (!hit){
    //                hit = this;
    //            }
    //
    //            event.node = hit;
    //
    //            hit->handleUXEvent(event);
    //        };
    //
    //        hitQueue.push(callBack);
    //    }
    //
    //    else if (useBulletDetection) {
    //        // IMPLEMENT THIS
    //    }
}

void Scene::setView(SceneController* view_){
    view = view_;
}

Scene::~Scene() {
    if (loaded) {
        unload();
    }
}

void Scene::unload() {
    
    glFinish();
    
    clear();
    
    while (hitQueue.size()) {
        hitQueue.pop();
    }
    
#if NK_USE_MIDI
    [_midiReceivedBlocks removeAllObjects];
#endif
    
    camera->removeAllActions();
    camera->removeFromParent();
    
    removeAllChildren();
    
#warning bullet
    //   [NKBulletWorld reset];
    
    lights.clear();
    
    hitDetectBuffer->unload();
    
    loaded = false;
}

#if NK_USE_MIDI
-(void)handleMidiCommand:(MIKMIDICommand *)command {
    for (MidiReceivedBlock block in _midiReceivedBlocks.allValues){
        block(command);
    }
    //else {
    // NSLog(@"received midi, provide scene a MidiReceivedBlock, or instead, implement: -(void)handleMidiCommand:(MIKMIDICommand *)command in subclass");
    //}
}
#endif

