#include "opencv4/opencv2/imgcodecs.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
#include "gtest/gtest.h"

using namespace cv;
using namespace std;

class Server{

public:
    int método()
    {
        // Read the image file
        Mat image = imread("/home/luis/CLionProjects/Proyecto 1 - Datos II/gray_scale/tst/cuadras.jpg");

        // Check for failure
        if (image.empty())
        {
            cout << "Could not open or find the image" << endl;
            cin.get(); //wait for any key press
            return -1;
        }

        //Blur the image with 3x3 Gaussian kernel
        Mat image_blurred_with_3x3_kernel;
        GaussianBlur(image, image_blurred_with_3x3_kernel, Size(3, 3), 0);

        //Blur the image with 5x5 Gaussian kernel
        Mat image_blurred_with_5x5_kernel;
        GaussianBlur(image, image_blurred_with_5x5_kernel, Size(5, 5), 0);

        //Define names of the windows
        String window_name = "Lotus";
        String window_name_blurred_with_3x3_kernel = "Lotus Blurred with 3 x 3 Gaussian Kernel";
        String window_name_blurred_with_5x5_kernel = "Lotus Blurred with 5 x 5 Gaussian Kernel";

        // Create windows with above names
        namedWindow(window_name);
        namedWindow(window_name_blurred_with_3x3_kernel);
        namedWindow(window_name_blurred_with_5x5_kernel);

        // Show our images inside the created windows.
        imshow(window_name, image);
        imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
        imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

        waitKey(0); // Wait for any keystroke in the window

        destroyAllWindows(); //destroy all opened windows

        return 0;
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