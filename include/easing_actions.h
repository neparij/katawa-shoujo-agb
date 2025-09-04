#ifndef KS_EASING_ACTIONS_H
#define KS_EASING_ACTIONS_H

#include "bn_assert.h"
#include "bn_limits.h"
#include "bn_fixed_point.h"
#include "bn_regular_bg_ptr.h"

using easing_t = unsigned char;
#define EASING_SMOOTHSTEP ((easing_t)0)
#define EASING_QUAD_IN ((easing_t)1)
#define EASING_QUAD_OUT ((easing_t)2)
#define EASING_QUAD_IN_OUT ((easing_t)3)
#define EASING_CUBIC_IN ((easing_t)4)
#define EASING_CUBIC_OUT ((easing_t)5)
#define EASING_CUBIC_IN_OUT ((easing_t)6)


template<typename Value, class PropertyManager>
class easing_to_value_template_action
{

public:
    void reset()
    {
        PropertyManager::set(_initial_property, _value);
        _current_update = 0;
    }

    void update()
    {
        BN_ASSERT(! done(), "Action is done");

        ++_current_update;

        if(_current_update == _duration_updates || _initial_property == _final_property)
        {
            PropertyManager::set(_final_property, _value);
        }
        else
        {
            const auto t = static_cast<float>(_current_update) / _duration_updates;
            const float easing_value = get_easing_value(t);

            const auto p = bn::fixed_point(
                _initial_property.x() + static_cast<int>((_final_property.x() - _initial_property.x()).to_float() * easing_value),
                _initial_property.y() + static_cast<int>((_final_property.y() - _initial_property.y()).to_float() * easing_value)
            );
            PropertyManager::set(p, _value);
        }
    }

    [[nodiscard]] bool done() const
    {
        return _current_update == _duration_updates;
    }

    [[nodiscard]] int duration_updates() const
    {
        return _duration_updates;
    }

protected:
    easing_to_value_template_action(const Value& value, const easing_t easing_func, int duration_updates, const bn::fixed_point& final_property) :
        _value(value),
        _final_property(final_property),
        _initial_property(PropertyManager::get(_value)),
        _duration_updates(duration_updates),
        _easing_func(easing_func)
    {
    }

    easing_to_value_template_action(Value&& value, const easing_t easing_func, int duration_updates, const bn::fixed_point& final_property) :
        _value(move(value)),
        _final_property(final_property),
        _initial_property(PropertyManager::get(_value)),
        _duration_updates(duration_updates),
        _easing_func(easing_func)
    {
    }

    [[nodiscard]] const Value& value() const
    {
        return _value;
    }

    [[nodiscard]] const bn::fixed_point& final_property() const
    {
        return _final_property;
    }

private:
    [[nodiscard]] float get_easing_value(const float t) const {
        switch (_easing_func) {
            case EASING_SMOOTHSTEP:
                return t * (t * (3.0f - 2.0f * t));
            case EASING_QUAD_IN:
                return t * t;
            case EASING_QUAD_OUT:
                return t * (2.0f - t);
            case EASING_QUAD_IN_OUT:
                return t < 0.5f ? 2.0f * t * t : -1.0f + (4.0f - 2.0f * t) * t;
            case EASING_CUBIC_IN:
                return t * t * t;
            case EASING_CUBIC_OUT:
                return 1.0f - (1.0f - t) * (1.0f - t) * (1.0f - t);
            case EASING_CUBIC_IN_OUT:
                return t < 0.5f ? 4.0f * t * t * t : 1.0f - (-2.0f * t + 2.0f) * (-2.0f * t + 2.0f) * (-2.0f * t + 2.0f) / 2.0f;
            default:
                return t;
        }
    }

    uint16_t _current_update = 0;
    Value _value;
    bn::fixed_point _final_property;
    bn::fixed_point _initial_property;
    int _duration_updates;
    easing_t _easing_func;
};




class regular_bg_move_to_easing_action :
        public easing_to_value_template_action<bn::regular_bg_ptr, bn::regular_bg_position_manager>
{

public:
    regular_bg_move_to_easing_action(const bn::regular_bg_ptr& bg, const easing_t easing, int duration_updates, bn::fixed final_x, bn::fixed final_y) :
        easing_to_value_template_action(bg, easing, duration_updates, bn::fixed_point(final_x, final_y))
    {
    }

    regular_bg_move_to_easing_action(bn::regular_bg_ptr&& bg, const easing_t easing, int duration_updates, bn::fixed final_x, bn::fixed final_y) :
        easing_to_value_template_action(move(bg), easing, duration_updates, bn::fixed_point(final_x, final_y))
    {
    }

    regular_bg_move_to_easing_action(const bn::regular_bg_ptr& bg, const easing_t easing, int duration_updates, const bn::fixed_point& final_position) :
        easing_to_value_template_action(bg, easing, duration_updates, final_position)
    {
    }

    regular_bg_move_to_easing_action(bn::regular_bg_ptr&& bg, const easing_t easing, int duration_updates, const bn::fixed_point& final_position) :
        easing_to_value_template_action(move(bg), easing, duration_updates, final_position)
    {
    }

    [[nodiscard]] const bn::regular_bg_ptr& bg() const
    {
        return value();
    }

    [[nodiscard]] const bn::fixed_point& final_position() const
    {
        return final_property();
    }
};


#endif //KS_EASING_ACTIONS_H
