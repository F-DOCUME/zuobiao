#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;  
int main()
{
  //define
  MatrixXd inverse_matrix1(3,3);
  MatrixXd inverse_matrix2(3,3);
  MatrixXd camera_matrix(3,3);
  MatrixXd transformation_matrix(4,4);
  double u,v;//the coordinates in pixel coordinate system
  
  double xw,yw,zw;//the coordinates in world coordinate system
  double z;
  z=0.07*490/500;
  
 
  
  camera_matrix<<490.0,   0.0,    480.0,
                 0.0,   300.0,    273.5,
                 0.0,     0.0,      1.0;
//|R t|
//|0 1|
  transformation_matrix<< 0.0042244,     0.00280237,       0.999987,     0.05,
                           0.999979,      0.0048524,     -0.004238,      0.10,
                          -0.004868,        0.99998,     -0.0027818,     0.20,
                                0.0,            0.0,          0.0,        1.0;
  inverse_matrix1=camera_matrix.inverse();
 
  cout << inverse_matrix1 << endl;
  //std::cout << inverse_matrix1(4,4) << std::endl;
  inverse_matrix2=transformation_matrix.inverse();
  cout << inverse_matrix2 << endl;
  //std::cout << inverse_matrix2(4,4) << std::endl;
/*
  Vector3f n(1000,1200,1);//小球在像平面坐標系下的坐標
  Vector3d b(xc,yc,zc);//小球在像素坐標系下的坐標
  Vector4d c(xw,yw,zw,1);  
  Vector4f q(xc,yc,zc,1);
*/
//1000,1200 -> x,y - cx,cy -> u,transformation_matrix
//|u| |fx 0  cx| |x|
//|transformation_matrix|=|0  fy cy|*|y|
//|1| |0  0   1| |z|
u=1000.0;
v=1200.0;
Vector3d n(3);//frame point
  Vector3d b(3);//
  Vector4d c(4);  
  Vector4d q(4);
  n << 1000.0, 1200.0, 1.0;
  b=inverse_matrix1*n;
  
  b=b/b(2);
  cout << b << endl;
  q << b(0), b(1), z, 1.0;
  //std::cout << q(4,1) << std::endl;
  c=inverse_matrix2*q;
 cout << c << endl;
  //b=camera_matrix*n;
  
  //b=b/b(2);
  //cout << b << endl;
  //q << b(0), b(1), b(2), 1.0;
  //c=transformation_matrix*q;

  std::cout << "xw=" << xw << std::endl;
   std::cout << "yw=" << yw << std::endl;
   std::cout << "zw=" << zw << std::endl;
   return 0;
}

