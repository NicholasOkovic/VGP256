#include <iostream>
#include "MathLibrary.h"

using namespace std;





int main()
{
    MathLibrary math;

    float var;

    cout << "Hello World!\n";

    cin >> var;

    float final = math.Equation1VF(var, 1, 1);

    

    cout << final;
}



