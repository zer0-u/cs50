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