#include "./brightener.h"
#include <memory>  // adding this for std::shared_ptr

// Function to determine if a pixel is attenuated
bool IsPixelAttenuated(int pixelValue, int addValue) {
    return pixelValue > (255 - addValue);
}

// Function to brighten a pixel and return its new value
int GetBrightenedPixelValue(int pixelValue, int addValue) {
    return IsPixelAttenuated(pixelValue, addValue) ? 255 : pixelValue + addValue;
}

// Function to process each pixel
void ProcessPixel(const std::shared_ptr<Image>& image,
    int x, int y, int addValue, int attenuatedPixelCount) {
    int pixelValue = image->GetPixel(x, y);
    if (IsPixelAttenuated(pixelValue, addValue)) {
        ++attenuatedPixelCount;
    }
    int newPixelValue = GetBrightenedPixelValue(pixelValue, addValue);
    image->SetPixel(x, y, newPixelValue);
}

// Main function to brighten the whole image
int ImageBrightener::BrightenWholeImage() {
    int attenuatedPixelCount = 0;
    int addValue = 25;

    for (int x = 0; x < m_inputImage->m_rows; ++x) {
        for (int y = 0; y < m_inputImage->m_columns; ++y) {
            ProcessPixel(m_inputImage, x, y, addValue, attenuatedPixelCount);
        }
    }

    return attenuatedPixelCount;
}
