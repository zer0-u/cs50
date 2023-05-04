実装した後初めてcheckした時の結果

## grayscale(0114)

:) grayscale correctly filters single pixel with whole number average
:( grayscale correctly filters single pixel without whole number average
    expected "28 28 28\n", not "27 27 27\n"
:) grayscale leaves alone pixels that are already gray
:) grayscale correctly filters simple 3x3 image
:( grayscale correctly filters more complex 3x3 image
    expected "20 20 20\n50 5...", not "20 20 20\n50 5..."
:( grayscale correctly filters 4x4 image
    expected "20 20 20\n50 5...", not "20 20 20\n50 5..."

## sepia(0114)

:) sepia correctly filters single pixel
:) sepia correctly filters simple 3x3 image
:) sepia correctly filters more complex 3x3 image
:) sepia correctly filters 4x4 image

## reflect(0114)

:( reflect correctly filters 1x2 image
    expected "0 0 255\n255 0...", not "0 0 0\n0 0 255..."
:( reflect correctly filters 1x3 image
    expected "0 0 255\n0 255...", not "0 0 0\n0 255 0..."
:( reflect correctly filters image that is its own mirror image
    expected "255 0 0\n255 0...", not "0 255 0\n255 0..."
:( reflect correctly filters 3x3 image
    expected "70 80 90\n40 5...", not "110 130 140\n4..."
:( reflect correctly filters 4x4 image
    expected "100 110 120\n7...", not "110 130 140\n1..."

## blur(0114)
:( blur correctly filters middle pixel
    expected "127 140 149\n", not "53 67 77\n"
:( blur correctly filters pixel on edge
    expected "80 95 105\n", not "25 35 45\n"
:( blur correctly filters pixel in corner
    expected "70 85 95\n", not "10 20 30\n"
:( blur correctly filters 3x3 image
    expected "70 85 95\n80 9...", not "10 20 30\n25 3..."
:( blur correctly filters 4x4 image
    expected "70 85 95\n80 9...", not "10 20 30\n25 3..."

## blurテスト用

### blur correctly filters middle pixel
image[0][0].rgbtBlue = 10;
image[0][0].rgbtGreen = 20;
image[0][0].rgbtRed = 30;

image[0][1].rgbtBlue = 40;
image[0][1].rgbtGreen = 50;
image[0][1].rgbtRed = 60;

image[0][2].rgbtBlue = 70;
image[0][2].rgbtGreen = 80;
image[0][2].rgbtRed = 90;

image[1][0].rgbtBlue = 110;
image[1][0].rgbtGreen = 130;
image[1][0].rgbtRed = 140;

image[1][1].rgbtBlue = 120;
image[1][1].rgbtGreen = 140;
image[1][1].rgbtRed = 150;

image[1][2].rgbtBlue = 130;
image[1][2].rgbtGreen = 150;
image[1][2].rgbtRed = 160;

image[2][0].rgbtBlue = 200;
image[2][0].rgbtGreen = 210;
image[2][0].rgbtRed = 220;

image[2][1].rgbtBlue = 220;
image[2][1].rgbtGreen = 230;
image[2][1].rgbtRed = 240;

image[2][2].rgbtBlue = 240;
image[2][2].rgbtGreen = 250;
image[2][2].rgbtRed = 255;