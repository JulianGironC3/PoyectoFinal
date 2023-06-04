#include "movimientos.h"

movimientos::movimientos(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)
{
    PX = posX_;
    PY = posY_;
    mass = masa_;
    R = radio_;
    VX = velX_;
    VY = velY_;
    AX = 0;
    AY = 0;
    G = 10;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;
}

float movimientos::get_posX()
{
    return PX;
}

float movimientos::get_posY(){//retorna la posicion en y.
    return PY;
}

float movimientos::get_Radio(){//retorna el radio
    return R;
}

float movimientos::get_velX(){//retorna la velocidad en x.
    return VX;
}

float movimientos::get_velY(){//retorna la velocidad en y.
    return VY;
}

float movimientos::get_masa(){//retorna la masa
    return mass;
}


float movimientos::get_e(){//retorna el coeficiente de restitucion.
    return e;
}

void movimientos::set_vel(float velx, float vely, float px, float py)
{
    VX = velx;
    VY = vely;
    PX = px;
    PY = py;
}

void movimientos::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),1/2);
    angulo = atan2(VY, VX);
    AX = -((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo);
    AY = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))-G;
    PX = PX + (VX*dt) + ((AX*(dt*dt))/2);
    PY = PY + (VY*dt) + ((AY*(dt*dt))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt;
}
