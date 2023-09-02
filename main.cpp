#include <QCoreApplication>
#include <iostream>
#include <QTimer>
#include <Eigen/Dense>
#include "matAdd3.h"


using std::cout, std::endl;
using Eigen::MatrixXd;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString str1 = "Hello";
    cout << "abc123" << endl;
    cout << str1.toStdString().data() << endl;
    //test function
    if (!matAdd3Initialize()) // DLL Initialize
    {
        cout << "DLL initialization failed";
        return app.exec();
    }

    MatrixXd a{
        {1,2},
        {3,4}
    };

    MatrixXd b{
        {100,200},
        {300,400}
    };

    MatrixXd c(2,2);
    //c = a + b;
    //cout << c << endl;

    cout << "vectA + vectB" << endl;
    double vectA[]={1,2,3};  // vector A
    double vectB[]={5,6,7};  // vector B

    int rowCnt=1;   // rows number
    int colCnt=3;   // cols number
    int elementCnt=3;  // element number

    mwArray matrixA(rowCnt, colCnt, mxDOUBLE_CLASS, mxREAL);  // define array
    matrixA.SetData(vectA, elementCnt);  // Store C++ one-dimensional arrays to MATLAB two-dimensional arrays

    mwArray matrixB(rowCnt, colCnt, mxDOUBLE_CLASS, mxREAL);
    matrixB.SetData(vectB, elementCnt);

    // calculate
    mwArray matrixC(rowCnt, colCnt, mxDOUBLE_CLASS, mxREAL);  // define array，double type
    mwArray matrixD(rowCnt, colCnt, mxDOUBLE_CLASS, mxREAL);
    int nargout=2;  // number of output variable
    matAdd3(nargout, matrixC, matrixD, matrixA, matrixB);  // Call the function to calculate, and the returned result is stored in the matrixC variable

    // Read result
    int dim = 1;  // read matrixC according to vector
    double av = matrixC.Get(dim, 1);  // 1st element
    double bv = matrixC.Get(dim, 2);  // 2nd element
    double cv = matrixC.Get(dim, 3);  // 3rd element

    cout << av << endl;
    cout << bv << endl;
    cout << cv << endl;
    cout << matrixC << endl;

    double av2 = matrixD.Get(dim, 1);  // 1st element
    double bv2 = matrixD.Get(dim, 2);  // 2nd element
    double cv2 = matrixD.Get(dim, 3);  // 3rd element

    cout << av2 << endl;
    cout << bv2 << endl;
    cout << cv2 << endl;
    cout << matrixD << endl;


    cout << "Matrix v_A + Matrix v_B" << endl;
    double v_A[]={100,200,300,400};   //vector A
    double v_B[]={1,2,3,4};           //vector B
    mwArray mA(2, 2, mxDOUBLE_CLASS, mxREAL);  //2 rows, 2 cols
    mwArray mB(2, 2, mxDOUBLE_CLASS, mxREAL);
    mwArray mC(2, 2, mxDOUBLE_CLASS, mxREAL);
    mwArray mD(2, 2, mxDOUBLE_CLASS, mxREAL);
    mA.SetData(v_A, 4);  //Store C++ one-dimensional arrays to MATLAB two-dimensional arrays
    mB.SetData(v_B, 4);
    cout << "mA:" << endl;
    cout << mA << endl;    //note: 2-dimen array data is cols priority
    cout << "mB:" << endl;
    cout << mB << endl;
    cout << "----" << endl;
    matAdd3(2, mC, mD, mA, mB);  //first param is 2, then get mC and mD 2 return param
    double c11 = mC.Get(1, 1);  //first cols first element
    double c12 = mC.Get(1, 2);  //first cols second element
    double c13 = mC.Get(1, 3);  //It's actually the first element in column 2
    cout << c11 << ' ' << c12 << ' ' << c13 << endl;
    double c21 = mC.Get(2, 1);
    double c22 = mC.Get(2, 2);
    double c23 = mC.Get(2, 3);
    cout << c21 << ' ' << c22 << ' ' << c23 << endl;
    cout << "----" << endl;
    cout << "mC:" << endl;
    cout << mC << endl;
    cout << "mD:" << endl;
    cout << mD << endl;



    cout << "done." << endl;
    //Add this, otherwise the Qt console program will not end automatically

    QTimer t;
    t.connect(&t, SIGNAL(timeout()), &app, SLOT(quit()));
    t.start(5);  // 5millisecond


    return app.exec();
}
