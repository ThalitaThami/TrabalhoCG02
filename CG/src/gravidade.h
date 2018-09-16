#ifndef GRAVIDADE_H_INCLUDED
#define GRAVIDADE_H_INCLUDED

float zBola = 120.0;
float focoX = zBola;
float focoY = zBola;
float posicaoAtual;
bool colisao = false;

float mouseY = 0.0;

float width_windows  = 800.0;
float height_windows = 700.0;

float velocidade = 1.0;
float gravidade = -10.0;
float dt = 0.1;

void updateVelocidadePosicao();
void idle();
float haColisao();
void motion();

void idle()
{
    float t, desiredFrameTime, frameTime;
    static float tLast = 0.0;

    /// Get elapsed time
    t = glutGet(GLUT_ELAPSED_TIME);

    /// convert milliseconds to seconds
    t /= 1000.0;

    /// Calculate frame time
    frameTime = t - tLast;
    /// Calculate desired frame time
    desiredFrameTime = 1.0 / (float) (desiredFPS);

    // Check if the desired frame time was achieved. If not, skip animation.
    if( frameTime <= desiredFrameTime)
        return;

    // **  UPDATE ANIMATION VARIABLES ** //
    float step = 1; // Speed of the animation

    updateVelocidadePosicao();

    tLast = t;

    glutPostRedisplay();
}

/// verificando se houve ou não a colisão e ajusta a posição
/// e a velocidade dependendo disso
void updateVelocidadePosicao(){

    if(haColisao() != 120){
        posicaoAtual = haColisao();
        colisao = true;
        velocidade = 25;
    }

    if(colisao == true){
         focoX = focoY = posicaoAtual;
    }else{
        focoX = focoY = zBola;
    }

    if(zBola <= posicaoAtual -5){
        colisao = false;
    }

    velocidade = velocidade + gravidade*dt;
    zBola = zBola + (velocidade*dt) + 0.5*gravidade*(dt*dt);
}

///compara a posição z da Bola com a posição z do Plano e mouse Y com o buraco do plano
///se o zBola ñ estiver no buraco entra no if e retorna o zPlano
/// caso contrário retorna a posição inicial da bola = 120;
float haColisao(){

    if(zBola <= 45.0){
        return 45.0;
    }else{
        return 120;
    }
}

#endif // GRAVIDADE_H_INCLUDED
