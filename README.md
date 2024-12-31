# Honors Project: Audio Programming and Oscillator Simulation

This project explores the fundamentals of audio programming and implements an oscillator using object-oriented programming in C++. It applies concepts from the **Gaddis C++ textbook**, research from industry professionals, and practical experimentation with tools like **Audacity** and **VS Code**.

## Project Overview

The goal of this project was to:

1. Simulate an audio oscillator using object-oriented programming principles.
2. Deepen understanding of audio programming, including waveforms and digital signal processing.
3. Gain practical experience with audio file specifications and visualization tools.

### Key Concepts and Features
- **Oscillator Simulation**: 
  - Generates sine waves using consistent frequency and amplitude.
  - Implements oscillation using classes and member functions in C++.
- **Audio File Creation**:
  - Writes binary `.wav` files using `WriteAsBinary` and `seekp()` functions.
  - Outputs are tested and visualized using **Audacity**.
- **Tool Integration**:
  - Audacity: Used to visualize and validate raw data outputs.
  - VS Code: Employed for direct audio playback during testing.

## Challenges and Lessons Learned

1. **Waveform Understanding**:
   - Difficulty distinguishing between waveforms and harmonics.
   - Audacity was essential for visualizing outputs and confirming waveform shapes.

2. **File Specification and Output**:
   - Explored RIFF file structure as documented by Craig Sapp.
   - Learned to interpret binary data and apply it to `.wav` file formatting.

3. **Debugging and Problem-Solving**:
   - Overcame numerous errors related to class implementation, binary writing, and visualization.
   - Utilized resources like StackOverflow, Quora, and community forums for solutions.

## Tools and Resources

- **Programming Language**: C++ 
- **Key Libraries/Extensions**:
  - Gaddis textbook: "Starting Out with C++: From Control Structures through Objects."
  - RIFF File Format Documentation by Craig Sapp.
- **Visualization and Testing**:
  - Audacity: For waveform visualization.
  - VS Code: For direct playback of raw data.

## Limitations and Future Improvements

- Current implementation generates sine waves but struggles with multi-channel wave positioning.
- Noise in output due to specification mismatches and limitations in Audacity or the oscillator.
- Future goals include:
  - Enhancing multi-channel output precision.
  - Exploring additional waveform types (e.g., square, triangle).
  - Improving user interaction and dynamic parameter adjustments.

## Work Cited

- ["Quick Guide to Oscillators"](http://making-music.com/quick-guides/oscillators/) by Ian Waugh.
- Gaddis, Tony. *Starting Out with C++: From Control Structures through Objects*, Ninth Edition, Pearson, 2018.
- [WAVE PCM Soundfile Format](http://soundfile.sapp.org/doc/WaveFormat/) by Craig Sapp.

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/audio-oscillator-project.git
   cd AudioFIleClass
2. Run the file either via the terminal or your IDE run button
  - This should result in an output file of type wav.
 
3. Import the .wav file to Audacity, with the following settings
<img width="314" alt="Screenshot 2024-12-31 at 11 09 19 AM" src="https://github.com/user-attachments/assets/a4c6af30-6a83-493e-a142-20f3c95e70d5" />
