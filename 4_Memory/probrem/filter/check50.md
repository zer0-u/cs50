:) grayscale correctly filters single pixel with whole number average
:( grayscale correctly filters single pixel without whole number average
    expected "28 28 28\n", not "27 27 27\n"
:) grayscale leaves alone pixels that are already gray
:) grayscale correctly filters simple 3x3 image
:( grayscale correctly filters more complex 3x3 image
    expected "20 20 20\n50 5...", not "20 20 20\n50 5..."
:( grayscale correctly filters 4x4 image
    expected "20 20 20\n50 5...", not "20 20 20\n50 5..."