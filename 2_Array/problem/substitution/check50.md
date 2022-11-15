# check50の結果

:) substitution.c exists
:) substitution.c compiles
:( encrypts "A" as "Z" using ZYXWVUTSRQPONMLKJIHGFEDCBA as key
    expected prompt for input, found none
:( encrypts "a" as "z" using ZYXWVUTSRQPONMLKJIHGFEDCBA as key
    expected prompt for input, found none
:( encrypts "ABC" as "NJQ" using NJQSUYBRXMOPFTHZVAWCGILKED as key
    expected prompt for input, found none
:( encrypts "XyZ" as "KeD" using NJQSUYBRXMOPFTHZVAWCGILKED as key
    expected prompt for input, found none
:( encrypts "This is CS50" as "Cbah ah KH50" using YUKFRNLBAVMWZTEOGXHCIPJSQD as key
    expected prompt for input, found none
:( encrypts "This is CS50" as "Cbah ah KH50" using yukfrnlbavmwzteogxhcipjsqd as key
    expected prompt for input, found none
:( encrypts "This is CS50" as "Cbah ah KH50" using YUKFRNLBAVMWZteogxhcipjsqd as key
    expected prompt for input, found none
:( encrypts all alphabetic characters using DWUSXNPQKEGCZFJBTLYROHIAVM as key
    expected prompt for input, found none
:( handles lack of key
    expected exit code 1, not 0
:( handles invalid key length
    expected exit code 1, not 0
:( handles invalid characters in key
    expected exit code 1, not 0
:( handles duplicate characters in key
    expected exit code 1, not 0
:( handles multiple duplicate characters in key
    expected exit code 1, not 0