#ifndef BACKGROUND_META_H
#define BACKGROUND_META_H

namespace ks {

    class background_meta {
    public:
        constexpr background_meta(const bn::regular_bg_item &bg_item, const bn::sprite_item &thumbnail_item, const unsigned int hash_id) :
            bg{bg_item},
            thumbnail{thumbnail_item},
            hash{hash_id} {

        }

        bn::regular_bg_item bg;
        bn::sprite_item thumbnail;
        const unsigned int hash;
    };

    // static bn::vector<const background_meta*, 512> bg_meta_ptrs;

    class auto_register_background {
        public:
        explicit auto_register_background(const background_meta *bg) {
            // BN_LOG("Registering background: ", bg->hash);
            // bg_meta_ptrs.push_back(bg);
            // auto &backgrounds = ks::globals::backgrounds;
            // backgrounds.push_back(bg);

        }
    };
}

#endif //BACKGROUND_META_H
