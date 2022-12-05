
#include "UI.h"

using namespace std;
using namespace sf;

UI::UI(){
};

void UI::drawSideMap(RenderWindow* window)
{
	sideMap.setTexture(textureSideMap);
    sideMap.setPosition(-10,0);
    sideMap.setScale(4.f,4.f);
    window->draw(sideMap);
}