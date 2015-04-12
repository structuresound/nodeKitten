//
//  NKColor.cpp
//  NodeKittenX
//
//  Created by Leif Shackelford on 2/2/15.
//  Copyright (c) 2015 structuresound. All rights reserved.
//

#include "NKColor.h"

std::map<std::string, C4t> NKColor::namedColor = {
    { "transparent", { 0 / 255.0, 0 / 255.0, 0 / 255.0, 0 } }, { "aliceblue", { 240 / 255.0, 248 / 255.0, 255 / 255.0, 1 } },
    { "antiquewhite", { 250 / 255.0, 235 / 255.0, 215 / 255.0, 1 } }, { "aqua", { 0 / 255.0, 255 / 255.0, 255 / 255.0, 1 } },
    { "aquamarine", { 127 / 255.0, 255 / 255.0, 212 / 255.0, 1 } }, { "azure", { 240 / 255.0, 255 / 255.0, 255 / 255.0, 1 } },
    { "beige", { 245 / 255.0, 245 / 255.0, 220 / 255.0, 1 } }, { "bisque", { 255 / 255.0, 228 / 255.0, 196 / 255.0, 1 } },
    { "black", { 0 / 255.0, 0 / 255.0, 0 / 255.0, 1 } }, { "blanchedalmond", { 255 / 255.0, 235 / 255.0, 205 / 255.0, 1 } },
    { "blue", { 0 / 255.0, 0 / 255.0, 255 / 255.0, 1 } }, { "blueviolet", { 138 / 255.0, 43 / 255.0, 226 / 255.0, 1 } },
    { "brown", { 165 / 255.0, 42 / 255.0, 42 / 255.0, 1 } }, { "burlywood", { 222 / 255.0, 184 / 255.0, 135 / 255.0, 1 } },
    { "cadetblue", { 95 / 255.0, 158 / 255.0, 160 / 255.0, 1 } }, { "chartreuse", { 127 / 255.0, 255 / 255.0, 0 / 255.0, 1 } },
    { "chocolate", { 210 / 255.0, 105 / 255.0, 30 / 255.0, 1 } }, { "coral", { 255 / 255.0, 127 / 255.0, 80 / 255.0, 1 } },
    { "cornflowerblue", { 100 / 255.0, 149 / 255.0, 237 / 255.0, 1 } }, { "cornsilk", { 255 / 255.0, 248 / 255.0, 220 / 255.0, 1 } },
    { "crimson", { 220 / 255.0, 20 / 255.0, 60 / 255.0, 1 } }, { "cyan", { 0 / 255.0, 255 / 255.0, 255 / 255.0, 1 } },
    { "darkblue", { 0 / 255.0, 0 / 255.0, 139 / 255.0, 1 } }, { "darkcyan", { 0 / 255.0, 139 / 255.0, 139 / 255.0, 1 } },
    { "darkgoldenrod", { 184 / 255.0, 134 / 255.0, 11 / 255.0, 1 } }, { "darkgray", { 169 / 255.0, 169 / 255.0, 169 / 255.0, 1 } },
    { "darkgreen", { 0 / 255.0, 100 / 255.0, 0 / 255.0, 1 } }, { "darkgrey", { 169 / 255.0, 169 / 255.0, 169 / 255.0, 1 } },
    { "darkkhaki", { 189 / 255.0, 183 / 255.0, 107 / 255.0, 1 } }, { "darkmagenta", { 139 / 255.0, 0 / 255.0, 139 / 255.0, 1 } },
    { "darkolivegreen", { 85 / 255.0, 107 / 255.0, 47 / 255.0, 1 } }, { "darkorange", { 255 / 255.0, 140 / 255.0, 0 / 255.0, 1 } },
    { "darkorchid", { 153 / 255.0, 50 / 255.0, 204 / 255.0, 1 } }, { "darkred", { 139 / 255.0, 0 / 255.0, 0 / 255.0, 1 } },
    { "darksalmon", { 233 / 255.0, 150 / 255.0, 122 / 255.0, 1 } }, { "darkseagreen", { 143 / 255.0, 188 / 255.0, 143 / 255.0, 1 } },
    { "darkslateblue", { 72 / 255.0, 61 / 255.0, 139 / 255.0, 1 } }, { "darkslategray", { 47 / 255.0, 79 / 255.0, 79 / 255.0, 1 } },
    { "darkslategrey", { 47 / 255.0, 79 / 255.0, 79 / 255.0, 1 } }, { "darkturquoise", { 0 / 255.0, 206 / 255.0, 209 / 255.0, 1 } },
    { "darkviolet", { 148 / 255.0, 0 / 255.0, 211 / 255.0, 1 } }, { "deeppink", { 255 / 255.0, 20 / 255.0, 147 / 255.0, 1 } },
    { "deepskyblue", { 0 / 255.0, 191 / 255.0, 255 / 255.0, 1 } }, { "dimgray", { 105 / 255.0, 105 / 255.0, 105 / 255.0, 1 } },
    { "dimgrey", { 105 / 255.0, 105 / 255.0, 105 / 255.0, 1 } }, { "dodgerblue", { 30 / 255.0, 144 / 255.0, 255 / 255.0, 1 } },
    { "firebrick", { 178 / 255.0, 34 / 255.0, 34 / 255.0, 1 } }, { "floralwhite", { 255 / 255.0, 250 / 255.0, 240 / 255.0, 1 } },
    { "forestgreen", { 34 / 255.0, 139 / 255.0, 34 / 255.0, 1 } }, { "fuchsia", { 255 / 255.0, 0 / 255.0, 255 / 255.0, 1 } },
    { "gainsboro", { 220 / 255.0, 220 / 255.0, 220 / 255.0, 1 } }, { "ghostwhite", { 248 / 255.0, 248 / 255.0, 255 / 255.0, 1 } },
    { "gold", { 255 / 255.0, 215 / 255.0, 0 / 255.0, 1 } }, { "goldenrod", { 218 / 255.0, 165 / 255.0, 32 / 255.0, 1 } },
    { "gray", { 128 / 255.0, 128 / 255.0, 128 / 255.0, 1 } }, { "green", { 0 / 255.0, 128 / 255.0, 0 / 255.0, 1 } },
    { "greenyellow", { 173 / 255.0, 255 / 255.0, 47 / 255.0, 1 } }, { "grey", { 128 / 255.0, 128 / 255.0, 128 / 255.0, 1 } },
    { "honeydew", { 240 / 255.0, 255 / 255.0, 240 / 255.0, 1 } }, { "hotpink", { 255 / 255.0, 105 / 255.0, 180 / 255.0, 1 } },
    { "indianred", { 205 / 255.0, 92 / 255.0, 92 / 255.0, 1 } }, { "indigo", { 75 / 255.0, 0 / 255.0, 130 / 255.0, 1 } },
    { "ivory", { 255 / 255.0, 255 / 255.0, 240 / 255.0, 1 } }, { "khaki", { 240 / 255.0, 230 / 255.0, 140 / 255.0, 1 } },
    { "lavender", { 230 / 255.0, 230 / 255.0, 250 / 255.0, 1 } }, { "lavenderblush", { 255 / 255.0, 240 / 255.0, 245 / 255.0, 1 } },
    { "lawngreen", { 124 / 255.0, 252 / 255.0, 0 / 255.0, 1 } }, { "lemonchiffon", { 255 / 255.0, 250 / 255.0, 205 / 255.0, 1 } },
    { "lightblue", { 173 / 255.0, 216 / 255.0, 230 / 255.0, 1 } }, { "lightcoral", { 240 / 255.0, 128 / 255.0, 128 / 255.0, 1 } },
    { "lightcyan", { 224 / 255.0, 255 / 255.0, 255 / 255.0, 1 } }, { "lightgoldenrodyellow", { 250 / 255.0, 250 / 255.0, 210 / 255.0, 1 } },
    { "lightgray", { 211 / 255.0, 211 / 255.0, 211 / 255.0, 1 } }, { "lightgreen", { 144 / 255.0, 238 / 255.0, 144 / 255.0, 1 } },
    { "lightgrey", { 211 / 255.0, 211 / 255.0, 211 / 255.0, 1 } }, { "lightpink", { 255 / 255.0, 182 / 255.0, 193 / 255.0, 1 } },
    { "lightsalmon", { 255 / 255.0, 160 / 255.0, 122 / 255.0, 1 } }, { "lightseagreen", { 32 / 255.0, 178 / 255.0, 170 / 255.0, 1 } },
    { "lightskyblue", { 135 / 255.0, 206 / 255.0, 250 / 255.0, 1 } }, { "lightslategray", { 119 / 255.0, 136 / 255.0, 153 / 255.0, 1 } },
    { "lightslategrey", { 119 / 255.0, 136 / 255.0, 153 / 255.0, 1 } }, { "lightsteelblue", { 176 / 255.0, 196 / 255.0, 222 / 255.0, 1 } },
    { "lightyellow", { 255 / 255.0, 255 / 255.0, 224 / 255.0, 1 } }, { "lime", { 0 / 255.0, 255 / 255.0, 0 / 255.0, 1 } },
    { "limegreen", { 50 / 255.0, 205 / 255.0, 50 / 255.0, 1 } }, { "linen", { 250 / 255.0, 240 / 255.0, 230 / 255.0, 1 } },
    { "magenta", { 255 / 255.0, 0 / 255.0, 255 / 255.0, 1 } }, { "maroon", { 128 / 255.0, 0 / 255.0, 0 / 255.0, 1 } },
    { "mediumaquamarine", { 102 / 255.0, 205 / 255.0, 170 / 255.0, 1 } }, { "mediumblue", { 0 / 255.0, 0 / 255.0, 205 / 255.0, 1 } },
    { "mediumorchid", { 186 / 255.0, 85 / 255.0, 211 / 255.0, 1 } }, { "mediumpurple", { 147 / 255.0, 112 / 255.0, 219 / 255.0, 1 } },
    { "mediumseagreen", { 60 / 255.0, 179 / 255.0, 113 / 255.0, 1 } }, { "mediumslateblue", { 123 / 255.0, 104 / 255.0, 238 / 255.0, 1 } },
    { "mediumspringgreen", { 0 / 255.0, 250 / 255.0, 154 / 255.0, 1 } }, { "mediumturquoise", { 72 / 255.0, 209 / 255.0, 204 / 255.0, 1 } },
    { "mediumvioletred", { 199 / 255.0, 21 / 255.0, 133 / 255.0, 1 } }, { "midnightblue", { 25 / 255.0, 25 / 255.0, 112 / 255.0, 1 } },
    { "mintcream", { 245 / 255.0, 255 / 255.0, 250 / 255.0, 1 } }, { "mistyrose", { 255 / 255.0, 228 / 255.0, 225 / 255.0, 1 } },
    { "moccasin", { 255 / 255.0, 228 / 255.0, 181 / 255.0, 1 } }, { "navajowhite", { 255 / 255.0, 222 / 255.0, 173 / 255.0, 1 } },
    { "navy", { 0 / 255.0, 0 / 255.0, 128 / 255.0, 1 } }, { "oldlace", { 253 / 255.0, 245 / 255.0, 230 / 255.0, 1 } },
    { "olive", { 128 / 255.0, 128 / 255.0, 0 / 255.0, 1 } }, { "olivedrab", { 107 / 255.0, 142 / 255.0, 35 / 255.0, 1 } },
    { "orange", { 255 / 255.0, 165 / 255.0, 0 / 255.0, 1 } }, { "orangered", { 255 / 255.0, 69 / 255.0, 0 / 255.0, 1 } },
    { "orchid", { 218 / 255.0, 112 / 255.0, 214 / 255.0, 1 } }, { "palegoldenrod", { 238 / 255.0, 232 / 255.0, 170 / 255.0, 1 } },
    { "palegreen", { 152 / 255.0, 251 / 255.0, 152 / 255.0, 1 } }, { "paleturquoise", { 175 / 255.0, 238 / 255.0, 238 / 255.0, 1 } },
    { "palevioletred", { 219 / 255.0, 112 / 255.0, 147 / 255.0, 1 } }, { "papayawhip", { 255 / 255.0, 239 / 255.0, 213 / 255.0, 1 } },
    { "peachpuff", { 255 / 255.0, 218 / 255.0, 185 / 255.0, 1 } }, { "peru", { 205 / 255.0, 133 / 255.0, 63 / 255.0, 1 } },
    { "pink", { 255 / 255.0, 192 / 255.0, 203 / 255.0, 1 } }, { "plum", { 221 / 255.0, 160 / 255.0, 221 / 255.0, 1 } },
    { "powderblue", { 176 / 255.0, 224 / 255.0, 230 / 255.0, 1 } }, { "purple", { 128 / 255.0, 0 / 255.0, 128 / 255.0, 1 } },
    { "red", { 255 / 255.0, 0 / 255.0, 0 / 255.0, 1 } }, { "rosybrown", { 188 / 255.0, 143 / 255.0, 143 / 255.0, 1 } },
    { "royalblue", { 65 / 255.0, 105 / 255.0, 225 / 255.0, 1 } }, { "saddlebrown", { 139 / 255.0, 69 / 255.0, 19 / 255.0, 1 } },
    { "salmon", { 250 / 255.0, 128 / 255.0, 114 / 255.0, 1 } }, { "sandybrown", { 244 / 255.0, 164 / 255.0, 96 / 255.0, 1 } },
    { "seagreen", { 46 / 255.0, 139 / 255.0, 87 / 255.0, 1 } }, { "seashell", { 255 / 255.0, 245 / 255.0, 238 / 255.0, 1 } },
    { "sienna", { 160 / 255.0, 82 / 255.0, 45 / 255.0, 1 } }, { "silver", { 192 / 255.0, 192 / 255.0, 192 / 255.0, 1 } },
    { "skyblue", { 135 / 255.0, 206 / 255.0, 235 / 255.0, 1 } }, { "slateblue", { 106 / 255.0, 90 / 255.0, 205 / 255.0, 1 } },
    { "slategray", { 112 / 255.0, 128 / 255.0, 144 / 255.0, 1 } }, { "slategrey", { 112 / 255.0, 128 / 255.0, 144 / 255.0, 1 } },
    { "snow", { 255 / 255.0, 250 / 255.0, 250 / 255.0, 1 } }, { "springgreen", { 0 / 255.0, 255 / 255.0, 127 / 255.0, 1 } },
    { "steelblue", { 70 / 255.0, 130 / 255.0, 180 / 255.0, 1 } }, { "tan", { 210 / 255.0, 180 / 255.0, 140 / 255.0, 1 } },
    { "teal", { 0 / 255.0, 128 / 255.0, 128 / 255.0, 1 } }, { "thistle", { 216 / 255.0, 191 / 255.0, 216 / 255.0, 1 } },
    { "tomato", { 255 / 255.0, 99 / 255.0, 71 / 255.0, 1 } }, { "turquoise", { 64 / 255.0, 224 / 255.0, 208 / 255.0, 1 } },
    { "violet", { 238 / 255.0, 130 / 255.0, 238 / 255.0, 1 } }, { "wheat", { 245 / 255.0, 222 / 255.0, 179 / 255.0, 1 } },
    { "white", { 255 / 255.0, 255 / 255.0, 255 / 255.0, 1 } }, { "whitesmoke", { 245 / 255.0, 245 / 255.0, 245 / 255.0, 1 } },
    { "yellow", { 255 / 255.0, 255 / 255.0, 0 / 255.0, 1 } }, { "yellowgreen", { 154 / 255.0, 205 / 255.0, 50 / 255.0, 1 } }
};

std::map<std::string, UB4t> NKByteColor::namedColor = {
    { "transparent", { 0, 0, 0, 0 } }, { "aliceblue", { 240, 248, 255, 255 } },
    { "antiquewhite", { 250, 235, 215, 255 } }, { "aqua", { 0, 255, 255, 255 } },
    { "aquamarine", { 127, 255, 212, 255 } }, { "azure", { 240, 255, 255, 255 } },
    { "beige", { 245, 245, 220, 255 } }, { "bisque", { 255, 228, 196, 255 } },
    { "black", { 0, 0, 0, 255 } }, { "blanchedalmond", { 255, 235, 205, 255 } },
    { "blue", { 0, 0, 255, 255 } }, { "blueviolet", { 138, 43, 226, 255 } },
    { "brown", { 165, 42, 42, 255 } }, { "burlywood", { 222, 184, 135, 255 } },
    { "cadetblue", { 95, 158, 160, 255 } }, { "chartreuse", { 127, 255, 0, 255 } },
    { "chocolate", { 210, 105, 30, 255 } }, { "coral", { 255, 127, 80, 255 } },
    { "cornflowerblue", { 100, 149, 237, 255 } }, { "cornsilk", { 255, 248, 220, 255 } },
    { "crimson", { 220, 20, 60, 255 } }, { "cyan", { 0, 255, 255, 255 } },
    { "darkblue", { 0, 0, 139, 255 } }, { "darkcyan", { 0, 139, 139, 255 } },
    { "darkgoldenrod", { 184, 134, 11, 255 } }, { "darkgray", { 169, 169, 169, 255 } },
    { "darkgreen", { 0, 100, 0, 255 } }, { "darkgrey", { 169, 169, 169, 255 } },
    { "darkkhaki", { 189, 183, 107, 255 } }, { "darkmagenta", { 139, 0, 139, 255 } },
    { "darkolivegreen", { 85, 107, 47, 255 } }, { "darkorange", { 255, 140, 0, 255 } },
    { "darkorchid", { 153, 50, 204, 255 } }, { "darkred", { 139, 0, 0, 255 } },
    { "darksalmon", { 233, 150, 122, 255 } }, { "darkseagreen", { 143, 188, 143, 255 } },
    { "darkslateblue", { 72, 61, 139, 255 } }, { "darkslategray", { 47, 79, 79, 255 } },
    { "darkslategrey", { 47, 79, 79, 255 } }, { "darkturquoise", { 0, 206, 209, 255 } },
    { "darkviolet", { 148, 0, 211, 255 } }, { "deeppink", { 255, 20, 147, 255 } },
    { "deepskyblue", { 0, 191, 255, 255 } }, { "dimgray", { 105, 105, 105, 255 } },
    { "dimgrey", { 105, 105, 105, 255 } }, { "dodgerblue", { 30, 144, 255, 255 } },
    { "firebrick", { 178, 34, 34, 255 } }, { "floralwhite", { 255, 250, 240, 255 } },
    { "forestgreen", { 34, 139, 34, 255 } }, { "fuchsia", { 255, 0, 255, 255 } },
    { "gainsboro", { 220, 220, 220, 255 } }, { "ghostwhite", { 248, 248, 255, 255 } },
    { "gold", { 255, 215, 0, 255 } }, { "goldenrod", { 218, 165, 32, 255 } },
    { "gray", { 128, 128, 128, 255 } }, { "green", { 0, 128, 0, 255 } },
    { "greenyellow", { 173, 255, 47, 255 } }, { "grey", { 128, 128, 128, 255 } },
    { "honeydew", { 240, 255, 240, 255 } }, { "hotpink", { 255, 105, 180, 255 } },
    { "indianred", { 205, 92, 92, 255 } }, { "indigo", { 75, 0, 130, 255 } },
    { "ivory", { 255, 255, 240, 255 } }, { "khaki", { 240, 230, 140, 255 } },
    { "lavender", { 230, 230, 250, 255 } }, { "lavenderblush", { 255, 240, 245, 255 } },
    { "lawngreen", { 124, 252, 0, 255 } }, { "lemonchiffon", { 255, 250, 205, 255 } },
    { "lightblue", { 173, 216, 230, 255 } }, { "lightcoral", { 240, 128, 128, 255 } },
    { "lightcyan", { 224, 255, 255, 255 } }, { "lightgoldenrodyellow", { 250, 250, 210, 255 } },
    { "lightgray", { 211, 211, 211, 255 } }, { "lightgreen", { 144, 238, 144, 255 } },
    { "lightgrey", { 211, 211, 211, 255 } }, { "lightpink", { 255, 182, 193, 255 } },
    { "lightsalmon", { 255, 160, 122, 255 } }, { "lightseagreen", { 32, 178, 170, 255 } },
    { "lightskyblue", { 135, 206, 250, 255 } }, { "lightslategray", { 119, 136, 153, 255 } },
    { "lightslategrey", { 119, 136, 153, 255 } }, { "lightsteelblue", { 176, 196, 222, 255 } },
    { "lightyellow", { 255, 255, 224, 255 } }, { "lime", { 0, 255, 0, 255 } },
    { "limegreen", { 50, 205, 50, 255 } }, { "linen", { 250, 240, 230, 255 } },
    { "magenta", { 255, 0, 255, 255 } }, { "maroon", { 128, 0, 0, 255 } },
    { "mediumaquamarine", { 102, 205, 170, 255 } }, { "mediumblue", { 0, 0, 205, 255 } },
    { "mediumorchid", { 186, 85, 211, 255 } }, { "mediumpurple", { 147, 112, 219, 255 } },
    { "mediumseagreen", { 60, 179, 113, 255 } }, { "mediumslateblue", { 123, 104, 238, 255 } },
    { "mediumspringgreen", { 0, 250, 154, 255 } }, { "mediumturquoise", { 72, 209, 204, 255 } },
    { "mediumvioletred", { 199, 21, 133, 255 } }, { "midnightblue", { 25, 25, 112, 255 } },
    { "mintcream", { 245, 255, 250, 255 } }, { "mistyrose", { 255, 228, 225, 255 } },
    { "moccasin", { 255, 228, 181, 255 } }, { "navajowhite", { 255, 222, 173, 255 } },
    { "navy", { 0, 0, 128, 255 } }, { "oldlace", { 253, 245, 230, 255 } },
    { "olive", { 128, 128, 0, 255 } }, { "olivedrab", { 107, 142, 35, 255 } },
    { "orange", { 255, 165, 0, 255 } }, { "orangered", { 255, 69, 0, 255 } },
    { "orchid", { 218, 112, 214, 255 } }, { "palegoldenrod", { 238, 232, 170, 255 } },
    { "palegreen", { 152, 251, 152, 255 } }, { "paleturquoise", { 175, 238, 238, 255 } },
    { "palevioletred", { 219, 112, 147, 255 } }, { "papayawhip", { 255, 239, 213, 255 } },
    { "peachpuff", { 255, 218, 185, 255 } }, { "peru", { 205, 133, 63, 255 } },
    { "pink", { 255, 192, 203, 255 } }, { "plum", { 221, 160, 221, 255 } },
    { "powderblue", { 176, 224, 230, 255 } }, { "purple", { 128, 0, 128, 255 } },
    { "red", { 255, 0, 0, 255 } }, { "rosybrown", { 188, 143, 143, 255 } },
    { "royalblue", { 65, 105, 225, 255 } }, { "saddlebrown", { 139, 69, 19, 255 } },
    { "salmon", { 250, 128, 114, 255 } }, { "sandybrown", { 244, 164, 96, 255 } },
    { "seagreen", { 46, 139, 87, 255 } }, { "seashell", { 255, 245, 238, 255 } },
    { "sienna", { 160, 82, 45, 255 } }, { "silver", { 192, 192, 192, 255 } },
    { "skyblue", { 135, 206, 235, 255 } }, { "slateblue", { 106, 90, 205, 255 } },
    { "slategray", { 112, 128, 144, 255 } }, { "slategrey", { 112, 128, 144, 255 } },
    { "snow", { 255, 250, 250, 255 } }, { "springgreen", { 0, 255, 127, 255 } },
    { "steelblue", { 70, 130, 180, 255 } }, { "tan", { 210, 180, 140, 255 } },
    { "teal", { 0, 128, 128, 255 } }, { "thistle", { 216, 191, 216, 255 } },
    { "tomato", { 255, 99, 71, 255 } }, { "turquoise", { 64, 224, 208, 255 } },
    { "violet", { 238, 130, 238, 255 } }, { "wheat", { 245, 222, 179, 255 } },
    { "white", { 255, 255, 255, 255 } }, { "whitesmoke", { 245, 245, 245, 255 } },
    { "yellow", { 255, 255, 0, 255 } }, { "yellowgreen", { 154, 205, 50, 255 } }
};
