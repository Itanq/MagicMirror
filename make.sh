
export ProjDir=$(cd `dirname $0`; pwd)

if (( $# == 1 ));then
    make -f ./build/Makefile clean
    make -f ./build/Makefile -f ./build/vars.mk ProjDir
else
    make -f ./build/Makefile clean
    make -f ./build/Makefile
fi
