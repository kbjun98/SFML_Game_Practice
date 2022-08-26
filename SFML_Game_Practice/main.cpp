#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber", Style::Fullscreen);
    Texture textureBackground;
    textureBackground.loadFromFile("Graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    Texture textureTree;
    textureTree.loadFromFile("Graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    Texture textureBee;
    textureBee.loadFromFile("Graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);
    bool beeActive = false;
    float beeSpeed = 0.0f;
    
    Texture textureCloud;
    textureCloud.loadFromFile("Graphics/cloud.png");
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    Clock clock;
    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        Time dt = clock.restart();
        if (!beeActive)
        {
            srand(time(0));
            beeSpeed = (rand() % 200) + 200;
            srand(time(0)*10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        }
        else {
            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
            if (spriteBee.getPosition().x < -100)
            {
                beeActive = false;
            }
        }

        if (!cloud1Active)
        {
            srand(time(0));
            cloud1Speed = (rand() % 200);
            srand(time(0) * 10);
            float height = (rand() % 150);
            spriteCloud1.setPosition(-200, height);
            cloud1Active = true;
        }
        else
        {
            spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
            if (spriteCloud1.getPosition().x > 1920)
            {
                cloud1Active = false;
            }

        }

        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.display();
    }

    return 0;
}
