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
    bool Timer=false;
    sf::Event event;
    int frame=0;
    sf::Clock clock;
    //int keyNum=0;
    int coins=0;
    int points2=0;
    int points3=0;
    std::string dir="stop";
    int Xpos=200;
    int Ypos=340;
    float CLXSpeed=0;
    int start=0;
    std::string gameState;
    CLXSpeed=-0.5;
    gameState="start";

    sf::RenderWindow window(sf::VideoMode(800,600),"My game");
    window.setFramerateLimit(60);

    //Add sound recordings


    //*******************************************************


//Button*****************************************
    sf::RectangleShape Arrow(sf::Vector2f(50.f, 30.f));
    sf::Texture ARTexture;
    ARTexture.loadFromFile("Assets/Arrow.png");
    Arrow.setTexture(&ARTexture);
    Arrow.setPosition(700,400);
//************************************************


//Button*****************************************
    sf::RectangleShape Arrow2(sf::Vector2f(50.f, 30.f));
    sf::Texture AR2Texture;
    AR2Texture.loadFromFile("Assets/Arrow.png");
    Arrow2.setTexture(&AR2Texture);
    Arrow2.setPosition(50,430);
    Arrow2.setFillColor(sf::Color::Black);
    Arrow2.setRotation(180.f);
//************************************************

//*************************************************


//Make bird*************************************************
    sf::RectangleShape mario(sf::Vector2f(500.f, 300.f));
    mario.setOrigin(25.f,20.f);
    sf::Texture texture1;
//*****************************************************************

//Make lucky block****************************************************
    sf::RectangleShape lucky(sf::Vector2f(50.f, 50.f));
    sf::Texture Luckytexture;
    Luckytexture.loadFromFile("Assets/LuckyB.png");
    lucky.setTexture(&Luckytexture);
//*********************************************************************

//Make coin*************************************************
    sf::CircleShape coin(20.f);
    sf::Texture CoinTexture;
    CoinTexture.loadFromFile("Assets/Coin.png");
    coin.setTexture(&CoinTexture);
//*****************************************************************


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

    sf::RectangleShape Portal1(sf::Vector2f(200.f, 250.f));
    sf::Texture Portal1texture;
    Portal1texture.loadFromFile("Assets/Blue Portal.png");
    Portal1.setTexture(&Portal1texture);
    Portal1.setPosition(10,100);

    sf::RectangleShape Portal2(sf::Vector2f(200.f, 250.f));
    sf::Texture Portal2texture;
    Portal2texture.loadFromFile("Assets/Purple portal.png");
    Portal2.setTexture(&Portal2texture);
        Portal2.setPosition(220,100);


    sf::RectangleShape Portal3(sf::Vector2f(200.f, 250.f));
    sf::Texture Portal3texture;
    Portal3texture.loadFromFile("Assets/Red portal.png");
    Portal3.setTexture(&Portal3texture);
        Portal3.setPosition(400,100);


    sf::RectangleShape Portal4(sf::Vector2f(200.f, 250.f));
    sf::Texture Portal4texture;
    Portal4texture.loadFromFile("Assets/Green portal.png");
    Portal4.setTexture(&Portal4texture);
        Portal4.setPosition(600,100);

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

//Text font*****************************************
    sf::Font myFont;
    myFont.loadFromFile("Assets/Mario.ttf");
//*******************************************************************

//Text*************************************************************

    sf::Text World;
    World.setFont(myFont);
    World.setString("World");
    World.setCharacterSize(30);
    World.setFillColor(sf::Color::White);

    sf::Text One;
    One.setFont(myFont);
    One.setString("1-");
    One.setCharacterSize(30);
    One.setFillColor(sf::Color::White);

    sf::Text Time;
    Time.setFont(myFont);
    Time.setString("Time");
    Time.setCharacterSize(30);
    Time.setFillColor(sf::Color::White);

    sf::Text Mario;
    Mario.setFont(myFont);
    Mario.setString("Mario");
    Mario.setCharacterSize(30);
    Mario.setFillColor(sf::Color::White);

    sf::Text X;
    X.setFont(myFont);
    X.setString("X");
    X.setCharacterSize(30);
    X.setFillColor(sf::Color::White);

//**********************************************************************

//Score*****************************************************************
    sf::Text WorldScore;
    WorldScore.setFont(myFont);
    WorldScore.setCharacterSize(30);
    WorldScore.setFillColor(sf::Color::White);

    sf::Text TimeScore;
    TimeScore.setFont(myFont);
    TimeScore.setCharacterSize(30);
    TimeScore.setFillColor(sf::Color::White);

    sf::Text CoinScore;
    CoinScore.setFont(myFont);
    CoinScore.setCharacterSize(30);
    CoinScore.setFillColor(sf::Color::White);


//***********************************************************************


//Mario left texture***********************************************
    texture1.loadFromFile("Assets/mario0002.png");
    mario.setTexture(&texture1);

    sf::Texture texture2;
    texture2.loadFromFile("Assets/mario0002.png");

    sf::Texture texture3;
    texture3.loadFromFile("Assets/mario0003.png");

    sf::Texture texture4;
    texture4.loadFromFile("Assets/mario0004.png");
//******************************************************************
//Mario right texture***********************************************

    sf::Texture texture6;
    texture6.loadFromFile("Assets/mario0007.png");

    sf::Texture texture7;
    texture7.loadFromFile("Assets/mario0007.png");

    sf::Texture texture8;
    texture8.loadFromFile("Assets/mario0008.png");

    sf::Texture texture9;
    texture9.loadFromFile("Assets/mario0009.png");
//******************************************************************

//Mario up texture***********************************************

    sf::Texture texture10;
    texture10.loadFromFile("Assets/mario0001.png");

    sf::Texture texture11;
    texture11.loadFromFile("Assets/mario0013.png");

    sf::Texture texture12;
    texture12.loadFromFile("Assets/mario0014.png");

    sf::Texture texture13;
    texture13.loadFromFile("Assets/mario0015.png");
//******************************************************************

//Mario stop motion*****************************************
    sf::Texture texture5;
    texture5.loadFromFile("Assets/mario0001.png");
//*********************************************************

//StartScreen*****************************************
    sf::RectangleShape SC(sf::Vector2f(900.f, 600.f));
    sf::Texture SCTexture;
    SCTexture.loadFromFile("Assets/startScreen.png");
    SC.setTexture(&SCTexture);
    SC.setPosition(-20,-100);
//************************************************

//PortalRoom*****************************************
    sf::RectangleShape PR(sf::Vector2f(900.f, 600.f));
    sf::Texture PRTexture;
    PRTexture.loadFromFile("Assets/PortalRoom.png");
    PR.setTexture(&PRTexture);
    PR.setPosition(0,0);
//************************************************

//Floor2*****************************************
    sf::RectangleShape BFL(sf::Vector2f(900.f, 600.f));
    sf::Texture BFLTexture;
    BFLTexture.loadFromFile("Assets/BlackBrick.png");
    BFL.setTexture(&BFLTexture);
    BFL.setPosition(-30,500);
//************************************************


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
            if(isButtonClicked(Arrow.getGlobalBounds(),sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                if(event.type== sf::Event::MouseButtonReleased && event.mouseButton.button== sf::Mouse::Left) {
                    gameState="Level 1";
                    points2=1;
                    Timer=true;
                    // Button.setColor(sf::Color::Transparent);
                    SC.setFillColor(sf::Color::Transparent);
                    Arrow.setFillColor(sf::Color::Transparent);

                }
            }
            if(isButtonClicked(Arrow2.getGlobalBounds(),sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                if(event.type== sf::Event::MouseButtonReleased && event.mouseButton.button== sf::Mouse::Left) {
                    gameState="Portal";
                    start=4;
                    points2=-1;
                    Timer=true;
                    // Button.setColor(sf::Color::Transparent);
                    SC.setFillColor(sf::Color::Transparent);
                    Arrow2.setFillColor(sf::Color::Transparent);

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

//Points********************************************************************
        std::stringstream ss2;
        ss2<<points2;
        WorldScore.setString(ss2.str());

        std::stringstream ss3;
        ss3<<points3;
        TimeScore.setString(ss3.str());

        std::stringstream ss4;
        ss4<<coins;
        CoinScore.setString(ss4.str());

//****************************************************************************


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
        } else if(dir=="stop") {
            mario.setTexture(&texture5);

        }

        if (dir=="right") {
            if (clock.getElapsedTime().asSeconds()> .1f) {
                frame ++;
                if (frame == 6) {
                    frame = 1;
                }
                if (frame == 1) {
                    mario.setTexture(&texture6);
                } else if (frame ==2) {
                    mario.setTexture(&texture7);
                } else if (frame==3) {
                    mario.setTexture(&texture8);
                } else if (frame==4) {
                    mario.setTexture(&texture9);
                } else if (frame==5) {
                    mario.setTexture(&texture9);
                }
                clock.restart();
            }
        }
        if (dir=="up") {
            if (clock.getElapsedTime().asSeconds()> .1f) {
                frame ++;
                if (frame == 4) {
                    frame = 1;
                }
                if (frame == 1) {
                    mario.setTexture(&texture10);
                } else if (frame ==2) {
                    mario.setTexture(&texture11);
                } else if (frame==3) {
                    mario.setTexture(&texture12);
                } else if (frame==4) {
                    mario.setTexture(&texture13);
                }
                // else if (frame==5) {
                //    mario.setTexture(&texture13);
                //   }
                clock.restart();
            }
        }
//**********************************************************************************
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

//The transfer of screens
        /*
        if(Xpos==-100){
            start=4;
        Xpos=700;

        }

        bool Level1=true;

        if(Level1==true){

        if(Xpos==500){
           gameState="Level 1";
           SC.setFillColor(sf::Color::Transparent);
            Xpos=-100;
            Level1=false;
        }
        }
        mario.setPosition(Xpos,Ypos);
        */
//****************************************************************************************

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


        if(dir=="right") {
            Xpos-=2;

        }
        if(dir=="left"&&Xpos<700) {
            Xpos+=2;
        }

        mario.setPosition(Xpos,Ypos);
        World.setPosition(450,0);
        One.setPosition(485,30);
        WorldScore.setPosition(520,30);
        Time.setPosition(650,0);
        TimeScore.setPosition(685,30);
        Mario.setPosition(50,0);
        coin.setPosition(250,30);
        X.setPosition(280,25);
        CoinScore.setPosition(310,25);
        lucky.setPosition(500,350);

        FL.setPosition(-30,500);

//Rendering.....this is where everything is displayed
        window.clear();

        window.draw(BG);
        window.draw(SC);
        window.draw(FL);
        window.draw(Arrow);
        window.draw(Arrow2);
        window.draw(World);
        window.draw(One);
        window.draw(WorldScore);
        window.draw(Time);
        window.draw(TimeScore);
        window.draw(Mario);
        window.draw(coin);
        window.draw(X);
        window.draw(CoinScore);

        if(gameState=="Level 1") {
            for(int i=0; i<3; i++) {
                window.draw(BigCLVector[i]);
                window.draw(SmallCLVector[i]);
            }
            window.draw(Sun);
            window.draw(Grant);
            window.draw(lucky);
        }
        if(start==4) {
            //if(gameState=="portal") {
            window.draw(PR);
            window.draw(BFL);
            window.draw(Portal1);
            window.draw(Portal2);
            window.draw(Portal3);
            window.draw(Portal4);
            BG.setFillColor(sf::Color::Transparent);

        }

        window.draw(mario);

//        window.draw(rect);
        window.display();


    }


    return 0;

}
