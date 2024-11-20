#include <iostream>
#include <memory>
#include "./brightener.h"

// Function to initialize the image pixels
void InitializeImage(const std::shared_ptr<Image>& image, int initialPixelValue) {
    for (uint16_t row = 0; row < image->m_rows; ++row) {
        for (uint16_t col = 0; col < image->m_columns; ++col) {
            image->SetPixel(row, col, initialPixelValue);
        }
    }
}

// Function to validate the image size
bool ValidateImageSize(const std::shared_ptr<Image>& image) {
    if (!image->ValidateImage()) {
        std::cerr << "Image is too large!" << std::endl;
        return false;
    }
    return true;
}

int main() {
    auto image = std::make_shared<Image>(512, 512);
    InitializeImage(image, 100);  // Initialize pixels to 100 for example

    if (!ValidateImageSize(image)) {
        return 1;
    }

    ImageBrightener brightener(image);
    int attenuatedPixels = brightener.BrightenWholeImage();

    std::cout << "Number of attenuated pixels: " << attenuatedPixels << std::endl;
    std::cout << "... in an image of: " << image->m_rows << " x " << image->m_columns << std::endl;

    return 0;
}
