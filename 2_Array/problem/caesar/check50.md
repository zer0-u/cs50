# check50の実行結果

:) caesar.c exists.
:) caesar.c compiles.
:) encrypts "a" as "b" using 1 as key
:( encrypts "barfoo" as "yxocll" using 23 as key
    output not valid ASCII text
:) encrypts "BARFOO" as "EDUIRR" using 3 as key
:) encrypts "BaRFoo" as "FeVJss" using 4 as key
:( encrypts "barfoo" as "onesbb" using 65 as key
    expected "ciphertext: on...", not "ciphertext: on..."
:( encrypts "world, say hello!" as "iadxp, emk tqxxa!" using 12 as key
    output not valid ASCII text
:) handles lack of argv[1]
:) handles non-numeric key
:) handles too many arguments