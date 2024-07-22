#include "MathLibrary.h"
#include "EquationsOfMotion.h"

void Question1Menu();
void Question2Menu();
void Question3Menu();

int main()
{
    //find out what the user wants to do
    int var;
    while (true)
    {
        cout << "What would you like to do?\n1 - Question 1(polynomial)\n2 - Question 2(Equations of motions)\n3 - Question 3(Forces&Acceleration)\n";
        cin >> var;

        switch (var)
        {
        case 1:
            Question1Menu(); //call a new Menu screen for each question
            break;
        case 2:
            Question2Menu();
            break;
        case 3:
            Question3Menu();
            break;
        default:
            cout << "\nInvalid input, please input 1,2 or 3\n\n";
            break;
        }
    }
}

void Question1Menu()
{
    
    int degree;
    float moment;
    float input;

    while (true)
    {
        cout << "\nWhat is your polynomial degree(Max degree: 10)?\n";
        cin >> degree;

        cout << "\nWhat is the moment\n";
        cin >> moment;

        vector<float> polynomial;
        
        cout << "\n\nNow enter the " << degree+1 << " numbers that make up your polynomial, starting from highest degree";
        int degreeCounter = 0;
        //have the user enter the degree and number, then add them to the vector of floats
        while (degreeCounter <= degree)
        {
            cout << "\nNumber" << degreeCounter+1 << ": ";
            cin >> input;
            polynomial.push_back(input);
            degreeCounter++;
        }
        degreeCounter = degree;
        //print the polynomial, 
        cout << "Your polynomial: " << polynomial[0] << "x^" << degreeCounter;
        degreeCounter--;
        for (int i = 1; i < polynomial.size()-1; i++)
        {
              cout << " + " << polynomial[i] << "x^" << degreeCounter;
              degreeCounter--;
        }
        cout << " + " << polynomial[degree];
        //ending doesnt have a degree, and it just looks nicer if doesnt say X^0
        cout << "\nWith a degree of " << degree;


        vector<float> accAndVel = PolyVelAndAcc(polynomial, moment);
        //get the acceleation and velocity, then print it
        cout << "\n\nVelocity = " << accAndVel[0] << "\nAccelation = " << accAndVel[1] << "\n";
    }
}
void Question2Menu()
{
    int missingVar;
    while (true)
    {
        //find what variable the user doesnt have
        cout << "\nWhat variable are you missing?\n";
        cout << "1 - Final Velocity\n2 - Initial Velocity\n3 - Average Velocity\n4 - Time\n5 - Displacement\n6 - Acceleration\n";
        cin >> missingVar;

        //switch statement instead of if statement because switch statements are cool
        switch (missingVar)
        {
        case 1:
            MissingVF(); //missing final velocity
            break;
        case 2:
            MissingVI();//missing Initial velocity
            break;
        case 3:
            MissingAV(); //missing Average velocity
            break;
        case 4:
            MissingTime();//missing Time
            break;
        case 5:
            MissingDis();//missing fDisplacement
            break;
        case 6:
            MissingAcc();//missing Acceleration
            break;
        default:
            cout << "\nInvalid input";
            break;
        }
    }

}
void Question3Menu()
{
    float weight;

    //find the weight of the object
    cout << "\nWhat is the weight of the object?\n";
    cin >> weight;

    //find all forces acting on the object(x,y,z)
    float xForce;
    float yForce;
    float zForce;
    cout << "What is the force acting along the x-Axis?\n";
    cin >> xForce;

    cout << "What is the force acting along the y-Axis?\n";
    cin >> yForce;

    cout << "What is the force acting along the z-Axis?\n";
    cin >> zForce;
    
    vector<float> acceleration = ForcesForAcc(weight, xForce, yForce, zForce);
    //call forces function, then print
    cout << "\n\nThe acceleration of the object is: (" << acceleration[0] << " , " << acceleration[1] << " , " << acceleration[2] << ")\n\n";
}

