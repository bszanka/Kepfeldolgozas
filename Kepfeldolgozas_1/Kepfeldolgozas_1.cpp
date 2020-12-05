//// Kepfeldolgozas_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    //std::cout << "Hello!\n";
//
//    //double a;
//    //cout << "Kerek egy szamot [0-1.0] kozott!\n";
//    //cin >> a;
//
//    //cout << "A beolvasott szam " << a * 10 << endl;
//
//    //Mat : Matrixbol jon. Abbol epul fel a kep!
//    Mat img1 = imread("baboon.jpg");
//    //imshow("Majom", img1);
//
//    Mat img2 = imread("butterfly.jpg");
//
//    cout << "Size=" << img2.size() << " Csatorna=" << img2.channels() << " Tipus=" << img2.type() << endl;
//
//    Size img1_size = img1.size();
//
//    Mat img3;
//    // Az img1 méretére átmérezetezzük az img2-t és lementjük az img3-ba.
//    resize(img2, img3, img1_size);
//
//    //----------------------------------------------------------------------------------------------
//    
//    //// Leklónozzunk az img3-at az img4-be. 
//    //Mat img4 = img3.clone();
//    //// A kép összes pixelét 0-ra állítom. (A képméret marad az img3-é!)
//    //img4.setTo(0);
//
//    //// A kép origója a bal felsõ sarok. Járjuk be a pixeleket soronként:
//    //for (int y = 0; y < img1.rows; y++)
//    //    // És oszloponként:
//    //    for (int x = 0; x < img1.cols; x++)
//    //        // Mivel színes képrõl van szó, a csatornákat is be kell járni: 
//    //        for (int c = 0; c < img1.channels(); c++)
//    //            // A kód elején bekért számmal súlyozzuk minden képpont minden csatornájára. (pl: 0.3)
//    //            // Magyarán melyik kép látszódjon jobban, a pillangó vagy a majom.
//    //            // Pont-operáció
//    //            img4.at<Vec3b>(y, x)[c] = a * img1.at<Vec3b>(y, x)[c] + (1 - a) * img3.at<Vec3b>(y, x)[c];
//
//    //imshow("Sulyozott kep:", img4);
//    
//    //----------------------------------------------------------------------------------------------
//
//    // Színes képbõl fekete-fehér
//    // 8 bites elõjel nélküli egycsatornás : CV_8UC1
//    
//    Mat grey(512, 512, CV_8UC1);
//    for (int y = 0; y < img1.rows; y++)
//        for (int x = 0; x < img1.cols; x++)
//            // Az openCV BGR sorrendben használja az RGB csatornákat
//            // [2] = RED -- 0.299-el szorozzuk (ld. dia)
//            // [1] = GREEN -- 0.587-el szorozzuk
//            // [0] = BLUE -- 0.114-el szorozzuk
//            // + az egészet átcastoljuk unsigned char-ra
//            grey.at<uchar>(y, x) = saturate_cast<uchar>(0.299 * img1.at<Vec3b>(y, x)[2] + 
//                0.587 * img1.at<Vec3b>(y, x)[1] + 0.114 * img1.at<Vec3b>(y, x)[0]);
//    //imshow("Szurke", grey);
//
//    //----------------------------------------------------------------------------------------------
//
//    // Képintenzitás-érték
//    Scalar s = mean(grey);
//
//    //cout << "Scalar s" << s;
//    double kep_intenzitas = s[0];
//
//    vector<double> sor_avg;
//    double sum = 0;
//
//    // Sor intenzitása
//    for (int y = 0; y < grey.rows; y++) {
//        for (int x = 0; x < grey.cols; x++) {
//            sum += grey.at<uchar>(y, x);
//        }
//        // Az adott sor átlaga
//        sor_avg.push_back(sum / grey.cols);
//        sum = 0;
//    }
//
//
//    // Azokat a sorokat ahol az átlagintenzitás alacsonyabb mint a képé azt kinullázzuk.
//    // (fekete csíkok lesznek helyette)
//    for (int y = 0; y < grey.rows; y++) {
//        if(sor_avg[y] < kep_intenzitas)
//            for (int x = 0; x < grey.cols; x++)
//                grey.at<uchar>(y, x) = 0;
//    }
//
//    //imshow("Nullazott kep", grey);
//
//    //----------------------------------------------------------------------------------------------
//    
//    // Gamma korrekció -- Sokkal árnyaltabb képet kapunk végeredményül
//
//    Mat img5 = imread("aero1.jpg");
//    //imshow("Aero1", img5);
//    double gamma = 0.5;
//
//    for (int y = 0; y < img5.rows; y++)
//        for (int x = 0; x < img5.cols; x++)
//            for (int c = 0; c < img5.channels(); c++)
//                img5.at<Vec3b>(y, x)[c] = 255 * pow(img5.at<Vec3b>(y,x)[c]/255.0 , 1/gamma);
//
//    //imshow("Aero_gamma", img5);
//
//    //----------------------------------------------------------------------------------------------
//
//    // Egyéb pont operációk
//
//    imshow("Kivonas", img1 - img3);
//    imshow("Invertalas", 255 - img1);
//
//
//    waitKey(0);
//    return 0;
//}
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
