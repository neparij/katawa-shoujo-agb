#ifndef KONAMI_CODE_H
#define KONAMI_CODE_H

#include "bn_array.h"
#include "bn_keypad.h"

constexpr bn::array<bn::keypad::key_type, 10> konami_code = {
    bn::keypad::key_type::UP,
    bn::keypad::key_type::UP,
    bn::keypad::key_type::DOWN,
    bn::keypad::key_type::DOWN,
    bn::keypad::key_type::LEFT,
    bn::keypad::key_type::RIGHT,
    bn::keypad::key_type::LEFT,
    bn::keypad::key_type::RIGHT,
    bn::keypad::key_type::B,
    bn::keypad::key_type::A
};

constexpr bn::array<bn::keypad::key_type, 10> all_keys = {
    bn::keypad::key_type::A,
    bn::keypad::key_type::B,
    bn::keypad::key_type::SELECT,
    bn::keypad::key_type::START,
    bn::keypad::key_type::RIGHT,
    bn::keypad::key_type::LEFT,
    bn::keypad::key_type::UP,
    bn::keypad::key_type::DOWN,
    bn::keypad::key_type::L,
    bn::keypad::key_type::R
};

void update_konami_code();

#endif //KONAMI_CODE_H
