#include <iostream>
#include <cmath>

double mag(double x, double y, double z)
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double firstForce[] = {00, 01, 02, 03}; //magnitude, x, y, z
double secondForce[] = {10, 11, 12, 13}; //magnitude, x, y, z

double uFirstForce[] = {00, 01, 02}; //x, y, z
double uSecondForce[] = {10, 11, 12}; //x, y, z
double uThirdForce[] = {20, 21, 22}; //x, y, z

double firstForcemag[] = {00, 01, 02};
double secondForcemag[] = {10, 11, 12};

double ufirstForcemag[] = {00, 01, 02};
double usecondForcemag[] = {10, 11, 12};
double uthirdForcemag[] = {20, 21, 22};
double ufirstForcemag2[] = {30, 31, 32};
double usecondForcemag2[] = {40, 41, 42};

double placeholder[] = {0, 1, 2};

double knownForceValue[] = {0, 0, 0};

double det = 0;
double detx = 0;
double dety = 0;
double detz = 0;

double I = 0;
double II = 0;
double III = 0;

double *knownCO[2] = {firstForce, secondForce};
double *unknownCO[3] = {uFirstForce, uSecondForce, uThirdForce};

double *knownCOmag[2] = {firstForcemag, secondForcemag};
double *unknownCOmag[5] = {ufirstForcemag, usecondForcemag, uthirdForcemag, ufirstForcemag2, usecondForcemag2};

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

        std::cin >> knownCO[0][i];
    }

    std::cout << "Please enter the magnitude and x, y, and z directional components of the second known force\nMagnitude: ";
    for (int i = 0; i < 4; i++)
    {
        if(i != 0)
        {
            std::cout << cinco[i-1] << ": ";
        }

        std::cin >> knownCO[1][i];
    }

    std::cout << "Please enter the x, y, and z directional components of the first unknown force" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << cinco[i] << ": ";
        std::cin >> unknownCO[0][i];
    }

    std::cout << "Please enter the x, y, and z directional components of the second unknown force" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << cinco[i] << ": ";
        std::cin >> unknownCO[1][i];
    }

    std::cout << "Please enter the x, y, and z directional components of the third unknown force" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << cinco[i] << ": ";
        std::cin >> unknownCO[2][i];
    }

        for (int i = 1; i < 4; i++)
        {
            knownCOmag[0][i - 1] = (knownCO[0][0] * knownCO[0][i]) / mag(knownCO[0][1], knownCO[0][2], knownCO[0][3]);
        } //first force direction
        for (int i = 1; i < 4; i++)
        {
            knownCOmag[1][i - 1] = (knownCO[1][0] * knownCO[1][i]) / mag(knownCO[1][1], knownCO[1][2], knownCO[1][3]);
        } //second force direction
        for (int i = 0; i < 3; i++)
        {
            unknownCOmag[0][i] = unknownCO[0][i] / mag(unknownCO[0][0], unknownCO[0][1], unknownCO[0][2]);
        } //first unknown force direction
        for (int i = 0; i < 3; i++)
        {
            unknownCOmag[1][i] = unknownCO[1][i] / mag(unknownCO[1][0], unknownCO[1][1], unknownCO[1][2]);
        } //second unknown force direction
        for (int i = 0; i < 3; i++)
        {
            unknownCOmag[2][i] = unknownCO[2][i] / mag(unknownCO[2][0], unknownCO[2][1], unknownCO[2][2]);
        } //third unknown force direction
        for (int i = 0; i < 3; i++)
        {
            unknownCOmag[3][i] = unknownCOmag[0][i];
            unknownCOmag[4][i] = unknownCOmag[1][i];
        } //determinant setup
        for (int i = 0; i < 3; i++)
    {
        knownForceValue[i] = knownCOmag[0][i] + knownCOmag[1][i];
    } //answer column setup

        //all of the directional vectors should be figured out at this point

    for (int i = 0; i < 3; i++)
    {
        det = det + (unknownCOmag[i][0] * unknownCOmag[i+1][1] * unknownCOmag[i+2][2]);
        det = det - (unknownCOmag[i+2][0] * unknownCOmag[i+1][1] * unknownCOmag[i][2]);
    } //evaluates D

    for (int i = 0; i < 3; i++)
    {
       placeholder[i] = unknownCOmag[0][i];
       unknownCOmag[0][i] = -knownForceValue[i];
       unknownCOmag[3][i] = -knownForceValue[i];
    } //prepares x column for detx

    for (int i = 1; i < 3; i++)
    {
        detx = detx + (unknownCOmag[i][0] * unknownCOmag[i+1][1] * unknownCOmag[i+2][2]);
        detx = detx - (unknownCOmag[i+2][0] * unknownCOmag[i+1][1] * unknownCOmag[i][2]);
    } //evaluates detx

    for (int i = 0; i < 3; i++)
    {
        unknownCOmag[0][i] = placeholder[i];
        unknownCOmag[3][i] = placeholder[i];
        placeholder[i] = unknownCOmag[1][i];
        unknownCOmag[1][i] = -knownForceValue[i];
        unknownCOmag[4][i] = -knownForceValue[i];
    } //prepares y column for dety

    for (int i = 1; i < 3; i++)
    {
        dety = dety + (unknownCOmag[i][0] * unknownCOmag[i+1][1] * unknownCOmag[i+2][2]);
        dety = dety - (unknownCOmag[i+2][0] * unknownCOmag[i+1][1] * unknownCOmag[i][2]);
    } //evaluates dety

    for (int i = 0; i < 3; i++)
    {
        unknownCOmag[1][i] = placeholder[i];
        unknownCOmag[4][i] = placeholder[i];
        unknownCOmag[2][i] = -knownForceValue[i];
    } //prepares z column for detz

    for (int i = 1; i < 3; i++)
    {
        dety = dety + (unknownCOmag[i][0] * unknownCOmag[i+1][1] * unknownCOmag[i+2][2]);
        dety = dety - (unknownCOmag[i+2][0] * unknownCOmag[i+1][1] * unknownCOmag[i][2]);
    } //evaluates detz

    I = detx / det;
    II = dety / det;
    III = detz / det;

    std::cout << det << std::endl;
    std::cout << knownForceValue[0] << std::endl;

    //std::cout << "Your force values are:\n#1: " << I << "\n#2: " << II << "\n#3: " << III << std::endl;

    return EXIT_SUCCESS;
}