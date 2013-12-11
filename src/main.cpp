#include "MathHeaders.h"

using namespace EX3;

int main(int argc, char* argv[])
{
    Tuple* tuple = new Tuple();
    delete tuple;

    Point* point = new Point();
    delete point;

    Quaternion* quaternion = new Quaternion();
    delete quaternion;

    Vector* vector = new Vector();
    delete vector;

    Matrix* matrix = new Matrix();
    delete matrix;

    Plane* plane = new Plane();
    delete plane;
}
