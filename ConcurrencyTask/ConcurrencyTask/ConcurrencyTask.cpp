#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <thread>

using namespace std;
using namespace cv;

void TopLeft(Mat img, int squareSize)
{
	int atl = img.size().width / 2;
	int btl = img.size().height / 2;
	int topLeftBorderWidth = atl - atl % squareSize;
	int topLeftBorderHeight = btl - btl % squareSize;

	int r = 0, g = 0, b = 0, count = 0;

	int minHeight = 0, maxHeight = squareSize, minWidth = 0, maxWidth = squareSize;

	for (int i = minHeight; i <= maxHeight; i++)
	{
		if (i == maxHeight)
		{
			if (minHeight == maxHeight)
			{
				break;
			}
			if (minWidth == maxWidth)
			{
				minHeight = maxHeight;
				maxHeight += squareSize;
				if (maxHeight > topLeftBorderHeight)
				{
					maxHeight = topLeftBorderHeight;
				}
				minWidth = 0;
				maxWidth = squareSize;
			}
			else
			{
				for (int l = minHeight; l < maxHeight && l < topLeftBorderHeight; l++)
				{
					for (int k = minWidth; k < maxWidth && k < topLeftBorderWidth; k++)
					{
						img.at<Vec3b>(l, k)[0] = r / count;
						img.at<Vec3b>(l, k)[1] = g / count;
						img.at<Vec3b>(l, k)[2] = b / count;
					}
				}
				imshow("monalisa", img);
				waitKey(1);
				i = 0;
				minWidth = maxWidth;
				maxWidth += squareSize;
				if (maxWidth > img.size().width)
				{
					maxWidth = img.size().width;
				}
				r = 0;
				g = 0;
				b = 0;
				count = 0;
			}
		}
		else
		{
			for (int j = minWidth; j < maxWidth && j < topLeftBorderWidth; j++)
			{
				r += img.at<Vec3b>(i, j)[0];
				g += img.at<Vec3b>(i, j)[1];
				b += img.at<Vec3b>(i, j)[2];
				count++;
			}
		}
	}
}

void TopRight(Mat img, int squareSize)
{
	int atl = img.size().width / 2;
	int btl = img.size().height / 2;
	int topRightBorderWidthMin = (atl - atl % squareSize);
	int topRightBorderHeight = btl - btl % squareSize;

	int r = 0, g = 0, b = 0, count = 0;

	int minHeight = 0, maxHeight = squareSize, minWidth = topRightBorderWidthMin, maxWidth = topRightBorderWidthMin + squareSize;

	for (int i = minHeight; i <= maxHeight; i++)
	{
		if (i == maxHeight)
		{
			if (minHeight == maxHeight)
			{
				break;
			}
			if (minWidth == maxWidth)
			{
				minHeight = maxHeight;
				maxHeight += squareSize;
				if (maxHeight > topRightBorderHeight)
				{
					maxHeight = topRightBorderHeight;
				}
				minWidth = topRightBorderWidthMin;
				maxWidth = topRightBorderWidthMin + squareSize;
			}
			else
			{
				for (int l = minHeight; l < maxHeight && l < topRightBorderHeight; l++)
				{
					for (int k = minWidth; k < maxWidth && k < img.size().width; k++)
					{
						img.at<Vec3b>(l, k)[0] = r / count;
						img.at<Vec3b>(l, k)[1] = g / count;
						img.at<Vec3b>(l, k)[2] = b / count;
					}
				}
				imshow("monalisa", img);
				waitKey(1);
				i = 0;
				minWidth = maxWidth;
				maxWidth += squareSize;
				if (maxWidth > img.size().width)
				{
					maxWidth = img.size().width;
				}
				r = 0;
				g = 0;
				b = 0;
				count = 0;
			}
		}
		else
		{
			for (int j = minWidth; j < maxWidth && j < img.size().width; j++)
			{
				r += img.at<Vec3b>(i, j)[0];
				g += img.at<Vec3b>(i, j)[1];
				b += img.at<Vec3b>(i, j)[2];
				count++;
			}
		}
	}
}

void BottomLeft(Mat img, int squareSize)
{
	int atl = img.size().width / 2;
	int btl = img.size().height / 2;
	int bottomLeftBorderWidth = atl - atl % squareSize;
	int bottomLeftBorderHeight = (btl - btl % squareSize);

	int r = 0, g = 0, b = 0, count = 0;

	int minHeight = bottomLeftBorderHeight, maxHeight = bottomLeftBorderHeight + squareSize, minWidth = 0, maxWidth = squareSize;

	for (int i = minHeight; i <= maxHeight; i++)
	{
		if (i == maxHeight)
		{
			if (minHeight == maxHeight)
			{
				break;
			}
			if (minWidth == maxWidth)
			{
				minHeight = maxHeight;
				maxHeight += squareSize;
				if (maxHeight > img.size().height)
				{
					maxHeight = img.size().height;
				}
				minWidth = 0;
				maxWidth = squareSize;
			}
			else
			{
				for (int l = minHeight; l < maxHeight && l < img.size().height; l++)
				{
					for (int k = minWidth; k < maxWidth && k < bottomLeftBorderWidth; k++)
					{
						img.at<Vec3b>(l, k)[0] = r / count;
						img.at<Vec3b>(l, k)[1] = g / count;
						img.at<Vec3b>(l, k)[2] = b / count;
					}
				}
				imshow("monalisa", img);
				waitKey(1);
				i = 0;
				minWidth = maxWidth;
				maxWidth += squareSize;
				if (maxWidth > img.size().width)
				{
					maxWidth = img.size().width;
				}
				r = 0;
				g = 0;
				b = 0;
				count = 0;
			}
		}
		else
		{
			for (int j = minWidth; j < maxWidth && j < bottomLeftBorderWidth; j++)
			{
				r += img.at<Vec3b>(i, j)[0];
				g += img.at<Vec3b>(i, j)[1];
				b += img.at<Vec3b>(i, j)[2];
				count++;
			}
		}
	}
}

void BottomRight(Mat img, int squareSize)
{
	int atl = img.size().width / 2;
	int btl = img.size().height / 2;
	int bottomRightBorderWidth = (atl - atl % squareSize);
	int bottomRightBorderHeight = (btl - btl % squareSize);

	int r = 0, g = 0, b = 0, count = 0;

	int minHeight = bottomRightBorderHeight, maxHeight = bottomRightBorderHeight + squareSize, minWidth = bottomRightBorderWidth, maxWidth = bottomRightBorderWidth + squareSize;

	for (int i = minHeight; i <= maxHeight; i++)
	{
		if (i == maxHeight)
		{
			if (minHeight == maxHeight)
			{
				break;
			}
			if (minWidth == maxWidth)
			{
				minHeight = maxHeight;
				maxHeight += squareSize;
				if (maxHeight > img.size().height)
				{
					maxHeight = img.size().height;
				}
				minWidth = bottomRightBorderWidth;
				maxWidth = bottomRightBorderWidth + squareSize;
			}
			else
			{
				for (int l = minHeight; l < maxHeight && l < img.size().height; l++)
				{
					for (int k = minWidth; k < maxWidth && k < img.size().width; k++)
					{
						img.at<Vec3b>(l, k)[0] = r / count;
						img.at<Vec3b>(l, k)[1] = g / count;
						img.at<Vec3b>(l, k)[2] = b / count;
					}
				}
				imshow("monalisa", img);
				waitKey(1);
				i = 0;
				minWidth = maxWidth;
				maxWidth += squareSize;
				if (maxWidth > img.size().width)
				{
					maxWidth = img.size().width;
				}
				r = 0;
				g = 0;
				b = 0;
				count = 0;
			}
		}
		else
		{
			for (int j = minWidth; j < maxWidth && j < img.size().width; j++)
			{
				r += img.at<Vec3b>(i, j)[0];
				g += img.at<Vec3b>(i, j)[1];
				b += img.at<Vec3b>(i, j)[2];
				count++;
			}
		}
	}
}

int main()
{
	//variables to be entered by the user
	string path;
	int squareSize;

	//reading entered image path
	cout << "Enter image path: (Put '/') ";
	getline(cin, path);


	//reading the image from the entered path and
	//checking its validity
    string image_path = samples::findFile(path);
    Mat img = imread(image_path, IMREAD_COLOR);

	if (img.empty())
	{
		cout << "Could not read the image!" << endl;
		return 0;
	}

	//reading entered square size
	cout << "Enter square size: ";
	cin >> squareSize;

	string threadMode;
	cout << "Enter thread Mode (S/M): ";
	cin >> threadMode;
	if (threadMode == "S")
	{
		int r = 0, g = 0, b = 0, count = 0;

		int minHeight = 0, maxHeight = squareSize, minWidth = 0, maxWidth = squareSize;

		for (int i = minHeight; i <= maxHeight; i++)
		{
			if (i == maxHeight)
			{
				if (minHeight == maxHeight)
				{
					break;
				}
				if (minWidth == maxWidth)
				{
					minHeight = maxHeight;
					maxHeight += squareSize;
					if (maxHeight > img.size().height)
					{
						maxHeight = img.size().height;
					}
					minWidth = 0;
					maxWidth = squareSize;
				}
				else
				{
					for (int l = minHeight; l < maxHeight && l < img.size().height; l++)
					{
						for (int k = minWidth; k < maxWidth && k < img.size().width; k++)
						{
							img.at<Vec3b>(l, k)[0] = r / count;
							img.at<Vec3b>(l, k)[1] = g / count;
							img.at<Vec3b>(l, k)[2] = b / count;
						}
					}
					imshow("monalisa", img);
					waitKey(1);
					i = 0;
					minWidth = maxWidth;
					maxWidth += squareSize;
					if (maxWidth > img.size().width)
					{
						maxWidth = img.size().width;
					}
					r = 0;
					g = 0;
					b = 0;
					count = 0;
				}
			}
			else
			{
				for (int j = minWidth; j < maxWidth && j < img.size().width; j++)
				{
					r += img.at<Vec3b>(i, j)[0];
					g += img.at<Vec3b>(i, j)[1];
					b += img.at<Vec3b>(i, j)[2];
					count++;
				}
			}
		}
	}
	else if (threadMode == "M")
	{
		thread th1(TopLeft, img, squareSize);
		thread th2(TopRight, img, squareSize);
		thread th3(BottomLeft, img, squareSize);
		thread th4(BottomRight, img, squareSize);

		th1.join();

		th2.join();

		th3.join();

		th4.join();
	}
	else
	{
		cout << "Invalid method! Enter S or M." << endl;
	}
	
	imwrite("result.jpg", img);

}

