#include "MathLibrary.h"


float MathLibrary::Equation1VF(float v1, float acc, float time)
{
    return (v1 + (acc * time));
}
float MathLibrary::Equation1VI(float vf, float acc, float time)
{
    return vf - (acc * time);
}
float MathLibrary::Equation1ACC(float v1, float vf, float time)
{
    return ((vf - v1) / time);
}
float MathLibrary::Equation1Time(float v1, float acc, float vf)
{
    return ((vf - v1) / acc);
}


float MathLibrary::Equation2AV(float v1, float vf)
{
    return ((v1 + vf) / 2);
}
float MathLibrary::Equation2VI(float av, float vf)  //////
{
    return ((av * 2) - vf);
}
float MathLibrary::Equation2VF(float av, float v1)  //////
{
    return -((av * 2) - v1);
}


float MathLibrary::Equation3Dis(float v1, float vf, float time)
{
    return ((1 / 2) * (v1 + vf) * time);
}
float MathLibrary::Equation3VI(float dis, float vf, float time)
{
    return (((2 * dis) / (time)) - vf);
}
float MathLibrary::Equation3VF(float v1, float dis, float time) //////
{
    return -(((2 * dis) / (time)) - v1);
}
float MathLibrary::Equation3Time(float v1, float vf, float dis)
{
    return ((2 * dis)/(v1 + vf));
}


float MathLibrary::Equation4Dis(float v1, float time, float acc)
{
    return ((v1 * time) + ((acc * (time*time))/2));
}
float MathLibrary::Equation4VI(float dis, float time, float acc) /////
{
    return ((dis) - ((acc * time) / 2));
}
float MathLibrary::Equation4Time(float v1, float dis, float acc)
{
    return ((v1 * time) + ((acc * (time * time)) / 2));
}
float MathLibrary::Equation4ACC(float v1, float time, float dis)
{
    return ((v1 * time) + ((acc * (time * time)) / 2));
}


float MathLibrary::Equation5VF(float v1, float acc, float dis)
{
    //returns vf^2
    return ((v1 * v1) + (2 * acc * dis));
}
float MathLibrary::Equation5VI(float vf, float acc, float dis)
{
    //returns vf^2
    return ((v1 * v1) + (2 * acc * dis));
}
float MathLibrary::Equation5ACC(float v1, float vf, float dis)
{
    //returns vf^2
    return ((v1 * v1) + (2 * acc * dis));
}
float MathLibrary::Equation5Dis(float v1, float acc, float vf)
{
    //returns vf^2
    return ((v1 * v1) + (2 * acc * dis));
}