#pragma once


class MathLibrary
{
public:



	float Equation1VF(float v1, float acc, float time);
	float Equation1VI(float vf, float acc, float time);
	float Equation1ACC(float v1, float vf, float time);
	float Equation1Time(float v1, float acc, float vf);

	float Equation2AV(float v1, float vf);
	float Equation2VI(float av, float vf);
	float Equation2VF(float av, float v1);

	float Equation3Dis(float v1, float vf, float time);
	float Equation3VI(float dis, float vf, float time);
	float Equation3VF(float v1, float dis, float time);
	float Equation3Time(float v1, float vf, float dis);

	float Equation4Dis(float v1, float time, float acc);
	float Equation4VI(float dis, float time, float acc);
	float Equation4Time(float v1, float dis, float acc);
	float Equation4ACC(float v1, float time, float dis);

	float Equation5VF(float v1, float acc, float dis);
	float Equation5VI(float vf, float acc, float dis);
	float Equation5ACC(float v1, float vf, float dis);
	float Equation5Dis(float v1, float acc, float vf);



private:

};


