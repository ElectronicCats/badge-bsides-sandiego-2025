#pragma once

/**
 * Bitmaps must be flipped horizontally to be displayed correctly.
 */

// 'bsides_logo', 128x32px
static const unsigned char epd_bitmap_bsides_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0xf0, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x0f, 0xf8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x1e,
    0x18, 0x00, 0x00, 0x00, 0x00, 0x03, 0x9e, 0x7d, 0xf1, 0xc0, 0x44, 0x63,
    0xc0, 0xff, 0xfe, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x04, 0x41, 0x04,
    0x42, 0x40, 0x4c, 0x90, 0x20, 0xf8, 0x1f, 0x0e, 0x1c, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x41, 0x04, 0x44, 0x40, 0x5c, 0x90, 0x21, 0xf0, 0x0f, 0x07,
    0xfc, 0x00, 0x00, 0x00, 0x00, 0x04, 0x4d, 0x1c, 0x44, 0x40, 0x74, 0xf1,
    0xc1, 0xe0, 0x07, 0x87, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x04, 0x51, 0x04,
    0x44, 0x40, 0x65, 0x0a, 0x03, 0xe0, 0x03, 0x87, 0x1e, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x51, 0x04, 0x42, 0x40, 0x45, 0x0a, 0x03, 0xe1, 0x83, 0xc6,
    0x0e, 0x00, 0x00, 0x00, 0x00, 0x03, 0x8e, 0x7d, 0xf1, 0xc0, 0x45, 0x09,
    0xe3, 0xc1, 0x83, 0xc6, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc3, 0x0e, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc1,
    0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x03, 0xfe, 0x01, 0xf8,
    0x60, 0x70, 0x0e, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f,
    0xc1, 0xfe, 0x03, 0xfc, 0x70, 0xfc, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x38, 0xe0, 0x07, 0x07, 0xfc, 0x30, 0xdf, 0x1e, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x03, 0x1e, 0x0c,
    0x38, 0x07, 0x9e, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xf0, 0x03, 0x9c, 0x0c, 0x38, 0x03, 0x9e, 0x18, 0x38, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0xf0, 0x03, 0x9c, 0x0c, 0x38, 0x07, 0x9e, 0x18,
    0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0xff, 0x9c, 0x0c,
    0x18, 0x3f, 0x1e, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f,
    0x80, 0x7f, 0x9c, 0x0c, 0x18, 0x7c, 0x1f, 0x00, 0x70, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3c, 0x00, 0x03, 0x86, 0x0c, 0x18, 0xe0, 0x0f, 0x80,
    0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x01, 0xc7, 0x0e,
    0x1c, 0xe0, 0x4f, 0xc1, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
    0x30, 0x01, 0xc3, 0xfe, 0x1c, 0xe1, 0xc7, 0xff, 0xc0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0f, 0xf8, 0xff, 0xc1, 0xff, 0x1c, 0x7f, 0xe3, 0xff,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x7f, 0xc0, 0x3f,
    0x0c, 0x1f, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// 'menu_1', 128x32px
static const unsigned char epd_bitmap_menu_1[] = {
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x7f,
    0x00, 0x3c, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x71, 0xff, 0x00, 0x43, 0xe1, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 0x87, 0x00, 0x80, 0x00, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x07,
    0x01, 0x08, 0x08, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
    0x33, 0xe0, 0x73, 0x07, 0x01, 0x1c, 0x14, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x30, 0x67, 0xf0, 0x73, 0x07, 0x01, 0x08, 0x08, 0x40,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x66, 0x38, 0x71, 0x87,
    0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
    0xc6, 0x1c, 0x70, 0xff, 0x01, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0xc6, 0x0c, 0x70, 0x7f, 0x01, 0x07, 0xf0, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xc7, 0x0c, 0x70, 0x07,
    0x01, 0x08, 0x08, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d,
    0x87, 0x8c, 0x70, 0x07, 0x01, 0x08, 0x08, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0d, 0x86, 0xdc, 0x70, 0x07, 0x01, 0x10, 0x04, 0x40,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x06, 0xf8, 0x70, 0x07,
    0x01, 0x20, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x0c, 0x70, 0x70, 0x07, 0x00, 0xc0, 0x01, 0x80, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// 'menu_2', 128x32px
static const unsigned char epd_bitmap_menu_2[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x07,
    0x00, 0x0e, 0x1c, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x07, 0x00, 0x18, 0x06, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0f, 0x00, 0x31, 0xe3, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1f,
    0x00, 0x22, 0x11, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x79,
    0xec, 0x7c, 0x0c, 0x3b, 0x00, 0x64, 0x09, 0x80, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x03, 0x18, 0xff, 0xf8, 0xfe, 0x0c, 0x33, 0x00, 0x44, 0x08, 0x80,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0xc7, 0x38, 0xc7, 0x0c, 0x73,
    0x00, 0x44, 0x08, 0x80, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0xc3,
    0x18, 0xc3, 0x8c, 0xe3, 0x00, 0x42, 0x10, 0x80, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x07, 0xfe, 0xc3, 0x18, 0xc1, 0x8c, 0xc3, 0x00, 0x41, 0xe0, 0x80,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0xc3, 0x18, 0xe1, 0x8d, 0xc3,
    0x00, 0x62, 0x11, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xc3,
    0x18, 0xf1, 0x8f, 0x83, 0x00, 0x24, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x1c, 0xc3, 0x18, 0xdb, 0x8f, 0x03, 0x00, 0x38, 0x07, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc3, 0x18, 0xdf, 0x0e, 0x03,
    0x00, 0x18, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0xc3,
    0x19, 0x8e, 0x0c, 0x03, 0x00, 0x0e, 0x1c, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// 'menu_3', 128x32px
static const unsigned char epd_bitmap_menu_3[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x00, 0x03, 0xf0, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x70,
    0x00, 0x0e, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
    0x00, 0x00, 0xc0, 0x70, 0x00, 0x18, 0x06, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0x00, 0x30, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xd8,
    0x00, 0x20, 0xc1, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x98, 0x30,
    0xf8, 0x1c, 0xc0, 0xd8, 0x00, 0x60, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7f, 0x18, 0x31, 0xdc, 0x3f, 0xc1, 0x8c, 0x00, 0x40, 0x00, 0x80,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x18, 0x33, 0x8e, 0x63, 0xc3, 0x8c,
    0x00, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x18, 0x33,
    0x06, 0x41, 0xc3, 0x06, 0x00, 0x40, 0xc0, 0x80, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x18, 0x32, 0x02, 0xc0, 0xc3, 0xfe, 0x00, 0x40, 0xc0, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x18, 0x32, 0x02, 0xc0, 0xc7, 0xff,
    0x00, 0x60, 0xc1, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x18, 0x33,
    0x06, 0x40, 0xc6, 0x03, 0x00, 0x20, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x06, 0x1c, 0x33, 0x8e, 0x60, 0xc6, 0x03, 0x00, 0x30, 0x03, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x16, 0x61, 0xdc, 0x31, 0xc4, 0x01,
    0x00, 0x18, 0x06, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x13, 0xc0,
    0xf8, 0x1f, 0x8c, 0x01, 0x80, 0x0e, 0x1c, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// 'menu_4', 128x32px
static const unsigned char epd_bitmap_menu_4[] = {
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x07,
    0x00, 0x0e, 0x1c, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x07, 0x00, 0x18, 0x06, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0f, 0x00, 0x31, 0xe3, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1f,
    0x00, 0x22, 0x11, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x79,
    0xec, 0x7c, 0x0c, 0x3b, 0x00, 0x64, 0x09, 0x80, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x03, 0x18, 0xff, 0xf8, 0xfe, 0x0c, 0x33, 0x00, 0x44, 0x08, 0x80,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0xc7, 0x38, 0xc7, 0x0c, 0x73,
    0x00, 0x44, 0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0xc3,
    0x18, 0xc3, 0x8c, 0xe3, 0x00, 0x42, 0x10, 0x80, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x07, 0xfe, 0xc3, 0x18, 0xc1, 0x8c, 0xc3, 0x00, 0x41, 0xe0, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0xc3, 0x18, 0xe1, 0x8d, 0xc3,
    0x00, 0x62, 0x11, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xc3,
    0x18, 0xf1, 0x8f, 0x83, 0x00, 0x24, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x1c, 0xc3, 0x18, 0xdb, 0x8f, 0x03, 0x00, 0x38, 0x07, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc3, 0x18, 0xdf, 0x0e, 0x03,
    0x00, 0x18, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0xc3,
    0x19, 0x8e, 0x0c, 0x03, 0x00, 0x0e, 0x1c, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// 'menu_5', 128x32px
static const unsigned char epd_bitmap_menu_5[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x10, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x8f, 0xf0, 0x03,
    0x00, 0x04, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x71, 0x8f, 0xf0, 0x03, 0x00, 0x05, 0x88, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc1, 0x80, 0x30, 0x03, 0x00, 0x0b, 0x04, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81, 0x80, 0x30, 0x03,
    0x00, 0x0a, 0x04, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc1,
    0x01, 0x80, 0x30, 0x03, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x06, 0x63, 0x01, 0x80, 0x30, 0x03, 0x00, 0x08, 0x04, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x33, 0x01, 0x8f, 0xf0, 0x03,
    0x00, 0x08, 0x04, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33,
    0x01, 0x87, 0xf0, 0x03, 0x00, 0x08, 0x04, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0xe3, 0x01, 0x80, 0x30, 0x03, 0x00, 0x08, 0x04, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x01, 0x01, 0x80, 0x30, 0x03,
    0x00, 0x1f, 0xfe, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x01,
    0x81, 0x80, 0x30, 0x03, 0x00, 0x04, 0x10, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x10, 0xc1, 0x80, 0x30, 0x03, 0x00, 0x04, 0x10, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x70, 0x61, 0x8f, 0xf1, 0xff,
    0x00, 0x04, 0x10, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0,
    0x3f, 0x8f, 0xf1, 0xff, 0x00, 0x04, 0x10, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// Array of all bitmaps for convenience. (Total bytes used to store images in
// PROGMEM = 2640)
// static const unsigned char* menus_bitmaps[5] = {
//     epd_bitmap_menu_1, epd_bitmap_menu_2, epd_bitmap_menu_3,
//     epd_bitmap_menu_4, epd_bitmap_menu_5};
static const unsigned char* menus_bitmaps[4] = {
    epd_bitmap_menu_1, epd_bitmap_menu_2, epd_bitmap_menu_3, epd_bitmap_menu_5};
// static const unsigned char* menus_bitmaps[] = {epd_bitmap_menu_1,
//                                                epd_bitmap_menu_2};
