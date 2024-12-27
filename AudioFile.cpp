#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
// Riff variables
const string chunk_id = "RIFF";
const string chunk_size = "----";
const string format = "WAVE";

//fmt variables (sub chunk)
const string subchunk1_id = "fmt "; //always looking for 4 bytes!
const int subchunk1_size = 16;
const int audio_format = 1;
const int num_channels = 2; //left and right speaker will do something different (stereo)
const int sample_rate = 44100; //audio samples per second (higher rate is better quality)
const int byte_rate = sample_rate * num_channels * (subchunk1_size/8);
const int block_align = num_channels * (subchunk1_size / 8);    //
const int bits_per_sample = 16;

//Header information
const string subchunk2_id = "data";
const string subchunk2_size = "----";

//Making actual sound
const int duration = 2;
const int max_amplitude = 32760; //Maximum aplitude of the sound wave because we are using a max of 16 bits in size
const double frequency = 300; // the higher the value the closer the waves will be resulting in a higher pitch

//Facilitate writting to the WAV file
void write_as_bytes(ofstream &file, int value, int byte_size) {
    file.write(reinterpret_cast<const char*>(&value), byte_size);

}

int main(){

    ofstream wav;
    wav.open("test.wav", ios::binary);

    if(wav.is_open()){

        wav << chunk_id;
        wav << chunk_size;
        wav << format;

        wav << subchunk1_id;
        write_as_bytes(wav, subchunk1_size, 4); //need the function because we need to declare byte size
        write_as_bytes(wav, audio_format, 2);
        write_as_bytes(wav, num_channels, 2);
        write_as_bytes(wav, sample_rate, 4);
        write_as_bytes(wav, byte_rate, 4);
        write_as_bytes(wav, block_align, 2);
        write_as_bytes(wav, bits_per_sample, 2);

        wav << subchunk2_id;
        wav << subchunk2_size;

        int startAudio = wav.tellp();

        for(int i = 0; i < sample_rate * duration; i++){    //tranversing through the sin function wave
            double amplitude = (double)i / sample_rate * max_amplitude;
            double value = sin((2 * 3.14 * i * frequency) / sample_rate); //Basic sin function where i is the hight and frequence is b value

            double channel1 = amplitude * value / 2;
            double channel2 = (max_amplitude - amplitude) * value;   //going from big numbers to small where you right ear is going up in numbers

            write_as_bytes(wav, channel1, 2); //
            write_as_bytes(wav, channel2, 2); //
        }

        int endAudio = wav.tellp(); 
        wav.seekp(startAudio - 4); 
        write_as_bytes(wav, endAudio - startAudio, 4); 

        wav.seekp(4, ios::beg); //puts us at the beggining of the file + 4, needed this because we need to locate chunk1 
        write_as_bytes(wav, endAudio - 8, 4); 

        wav.close();

    }

    return 0;
}