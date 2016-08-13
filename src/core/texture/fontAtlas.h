//
// Created by Leif Shackelford on 4/25/15.
//

#ifndef NODEKITTENX_NKFONTATLAS_H
#define NODEKITTENX_NKFONTATLAS_H

#include "texture.h"
#include "../vector/vertexBuffer.h"
#include "../../ext/freetype-gl/freetype-gl.h"
#include "../../ext/freetype-gl/texture-atlas.h"
#include "../../ext/freetype-gl/texture-font.h"

class FontAtlas : public Texture {

public:

    texture_font_t *font = nullptr;
    texture_atlas_t *atlas = nullptr;

    FontAtlas(std::string fontName, U1t fontSize = 48, I1t width = 512, I1t height = 512){

        atlas = texture_atlas_new( width, height, 1);

        std::string filename = File::pathForFileNamed(fontName);
        nkLog("font: %s", filename);

        font = texture_font_new_from_file( atlas, fontSize, filename.c_str() );

        texture_atlas_upload( atlas );

        nkLog("new atlas texture : %d", atlas->id);
    }

    FontAtlas(I1t width, I1t height) {
        atlas = texture_atlas_new(width, height, 3);
    }

    ~FontAtlas(){
        if (atlas){
            texture_atlas_delete(atlas);
        }
        if (font){
            texture_font_delete(font);
        }
    }

    virtual void bind() override;


};


#endif //NODEKITTENX_NKFONTATLAS_H
