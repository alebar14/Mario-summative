#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>



bool isButtonClicked(sf::FloatRect sprite, sf::Vector2f mp) {
    if(sprite.contains(mp)) {

        return true;
    }
    return false;


}

int main() {

    srand(time(NULL));


    bool play=true;
    sf::Event event;
    int frame=0;
    sf::Clock clock;
    int keyNum=0;
    std::string dir="stop";
    int Xpos=200;
    int Ypos=340;
    float CLXSpeed=0;
    int start=0;

    CLXSpeed=-0.5;





    sf::RenderWindow window(sf::VideoMode(800,600),"My game");
    window.setFramerateLimit(60);

    //Add sound recordings


    //*******************************************************

    //Start button*******************************************

    sf::Texture ArrowTX;
    if(!ArrowTX.loadFromFile("Assets/Arrow.png")) {
        return 0;
    }
    sf::Sprite Button;
    Button.setTexture(ArrowTX);
    Button.setPosition(0,0);
//Button.scale(sf::Vector2f(200.f, 350.f));

//*************************************************

    //******************************************************

//Make bird*************************************************
    sf::RectangleShape mario(sf::Vector2f(500.f, 300.f));
    mario.setOrigin(25.f,20.f);
    sf::Texture texture1;
//*****************************************************************

    sf::RectangleShape lucky(sf::Vector2f(50.f, 50.f));
    sf::Texture Luckytexture;
    Luckytexture.loadFromFile("Assets/LuckyB.png");
    lucky.setTexture(&Luckytexture);


//Make sun *********************************************************
    sf::RectangleShape Sun(sf::Vector2f(200.f, 200.f));
    sf::Texture Suntexture;
    Suntexture.loadFromFile("Assets/Sun.png");
    Sun.setTexture(&Suntexture);
    Sun.setPosition(600,30);
    Sun.setRotation(-10);
//******************************************************************



//Make Grant *********************************************************
    sf::RectangleShape Grant(sf::Vector2f(200.f, 200.f));
    sf::Texture GrantTX;
    GrantTX.loadFromFile("Assets/Grant .png");
    Grant.setTexture(&GrantTX);
    Grant.setPosition(170,80);
    Grant.setRotation(90);
//******************************************************************

//Make portal**********************************************************

    sf::RectangleShape Portal1(sf::Vector2f(100.f, 150.f));
    sf::Texture Portal1texture;
    Portal1texture.loadFromFile("Assets/Blue Portal.png");
    Portal1.setTexture(&Portal1texture);

    sf::RectangleShape Portal2(sf::Vector2f(100.f, 150.f));
    sf::Texture Portal2texture;
    Portal2texture.loadFromFile("Assets/Purple portal.png");
    Portal2.setTexture(&Portal2texture);

    sf::RectangleShape Portal3(sf::Vector2f(100.f, 150.f));
    sf::Texture Portal3texture;
    Portal3texture.loadFromFile("Assets/Red portal.png");
    Portal3.setTexture(&Portal3texture);

    sf::RectangleShape Portal4(sf::Vector2f(100.f, 150.f));
    sf::Texture Portal4texture;
    Portal4texture.loadFromFile("Assets/lychy.png");
    Portal4.setTexture(&Portal4texture);
//********************************************************************

//Cloud texture****************************************************
    sf::Texture BigCLtexture;
    if(!BigCLtexture.loadFromFile("Assets/BigCloud.png")) {

        std::cout<<"Problems with the clouds";
    }
    sf::Texture SmallCLtexture;
    if(! SmallCLtexture.loadFromFile("Assets/SmallCloud.png")) {
        std::cout<<"Problems with the clouds";
    }
//**********************************************************************8

//Make clouds*******************************************
    std::vector<sf::Sprite> BigCLVector;
    for(int i=0; i<3; i++) {
        sf::Sprite BigCL;
        BigCL.setTexture(BigCLtexture);
        BigCLVector.push_back(BigCL);
    }
    std::vector<sf::Sprite> SmallCLVector;
    for(int i=0; i<3; i++) {
        sf::Sprite SmallCL;
        SmallCL.setTexture(SmallCLtexture);
        SmallCLVector.push_back(SmallCL);
    }
//*************************************************************

//This will position the pipes*********************************

    for(int i=0; i<3; i++) {
        int num=rand()%50+75;
        BigCLVector[i].setPosition(i*250+300, num);
        SmallCLVector[i].setPosition(i*250+300, num);
    }

//*****************************************************************



// sf::SoundBuffer buffer;
    // buffer.loadFromFile("Assets/FlappyJump.wav");
    //  sf::Sound sound;
    //sound.setBuffer(buffer);

//Make clouds*********************************************************

    /*  sf::RectangleShape BigCL(sf::Vector2f(50.f, 20.f));
          sf::Texture BigCLtexture;
        BigCLtexture.loadFromFile("Assets/BigCloud.png");
      BigCL.setTexture(&BigCLtexture);

      sf::RectangleShape SmallCL(sf::Vector2f(20.f, 10.f));
          sf::Texture SmallCLtexture;
        SmallCLtexture.loadFromFile("Assets/SmallCloud.png");
      SmallCL.setTexture(&SmallCLtexture);
      */
//*******************************************************************


//Bird Texture***********************************************
    texture1.loadFromFile("Assets/mario0001.png");
    mario.setTexture(&texture1);

    sf::Texture texture2;
    texture2.loadFromFile("Assets/mario0002.png");

    sf::Texture texture3;
    texture3.loadFromFile("Assets/mario0003.png");

    sf::Texture texture4;
    texture4.loadFromFile("Assets/mario0004.png");
//*********************************************************


//Floor*****************************************
    sf::RectangleShape FL(sf::Vector2f(900.f, 600.f));
    sf::Texture FLTexture;
    FLTexture.loadFromFile("Assets/bricks.png");
    FL.setTexture(&FLTexture);
//************************************************

//BackGround*****************************************
    sf::RectangleShape BG(sf::Vector2f(900.f, 600.f));
    sf::Texture BgTexture;
    BgTexture.loadFromFile("Assets/NewBG.png");
    BG.setTexture(&BgTexture);
//************************************************



    while(play == true) {

//Events....listen to computer events
        while(window.pollEvent(event)) {

//Close Window*********************************************************************
            if(event.type==sf::Event::Closed) {
                window.close();
            }
//**********************************************************************************************************************


//Button Pressed******************************************************************************************************
            if(isButtonClicked(Button.getGlobalBounds(),sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                if(event.type== sf::Event::MouseButtonReleased && event.mouseButton.button== sf::Mouse::Left) {
                    start=1;
                    Button.setColor(sf::Color::Transparent);

                }
            }
//*****************************************************************************************************************************
//if keypressed
            if(event.type == sf::Event::KeyPressed) {

                if(event.key.code==73) {
                    dir="up";
                    // sound.play();
                }

                if(event.key.code==74) {
                    dir="down";
                }
                if(event.key.code==71) {
                    dir="right";

                }
                if(event.key.code==72) {
                    dir="left";
                    CLXSpeed=-1;

                }
                if(event.key.code==19) {
                    start=1;
                }

                if(event.key.code==73&&event.key.code==72) {
                    dir="left jump";
                }

            }
//if keyrealeased

            if(event.type == sf::Event::KeyReleased) {

                if(event.key.code==73) {
                    dir="stop";
                    Ypos +=30;

                }
                if(event.key.code==74) {
                    dir="stop";
                }
                if(event.key.code==71) {
                    dir="stop";
                }
                if(event.key.code==72) {
                    dir="stop";
                    CLXSpeed=-0.5;


                }

            }

        }
//Game logic....this is where you check if things are hitting/working


//this is the annimation effect*****************************************

//do{

        if (dir=="left") {
            if (clock.getElapsedTime().asSeconds()> .1f) {
                frame ++;
                if (frame == 6) {
                    frame = 1;
                }
                if (frame == 1) {
                    mario.setTexture(&texture1);
                } else if (frame ==2) {
                    mario.setTexture(&texture2);
                } else if (frame==3) {
                    mario.setTexture(&texture3);
                } else if (frame==4) {
                    mario.setTexture(&texture4);
                } else if (frame==5) {
                    mario.setTexture(&texture4);
                }
                clock.restart();
            }
        }

        //   }while( event.key.code==73);

//**********************************************************************************

//Make more pipes when a pipe gets off the screen*************************************
        mario.setPosition(Xpos,Ypos);
        for(int i=0; i<3; i++) {
            BigCLVector[i].move(CLXSpeed,0);
            SmallCLVector[i].move(CLXSpeed,0);

            if(BigCLVector[i].getPosition().x<-50) {
                int num=rand()%50+75;
                int numX=rand()%300+800;
                BigCLVector[i].setPosition(i*numX, num);
                SmallCLVector[i].setPosition(i*numX+135, num+135);
                //okToScore= true;
            }
        }
//*****************************************************************************



        if(dir=="up"&&Ypos>320) {
            // Ypos-=2;
            Ypos -=15;
        }
        if(dir=="down") {
            //angle=-45;
            //angle -= 3;
            //Ypos+=2;
        }
        if(dir=="left jump") {
            Ypos -=15;
            Xpos+=15;
        }

        mario.setPosition(Xpos, Ypos);
        //Ypos +=5;

        mario.setPosition(Xpos, Ypos);


        if(dir=="right"&&Xpos>0) {
            Xpos-=2;

        }
        if(dir=="left"&&Xpos<700) {
            Xpos+=2;
        }

        mario.setPosition(Xpos,Ypos);
        lucky.setPosition(500,350);
        Portal1.setPosition(50,350);
        Portal2.setPosition(150,350);
        Portal3.setPosition(250,350);
        Portal4.setPosition(350,350);

        FL.setPosition(-30,500);

//Rendering.....this is where everything is displayed
        window.clear();

        window.draw(BG);
        window.draw(FL);
        window.draw(Button);

        if(start==1) {
            for(int i=0; i<3; i++) {
                window.draw(BigCLVector[i]);
                window.draw(SmallCLVector[i]);
            }
            window.draw(Sun);
            window.draw(Grant);
            window.draw(Portal1);
            window.draw(Portal2);
            window.draw(Portal3);
            window.draw(Portal4);
            window.draw(lucky);
        }


        window.draw(mario);

//        window.draw(rect);
        window.display();


    }


    return 0;

}
