#include "examples.h"
#include "nkSDLView.h"

NKSDLView *sdlView;

int main(int, char**){

    sdlView = new NKSDLView(800,600);

    sdlView->setup();
    sdlView->setScene(make_shared<LayoutExample>(sdlView->size.get()));

    return sdlView->loop();
}