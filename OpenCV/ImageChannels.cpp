#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

   Mat_<Vec3b>image;
   image = imread( "/home/jhermosilla/Proyects/C-Party/OpenCV/Images/image.jpg", 1 );
   Vec3b pixel = image(10, 29);

   cout << "El Vector pixel en la coordenada (10,29) es: " << pixel << endl;  
   return 0;
}