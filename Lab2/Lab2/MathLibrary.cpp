#include "MathLibrary.h"

vector<float> PolyVelAndAcc(vector<float> poly, float moment)
{
    vector<float> velocityAndAcceleration;
    velocityAndAcceleration.push_back(0);
    velocityAndAcceleration.push_back(0);
    //inializing both vel and acc early for easier calculation

    int counter = 0;
    int degreeCounter = poly.size()-1;
    while (counter < poly.size())
    {
        poly[counter] *= degreeCounter;
        counter++;
        degreeCounter--;
    }
    poly.pop_back();
    //Poly has now been derived, so the degree is 1 less
  
    //now add them together in terms of moment
    degreeCounter = poly.size()-1;
    for (int i = 0; i < poly.size(); i++)
    {
        velocityAndAcceleration[0] += (poly[i] * pow(moment, degreeCounter));
        degreeCounter--;
    }


    //now we find acceleration
    counter = 0;
    degreeCounter = poly.size()-1;
    while (counter < poly.size())
    {
        poly[counter] *= degreeCounter;
        counter++;
        degreeCounter--;
    }
    poly.pop_back();
    //Poly has now been derived, so the degree is 1 less

    //now add them together in terms of moment
    degreeCounter = poly.size()-1;
    for (int i = 0; i < poly.size(); i++)
    {
        velocityAndAcceleration[1] += (poly[i] * pow(moment, degreeCounter));
        degreeCounter--;
    }

    return velocityAndAcceleration;
}

//Just a lot of equations for each variable involved

float Equation1VF(float v1, float acc, float time)
{
    return (v1 + (acc * time));
}
float Equation1VI(float vf, float acc, float time)
{
    return vf - (acc * time);
}
float Equation1ACC(float v1, float vf, float time)
{
    return ((vf - v1) / time);
}
float Equation1Time(float v1, float acc, float vf)
{
    return ((vf - v1) / acc);
}


float Equation2AV(float v1, float vf)
{
    return ((v1 + vf) / 2);
}
float Equation2VI(float av, float vf)
{
    return ((av * 2) - vf);
}
float Equation2VF(float av, float v1) 
{
    return ((av * 2) - v1);
}


float Equation3Dis(float v1, float vf, float time)
{
    return ((1 / 2) * (v1 + vf) * time);
}
float Equation3VI(float dis, float vf, float time)
{
    return (((2 * dis) / (time)) - vf);
}
float Equation3VF(float v1, float dis, float time) 
{
    return (((2 * dis) / (time)) - v1);
}
float Equation3Time(float v1, float vf, float dis)
{
    return ((2 * dis)/(v1 + vf));
}


float Equation4Dis(float v1, float time, float acc)
{
    return ((v1 * time) + ((acc * (time*time))/2));
}
float Equation4VI(float dis, float time, float acc) 
{
    return ((dis / time) - ((acc * time) / 2));
}
float Equation4Time(float v1, float dis, float acc)
{
    return ((2 * v1) + ((acc * dis) / 2));
}
float Equation4ACC(float v1, float time, float dis)
{
    return (((2 * dis)/(time * time)) - ((2 * v1)/time));
}


float Equation5VF(float v1, float acc, float dis)
{
    return sqrt(((v1 * v1) + (2 * acc * dis)));
}
float Equation5VI(float vf, float acc, float dis)
{
    return sqrt(((vf * vf) - (2 * acc * dis)));
}
float Equation5ACC(float v1, float vf, float dis)
{
    return (((vf * vf) - (v1 * v1)) / (2 * dis));
}
float Equation5Dis(float v1, float acc, float vf)
{
    return (((vf * vf) - (v1 * v1)) / (2 * acc));
}

vector<float> ForcesForAcc(float weight, float X, float Y, float Z) //equation for finding Acceleration using x,y,z forces
{
    vector<float> acceleration{ X / weight, (Y / weight), Z / weight };
    return acceleration;
}
