#include <eigen3/Eigen/Eigenvalues>
#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <math.h>

using namespace Eigen;
using namespace std;
using namespace cv;

int main() {
   
// Data  
   ofstream Spectral_space_file;
   ofstream Spectral_transformations_file;
   ofstream New_Spectral_space_file;
   
   Spectral_space_file.open("Spectral_space.txt");
   Spectral_transformations_file.open("Spectral_transformations.txt");
   New_Spectral_space_file.open("New_Spectral_space.txt");

// Pixel data
   Mat_<Vec3b>image;
   image = imread( "/home/jhermosilla/Proyects/C-Party/OpenCV/Images/Minecraft.jpeg", 1 );

   vector<int> greenvector;
   vector<int> bluevector;
   vector<int> redvector;

   for (int i = 0; i < image.rows; i++)
   {
      for (int j = 0; j < image.cols; j++)
      {
         Vec3b pixel = image.at<Vec3b>(i, j);
         redvector.push_back (pixel[0]);
         greenvector.push_back (pixel[1]);
         bluevector.push_back (pixel[2]);
      }   
   }

// Vector space
   const int n = image.rows*image.cols;
   MatrixXf x_space(3,n);
   for (int i = 0; i < n; i++) 
   {
      x_space(0,i) = redvector[i];
      x_space(1,i) = greenvector[i];
      x_space(2,i) = bluevector[i];
   }   
   Spectral_space_file << x_space << endl;

// Mean Pixel Vector 
   float size_k = image.rows*image.cols;
   Vector3f m = Vector3f( cv::sum( image )[0],cv::sum( image )[1], cv::sum( image )[2] ) /size_k;
   Spectral_transformations_file << "Mean pixel vector \n" << m << endl;

// Covariance matrix
   MatrixXf covariance(3,3);
   covariance = ( 1/( size_k - 1 )) * ((x_space.colwise() - m) * (x_space.colwise() - m).transpose());
   Spectral_transformations_file << "Covariance matrix \n" << covariance << endl;

// Correlation matrix
   MatrixXf correlation(3,3);
   for (int i = 0; i < 3; ++i)
   { 
      for (int j = 0; j < 3; ++j)
      {
         correlation(i,j) = covariance(i,j) / sqrt (covariance(i,i)*covariance(j,j));
      }
   }
   Spectral_transformations_file << "Correlation matrix \n" << correlation << endl;

// Eigenvalues and eigenvector
   SelfAdjointEigenSolver<Matrix3f> eigensolver(covariance);
   Matrix3f cov_eigenvectors = eigensolver.eigenvectors();
   Spectral_transformations_file << "Eigenvalues \n" << eigensolver.eigenvalues() << endl;
   Spectral_transformations_file << "Eigenvectors \n" << eigensolver.eigenvectors() << endl;

// Transformation matrix
   Matrix3f G = cov_eigenvectors.transpose();
   Spectral_transformations_file << "Transformation matrix \n" << G << endl;

// New non correlated data space
   MatrixXf y_space = G*x_space;
   New_Spectral_space_file << y_space << endl;

   Spectral_space_file.close();
   Spectral_transformations_file.close();
   New_Spectral_space_file.close();
   return 0;
}
