        #include <SDL2/SDL.h>
        #include <stdio.h>
        #include <stdbool.h>
        #include <SDL2/SDL_image.h>
        #include <math.h>
        #include <SDL2/SDL_ttf.h>

        #define FPS 60
        #define FrameDelay 1000/FPS
        #define PI 3,141592653589793

        /******************************* Global Variables ***************************************/

        int frames1 = 0;
        int frames = 0;
        int framesMili = 0;
        int frameSegundos = 0;
        int frameSegundos1 = 0;
        int frameMinutos = 0;
        int frameMinutos1 = 0;

        bool Bot1Explodir;
        bool Bot2Explodir;
        bool Bot3Explodir;

        double localx1;
        double localy1;

        double localx2;
        double localy2;

        double localx3;
        double localy3;

        int FrameExplodir1 = 0;
        int FrameExplodir2 = 0;
        int FrameExplodir3 = 0;

        bool RodarMenu = true;


        Uint32 seconds;
        int  frameStart;
        float frameTime;



        /**--ANGULOS--**/

        double degrees = 0.0;
        double angleredemoinho = 0.0;

        SDL_RendererFlip flipType = SDL_FLIP_NONE;




        /******************************* Structures Variables ***************************************/

        typedef struct _CARRO
        {
            double x;
            double y;
            double aceleracao;
            double velocidade;
            double frontWheelX;
            double frontWheelY;
            double backWheelX;
            double backWheelY;
            double wheelBase;
            double carHeading;
            double Angle;
            double rumo;
            double raio;

        } CARRO;



        /******************************* Window variables ***************************************/

        SDL_Window* janela = NULL;
        SDL_Renderer* renderer = NULL;



        /******************************* Player variables ***************************************/

        SDL_Texture* playerTex = NULL;
        SDL_Rect destPlayer;
        SDL_Rect drawingRect;

        bool sobe = false, desce = false, esquerda = false, direita = false;

        CARRO jogador;



        /******************************* Bots variables ***************************************/

        SDL_Texture* Bot1Tex = NULL;
        SDL_Rect destBot1;
        SDL_Texture* Bot2Tex = NULL;
        SDL_Rect destBot2;
        SDL_Texture* Bot3Tex = NULL;
        SDL_Rect destBot3;


        CARRO jogador1;
        CARRO jogador2;
        CARRO jogador3;



        /******************************* Map variables ***************************************/

        SDL_Texture* mapTex = NULL;
        SDL_Rect destMap;

        SDL_Texture* map1Tex = NULL;
        SDL_Rect destMap1;

        SDL_Texture* map2Tex = NULL;
        SDL_Rect destMap2;

        SDL_Texture* map3Tex = NULL;
        SDL_Rect destMap3;

        SDL_Texture* map4Tex = NULL;
        SDL_Rect destMap4;

        SDL_Texture* map5Tex = NULL;
        SDL_Rect destMap5;

        SDL_Texture* map6Tex = NULL;
        SDL_Rect destMap6;

        SDL_Texture* map7Tex = NULL;
        SDL_Rect destMap7;

        SDL_Texture* map8Tex = NULL;
        SDL_Rect destMap8;

        SDL_Texture* map9Tex = NULL;
        SDL_Rect destMap9;




        /******************************* Clips variables ***************************************/

        SDL_Texture* gSpriteSheetTexture;
        SDL_Rect gSpriteClips[ 4 ];

        SDL_Texture* explosionTex;
        SDL_Rect destExplosion[ 10 ];

        SDL_Texture* numerosTex;
        SDL_Rect destnumeros[11];




         /******************************* Menu Variables ***************************************/


         SDL_Texture* BackTex = NULL;
         SDL_Rect destBack;

         SDL_Texture* OpcoesTex = NULL;
         SDL_Rect destOpcoes;

         SDL_Texture* LogoTex = NULL;
         SDL_Rect destLogo;

         SDL_Texture* CartaTex = NULL;
         SDL_Rect destCarta;

         SDL_Texture* Hist1Tex = NULL;
         SDL_Rect destHist1;

         SDL_Texture* Hist2Tex = NULL;
         SDL_Rect destHist2;

         SDL_Texture* TimaoTex = NULL;
         SDL_Rect destTimao;

         SDL_Texture* creditosTex = NULL;
         SDL_Rect destcreditos;

         SDL_Texture* FimTex = NULL;
         SDL_Rect destFim;




        /******************************* Objetos variables ***************************************/

        /*-CHEST SUPERIOR-*/
        SDL_Texture* chestTex = NULL;
        SDL_Rect distChest;

        /*-POSITIONS-*/
        SDL_Texture* N5Tex = NULL;
        SDL_Rect distN5;

        SDL_Texture* BarraTex = NULL;
        SDL_Rect distBarra;

        /*-FAIXA-*/
        SDL_Texture* FaixaTex = NULL;
        SDL_Rect distFaixa;

        /*-FAIXA-*/
        SDL_Texture* RedemoinhoTex = NULL;
        SDL_Rect distRedemoinho;

        /*-ROCHA-*/
        SDL_Texture* RochaTex = NULL;
        SDL_Rect distRocha;

        /*-TESTES-*/
        SDL_Texture* simuTex = NULL;
        SDL_Rect distSimu[8];



        /******************************* FUNCTIONS ***************************************/

        void GameEventos();
        void GameRender();
        void GameUpdate();
        void GameClean();
        bool running();
        bool isRunning;
        SDL_Texture* LoadTexture();



        int Cont1 = 0;


        int main(int argc, char ** argv)
        {

            /******************************* assigning Player Values ***************************************/


            destPlayer.h = 94.16;
            destPlayer.w = 53.33;
            destPlayer.x = 1366/ 2;
            destPlayer.y = 768/1.4;

            jogador.x = 925;
            jogador.y = 4732;
            jogador.aceleracao = 0;
            jogador.velocidade = 0;
            jogador.wheelBase =  113;
            jogador.Angle = 0.0;
            jogador.carHeading = -1.573;
            jogador1.raio = 2 * PI * 3;



            /******************************* Assigning Map Values ***************************************/

            //destMap.w = 1262 * 5;
            //destMap.h = 3822 * 5;
            destMap.w = 3210;
            destMap.h = 5698;
            destMap.x = 0;
            destMap.y = 0;

            destMap1.w = 3210;
            destMap1.h = 5698;

            destMap2.w = 3210;
            destMap2.h = 5698;

            destMap3.w = 3210;
            destMap3.h = 5698;

            destMap4.w = 3210;
            destMap4.h = 5698;

            destMap5.w = 3210;
            destMap5.h = 5698;

            destMap6.w = 3210;
            destMap6.h = 5698;

            destMap7.w = 3210;
            destMap7.h = 5698;

            destMap8.w = 3210;
            destMap8.h = 5698;

            destMap9.w = 3210;
            destMap9.h = 5698;



            /******************************* assigning Bots Values ***************************************/

            destBot1.h = 94.16;
            destBot1.w = 53.33;

            destBot2.h = 94.16;
            destBot2.w = 53.33;

            destBot3.h = 94.16;
            destBot3.w = 53.33;


            jogador1.x = 1490;
            jogador1.y = 5286;
            jogador1.aceleracao = 0;
            jogador1.velocidade = 0;
            jogador1.wheelBase =  113;
            jogador1.Angle = 0.0;
            jogador1.carHeading = -1.573;

            jogador2.x = 1375;
            jogador2.y = 5286;
            jogador2.aceleracao = 0;
            jogador2.velocidade = 0;
            jogador2.wheelBase =  113;
            jogador2.Angle = 0.0;
            jogador2.carHeading = -1.573;

            jogador3.x = 1730;
            jogador3.y = 5286;
            jogador3.aceleracao = 0;
            jogador3.velocidade = 0;
            jogador3.wheelBase =  113;
            jogador3.Angle = 0.0;
            jogador3.carHeading = -1.573;


            Bot1Explodir = false;
            Bot2Explodir = false;
            Bot3Explodir = false;




            /******************************* Assigning Camera Values ***************************************/


            drawingRect.x = destPlayer.x - destMap.x;
            drawingRect.y = destPlayer.y - destMap.y;
            drawingRect.w = destPlayer.w;
            drawingRect.h = destPlayer.h;


            /**Starting window **/

            GameInit(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, true);

          while(running())
          {
            frameStart = SDL_GetTicks();

            GameEventos();
            GameUpdate();
            GameRender();

            frameTime = SDL_GetTicks() - frameStart;

            if(FrameDelay > frameTime)
            {
               SDL_Delay(FrameDelay - frameTime);
            }

          }

          GameClean();

         return 0;
        }





/**------------------------------------------------------------------------------------------------------------------------**/





        void GameInit(int xpos, int ypos, int width, int height, bool fullscreen)
        {
            int flags;
            if(fullscreen)
            {
                flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
            }

            if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
            {
                printf("Subsistemas Inicializados!\n");

                janela = SDL_CreateWindow("GameRacing", xpos, ypos, width, height, flags);
                if(janela)
                {
                    printf("Janela Criada!\n");
                }

                renderer = SDL_CreateRenderer(janela, -1, 0);
                if (renderer)
                {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    printf("Renderer Criada!\n");
                }

                isRunning = true;
            }

            else
            {
                isRunning = false;
            }




            /******************************* Loading Images ***************************************/


             /*-Menu-*/
            BackTex = LoadTexture("Imagens/menu.png", renderer);
            CartaTex = LoadTexture("Imagens/carta.png", renderer);
            Hist1Tex = LoadTexture("Imagens/historia_1.png", renderer);
            Hist2Tex = LoadTexture("Imagens/historia_2.png", renderer);
            TimaoTex = LoadTexture("Imagens/timao.png", renderer);
            creditosTex = LoadTexture("Imagens/creditos.png");
            FimTex = LoadTexture("Imagens/venceu.png");



            /*-MAPS-*/
            mapTex = LoadTexture("Imagens//aguailhas.png", renderer);
            map1Tex = LoadTexture("Imagens//aguailhas.png", renderer);

            map2Tex = LoadTexture("Imagens//aguailhas.png", renderer);
            map3Tex = LoadTexture("Imagens//aguailhas.png", renderer);
            map4Tex = LoadTexture("Imagens//final_1.png", renderer);
            map5Tex = LoadTexture("Imagens//final_2.png", renderer);


            /*--PLAYER--*/
            playerTex = LoadTexture("Imagens//barco.png", renderer);


            /*--BOTS--*/
            Bot1Tex = LoadTexture("Imagens//Bot1.png");
            Bot2Tex = LoadTexture("Imagens//Bot2.png");
            Bot3Tex = LoadTexture("Imagens//Bot3.png");


            /*--CLIPS--*/
            numerosTex = LoadTexture("Imagens//numeros.png");


            /*--OBJECTS--*/
            FaixaTex = LoadTexture("Imagens//largada.jpeg");
            RochaTex = LoadTexture("Imagens//planta.png");
            RedemoinhoTex = LoadTexture("Imagens//ciclone.png");
            simuTex = LoadTexture("Imagens//explosao.png");

        }

         /******************************* EVENTS/KEYBOARD ***************************************/



        void GameEventos()
        {
            int posicaox = 460;
            int posicaoy = 340;
            int TimaoAngle = 0;

            int jogar = 340, recorde = 430, creditos = 535, sair = 628;

            while(RodarMenu == true)
            {
                frameStart = SDL_GetTicks();
                SDL_Event event;
                SDL_PollEvent(&event);


                switch (event.type)
                {
                    case SDL_QUIT:
                RodarMenu = false;
                break;


                 case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                        case SDLK_UP:
                            sobe = true;
                            break;

                        case SDLK_DOWN:
                            desce = true;
                            break;

                        case SDLK_LEFT:
                            esquerda = true;
                            break;

                        case SDLK_RIGHT:
                            direita = true;
                            break;

                        case SDLK_RETURN:
                            Historia();
                            RodarMenu = false;
                            break;

                        case SDLK_ESCAPE:
                            RodarMenu = false;
                            break;

                        } break;


                  case SDL_KEYUP:
                         switch (event.key.keysym.sym)
                         {
                            case SDLK_UP:
                            sobe = false;
                            break;

                            case SDLK_DOWN:
                                desce = false;
                            break;

                            case SDLK_LEFT:
                            esquerda = false;
                            break;

                            case SDLK_RIGHT:
                            direita = false;
                            break;

                         }break;
                }


                destBack.x = 0;
                destBack.y = 0;
                destBack.w = 1388;
                destBack.h = 788;

                destOpcoes.x = 1160/2;
                destOpcoes.y = 300;
                destOpcoes.w = 1361/6;
                destOpcoes.h = 2687/6;

                destLogo.x = 230;
                destLogo.y = -70;
                destLogo.w = 1366/1.5;
                destLogo.h = 768/1.5;

                destCarta.x = 0;
                destCarta.y = 0;
                destCarta.w = 1366;
                destCarta.h = 768;

                destHist1.x = 0;
                destHist1.y = 0;
                destHist1.w = 1366;
                destHist1.h = 768;

                destHist2.x = 0;
                destHist2.y = 0;
                destHist2.w = 1366;
                destHist2.h = 768;

                destFim.x = 0;
                destFim.y = 0;
                destFim.w = 1366;
                destFim.h = 768;

                destcreditos.x = 0;
                destcreditos.y = 0;
                destcreditos.w = 1366;
                destcreditos.h = 768;

                destTimao.x = posicaox + 57;
                destTimao.y = posicaoy + 160;

                destTimao.w = 456/3.7;
                destTimao.h = 256/3.7;


                TimaoAngle += 7;

                 frameTime = SDL_GetTicks() - frameStart;

                if(FrameDelay > frameTime)
                {
                    SDL_Delay(FrameDelay - frameTime);
                }

            SDL_RenderCopy(renderer, BackTex, NULL, &destBack);
            SDL_RenderCopy(renderer, LogoTex, NULL, &destLogo);
            SDL_RenderCopy(renderer, OpcoesTex, NULL, &destOpcoes);
            SDL_RenderCopyEx(renderer, TimaoTex, NULL, &destTimao, TimaoAngle, NULL, flipType);
            SDL_RenderPresent(renderer);
            }

            double aux;




            SDL_Event event;
            SDL_PollEvent(&event);

            switch (event.type)
            {
                case SDL_QUIT:
                isRunning = false;
                break;


                 case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                        case SDLK_UP:
                            sobe = true;
                            break;

                        case SDLK_DOWN:
                            desce = true;
                            break;

                        case SDLK_LEFT:
                            esquerda = true;
                            break;

                        case SDLK_RIGHT:
                            direita = true;
                            break;

                        case SDLK_ESCAPE:
                            isRunning = false;
                            break;

                        case SDLK_p:
                        sobe = true;
                        break;

                        } break;


                  case SDL_KEYUP:
                         switch (event.key.keysym.sym)
                         {
                            case SDLK_UP:
                            sobe = false;
                            break;

                            case SDLK_DOWN:
                            desce = false;
                            break;

                            case SDLK_LEFT:
                            esquerda = false;
                            break;

                            case SDLK_RIGHT:
                            direita = false;
                            break;

                         }break;
            }



            /**--LIMITEMAP--**/



            if(jogador.x < 415)
            {
                jogador.x = 416;
                esquerda = false;

            }

            if(jogador.x > 1365)
            {
                jogador.x = 1364;
                direita = false;
            }

            if(jogador.y < -28400)
            {
                sobe = false;
                jogador.aceleracao = 0;
                jogador.velocidade -= 2;
                Fim();
            }




        /******************************* COLISÕES ***************************************/








        /******************************* CONTROLES ***************************************/


            /**--SOBE--**/


            if(sobe == true)
            {
               jogador.aceleracao += 0.05;
            }



            /**-DESCE-**/


            if(desce == true)
            {
                jogador.aceleracao -= 2;
                jogador.velocidade -= 0.04;

                if(jogador.aceleracao == 0 && jogador.velocidade == 0)
                {
                    jogador.velocidade = -2;
                }

            }


            /**--ESQUERDA--**/


            if(esquerda == true)
            {
               //jogador.x -= 10;


                if(jogador.Angle < -0.30)
                {
                   jogador.Angle = -0.30;
                }
                else
                {
                    jogador.Angle -= 0.007;
                }
               // degrees += 5 * jogador.Angle * jogador.aceleracao;

            }



            /**--DIREITA--**/


            if(direita == true)
            {

                //jogador.x += 10;

                if(jogador.Angle > 0.30)
                {
                    jogador.Angle = 0.30;
                }
                else
                {
                   jogador.Angle += 0.007;
                }

            }



            if(direita == false && esquerda == false)
                jogador.Angle = 0;



            jogador1.aceleracao += 0.03;
            jogador2.aceleracao += 0.03;
            jogador3.aceleracao += 0.03;


            atualiza(&jogador);
            atualiza(&jogador1);
            atualiza(&jogador2);
            atualiza(&jogador3);

            printf(" 1 %d\n", jogador.x);
            printf(" 2 %df\n", jogador.y);
        }






        /******************************* GAME UPDATE() ***************************************/



        void GameUpdate()
        {
            destMap.x = -destPlayer.x;
            destMap.y = -destPlayer.y;

            destPlayer.x = jogador.x;
            destPlayer.y = jogador.y;

            destMap1.x = 0 + destMap.x;
            destMap1.y = -5698 + destMap.y;

            destMap2.x = -12 + destMap.x;
            destMap2.y = -11396 + destMap.y;

            destMap3.x = 0 + destMap.x;
            destMap3.y = -17094 + destMap.y;

            destMap4.x = 0 + destMap.x;
            destMap4.y = -22792 + destMap.y;

            destMap5.x = 0 + destMap.x;
            destMap5.y = -28490 + destMap.y;

            destMap6.x = 0 + destMap.x;
            destMap6.y = -34188 + destMap.y;

            destMap7.x = 0 + destMap.x;
            destMap7.y = -39886 + destMap.y;

            destMap8.x = 0 + destMap.x;
            destMap8.y = -45584 + destMap.y;

            destMap9.x = 0 + destMap.x;
            destMap9.y = -51282+ destMap.y;


            destBot1.x = jogador1.x + destMap.x;
            destBot1.y = jogador1.y + destMap.y;


            destBot2.x = jogador2.x + destMap.x;
            destBot2.y = jogador2.y + destMap.y;


            destBot3.x = jogador3.x + destMap.x;
            destBot3.y = jogador3.y + destMap.y;


            distFaixa.h = 125;
            distFaixa.w = 1000;
            distFaixa.x = 1100 + destMap.x;
            distFaixa.y = 5150 + destMap.y;

            distRocha.h = 203/1.3;
            distRocha.w = 394/1.3;
            distRocha.x = jogador1.x + destMap.x;
            distRocha.y = jogador1.y + destMap.y;

            distRedemoinho.h = 300;
            distRedemoinho.w = 300;




            //explosion

            distSimu[ 0 ].x = 0;
            distSimu[ 0 ].y = 0;
            distSimu[ 0 ].w =  204;
            distSimu[ 0 ].h = 185;

            distSimu[ 1 ].x = 220;
            distSimu[ 1 ].y = 0;
            distSimu[ 1 ].w = 204;
            distSimu[ 1 ].h = 185;

            distSimu[ 2 ].x = 458;
            distSimu[ 2 ].y = 0;
            distSimu[ 2 ].w =  204;
            distSimu[ 2 ].h = 185;

            distSimu[ 3 ].x = 716;
            distSimu[ 3 ].y = 0;
            distSimu[ 3 ].w = 204;
            distSimu[ 3 ].h = 185;

            distSimu[ 4 ].x = 949;
            distSimu[ 4 ].y = 0;
            distSimu[ 4 ].w =  204;
            distSimu[ 4 ].h = 185;

            distSimu[ 5 ].x = 1160;
            distSimu[ 5 ].y = 0;
            distSimu[ 5 ].w =  204;
            distSimu[ 5 ].h = 185;

            distSimu[ 6 ].x = 1374;
            distSimu[ 6 ].y = 0;
            distSimu[ 6 ].w =  204;
            distSimu[ 6 ].h = 185;

            distSimu[ 7 ].x = 1578;
            distSimu[ 7 ].y = 0;
            distSimu[ 7 ].w = 204;
            distSimu[ 7 ].h = 185;


            //Contador

            destnumeros[ 0 ].x = 0;
            destnumeros[ 0 ].y = 0;
            destnumeros[ 0 ].w = 40;
            destnumeros[ 0 ].h = 62;


            destnumeros[ 1 ].x = 32;
            destnumeros[ 1 ].y = 0;
            destnumeros[ 1 ].w = 29;
            destnumeros[ 1 ].h = 62;

            destnumeros[ 2 ].x = 69;
            destnumeros[ 2 ].y = 0;
            destnumeros[ 2 ].w = 39;
            destnumeros[ 2 ].h = 62;

            destnumeros[ 3 ].x = 108;
            destnumeros[ 3 ].y = 0;
            destnumeros[ 3 ].w = 40;
            destnumeros[ 3 ].h = 62;

            destnumeros[ 4 ].x = 148;
            destnumeros[ 4 ].y = 0;
            destnumeros[ 4 ].w = 38;
            destnumeros[ 4 ].h = 62;

            destnumeros[ 5 ].x = 186;
            destnumeros[ 5 ].y = 0;
            destnumeros[ 5 ].w = 43;
            destnumeros[ 5 ].h = 62;

            destnumeros[ 6 ].x = 229;
            destnumeros[ 6 ].y = 0;
            destnumeros[ 6 ].w = 39;
            destnumeros[ 6 ].h = 62;

            destnumeros[ 7 ].x = 268;
            destnumeros[ 7 ].y = 0;
            destnumeros[ 7 ].w = 39;
            destnumeros[ 7 ].h = 62;

            destnumeros[ 8 ].x = 307;
            destnumeros[ 8 ].y = 0;
            destnumeros[ 8 ].w = 40;
            destnumeros[ 8 ].h = 62;

            destnumeros[ 9 ].x = 346;
            destnumeros[ 9 ].y = 0;
            destnumeros[ 9 ].w = 39;
            destnumeros[ 9 ].h = 62;

            destnumeros[ 10 ].x = 414;
            destnumeros[ 10 ].y = 20;
            destnumeros[ 10 ].w = 16;
            destnumeros[ 10 ].h = 62;

            printf(" 1 %ld", jogador.x);
            printf(" 2 %ld", jogador.y);

        }








        /******************************* GAME RENDERER() ***************************************/



        void GameRender()
        {
            angleredemoinho += 7;

           SDL_RenderClear(renderer);
           SDL_RenderCopy(renderer, mapTex, NULL, &destMap);
           SDL_RenderCopy(renderer, map1Tex, NULL, &destMap1);
           SDL_RenderCopy(renderer, map2Tex, NULL, &destMap2);
           SDL_RenderCopy(renderer, map3Tex, NULL, &destMap3);
           SDL_RenderCopy(renderer, map4Tex, NULL, &destMap4);
           SDL_RenderCopy(renderer, map5Tex, NULL, &destMap5);
           SDL_RenderCopy(renderer, map6Tex, NULL, &destMap6);
           SDL_RenderCopy(renderer, map7Tex, NULL, &destMap7);
           SDL_RenderCopy(renderer, map8Tex, NULL, &destMap8);
           SDL_RenderCopy(renderer, map9Tex, NULL, &destMap9);

           SDL_Rect* currentClip = &gSpriteClips[ frames / 4 ];

           SDL_Rect* ClipExplodir1 = &distSimu[ FrameExplodir1 / 10 ];
           SDL_Rect* ClipExplodir2 = &distSimu[ FrameExplodir2 / 10 ];
           SDL_Rect* ClipExplodir3 = &distSimu[ FrameExplodir3 / 10 ];

           SDL_Rect* Clip1 = &destnumeros[ framesMili / 10];
           SDL_Rect* Clip2 = &destnumeros[ frameSegundos / 10];
           SDL_Rect* Clip3 = &destnumeros[ frameMinutos / 10];

            frames++;
            frames1++;
            framesMili += 1;



            if( frames / 4 >= 4 )
            {
               frames = 0;
            }

            //frames explosion
            if( frames1 / 8 >= 8 )
            {
               frames1 = 0;
            }

            if( framesMili / 6 >= 10 )
            {
               framesMili = 0;
            }

            if( framesMili == 0 )
            {
               frameSegundos++;
            }

            if(frameSegundos > 9)
            {
                frameSegundos = 0;
                frameSegundos1++;
            }

            if( frameSegundos1 > 5)
            {
               frameSegundos1 = 0;
               frameMinutos++;
            }

            if( frameMinutos > 9)
            {
                frameMinutos = 0;
                frameMinutos1++;
            }




             if(Bot1Explodir == true)
             {
                 FrameExplodir1++;

                 renderExplosion(destBot1.x - 80, destBot1.y - 60, ClipExplodir1,0.0, flipType, NULL, simuTex);

                 destBot1.x = 122000;

                 if( FrameExplodir1 / 8 >= 8 )
                 {
                    FrameExplodir1 = 0;
                    Bot1Explodir = false;
                 }
             }


              if(Bot2Explodir == true)
              {
                 FrameExplodir2++;

                 renderExplosion(destBot2.x - 80, destBot2.y - 60 , ClipExplodir2, 0.0, flipType, NULL, simuTex);
                 destBot2.x = 122000;

                 if( FrameExplodir2 / 8 >= 8 )
                 {
                    FrameExplodir2 = 0;
                    Bot2Explodir = false;
                 }
              }


              if(Bot3Explodir == true)
              {
                 FrameExplodir3++;

                 renderExplosion(destBot3.x - 80, destBot3.y - 60, ClipExplodir3, 0.0, flipType, NULL, simuTex);
                 destBot3.x = 122000;

                 if( FrameExplodir3 / 8 >= 8 )
                 {
                    FrameExplodir3 = 0;
                    Bot3Explodir = false;
                 }
              }





            printf("Segundos: %d  -> Milisegundo: %d\n\n", frameSegundos,  framesMili);


            ContadorMili(1290, 0, Clip1, 0.0, flipType, NULL, numerosTex);
            ContadorSegundos(1198, 0, Clip2, 0.0, flipType, NULL, numerosTex, frameSegundos, frameSegundos1);
            ContadorSegundos(1100, 0, Clip3, 0.0, flipType, NULL, numerosTex, frameMinutos, frameMinutos1);

            RenderCiclone(1790, 4000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);

            RenderPedras(900, 3000, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);

            RenderCiclone(1300, 3000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);

            RenderPedras(1000, 2500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);

            RenderPedras(1760, 1600, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);

            RenderCiclone(1790, 1000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);

            RenderPedras(900, 1000, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderPedras(900, 1500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderPedras(1000, 0000, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderCiclone(1700, 0000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);

            RenderPedras(1000, -1000, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);

            RenderCiclone(1790, -2000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);

            RenderPedras(1000, -2000, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);




            RenderCiclone(1790, -4000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1100, -4500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1590, -5000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);

            RenderCiclone(1490, -5500, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1100, -6500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);




            RenderCiclone(1790, -7000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);

            RenderPedras(1100, -8500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderPedras(1800, -8500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);




            RenderCiclone(1290, -9000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1700, -9500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderCiclone(1390, -1000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1800, -10500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1590, -11000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1800, -11500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1590, -12000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1200, -13000, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1590, -13500, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1100, -14300, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);




            RenderCiclone(1590, -15000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1100, -15000, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1190, -16000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1800, -16500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1890, -17000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1000, -18000, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1490, -19000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1800, -19500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1800, -20000, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1000, -21500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1590, -21800, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1000, -19500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderCiclone(1890, -22800, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderPedras(1000, -22800, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderCiclone(1190, -23800, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderCiclone(1000, -23800, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            RenderCiclone(1590, -24300, &distRedemoinho , NULL, angleredemoinho, flipType, NULL, RedemoinhoTex);


            RenderCiclone(1700, -24300, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderPedras(1900, -25300, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);


            RenderPedras(1000, -25300, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



           // RenderPedras(1400, -27500, &distRocha, NULL, 3.0, flipType, NULL, RochaTex);



            SDL_RenderCopy(renderer, FaixaTex, NULL, &distFaixa);

            SDL_RenderCopy(renderer, Bot1Tex, NULL, &destBot1);

            SDL_RenderCopyEx(renderer, playerTex, NULL, &drawingRect, degrees, NULL, flipType);

            SDL_RenderCopy(renderer, Bot2Tex, NULL, &destBot2);

            SDL_RenderCopy(renderer, Bot3Tex, NULL, &destBot3);

            SDL_RenderCopy(renderer, N5Tex, NULL, &distN5);

            SDL_RenderCopyEx(renderer, BarraTex, NULL, &distBarra, 0.0, NULL, flipType);


            SDL_RenderPresent(renderer);
        }




        /******************************* GAME CLEAN() ***************************************/


        void GameClean()
        {
           SDL_DestroyWindow(janela);
           SDL_DestroyRenderer(renderer);
           SDL_DestroyTexture(mapTex);
           SDL_DestroyTexture(playerTex);
           SDL_DestroyTexture(Bot1Tex);
           SDL_DestroyTexture(Bot2Tex);
           SDL_DestroyTexture(Bot3Tex);
           SDL_DestroyTexture(chestTex);
           SDL_DestroyTexture(gSpriteSheetTexture);
           SDL_DestroyTexture(explosionTex);
           SDL_DestroyTexture(RedemoinhoTex);
           SDL_DestroyTexture(FaixaTex);
           SDL_DestroyTexture(map1Tex);
           SDL_DestroyTexture(map2Tex);
           SDL_DestroyTexture(map3Tex);
           SDL_DestroyTexture(map4Tex);
           SDL_Quit();

           printf("Jogo Limpo\n");
        }






        /******************************* GAME TEXTURA() ***************************************/

        SDL_Texture* LoadTexture(const char* texture, SDL_Renderer* ren)
        {
            SDL_Surface* tempSurface = IMG_Load(texture);
            SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
            SDL_FreeSurface(tempSurface);
            return tex;
        }










        /******************************* GAME RENDER CLIPS ***************************************/


        void render(int x, int y, SDL_Rect* rect, SDL_Rect* clip, double angle, SDL_RendererFlip flip, SDL_Point* center, SDL_Texture* textura)
        {
            //Set rendering space and render to screen
            SDL_Rect renderQuad;
            renderQuad.h = NULL;
            renderQuad.w = NULL;
            renderQuad.x = x + destMap.x;
            renderQuad.y = y + destMap.y;

            //Set clip rendering dimensions
            if( clip != NULL )
            {
                renderQuad.w = clip->w;
                renderQuad.h = clip->h;
            }

            else if(clip == NULL)
            {
                renderQuad.w = rect->w;
                renderQuad.h = rect->h;
            }

            //Render to screen
            SDL_RenderCopyEx(renderer, textura, clip, &renderQuad , angle, center, flip);
        }





         void renderExplosion(int x, int y, SDL_Rect* clip, double angle, SDL_RendererFlip flip, SDL_Point* center, SDL_Texture* textura)
        {
            //Set rendering space and render to screen
            SDL_Rect renderQuad;
            renderQuad.h = NULL;
            renderQuad.w = NULL;
            renderQuad.x = x;
            renderQuad.y = y;

            //Set clip rendering dimensions
            if( clip != NULL )
            {
                renderQuad.w = clip->w;
                renderQuad.h = clip->h;
            }

            //Render to screen
            SDL_RenderCopyEx(renderer, textura, clip, &renderQuad , angle, center, flip);
        }



        /******************************* FÍSICA CARRO() ***************************************/


        void atualiza(CARRO *p_carro)
        {
             if((*p_carro).aceleracao > 1)
             {
                (*p_carro).aceleracao = 1;
             }

             if((*p_carro).aceleracao < -1)
            {
                 (*p_carro).aceleracao = -0.2;
            }



            (*p_carro).velocidade = (*p_carro).velocidade + (*p_carro).aceleracao * 0.03;

            if((p_carro)->velocidade > 12)
            {
                (p_carro)->velocidade = 12;
            }



            andar(p_carro);
        }





        void andar(CARRO * barco)
        {
             barco -> frontWheelX = barco -> x + barco -> wheelBase/2 * cos(barco -> carHeading);
             barco -> frontWheelY = barco -> y + barco -> wheelBase/2 * sin(barco -> carHeading);
             barco -> backWheelX = barco->   x - barco -> wheelBase/2 * cos(barco -> carHeading);
             barco -> backWheelY = barco ->  y - barco -> wheelBase/2 * sin(barco -> carHeading);

             barco -> backWheelX += barco -> velocidade *cos(barco -> carHeading);
             barco -> backWheelY += barco -> velocidade * sin(barco -> carHeading);
             barco -> frontWheelX += barco -> velocidade * cos(barco -> carHeading + barco -> Angle);
             barco -> frontWheelY += barco -> velocidade * sin(barco -> carHeading + barco -> Angle);

             barco -> x = (barco -> frontWheelX + barco -> backWheelX) / 2;
             barco -> y = (barco -> frontWheelY + barco -> backWheelY) / 2;

             barco -> carHeading = atan2( barco -> frontWheelY - barco -> backWheelY , barco -> frontWheelX - barco -> backWheelX );
        }








        /******************************* FISICA COLISÃO ***************************************/


         int colisao(SDL_Rect ent_1,SDL_Rect ent_2)
         {
            int colide=-1;



            if((ent_1.y - jogador.velocidade <= ent_2.y + ent_2.h) && (ent_1.y + ent_1.h >= ent_2.y + ent_2.h) && ((ent_1.x >=ent_2.x && ent_1.x <= ent_2.x + ent_2.w) || (ent_1.x + ent_1.w >= ent_2.x && ent_1.x + ent_1.w <= ent_2.x + ent_2.w)  ))
            {
                colide = 0;
            }

            if((ent_1.y + ent_1.h + jogador.velocidade >= ent_2.y) && (ent_1.y + ent_1.h <= ent_2.y) && ((ent_1.x >=ent_2.x && ent_1.x <= ent_2.x + ent_2.w) || (ent_1.x + ent_1.w >= ent_2.x && ent_1.x + ent_1.w <= ent_2.x + ent_2.w)))
            {
                colide = 1;
            }

            if((ent_1.x +ent_1.w + jogador.velocidade >= ent_2.x) && (ent_1.x + ent_1.w <= ent_2.x) && (ent_1.y <= ent_2.y + ent_2.h && ent_1.y + ent_1.h >= ent_2.y))
            {
                colide = 2;
            }

            if((ent_1.x - jogador.velocidade <= ent_2.x + ent_2.w) && (ent_1.x >= ent_2.x + ent_2.w) && (ent_1.y <= ent_2.y + ent_2.h && ent_1.y + ent_1.h >= ent_2.y))
            {
                colide = 3;
            }

                return colide;
            }




        /******************************* RODANDO ***************************************/

        bool running()
        {
            return isRunning;
        }




        /******************************* CONTADORES ***************************************/




        /**--MILISEGUNDOS--**/

        void ContadorMili(int x, int y, SDL_Rect* clip, double angle, SDL_RendererFlip flip, SDL_Point* center, SDL_Texture* textura)
        {

            SDL_Rect renderQuad;
            renderQuad.h = NULL;
            renderQuad.w = NULL;
            renderQuad.x = x;
            renderQuad.y = y;

            //Set clip rendering dimensions
            if( clip != NULL )
            {
                renderQuad.w = clip->w;
                renderQuad.h = clip->h;
            }

            //Render to screen
            SDL_RenderCopyEx(renderer, textura, clip, &renderQuad , angle, center, flip);

            SDL_Rect zero;
            zero.h = destnumeros->h;
            zero.w = destnumeros->w;
            zero.x = x + 35;
            zero.y = y - 1;



            SDL_RenderCopyEx(renderer, textura, &destnumeros[0], &zero, angle, center, flip);



            SDL_Rect ponto;
            ponto.h = destnumeros[10].h;
            ponto.w = destnumeros[10].w;
            ponto.x = x - 25;
            ponto.y = y + 10;

            SDL_RenderCopyEx(renderer, textura, &destnumeros[10], &ponto, angle, center, flip);


            SDL_Rect ponto1;
            ponto1.h = destnumeros[10].h;
            ponto1.w = destnumeros[10].w;
            ponto1.x = x - 125;
            ponto1.y = y + 10;

            SDL_RenderCopyEx(renderer, textura, &destnumeros[10], &ponto1, angle, center, flip);

        }





        /**--SEGUNDOS--**/

        void ContadorSegundos(int x, int y, SDL_Rect* clip, double angle, SDL_RendererFlip flip, SDL_Point* center, SDL_Texture* textura, int segundos, int segundos1)
        {

            SDL_Rect dec1;
            dec1.h = destnumeros[segundos].h;
            dec1.w = destnumeros[segundos].w;
            dec1.x = x + 30;
            dec1.y = y - 1;



            SDL_RenderCopyEx(renderer, textura, &destnumeros[segundos], &dec1, angle, center, flip);


            SDL_Rect dec2;
            dec2.h = destnumeros[segundos1].h;
            dec2.w = destnumeros[segundos1].w;
            dec2.x = x - 7;
            dec2.y = y - 1;



            SDL_RenderCopyEx(renderer, textura, &destnumeros[segundos1], &dec2, angle, center, flip);

        }




        /**--MINUTOS--**/

        void ContadorMinutos(int x, int y, SDL_Rect* clip, double angle, SDL_RendererFlip flip, SDL_Point* center, SDL_Texture* textura, int minutos, int minutos1)
        {

            SDL_Rect dec1;
            dec1.h = destnumeros[minutos].h;
            dec1.w = destnumeros[minutos].w;
            dec1.x = x + 10;
            dec1.y = y - 1;



            SDL_RenderCopyEx(renderer, textura, &destnumeros[minutos], &dec1, angle, center, flip);


            SDL_Rect dec2;
            dec2.h = destnumeros[minutos1].h;
            dec2.w = destnumeros[minutos1].w;
            dec2.x = x - 27;
            dec2.y = y - 1;



            SDL_RenderCopyEx(renderer, textura, &destnumeros[minutos1], &dec2, angle, center, flip);


        }





        /******************************* RENDER OBSTÁCULOS ***************************************/


        /**--CICLONE--**/

        void RenderCiclone(int x, int y, SDL_Rect* rect, SDL_Rect* clip, double angle, SDL_RendererFlip flip, SDL_Point* center, SDL_Texture* textura)
        {
            //Set rendering space and render to screen
            SDL_Rect renderQuad;
            renderQuad.h = NULL;
            renderQuad.w = NULL;
            renderQuad.x = x + destMap.x;
            renderQuad.y = y + destMap.y;

            //Set clip rendering dimensions
            if( clip != NULL )
            {
                renderQuad.w = clip->w;
                renderQuad.h = clip->h;
            }

            else if(clip == NULL)
            {
                renderQuad.w = rect->w;
                renderQuad.h = rect->h;
            }

            //Render to screen
            SDL_RenderCopyEx(renderer, textura, clip, &renderQuad , angle, center, flip);




            if(colisao(drawingRect, renderQuad) == 0)
            {
               jogador.velocidade = 3;
            }

            if(colisao(drawingRect, renderQuad) == 2)
            {
               jogador.velocidade = 3;
               jogador1.aceleracao = 2;
            }

            if(colisao(drawingRect, renderQuad) == 3)
            {
               jogador.velocidade = 3;
            }





            if(colisao(destBot1, renderQuad) == 0)
            {
               jogador1.velocidade = 3;
            }

            if(colisao(destBot1, renderQuad) == 2)
            {
               jogador1.velocidade = 3;
            }

            if(colisao(destBot1, renderQuad) == 3)
            {
               jogador1.velocidade = 3;
            }





            if(colisao(destBot2, renderQuad) == 0)
            {
               jogador2.velocidade = 3;
            }

            if(colisao(destBot2, renderQuad) == 2)
            {
               jogador2.velocidade = 3;
            }

            if(colisao(destBot2, renderQuad) == 3)
            {
               jogador2.velocidade = 3;
            }






            if(colisao(destBot3, renderQuad) == 0)
            {
               jogador3.velocidade = 3;
            }

            if(colisao(destBot3, renderQuad) == 2)
            {
               jogador3.velocidade = 3;
            }

            if(colisao(destBot3, renderQuad) == 3)
            {
               jogador3.velocidade = 3;
            }


        }




         /**--PEDRAS--**/

        void RenderPedras(int x, int y, SDL_Rect* rect, SDL_Rect* clip, double angle, SDL_RendererFlip flip, SDL_Point* center, SDL_Texture* textura)
        {
            //Set rendering space and render to screen
            SDL_Rect renderQuad;
            renderQuad.h = NULL;
            renderQuad.w = NULL;
            renderQuad.x = x + destMap.x;
            renderQuad.y = y + destMap.y;

            //Set clip rendering dimensions
            if( clip != NULL )
            {
                renderQuad.w = clip->w;
                renderQuad.h = clip->h;
            }

            else if(clip == NULL)
            {
                renderQuad.w = rect->w;
                renderQuad.h = rect->h;
            }

            //Render to screen
            SDL_RenderCopyEx(renderer, textura, clip, &renderQuad , angle, center, flip);



            if(colisao(drawingRect, renderQuad) == 0)
            {
               jogador.velocidade = 0;
               jogador.aceleracao = 0;

            }





            if(colisao(destBot1, renderQuad) == 0)
            {
               jogador1.velocidade = 0;
               jogador1.aceleracao = 0;
               Bot1Explodir = true;
            }


            if(colisao(destBot2, renderQuad) == 0)
            {
               jogador2.velocidade = 0;
               jogador2.aceleracao = 0;
               Bot2Explodir = true;
            }



            if(colisao(destBot3, renderQuad) == 0)
            {
               jogador3.velocidade = 0;
               jogador3.aceleracao = 0;
               Bot3Explodir = true;
            }

        }



         /******************************* MENU ***************************************/


        void Historia()
        {
            bool aux = true;

            while(aux == true)
            {
                SDL_Event event;
                SDL_PollEvent(&event);


                switch (event.type)
                {
                    case SDL_QUIT:
                    aux= false;
                    break;


                 case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {

                            case SDLK_RETURN:
                             Carta();
                            aux = false;
                            break;


                        } break;

                }


                SDL_RenderCopyEx(renderer, Hist1Tex, NULL, &destHist1, 0.0, NULL, flipType);
                SDL_RenderPresent(renderer);
            }
        }





         void Historia1()
        {
            bool aux1 = true;

            while(aux1 == true)
            {
                SDL_Event event;
                SDL_PollEvent(&event);


                switch (event.type)
                {
                    case SDL_QUIT:
                    aux1 = false;
                    break;


                 case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {

                            case SDLK_RETURN:
                            aux1 = false;
                            break;


                        } break;

                }


                SDL_RenderCopyEx(renderer, Hist2Tex, NULL, &destHist2, 0.0, NULL, flipType);
                SDL_RenderPresent(renderer);
            }
        }




         void Carta()
        {
            bool aux2 = true;

            while(aux2 == true)
            {
                SDL_Event event;
                SDL_PollEvent(&event);


                switch (event.type)
                {
                    case SDL_QUIT:
                    aux2 = false;
                    break;


                 case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {

                            case SDLK_RETURN:
                            Historia1();
                            aux2 = false;
                            break;


                        } break;

                }


                SDL_RenderCopyEx(renderer, CartaTex, NULL, &destCarta, 0.0, NULL, flipType);
                SDL_RenderPresent(renderer);
            }
        }




         void Fim()
        {
            bool aux3 = true;

            while(aux3 == true)
            {
                SDL_Event event;
                SDL_PollEvent(&event);


                switch (event.type)
                {
                    case SDL_QUIT:
                    aux3 = false;
                    break;


                 case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {

                            case SDLK_RETURN:
                            Creditos();
                            aux3 = false;
                            break;


                        } break;

                }


                SDL_RenderCopyEx(renderer, FimTex, NULL, &destFim, 0.0, NULL, flipType);
                SDL_RenderPresent(renderer);
            }
        }




        void Creditos()
        {
            bool aux4 = true;

            while(aux4 == true)
            {
                SDL_Event event;
                SDL_PollEvent(&event);


                switch (event.type)
                {
                    case SDL_QUIT:
                    aux4 = false;
                    break;


                 case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {

                            case SDLK_RETURN:
                            isRunning = false;
                            aux4 = false;
                            break;


                        } break;

                }


                SDL_RenderCopyEx(renderer, creditosTex, NULL, &destcreditos, 0.0, NULL, flipType);
                SDL_RenderPresent(renderer);
            }
        }





