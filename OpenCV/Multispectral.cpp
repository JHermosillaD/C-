#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
   
// Data  
   std::ofstream myFile_Handler;
   myFile_Handler.open("Data.txt");

// Pixel data
   Mat_<Vec3b>image;
   image = imread( "/home/jhermosilla/Proyects/C-Party/OpenCV/Images/Minecraft.jpeg", 1 );
   vector<int> redvector;   
   vector<int> greenvector;
   vector<int> bluevector;

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
   int n = image.rows*image.cols;
   float x_space [3][n];
   float x_space_transpose [n][3];
   for(int i = 0; i < n; i++) 
   {
      x_space[0][i] = redvector[i];
      x_space[1][i] = greenvector[i];
      x_space[2][i] = bluevector[i];
   }   

   for (int i = 0; i < 3; ++i)
   {
      for (int j = 0; j < n; ++j) 
      {
         x_space_transpose[j][i] = x_space[i][j];
      }
   }


// Mean Pixel Vector
   float m [2] = {}; 
   float size_k = image.rows*image.cols;
   m [0] = (cv::sum( image )[0])/size_k;
   m [1] = (cv::sum( image )[1])/size_k;
   m [2] = (cv::sum( image )[2])/size_k;

// Covariance matrix
   float covariance [3][3];
   for(int i = 0; i < 3; ++i)
   {
      for(int j = 0; j < 3; ++j)
      {
         covariance[i][j] = 0;
         for(int k = 0; k < n; ++k)
            {
               covariance[i][j] += ( 1/( size_k - 1 )) * (x_space[i][k] - m[j]) * (x_space_transpose[k][j] - m[j]);
            }
      }
   }

   myFile_Handler.close();
   return 0;
}
