
#include "MockConfig.h"

bool NullOutput::open() noexcept {
    return true;
}
bool NullOutput::write(const uint8_t* data, size_t size) noexcept {
    return true;
}
std::ostream& NullOutput::getOutputStream() noexcept {
    return mNullStream;
}
bool NullOutput::close() noexcept {
    return true;
}

MockInput::MockInput(uint8_t* data, size_t size) : mSize(size) {
    mData = new uint8_t[size];
    memcpy(mData, data, size);
}

ssize_t MockInput::open() noexcept {
    return mSize;
}

std::unique_ptr<const char[]> MockInput::read() noexcept {
    char* rawBuffer = new char[mSize];
    memcpy(rawBuffer, mData, mSize);
    return std::unique_ptr<const char[]>(rawBuffer);
}

bool MockInput::close() noexcept {
    return false;
}

MockInput::~MockInput() {
    delete mData;
}

matc::Config::Output* MockConfig::getOutput() const noexcept {
    return nullptr;
}

matc::Config::Input* MockConfig::getInput() const noexcept {
    return nullptr;
}

std::string MockConfig::toString() const noexcept {
    return {};
}
