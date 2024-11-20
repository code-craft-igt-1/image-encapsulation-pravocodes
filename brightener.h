#pragma once
#include <memory>
#include <utility>  // adding this for std::move

#include "./image.h"

class ImageBrightener {
 public:
    explicit ImageBrightener(std::shared_ptr<Image> inputImage)
        : m_inputImage(std::move(inputImage)) {}

    int BrightenWholeImage();

 private:
    std::shared_ptr<Image> m_inputImage;
};
