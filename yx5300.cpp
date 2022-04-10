#include "yx5300.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

player::player(int tx_pin, int rx_pin){
    serialPlayer = new SoftwareSerial(tx_pin, rx_pin, false);
}

void player::command(uint8_t command, uint8_t parameter1=0x00, uint8_t parameter2=0x00, bool feedback=false){
    delay(20);

    uint8_t cmdbuf[8] = {
        0x7e,       //command start
        0xff,       //version
        0x06,       //command length
        command, 
        feedback ? (uint8_t)0x00 : (uint8_t)0x01, 
        parameter1, 
        parameter2, 
        0xef        //ending
    };
    for (int i = 0; i < 8; i++){
        serialPlayer->write(cmdbuf[i]);
    }
}

void player::init(){
    serialPlayer->begin(9600);
    delay(500);
    command(0x09, 0x00, 0x02);
    delay(200);
}

void player::playFilename(int8_t folder, int8_t file_prefix){
    command(0x0F, folder, file_prefix);
}

void player::playLoop(int8_t folder){
    command(0x17, folder, 0x00);
}

void player::setVolume(int8_t volume){
    command(0x06, 0x00, volume);
}

void player::increaseVolume(){
    command(0x04);
}

void player::decreaseVolume(){
    command(0x05);
}

void player::pause(){
    command(0x0e);
}

void player::resume(){
    command(0x0d);
}

void player::stop(){
    command(0x16);
}

void player::prev(){
    command(0x02);
}

void player::next(){
    command(0x01);
}