#include <iostream>
#include <cmath>

float firstForce[] = {0, 0, 0, 0};
float secondForce[] = {0, 0, 0, 0};

float mag(float x, float y, float z)
{
    return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

float uFirstForce[] = {1, 2, 3};
float uSecondForce[] = {4, 5, 6};
float uThirdForce[] = {7, 8, 9};

float *coo[2] = {firstForce, secondForce};
float *ucoo[3] = {uFirstForce, uSecondForce, uThirdForce};

char cinco[] = {'x', 'y', 'z'};

int main()
{
    std::cout << "Please enter the magnitude and x, y, and z directional components of the first known force\nMagnitude: ";
    for (int i = 0; i < 4; i++)
    {
        if(i != 0)
        {
            std::cout << cinco[i-1] << ": ";
        }

        std::cin >> coo[0][i];
    }

    std::cout << "Please enter the magnitude and x, y, and z directional components of the second known force\nMagnitude: ";
    for (int i = 0; i < 4; i++)
    {
        if(i != 0)
        {
            std::cout << cinco[i-1] << ": ";
        }

        std::cin >> coo[1][i];
    }

    std::cout << "Please enter the x, y, and z directional components of the first unknown force" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << cinco[i] << ": ";
        std::cin >> ucoo[0][i];
    }

    std::cout << "Please enter the x, y, and z directional components of the second unknown force" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << cinco[i] << ": ";
        std::cin >> ucoo[1][i];
    }

    std::cout << "Please enter the x, y, and z directional components of the third unknown force" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << cinco[i] << ": ";
        std::cin >> ucoo[2][i];
    }

    for (int i = 1; i < 5; i++)
    {
        firstForce[i] = firstForce[i]/mag(coo[0][0], coo[0][1], coo[0][2]);
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << firstForce[i] << std::endl;
    }

    return EXIT_SUCCESS;
}