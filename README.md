# mbed-compile

### Pre build
```
sudo apt install python3 python3-pip git mercurial
python3 -m pip install mbed-cli
sudo apt install ninja-build
sudo apt install gcc-arm-none-eabi
python -m pip install intelhex prettytable future

git submodule foreach git pull origin master
python3 -m pip install -r cmake_setup/mbed-cmake/mbed-src/requirements.txt
```

### Setup target (Nucleo 144 as example) :
Target name can be found on the top right of microcontroller page on mbed site : https://os.mbed.com/platforms/ST-Nucleo-F767ZI/
```
cd cmake_setup
python3 mbed-cmake/configure_for_target.py -a mbed_app.json -i .mbedignore NUCLEO_F767ZI
```

### Generate makefile for a cpp file for a given target :

add this line in  cmake_setup/CMakeLists.txt (multiple rules can be added):
> add_mbed_executable(icecream ../code/icecream.cpp)

After updating the file :
```
cd build && cmake ../cmake_setup
```

### To compile
```
cd build
make -j2 icecream
```

### To compile (icecream as example) and flash to the nucleo from *code* directory
```
make -j2 -C ../build icecream && sudo mount /dev/sda /media/nucleo && sudo cp ../build/icecream.bin /media/nucleo/ && sync && sudo umount /media/nucleo
```

### .bashrc
```
compile() {
    local target=$1
    if [ $# -lt 1 ]
    then
        target="icecream"
    elif [ $1 == "help" ] || [ $1 == "-h" ]
    then
        echo "Usage : Compile [target=icecream]"
        return 0
    fi
    make -j2 -C ../build $target
    sudo mount /dev/sda /media/nucleo
    sudo cp ../build/$target.bin /media/nucleo/
    sync
    sudo umount /media/nucleo
}
```
Make sure directory */media/nucleo* has been created


```
// from *code/* directory
// To compile and copy 
compile // <=> compile icecream

// To use another .cpp file
compile blinky // use blinky.cpp or whatever declared in add_mbed_executable
```

### Useful references 
https://github.com/ARMmbed/mbed-os-5-docs/blob/development/docs/tools/mbed_cli_2/use.md#build-the-project-with-cmake-advanced

https://mynewt.apache.org/latest/get_started/native_install/cross_tools.html

https://os.mbed.com/docs/mbed-os/v6.16/build-tools/install-or-upgrade.html

