#include "opencv4/opencv2/imgcodecs.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include <iostream>
#include "gtest/gtest.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

// we're NOT "using namespace std;" here, to avoid collisions between the beta variable and std::beta in c++17
using std::cin;
using std::cout;
using std::endl;
using namespace cv;

class Server{

public:

    int método(int argc, char **argv) {
        CommandLineParser parser(argc, argv,"{@input | /home/luis/CLionProjects/Proyecto 1 - Datos II/Gamma_Correction/cuadras.jpg | input image}");
        Mat image = imread(samples::findFile(parser.get<String>("@input")));
        if (image.empty()) {
            cout << "Could not open or find the image!\n" << endl;
            cout << "Usage: " << argv[0] << " <Input image>" << endl;
            return -1;
        }

    }

    void metodo2(){
        Mat new_image = Mat::zeros( image.size(), image.type() );
        double alpha = 1.0; /*< Simple contrast control */
        int beta = 0;       /*< Simple brightness control */
        cout << " Basic Linear Transforms " << endl;
        cout << "-------------------------" << endl;
        cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
        cout << "* Enter the beta value [0-100]: ";    cin >> beta;
        for( int y = 0; y < image.rows; y++ ) {
            for( int x = 0; x < image.cols; x++ ) {
                for( int c = 0; c < image.channels(); c++ ) {
                    new_image.at<Vec3b>(y,x)[c] =
                            saturate_cast<uchar>( alpha*image.at<Vec3b>(y,x)[c] + beta );
                }
            }
        }
        imshow("Original Image", image);
        imshow("New Image", new_image);
        waitKey();
        return 0;
    }
    }
};

TEST(SeverTEST, Test1){
    Server servidor;

    EXPECT_EQ(servidor.método(), 0);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}