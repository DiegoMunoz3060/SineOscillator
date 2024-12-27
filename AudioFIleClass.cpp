#include <iostream> 
#include <cmath>
#include <fstream> 
using namespace std;

const int SAMPLERATE = 44100;
const int BITDEPTH = 16;    //signed bits are able to handle negative values which means that the audio is writtin with 0 equilibrium
//From first file
const string chunk_id = "RIFF";
const string chunk_size = "----";
const string format = "WAVE";

const string subchunk1_id = "fmt ";
const int subchunk1_size = 16;
const int audio_format = 1;
const int num_channels = 2;     //left and right speaker will do something different (stereo)
const int byte_rate = SAMPLERATE * num_channels * (subchunk1_size/8);
const int block_align = BITDEPTH / 8;

void write_as_bytes(ofstream &file, int value, int byte_size) {
    file.write(reinterpret_cast<const char*>(&value), byte_size);
}

class SinOscillator{
    float frequency, amplitude, angle = 0.0f, offset = 0.0; //Classe's attributes, requires f for constant treatment as a float var
    public:
    SinOscillator(int freq, float amp){     //using a member list to initilize the members of the class
        frequency = freq; 
        amplitude = amp;
        offset = 2 * M_PI * frequency / SAMPLERATE; 
    }
    float process(){    //Method encharge of generating next sample value
        auto sample = amplitude * sin(angle); 
        angle += offset;
        return sample; 
    }
};

int main(){
    int duration = 2; //Durataion will be in secoonds. 
    SinOscillator sinOscillator(440, 0.5);
    ofstream audioFile; 
    audioFile.open("waveForm.wav", ios:: binary);   //We will be able to replay audio using bianary 
    auto maxAmplitude = pow(2, BITDEPTH -1 ) -1;
    
    audioFile << chunk_id;
    audioFile << chunk_size; 
    audioFile << format;        
    audioFile << subchunk1_id;

    write_as_bytes(audioFile, subchunk1_size, 4); 
    write_as_bytes(audioFile, audio_format, num_channels); 
    write_as_bytes(audioFile, audio_format, num_channels); 
    write_as_bytes(audioFile, SAMPLERATE, 4); 
    write_as_bytes(audioFile, byte_rate, 4); 
    write_as_bytes(audioFile, block_align, 2);
    write_as_bytes(audioFile, BITDEPTH, 2);
    
    audioFile << "data"; 
    //audioFile << 
    
    int prePosition = audioFile.tellp();

    for(int i = 0; i < SAMPLERATE * duration; i++){    //
        
        auto sample = sinOscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude); 
        audioFile.write(reinterpret_cast<char*>(&intSample), 2); 
         
    }
    int postPosition = audioFile.tellp(); 
    audioFile.seekp(prePosition - 4); 
    write_as_bytes(audioFile, postPosition - prePosition, 4);

    audioFile.seekp(4, ios::beg); 
    write_as_bytes(audioFile, postPosition - 8, 4); 
    //Testing size of data types in order to calculate bitdepth var
    // cout << "Float size: " << sizeof(float) << endl;
    // cout << "Float int: " << sizeof(int) << endl;
    
    audioFile.close(); 
    return 0; 
}
