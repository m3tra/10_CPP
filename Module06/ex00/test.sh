#!/bin/bash

WHITE='\033[0m'
YELLOW='\033[33m'
RED='\033[38;5;9m'
ORANGE='\033[38;5;208m'
GREEN='\033[38;5;47m'
BLUE='\033[38;5;14m'
PURPLE='\033[38;5;13m'

make debug_asan

if [ $? -ne 0 ]; then
	exit
fi

BIN='./bin/convert'

# Non literals
echo -e "${YELLOW}Non literals\n${WHITE}"

$BIN "1a"; echo
$BIN "+1a"; echo
$BIN "-1a"; echo
$BIN "1af"; echo
$BIN "+1af"; echo
$BIN "-1af"; echo

$BIN "a1"; echo
$BIN "+a1"; echo
$BIN "-a1"; echo
$BIN "a1f"; echo
$BIN "+a1f"; echo
$BIN "-a1f"; echo

$BIN "1.a"; echo
$BIN "+1.a"; echo
$BIN "-1.a"; echo
$BIN "1.af"; echo
$BIN "+1.af"; echo
$BIN "-1.af"; echo

$BIN "a.1"; echo
$BIN "+a.1"; echo
$BIN "-a.1"; echo
$BIN "a.1f"; echo
$BIN "+a.1f"; echo
$BIN "-a.1f"; echo

$BIN "aa1"; echo
$BIN "+aa1"; echo
$BIN "-aa1"; echo
$BIN "aa1f"; echo
$BIN "+aa1f"; echo
$BIN "-aa1f"; echo

$BIN "+nanf"; echo
$BIN "-nanf"; echo
$BIN "+nan"; echo
$BIN "-nan"; echo

# char literals
echo -e "${YELLOW}Char literals\n${WHITE}"

$BIN " "; echo
$BIN "a"; echo
$BIN "A"; echo
$BIN "1"; echo
$BIN "^"; echo
$BIN "~"; echo

# int literals
echo -e "${YELLOW}Int literals\n${WHITE}"

$BIN "0"; echo
$BIN "1"; echo
$BIN "-1"; echo
$BIN "123"; echo
$BIN "-123"; echo
$BIN "12345"; echo
$BIN "-12345"; echo
$BIN "-2147483648"; echo
$BIN "-2147483649"; echo
$BIN "2147483647"; echo
$BIN "2147483648"; echo

# float literals
echo -e "${YELLOW}Float literals\n${WHITE}"

$BIN "42.0f"; echo
$BIN "-42.0f"; echo
$BIN "1.7f"; echo
$BIN "-1.7f"; echo
$BIN "123.7f"; echo
$BIN "-123.7f"; echo
$BIN "26785833972365972987426682458543.34789263572359235623795623975672935692f"; echo
$BIN "-2678583543.123214f"; echo

# pseudo literals
echo -e "${YELLOW}Pseudo literals\n${WHITE}"

$BIN "+inff"; echo
$BIN "-inff"; echo
$BIN "nanf"; echo
$BIN "+inf"; echo
$BIN "-inf"; echo
$BIN "nan"; echo
