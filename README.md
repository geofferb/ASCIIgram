# ASCIIgram

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

ASCIIgram is a simple C++ library for creating normalized ASCII histograms strings from a vector of integer data.

## Installation and usage

To use ASCIIgram in your C++ project, simply include `ASCIIgram.hpp` in your source code.

## Features 
* Customizable number of bins
* Customizable bar scale and marker character
* Custom units for bins

## Example
### Code
```cpp
    #include "ASCIIgram.hpp"
    #include <vector>
    #include <iostream>

    int main() {
        // Create a vector of integers
        std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        // Set the maximum number of bins1
        int maxBins = 5;
        
        // Create a histogram with a maximum of 5 bins
        ASCIIgram::Histogram h = ASCIIgram::Histogram(data,maxBins); 
        
        // Print the histogram with default settings
        std::cout << h.toString() << std::endl; 
        return 0;
    }
```

### Output
```
1 -   2 (0.20) | ********************
3 -   4 (0.20) | ********************
5 -   6 (0.20) | ********************
7 -   8 (0.20) | ********************
9 -  10 (0.20) | ********************
```



