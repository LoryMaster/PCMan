/* date = April 29th 2021 1:56 pm */

#ifndef BUTTON_IMAGE_H
#define BUTTON_IMAGE_H

const s32 closeBtnWidth  = 16;
const s32 closeBtnHeight = 16;


u8 closeBtnData[closeBtnWidth * closeBtnHeight * 4] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00, 0x04, 0x11, 0x11, 0xBC, 0x51, 0x11, 0x11, 0xC9, 0x78,
    0x11, 0x11, 0xC9, 0x78, 0x11, 0x11, 0xBC, 0x51, 0x11, 0x11, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x07, 0x05,
    0x11, 0x11, 0xCD, 0xA2, 0x11, 0x11, 0xDD, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE4, 0xFF,
    0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xDD, 0xFF, 0x11, 0x11, 0xCD, 0xA2,
    0x11, 0x11, 0x07, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xA1, 0x1D, 0x11, 0x11, 0xDA, 0xF6,
    0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE4, 0xFF,
    0x11, 0x11, 0xDA, 0xF6, 0x11, 0x11, 0xA1, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x07, 0x05, 0x11, 0x11, 0xDA, 0xF6, 0x10, 0x10, 0xCA, 0xFF,
    0x11, 0x11, 0x88, 0xFF, 0x10, 0x10, 0xD4, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xD6, 0xFF, 0x11, 0x11, 0x8B, 0xFF,
    0x11, 0x11, 0xC4, 0xFF, 0x11, 0x11, 0xDA, 0xF6, 0x11, 0x11, 0x07, 0x05, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xCD, 0xA2, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0x94, 0xFF,
    0x11, 0x11, 0x42, 0xFF, 0x11, 0x11, 0x5D, 0xFF, 0x10, 0x10, 0xD4, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xD5, 0xFF, 0x11, 0x11, 0x5F, 0xFF, 0x11, 0x11, 0x46, 0xFF,
    0x11, 0x11, 0x8B, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xCD, 0xA2, 0x00, 0x00, 0x00, 0x00,
    0x11, 0x11, 0x00, 0x04, 0x11, 0x11, 0xDD, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x10, 0x10, 0xD6, 0xFF,
    0x11, 0x11, 0x61, 0xFF, 0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x5D, 0xFF, 0x10, 0x10, 0xD4, 0xFF,
    0x11, 0x11, 0xD6, 0xFF, 0x11, 0x11, 0x5F, 0xFF, 0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x5F, 0xFF,
    0x11, 0x11, 0xD6, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xDD, 0xFF, 0x11, 0x11, 0x00, 0x04,
    0x11, 0x11, 0xBC, 0x51, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xD5, 0xFF, 0x11, 0x11, 0x61, 0xFF, 0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x59, 0xFF,
    0x11, 0x11, 0x62, 0xFF, 0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x5F, 0xFF, 0x11, 0x11, 0xD5, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xBC, 0x51,
    0x11, 0x11, 0xC9, 0x78, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x10, 0x10, 0xD5, 0xFF, 0x11, 0x11, 0x64, 0xFF, 0x11, 0x11, 0x41, 0xFF,
    0x11, 0x11, 0x42, 0xFF, 0x11, 0x11, 0x62, 0xFF, 0x11, 0x11, 0xD6, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xC9, 0x78,
    0x11, 0x11, 0xC9, 0x78, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xD6, 0xFF, 0x11, 0x11, 0x5B, 0xFF, 0x11, 0x11, 0x41, 0xFF,
    0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x59, 0xFF, 0x10, 0x10, 0xD4, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xC9, 0x78,
    0x11, 0x11, 0xBC, 0x51, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xD6, 0xFF, 0x11, 0x11, 0x5E, 0xFF, 0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x5B, 0xFF,
    0x11, 0x11, 0x64, 0xFF, 0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x5D, 0xFF, 0x10, 0x10, 0xD4, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xBC, 0x51,
    0x11, 0x11, 0x00, 0x04, 0x11, 0x11, 0xDD, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xD6, 0xFF,
    0x11, 0x11, 0x5E, 0xFF, 0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x5E, 0xFF, 0x11, 0x11, 0xD6, 0xFF,
    0x10, 0x10, 0xD5, 0xFF, 0x11, 0x11, 0x61, 0xFF, 0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x5D, 0xFF,
    0x10, 0x10, 0xD4, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xDD, 0xFF, 0x11, 0x11, 0x00, 0x04,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xCD, 0xA2, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0x91, 0xFF,
    0x11, 0x11, 0x41, 0xFF, 0x11, 0x11, 0x5E, 0xFF, 0x11, 0x11, 0xD6, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xD5, 0xFF, 0x11, 0x11, 0x61, 0xFF, 0x11, 0x11, 0x42, 0xFF,
    0x11, 0x11, 0x88, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xCD, 0xA2, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x07, 0x05, 0x11, 0x11, 0xDA, 0xF6, 0x10, 0x10, 0xCE, 0xFF,
    0x11, 0x11, 0x91, 0xFF, 0x11, 0x11, 0xD6, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x10, 0x10, 0xD6, 0xFF, 0x11, 0x11, 0x94, 0xFF,
    0x10, 0x10, 0xCA, 0xFF, 0x11, 0x11, 0xDA, 0xF6, 0x11, 0x11, 0x07, 0x05, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xA1, 0x1D, 0x11, 0x11, 0xDA, 0xF6,
    0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF,
    0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE3, 0xFF, 0x11, 0x11, 0xE4, 0xFF,
    0x11, 0x11, 0xDA, 0xF6, 0x11, 0x11, 0xA1, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x07, 0x05,
    0x11, 0x11, 0xCD, 0xA2, 0x11, 0x11, 0xDD, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE4, 0xFF,
    0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xE4, 0xFF, 0x11, 0x11, 0xDD, 0xFF, 0x11, 0x11, 0xCD, 0xA2,
    0x11, 0x11, 0x07, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00, 0x04, 0x11, 0x11, 0xBC, 0x51, 0x11, 0x11, 0xC9, 0x78,
    0x11, 0x11, 0xC9, 0x78, 0x11, 0x11, 0xBC, 0x51, 0x11, 0x11, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const s32 minBtnWidth  = 16;
const s32 minBtnHeight = 16;

u8 minBtnData[minBtnWidth * minBtnHeight * 4] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAE, 0x50, 0x2F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x35, 0x1C, 0x0A, 0x04, 0xC1, 0x59, 0x34, 0x51, 0xC7, 0x5B, 0x36, 0x78,
    0xC7, 0x5B, 0x36, 0x78, 0xC1, 0x59, 0x34, 0x51, 0x35, 0x1C, 0x0A, 0x04, 0x00, 0x00, 0x00, 0x00,
    0xAE, 0x50, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x5A, 0x35, 0x00, 0x70, 0x36, 0x1E, 0x05,
    0xC9, 0x5C, 0x37, 0xA2, 0xD0, 0x5F, 0x38, 0xFF, 0xD3, 0x60, 0x39, 0xFF, 0xD3, 0x60, 0x39, 0xFF,
    0xD3, 0x60, 0x39, 0xFF, 0xD3, 0x60, 0x39, 0xFF, 0xD0, 0x5F, 0x38, 0xFF, 0xC9, 0x5C, 0x37, 0xA2,
    0x70, 0x36, 0x1E, 0x05, 0xC3, 0x5A, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC3, 0x5A, 0x35, 0x00, 0xB5, 0x53, 0x31, 0x1D, 0xCE, 0x5E, 0x38, 0xF6,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xCE, 0x5E, 0x38, 0xF6, 0xB5, 0x53, 0x31, 0x1D, 0xC3, 0x5A, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xAE, 0x50, 0x2F, 0x00, 0x70, 0x36, 0x1E, 0x05, 0xCE, 0x5E, 0x38, 0xF6, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xCE, 0x5E, 0x38, 0xF6, 0x70, 0x36, 0x1E, 0x05, 0xAE, 0x50, 0x2F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC9, 0x5C, 0x37, 0xA2, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xC9, 0x5C, 0x37, 0xA2, 0x00, 0x00, 0x00, 0x00,
    0x35, 0x1C, 0x0A, 0x04, 0xD0, 0x5F, 0x38, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD0, 0x5F, 0x38, 0xFF, 0x35, 0x1C, 0x0A, 0x04,
    0xC1, 0x59, 0x34, 0x51, 0xD3, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xB8, 0x54, 0x32, 0xFF,
    0x89, 0x3F, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF,
    0x8A, 0x40, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF, 0x89, 0x3F, 0x26, 0xFF,
    0xB8, 0x54, 0x32, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD3, 0x60, 0x39, 0xFF, 0xC1, 0x59, 0x34, 0x51,
    0xC7, 0x5B, 0x36, 0x78, 0xD3, 0x60, 0x39, 0xFF, 0xDA, 0x64, 0x3B, 0xFF, 0x3F, 0x1E, 0x13, 0xFF,
    0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF,
    0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF,
    0x3F, 0x1E, 0x13, 0xFF, 0xDA, 0x64, 0x3B, 0xFF, 0xD3, 0x60, 0x39, 0xFF, 0xC7, 0x5B, 0x36, 0x78,
    0xC7, 0x5B, 0x36, 0x78, 0xD3, 0x60, 0x39, 0xFF, 0xDA, 0x64, 0x3B, 0xFF, 0x3F, 0x1E, 0x13, 0xFF,
    0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF,
    0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF, 0x42, 0x1F, 0x13, 0xFF,
    0x3F, 0x1E, 0x13, 0xFF, 0xDA, 0x64, 0x3B, 0xFF, 0xD3, 0x60, 0x39, 0xFF, 0xC7, 0x5B, 0x36, 0x78,
    0xC1, 0x59, 0x34, 0x51, 0xD3, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xB8, 0x54, 0x32, 0xFF,
    0x89, 0x3F, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF,
    0x8A, 0x40, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF, 0x8A, 0x40, 0x26, 0xFF, 0x89, 0x3F, 0x26, 0xFF,
    0xB8, 0x54, 0x32, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD3, 0x60, 0x39, 0xFF, 0xC1, 0x59, 0x34, 0x51,
    0x35, 0x1C, 0x0A, 0x04, 0xD0, 0x5F, 0x38, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD0, 0x5F, 0x38, 0xFF, 0x35, 0x1C, 0x0A, 0x04,
    0x00, 0x00, 0x00, 0x00, 0xC9, 0x5C, 0x37, 0xA2, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xC9, 0x5C, 0x37, 0xA2, 0x00, 0x00, 0x00, 0x00,
    0xAE, 0x50, 0x2F, 0x00, 0x70, 0x36, 0x1E, 0x05, 0xCE, 0x5E, 0x38, 0xF6, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xCE, 0x5E, 0x38, 0xF6, 0x70, 0x36, 0x1E, 0x05, 0xAE, 0x50, 0x2F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xC3, 0x5A, 0x35, 0x00, 0xB5, 0x53, 0x31, 0x1D, 0xCE, 0x5E, 0x38, 0xF6,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF, 0xD2, 0x60, 0x39, 0xFF,
    0xCE, 0x5E, 0x38, 0xF6, 0xB5, 0x53, 0x31, 0x1D, 0xC3, 0x5A, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x5A, 0x35, 0x00, 0x70, 0x36, 0x1E, 0x05,
    0xC9, 0x5C, 0x37, 0xA2, 0xD0, 0x5F, 0x38, 0xFF, 0xD3, 0x60, 0x39, 0xFF, 0xD3, 0x60, 0x39, 0xFF,
    0xD3, 0x60, 0x39, 0xFF, 0xD3, 0x60, 0x39, 0xFF, 0xD0, 0x5F, 0x38, 0xFF, 0xC9, 0x5C, 0x37, 0xA2,
    0x70, 0x36, 0x1E, 0x05, 0xC3, 0x5A, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAE, 0x50, 0x2F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x35, 0x1C, 0x0A, 0x04, 0xC1, 0x59, 0x34, 0x51, 0xC7, 0x5B, 0x36, 0x78,
    0xC7, 0x5B, 0x36, 0x78, 0xC1, 0x59, 0x34, 0x51, 0x35, 0x1C, 0x0A, 0x04, 0x00, 0x00, 0x00, 0x00,
    0xAE, 0x50, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


#endif //BUTTON_IMAGE_H
