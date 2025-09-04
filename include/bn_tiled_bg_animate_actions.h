//zlib License
//
//(C) 2020-2025 Javier Sánchez
//
//This software is provided 'as-is', without any express or implied
//warranty. In no event will the authors be held liable for any damages
//arising from the use of this software.
//
//Permission is granted to anyone to use this software for any purpose,
//including commercial applications, and to alter it and redistribute it
//freely, subject to the following restrictions:
//
//1. The origin of this software must not be misrepresented; you must not
//   claim that you wrote the original software. If you use this software
//   in a product, an acknowledgment in the product documentation would be
//   appreciated but is not required.
//2. Altered source versions must be plainly marked as such, and must not be
//   misrepresented as being the original software.
//3. This notice may not be removed or altered from any source distribution.

#ifndef BN_TILED_BG_ANIMATE_ACTION_H
#define BN_TILED_BG_ANIMATE_ACTION_H

#include "bn_array.h"
#include "bn_vector.h"
#include "bn_limits.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_item.h"

namespace bn{

class itiled_bg_animate_action{
public:
    itiled_bg_animate_action(const itiled_bg_animate_action& other) = delete;

    void update()
    {
        BN_ASSERT(! done(), "Action is done");

        if(_current_wait_updates)
        {
            --_current_wait_updates;
        }
        else
        {
            const bn::ivector<uint16_t>& graphics_indexes = this->graphics_indexes();
            int current_graphics_indexes_index = _current_graphics_indexes_index;
            int current_graphics_index = graphics_indexes[current_graphics_indexes_index];
            _current_wait_updates = _wait_updates;

            if(current_graphics_indexes_index == 0 ||
                    graphics_indexes[current_graphics_indexes_index - 1] != current_graphics_index)
            {
                _bg_ref->set_tiles(_tiles_item_ref[current_graphics_index]);
            }

            if(_forever && current_graphics_indexes_index == graphics_indexes.size() - 1)
            {
                _current_graphics_indexes_index = 0;
            }
            else
            {
                ++_current_graphics_indexes_index;
            }
        }
    }

    [[nodiscard]] bool done() const
    {
        return _current_graphics_indexes_index == _graphics_indexes_ref->size();
    }

    void reset()
    {
        _current_graphics_indexes_index = 0;
        _current_wait_updates = 0;
    }

    [[nodiscard]] const bn::regular_bg_ptr& regular_bg() const
    {
        return *_bg_ref;
    }

    [[nodiscard]] int wait_updates() const
    {
        return _wait_updates;
    }

    void set_wait_updates(int wait_updates){
        BN_ASSERT(wait_updates >= 0, "Invalid wait updates: ", wait_updates);
        BN_ASSERT(wait_updates <= std::numeric_limits<decltype(_wait_updates)>::max(),
                "Too many wait updates: ", wait_updates);

        _wait_updates = uint16_t(wait_updates);

        if(wait_updates < _current_wait_updates)
        {
            _current_wait_updates = uint16_t(wait_updates);
        }
    }

    [[nodiscard]] int next_change_updates() const
    {
        return _current_wait_updates;
    }

    void set_next_change_updates(int next_change_updates){
        BN_ASSERT(next_change_updates >= 0 && next_change_updates <= _wait_updates,
                "Invalid next change updates: ", next_change_updates, " - ", _wait_updates);

        _current_wait_updates = next_change_updates;
    }

    [[nodiscard]] const bn::regular_bg_tiles_item& tiles_item() const
    {
        return *_tiles_item_ref;
    }

    [[nodiscard]] const bn::ivector<uint16_t>& graphics_indexes() const
    {
        return *_graphics_indexes_ref;
    }

    [[nodiscard]] bool update_forever() const
    {
        return _forever;
    }

    [[nodiscard]] int current_index() const
    {
        return _current_graphics_indexes_index;
    }

    void set_current_index(int current_index){
        const bn::ivector<uint16_t>& graphics_indexes = this->graphics_indexes();
        int num_graphics_indexes = graphics_indexes.size();

        if(_forever)
        {
            BN_ASSERT(current_index >= 0 && current_index < num_graphics_indexes,
                    "Invalid current index: ", current_index, " - ", num_graphics_indexes);

            _current_graphics_indexes_index = current_index;
        }
        else
        {
            BN_ASSERT(current_index >= 0 && current_index <= num_graphics_indexes,
                    "Invalid current index: ", current_index, " - ", num_graphics_indexes);

            _current_graphics_indexes_index = current_index;

            if(current_index == num_graphics_indexes)
            {
                --current_index;
            }
        }

        _bg_ref->set_tiles(_tiles_item_ref[current_index]);
    }

    [[nodiscard]] int current_graphics_index() const
    {
        return graphics_indexes()[_current_graphics_indexes_index];
    }

protected:
    itiled_bg_animate_action() = default;

    void _set_refs(bn::regular_bg_ptr& bg, bn::regular_bg_tiles_item* tiles_item, bn::ivector<uint16_t>& graphics_indexes){
        _bg_ref = &bg;
        _tiles_item_ref = tiles_item;
        _graphics_indexes_ref = &graphics_indexes;
    }

    void _assign(const itiled_bg_animate_action& other){
        _wait_updates = other._wait_updates;
        _current_graphics_indexes_index = other._current_graphics_indexes_index;
        _current_wait_updates = other._current_wait_updates;
        _forever = other._forever;
    }

    void _set_update_forever(bool forever)
    {
        _forever = forever;
    }

    void _assign_graphics_indexes(const bn::span<const uint16_t>& graphics_indexes){
        BN_ASSERT(graphics_indexes.size() > 1 && graphics_indexes.size() <= _graphics_indexes_ref->max_size(),
                "Invalid graphics indexes count: ", graphics_indexes.size(), " - ", _graphics_indexes_ref->max_size());

        for(uint16_t graphics_index : graphics_indexes)
        {
            _graphics_indexes_ref->push_back(graphics_index);
        }
    }

    void _assign_graphics_indexes(const bn::ivector<uint16_t>& graphics_indexes){
        BN_ASSERT(graphics_indexes.size() > 1 && graphics_indexes.size() <= _graphics_indexes_ref->max_size(),
                "Invalid graphics indexes count: ", graphics_indexes.size(), " - ", _graphics_indexes_ref->max_size());

        *_graphics_indexes_ref = graphics_indexes;
    }

private:
    bn::regular_bg_ptr* _bg_ref = nullptr;
    bn::regular_bg_tiles_item* _tiles_item_ref = nullptr;
    bn::ivector<uint16_t>* _graphics_indexes_ref = nullptr;
    uint16_t _wait_updates = 0;
    uint16_t _current_graphics_indexes_index = 0;
    uint16_t _current_wait_updates = 0;
    bool _forever = true;
};


template<int MaxSize>
class tiled_bg_animate_action: public itiled_bg_animate_action{
    static_assert(MaxSize > 1);
public:
    [[nodiscard]] static tiled_bg_animate_action once(
            const bn::regular_bg_ptr& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item,
            const bn::span<const uint16_t>& graphics_indexes)
    {
        return tiled_bg_animate_action(regular_bg, wait_updates, tiles_item, false, graphics_indexes);
    }

    [[nodiscard]] static tiled_bg_animate_action once(
            bn::regular_bg_ptr&& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item,
            const bn::span<const uint16_t>& graphics_indexes)
    {
        return tiled_bg_animate_action(std::move(regular_bg), wait_updates, tiles_item, false, graphics_indexes);
    }

    [[nodiscard]] static tiled_bg_animate_action forever(
            const bn::regular_bg_ptr& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item,
            const bn::span<const uint16_t>& graphics_indexes)
    {
        return tiled_bg_animate_action(regular_bg, wait_updates, tiles_item, true, graphics_indexes);
    }

    [[nodiscard]] static tiled_bg_animate_action forever(
            bn::regular_bg_ptr&& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item,
            const bn::span<const uint16_t>& graphics_indexes)
    {
        return tiled_bg_animate_action(std::move(regular_bg), wait_updates, tiles_item, true, graphics_indexes);
    }

    tiled_bg_animate_action(const tiled_bg_animate_action& other) :
        _regular_bg(other._regular_bg),
        _tiles_item(other._tiles_item),
        _graphics_indexes(other._graphics_indexes)
    {
        this->_set_refs(_regular_bg, _tiles_item, _graphics_indexes);
        this->_assign(other);
    }

    tiled_bg_animate_action(tiled_bg_animate_action&& other) noexcept :
        _regular_bg(std::move(other._regular_bg)),
        _tiles_item(other._tiles_item),
        _graphics_indexes(other._graphics_indexes)
    {
        this->_set_refs(_regular_bg, _tiles_item, _graphics_indexes);
        this->_assign(other);
    }

    tiled_bg_animate_action(const itiled_bg_animate_action& other) :
        _regular_bg(other.regular_bg()),
        _tiles_item(other.tiles_item()),
        _graphics_indexes(other.graphics_indexes())
    {
        BN_ASSERT(other.graphics_indexes().size() <= MaxSize,
                  "Too many graphics indexes: ", other.graphics_indexes().size(), " - ", MaxSize);

        this->_set_refs(_regular_bg, _tiles_item, _graphics_indexes);
        this->_assign(other);
    }

    tiled_bg_animate_action& operator=(const tiled_bg_animate_action& other)
    {
        if(this != &other)
        {
            _regular_bg = other._regular_bg;
            _tiles_item = other._tiles_item;
            _graphics_indexes = other._graphics_indexes;
            this->_assign(other);
        }

        return *this;
    }

    tiled_bg_animate_action& operator=(tiled_bg_animate_action&& other) noexcept
    {
        if(this != &other)
        {
            _regular_bg = std::move(other._regular_bg);
            _tiles_item = other._tiles_item;
            _graphics_indexes = other._graphics_indexes;
            this->_assign(other);
        }

        return *this;
    }

    tiled_bg_animate_action& operator=(const itiled_bg_animate_action& other)
    {
        static_cast<itiled_bg_animate_action&>(*this) = other;
        return *this;
    }

    tiled_bg_animate_action& operator=(itiled_bg_animate_action&& other) noexcept
    {
        static_cast<itiled_bg_animate_action&>(*this) = std::move(other);
        return *this;
    }


private:
    bn::regular_bg_ptr _regular_bg;
    bn::regular_bg_tiles_item* _tiles_item;
    bn::vector<uint16_t, MaxSize> _graphics_indexes;

    tiled_bg_animate_action(const bn::regular_bg_ptr& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item,
                          bool forever, const bn::span<const uint16_t>& graphics_indexes) :
        _regular_bg(regular_bg),
        _tiles_item(tiles_item)
    {
        this->_set_refs(_regular_bg, _tiles_item, _graphics_indexes);
        this->_set_update_forever(forever);
        this->set_wait_updates(wait_updates);
        this->_assign_graphics_indexes(graphics_indexes);
    }

    tiled_bg_animate_action(bn::regular_bg_ptr&& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item, bool forever,
                          const bn::span<const uint16_t>& graphics_indexes) :
        _regular_bg(std::move(regular_bg)),
        _tiles_item(tiles_item)
    {
        this->_set_refs(_regular_bg, _tiles_item, _graphics_indexes);
        this->_set_update_forever(forever);
        this->set_wait_updates(wait_updates);
        this->_assign_graphics_indexes(graphics_indexes);
    }
};



template<typename ...Args>
[[nodiscard]] auto create_tiled_bg_animate_action_once(
        const bn::regular_bg_ptr& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item, Args ...graphics_indexes)
{
    return tiled_bg_animate_action<sizeof...(Args)>::once(
                regular_bg, wait_updates, tiles_item,
                bn::array<uint16_t, sizeof...(Args)>{{ uint16_t(graphics_indexes)... }});
}


template<typename ...Args>
[[nodiscard]] auto create_tiled_bg_animate_action_once(
        bn::regular_bg_ptr&& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item, Args ...graphics_indexes)
{
    return tiled_bg_animate_action<sizeof...(Args)>::once(
                std::move(regular_bg), wait_updates, tiles_item,
                bn::array<uint16_t, sizeof...(Args)>{{ uint16_t(graphics_indexes)... }});
}


template<typename ...Args>
[[nodiscard]] auto create_tiled_bg_animate_action_forever(
        const bn::regular_bg_ptr& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item, Args ...graphics_indexes)
{
    return tiled_bg_animate_action<sizeof...(Args)>::forever(
                regular_bg, wait_updates, tiles_item,
                bn::array<uint16_t, sizeof...(Args)>{{ uint16_t(graphics_indexes)... }});
}


template<typename ...Args>
[[nodiscard]] auto create_tiled_bg_animate_action_forever(
        bn::regular_bg_ptr&& regular_bg, int wait_updates, bn::regular_bg_tiles_item* tiles_item, Args ...graphics_indexes)
{
    return tiled_bg_animate_action<sizeof...(Args)>::forever(
                std::move(regular_bg), wait_updates, tiles_item,
                bn::array<uint16_t, sizeof...(Args)>{{ uint16_t(graphics_indexes)... }});
}


}

#endif