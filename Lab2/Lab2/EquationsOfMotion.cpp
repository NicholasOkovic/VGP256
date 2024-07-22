#include "EquationsOfMotion.h"


//big file, but it is only to find the right formula for the user and then uses that formula



void MissingVF()
{
    float initalVelocity;
    float finalVelocity;
    float acceleration;
    float time;
    float averageVelocity;
    float displacement;

    //Find what variables the user has, to get the right formula
    int foundVar;
    cout << "\nWhat variables do you have?\n";
    cout << "1 - Initial Velocity, Acceleration, and Time\n2 - Initial Velocity, and Average Velocity\n3 - Initial Velocity, Displacement, and Time\n4 - Initial Velocity, Dispalcement, and Acceleration\n";
    cin >> foundVar;
    switch (foundVar)
    {
    case 1:
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your acceleration\n";
        cin >> acceleration;
        cout << "\nEnter your time\n";
        cin >> time;
        cout << "\nAnswer: " << Equation1VF(initalVelocity, acceleration, time) << "\n";//User inputs variables, and then the answer is printed
        break;
    case 2:
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your averageVelocity\n";
        cin >> averageVelocity;
        cout << "\nAnswer: " << Equation2VF(averageVelocity, initalVelocity) << "\n"; //calls all the equations from the MathLibrary.cpp
        break;
    case 3:
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Displacement\n";
        cin >> displacement;
        cout << "\nEnter your time\n";
        cin >> time;
        cout << "\nAnswer: " << Equation3VF(initalVelocity, displacement, time) << "\n";
        break;
    case 4:
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Displacement\n";
        cin >> displacement;
        cout << "\nEnter your acceleration\n";
        cin >> acceleration;
        cout << "\nAnswer: " << Equation5VF(initalVelocity, acceleration, displacement) << "\n";
        break;
    default:
        cout << "\nInvalid input";
        break;
    }
}

void MissingVI()
{
    float initalVelocity;
    float finalVelocity;
    float acceleration;
    float time;
    float averageVelocity;
    float displacement;

    int foundVar;
    cout << "\nWhat variables do you have?\n";
    cout << "1 - Final Velocity, Acceleration, and Time\n2 - Final Velocity, and Average Velocity\n3 - Final Velocity, Dispalcement, and Time\n4 - Time, Dispalcement, and Acceleration\n5 - Final Velocity, Dispalcement, and Acceleration\n";
    cin >> foundVar;
    switch (foundVar)
    {
    case 1:
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your acceleration\n";
        cin >> acceleration;
        cout << "\nEnter your time\n";
        cin >> time;
        cout << "\nAnswer: " << Equation1VI(finalVelocity, acceleration, time) << "\n";
        break;
    case 2:
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your averageVelocity\n";
        cin >> averageVelocity;
        cout << "\nAnswer: " << Equation2VI(finalVelocity, averageVelocity) << "\n";
        break;
    case 3:
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your Displacement\n";
        cin >> displacement;
        cout << "\nEnter your time\n";
        cin >> time;
        cout << "\nAnswer: " << Equation3VF(finalVelocity, displacement, time) << "\n";
        break;
    case 4:
        cout << "\nEnter your Time\n";
        cin >> time;
        cout << "\nEnter your Displacement\n";
        cin >> displacement;
        cout << "\nEnter your acceleration\n";
        cin >> acceleration;
        cout << "\nAnswer: " << Equation5VF(time, displacement, acceleration) << "\n";
        break;
    default:
        cout << "\nInvalid input";
        break;
    }
}

void MissingAV()
{
    float initalVelocity;   //only one of the formulas use average velocity, so its much shorter
    float finalVelocity;

    cout << "\nEnter your Initial Velocity\n";
    cin >> initalVelocity;
    cout << "\nEnter your Final velocity\n";
    cin >> finalVelocity;
    cout << "\nAnswer: " << Equation2AV(initalVelocity, finalVelocity) << "\n";

}

void MissingTime()
{
    float initalVelocity;
    float finalVelocity;
    float acceleration;
    float time;
    float averageVelocity;
    float displacement;

    int foundVar;
    cout << "\nWhat variables do you have?\n";
    cout << "1 - Final Velocity, Initial Velocity, and Acceleration\n2 - Final Velocity, Inital Velocity, and Displacement\n3 - Inital Velocity, Dispalcement, and Acceleration\n";
    cin >> foundVar;
    switch (foundVar)
    {
    case 1:
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Acceleration\n";
        cin >> acceleration;
        cout << "\nAnswer: " << Equation1Time(finalVelocity, acceleration, initalVelocity) << "\n";
        break;
    case 2:
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your Initial Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Displacement\n";
        cin >> displacement;
        cout << "\nAnswer: " << Equation3Time(initalVelocity, finalVelocity, displacement) << "\n";
        break;
    case 3:
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Displacement\n";
        cin >> displacement;
        cout << "\nEnter your Acceleration\n";
        cin >> acceleration;
        cout << "\nAnswer: " << Equation4Time(initalVelocity, displacement, acceleration) << "\n";
        break;
    default:
        cout << "\nInvalid input";
        break;
    }
}

void MissingDis()
{
    float initalVelocity;
    float finalVelocity;
    float acceleration;
    float time;
    float averageVelocity;
    float displacement;

    int foundVar;
    cout << "\nWhat variables do you have?\n";
    cout << "1 - Final Velocity, Inital Velocity, and Time\n2 - Initial Velocity, Acceleration, and Time\n3 - Final Velocity, Inital velocity, and Acceleration\n";
    cin >> foundVar;
    switch (foundVar)
    {
    case 1:
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your time\n";
        cin >> time;
        cout << "\nAnswer: " << Equation3Dis(initalVelocity, finalVelocity, time) << "\n";
        break;
    case 2:
        cout << "\nEnter your Initial Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your acceleration\n";
        cin >> acceleration;
        cout << "\nEnter your time\n";
        cin >> time;
        cout << "\nAnswer: " << Equation4Dis(initalVelocity, time, acceleration) << "\n";
        break;
    case 3:
        cout << "\nEnter your Initial Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your acceleration\n";
        cin >> acceleration;
        cout << "\nAnswer: " << Equation5Dis(initalVelocity, acceleration, finalVelocity) << "\n";
        break;

    default:
        cout << "\nInvalid input";
        break;
    }
}

void MissingAcc()
{
    float initalVelocity;
    float finalVelocity;
    float acceleration;
    float time;
    float averageVelocity;
    float displacement;

    int foundVar;
    cout << "\nWhat variables do you have?\n";
    cout << "1 - Final Velocity, Initial Velocity, and Time\n2 - Inital Velocity, Time, and Displacement\n3 - Inital Velocity, Dispalcement, and Final velocity\n";
    cin >> foundVar;
    switch (foundVar)
    {
    case 1:
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Time\n";
        cin >> time;
        cout << "\nAnswer: " << Equation1ACC(initalVelocity, finalVelocity, time) << "\n";
        break;
    case 2:
        cout << "\nEnter your time\n";
        cin >> time;
        cout << "\nEnter your Initial Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Displacement\n";
        cin >> displacement;
        cout << "\nAnswer: " << Equation4ACC(initalVelocity, time, displacement) << "\n";
        break;
    case 3:
        cout << "\nEnter your Inital Velocity\n";
        cin >> initalVelocity;
        cout << "\nEnter your Final Velocity\n";
        cin >> finalVelocity;
        cout << "\nEnter your Displacement\n";
        cin >> displacement;
        cout << "\nAnswer: " << Equation5ACC(initalVelocity, finalVelocity, displacement) << "\n";
        break;
    default:
        cout << "\nInvalid input";
        break;
    }
}


