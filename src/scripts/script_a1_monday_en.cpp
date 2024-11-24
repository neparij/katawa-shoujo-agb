#include "script_a1_monday.h"
namespace ks {
    class ScriptA1MondayEn : public ScriptA1Monday {
        public:
            static void a1_monday_out_cold() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                bn::optional<bn::regular_bg_ptr> main_bg;
                ks::SceneManager scene(main_bg);
            
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::op_snowywoods));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("", "A light breeze causes the naked branches overhead to rattle like wooden windchimes."));
                scene.add_sequence(ks::DialogItem("", "This is a popular retreat for couples in the summer. The deciduous trees provide a beautiful green canopy, far out of sight of teachers and fellow students."));
                scene.add_sequence(ks::DialogItem("", "But now, in late winter, it feels like I'm standing under a pile of kindling."));
                scene.add_sequence(ks::DialogItem("", "I breathe into my cupped hands and rub them together furiously to prevent them from numbing in this cold."));
                scene.add_sequence(ks::DialogItem("hi", "Just how long am I expected to wait out here, anyway? I'm sure the note said 4:00 PM."));
                scene.add_sequence(ks::DialogItem("", "Ah yes… the note… slipped between the pages of my math book while I wasn't looking."));
                scene.add_sequence(ks::DialogItem("", "As far as clichés go, I'm more a fan of the letter-in-the-locker, but at least this way shows a bit of initiative."));
                scene.add_sequence(ks::DialogItem("", "As I ponder the meaning of the note, the snowfall gradually thickens."));
                scene.add_sequence(ks::DialogItem("", "The snowflakes silently falling from the white-painted sky are the only sign of time passing in this stagnant world."));
                scene.add_sequence(ks::DialogItem("", "Their slow descent upon the frozen forest makes it seem like time has slowed to a crawl."));
                scene.add_sequence(ks::DialogItem("", "The rustling of dry snow underfoot startles me, interrupting the quiet mood. Someone is approaching me from behind."));
                scene.add_sequence(ks::DialogItem("mystery", "Hi… Hisao? You came?"));
                scene.add_sequence(ks::DialogItem("", "A hesitating, barely audible question."));
                scene.add_sequence(ks::DialogItem("", "However, I recognize the owner of that dainty voice instantly."));
                scene.add_sequence(ks::DialogItem("", "I feel my heart skip a beat."));
                scene.add_sequence(ks::DialogItem("", "It's a voice I've listened to hundreds of times, but never as more than an eavesdropper to a conversation."));
                scene.add_sequence(ks::DialogItem("", "I turn to face this voice, the voice of my dreams, and my heart begins to race…"));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::other_iwanako));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("hi", "Iwanako? I got a note telling me to wait here… it was yours?"));
                scene.add_sequence(ks::DialogItem("", "Dammit. I spent all afternoon trying to come up with a good line and that was the result."));
                scene.add_sequence(ks::DialogItem("", "Pathetic."));
                scene.add_sequence(ks::DialogItem("Iwanako", "Ahmm… yes. I asked a friend to give you that note… I'm so glad you got it."));
                scene.add_sequence(ks::DialogItem("", "A shy, joyous smile that makes me so tense I couldn't move a single muscle even if I tried."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::op_snowywoods));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "My heart is pounding now, as if it were trying to burst out from my chest and claim this girl for itself."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::other_iwanako));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("hi", "So… ah… here we are. Out in the cold…"));
                scene.add_sequence(ks::DialogItem("", "Once again, the wind stirs up the branches. The cacophonous noise is music to my ears."));
                scene.add_sequence(ks::DialogItem("", "Iwanako flinches ever so softly against the gust of wind."));
                scene.add_sequence(ks::DialogItem("", "As it passes, she rights herself, as if supported by some new confidence."));
                scene.add_sequence(ks::DialogItem("", "Her eyes lock with mine and she lazily twirls her long, dark hair around her finger."));
                scene.add_sequence(ks::DialogItem("", "All the while, the anxious beating of my heart grows louder."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::op_snowywoods));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "My throat is tight; I doubt I could even force a word out if I tried."));
                scene.add_sequence(ks::DialogItem("Iwanako", "You see…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("Iwanako", "…I wanted to know…"));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("Iwanako", "… if you'd go out with me…"));
                scene.add_sequence(ks::DialogItem("", "I stand there, motionless, save for my pounding heart."));
                scene.add_sequence(ks::DialogItem("", "I want to say something in reply, but my vocal cords feel like they've been stretched beyond the breaking point."));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_tragic));
                scene.add_sequence(ks::DialogItem("Iwanako", "… Hisao?"));
                scene.add_sequence(ks::DialogItem("", "I reach up to try to massage my throat, but this only sends spikes of blinding pain along my arms."));
                scene.add_sequence(ks::DialogItem("Iwanako", "Hisao?!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "My whole body freezes, save for my eyes, which shoot open in terror."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("Iwanako", "HISAO!"));
                scene.add_sequence(ks::DialogItem("", "The beating in my chest suddenly stops, and I go weak at the knees."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::passoutOP1, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("n", "{vspace=210}The world around me - the canopy of bare branches, the dull winter sky, Iwanako running towards me - all these fade to black."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}The last things I remember before slipping away are the sounds of Iwanako screaming for help and the incessant clatter of the branches above…"));
                // bn::vector<ks::ConditionItem, 1> a1_monday_out_cold__condition_0;
                // a1_monday_out_cold__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayEn::a1_monday_out_cold__condition_0_0));
                // scene.add_condition(a1_monday_out_cold__condition_0);
                scene.start();
            
                while(!scene.is_finished()) {
                    scene.update();
                    bn::core::update();
                }
            }
            static void a1_monday_bundle_of_hisao() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                bn::optional<bn::regular_bg_ptr> main_bg;
                ks::SceneManager scene(main_bg);
            
                scene.add_sequence(ks::DialogItem("centered", "It's been four months since my heart attack."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hosp_room));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::sakura, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hospitalmask, ks::SpriteEventType::None));
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(0.5, 0.0, channel="music")"));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("n", "{vspace=60}In that whole time, I can probably count the times I've left this hospital room unsupervised on one hand."));
                scene.add_sequence(ks::DialogItem("n", "Four months is a pretty long time when you're left alone with your thoughts. So, I've had plenty of time to come to terms with my situation."));
                scene.add_sequence(ks::DialogItem("n", "Arrhythmia."));
                scene.add_sequence(ks::DialogItem("n", "A strange word. A foreign, alien one. One that you don't want to be in the same room with."));
                scene.add_sequence(ks::DialogItem("n", "A rare condition. It causes the heart to act erratically and occasionally beat way too fast. It can be fatal."));
                scene.add_sequence(ks::DialogItem("n", "Apparently, I've had it for a long time. They said it was a miracle that I was able to go on so long without anything happening."));
                scene.add_sequence(ks::DialogItem("n", "Is that really a miracle? I guess it was supposed to make me feel better, more appreciative of my life."));
                scene.add_sequence(ks::DialogItem("n", "It really didn't do anything to cheer me up."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=150}My parents, I think, were hit harder by the news than I was. They practically had two hemorrhages apiece."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}I had already had a full day by then to digest everything. To them, it was all fresh. They were even willing to sell our house in order to pay for a cure."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=60}Of course there isn't a cure."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Because of the late discovery of this… condition, I've had to stay at the hospital, to recuperate from the treatments."));
                scene.add_sequence(ks::DialogItem("n", "When I was first admitted, it felt as if I was missed…"));
                scene.add_sequence(ks::DialogItem("n", "For about a week, my room in the ward was full of flowers, balloons and cards."));
                scene.add_sequence(ks::DialogItem("n", "But, the visitors soon dwindled and all the get-well gifts began trickling down to nothing shortly after."));
                scene.add_sequence(ks::DialogItem("n", "I realized that the only reason I had gotten so many cards and flowers was because sending me their sympathy had been turned into a class project."));
                scene.add_sequence(ks::DialogItem("n", "Maybe some people were genuinely concerned, but I doubt it. Even in the beginning, I barely had visitors. By the end of the first month, only my parents came by on a regular basis."));
                scene.add_sequence(ks::DialogItem("n", "Iwanako was the last to stop visiting."));
                scene.add_sequence(ks::DialogItem("n", "After six weeks, I never saw her again. We never had that much to talk about when she visited, anyway."));
                scene.add_sequence(ks::DialogItem("n", "We didn't touch the subject that was between us on that snowy day ever again."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}The hospital?"));
                scene.add_sequence(ks::DialogItem("n", "It's not really a place I'd like to live in."));
                scene.add_sequence(ks::DialogItem("n", "The doctors and nurses feel so impersonal and faceless."));
                scene.add_sequence(ks::DialogItem("n", "I guess it's because they are in a hurry and they have a million other patients waiting for them, but it makes me feel uncomfortable."));
                scene.add_sequence(ks::DialogItem("n", "For the first month or so, I asked the head cardiologist every time I saw him for a rough estimate of when I'd be able to leave."));
                scene.add_sequence(ks::DialogItem("n", "He never answered anything in a straightforward way, but told me to wait and see if the treatment and surgeries worked."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}So, I idly observed the scar that those surgeries had left on my chest slowly change its appearance over time, thinking of it as some kind of an omen."));
                scene.add_sequence(ks::DialogItem("n", "I still ask the head cardiologist about leaving, but my expectations are low enough now that I'm not disappointed any more when I don't get a reply. The way he shuffles around the answer shows that there is at least some hope."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=120}At some point I stopped watching TV. I don't know why, I just did."));
                scene.add_sequence(ks::DialogItem("n", "Maybe it was the wrong kind of escapism for my situation."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}I started reading instead. There was a small 'library' at the hospital, although it was more like a storeroom for books. I began working my way through it, one small stack at a time. After consuming them, I would go back for more."));
                scene.add_sequence(ks::DialogItem("n", "I found that I liked reading and I think I even became a bit addicted. I started feeling naked without a book in my hands."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}But I loved the stories."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}That was what my life was like."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}The days became increasingly harder to distinguish from each other, differing only by the book I was reading and the weather outside. It felt like time blurred into some kind of gooey mass I was trapped inside, instead of moving within."));
                scene.add_sequence(ks::DialogItem("n", "A week could go by without me really noticing it."));
                scene.add_sequence(ks::DialogItem("n", "Sometimes, I'd pause in realization that I didn't know what day of the week it was."));
                scene.add_sequence(ks::DialogItem("n", "But other times, all the things that surrounded me would painfully crash into my consciousness, through the barrier of nonchalance I had set up for myself."));
                scene.add_sequence(ks::DialogItem("n", "The pages of my book would start to feel sharp and burning hot and the heaviness in my chest would become so hard to bear that I had to put the book aside and just lay down for a while, looking at the ceiling as if I was going to cry."));
                scene.add_sequence(ks::DialogItem("n", "But that happened only rarely."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}And I couldn't even cry."));
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(1.0, 1.0, channel="music")"));
                scene.add_sequence(ks::DialogItem("", "Today, the doctor comes in and gives me a smile. He seems excited, but not very. It's like he is trying to make an effort to be happy on my behalf."));
                scene.add_sequence(ks::DialogItem("", "My parents are here. It's been a few days since I've last seen them. Both of them are even sort of dressed up. Is this supposed to be some kind of special occasion? It's not a party."));
                scene.add_sequence(ks::DialogItem("", "There is this ritual the head cardiologist has. He takes his time, sorting his papers, then setting them aside as if to make a point of the pointlessness of what he just did."));
                scene.add_sequence(ks::DialogItem("", "Then he casually sits down on the edge of the bed next to mine. He looks me in the eyes for a moment."));
                scene.add_sequence(ks::DialogItem("Doctor", "Hello, Hisao. How are you today?"));
                scene.add_sequence(ks::DialogItem("", "I don't answer him but I smile a little, back at him."));
                scene.add_sequence(ks::DialogItem("Doctor", "I believe that you can go home; your heart is stronger now, and with some precautions, you should be fine."));
                scene.add_sequence(ks::DialogItem("Doctor", "We have all your medication sorted out. I'll give your father the prescription."));
                scene.add_sequence(ks::DialogItem("", "The doctor hands a sheet of paper to my dad, whose expression turns wooden as he reads it quickly."));
                scene.add_sequence(ks::DialogItem("Dad", "So many…"));
                scene.add_sequence(ks::DialogItem("", "I take it from his hand and take a look myself, feeling numb. How am I supposed to react to this?"));
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(0.5, 2.0, channel="music")"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::drugs:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "The absurdly long list of medications staring back at me from the paper seems insurmountable. They all blend together in a sea of letters."));
                scene.add_sequence(ks::DialogItem("", "This is insane."));
                scene.add_sequence(ks::DialogItem("", "Side effects, adverse effects, contraindications and dosages are listed line after line with cold precision."));
                scene.add_sequence(ks::DialogItem("", "I try to read them, but it's so futile."));
                scene.add_sequence(ks::DialogItem("", "I can't understand any of it. Attempting to only makes me feel sicker."));
                scene.add_sequence(ks::DialogItem("", "All this… for the rest of my life, every day?"));
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(1.0, 1.0, channel="music")"));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hosp_room));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::sakura, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hospitalmask, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("Doctor", "I'm afraid that is the best we can do at this point."));
                scene.add_sequence(ks::DialogItem("Doctor", "However, new medications are always being developed, so I wouldn't be surprised to see that list fade over the years."));
                scene.add_sequence(ks::DialogItem("", "Years… What kind of confidence booster is that? I'd have felt better if he hadn't said anything at all…"));
                scene.add_sequence(ks::DialogItem("Doctor", "Also, I've spoken with your parents and we believe that it would be best if you don't return to your old school."));
                scene.add_sequence(ks::DialogItem("", "What!?"));
                scene.add_sequence(ks::DialogItem("Dad", "Please, calm down, Hisao. Listen to what the doctor has to say…"));
                scene.add_sequence(ks::DialogItem("", "Calm down? The way he says it tells me he knew full well that I wouldn't like it. Am I going to be home schooled?"));
                scene.add_sequence(ks::DialogItem("", "Whatever of my concern shows, it's ignored."));
                scene.add_sequence(ks::DialogItem("Doctor", "We all understand that your education is paramount; however, I don't think that it's wise for you to be without supervision."));
                scene.add_sequence(ks::DialogItem("Doctor", "At least not until we're sure that your medication is suitable."));
                scene.add_sequence(ks::DialogItem("Doctor", "So, I've spoken to your parents about a transfer."));
                scene.add_sequence(ks::DialogItem("Doctor", "It's a school called Yamaku Academy that specializes in dealing with disabled students."));
                scene.add_sequence(ks::DialogItem("", "Disabled? What? Am I…"));
                scene.add_sequence(ks::DialogItem("Doctor", "It has a 24-hour nursing staff and it's only a few minutes from a highly regarded general hospital. The majority of students live on the campus."));
                scene.add_sequence(ks::DialogItem("Doctor", "Think of it as a boarding school of sorts. It's designed to give students a degree of independence, while keeping help nearby."));
                scene.add_sequence(ks::DialogItem("", "Independence? It's a school for disabled kids. Don't try to disguise that fact."));
                scene.add_sequence(ks::DialogItem("", "If it was really that 'free,' there wouldn't be a 24-hour nursing staff, and you wouldn't make a hospital being nearby a selling point."));
                scene.add_sequence(ks::DialogItem("Dad", "Of course, that's only if you want to go. But… your mother and I aren't really able to home school you."));
                scene.add_sequence(ks::DialogItem("Dad", "We went out there and had a look a couple of weeks back; I think you'd like it."));
                scene.add_sequence(ks::DialogItem("", "It looks like I really don't have a choice."));
                scene.add_sequence(ks::DialogItem("Doctor", "Compared to other heart problems, people with your condition usually tend to live long lives. You'll need a job one day and this is a good opportunity to continue your education."));
                scene.add_sequence(ks::DialogItem("", "This isn't an opportunity, don't call it an opportunity. Don't call it a goddamned opportunity."));
                scene.add_sequence(ks::DialogItem("Doctor", "Well, you should be excited at the chance to go back to school. I remember you wanted to return to school, and while it's not the same one…"));
                scene.add_sequence(ks::DialogItem("", "A special school. That's…"));
                scene.add_sequence(ks::DialogItem("", "An insult. That is what I want to say. It's a step down."));
                scene.add_sequence(ks::DialogItem("Dad", "It's not what you think. All of the students there are pretty active, in their own sort of way."));
                scene.add_sequence(ks::DialogItem("Dad", "It's geared towards students that can still get around and learn, but just need a little help… in one way or another."));
                scene.add_sequence(ks::DialogItem("Doctor", "Your father's right. And many of the graduates of the school have gone on to do amazing things. A person doesn't have to be held back by their disability."));
                scene.add_sequence(ks::DialogItem("Doctor", "One of my colleagues in another hospital is a graduate."));
                scene.add_sequence(ks::DialogItem("", "I don't care. A person doesn't have to be held back by their disability? That's what a disability is."));
                scene.add_sequence(ks::DialogItem("", "I really hate that something so important was decided for me. But what can I do about it? A 'normal' life is out of the question now."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "It's funny, I had always thought my life was actually kind of boring, but now I miss it."));
                scene.add_sequence(ks::DialogItem("", "I want to protest. I want to blame this lack of reaction on shock, or fatigue. I could easily yell out something now - something about how I can go back to school anyway. But, no."));
                scene.add_sequence(ks::DialogItem("", "I don't say anything. The fact is that I know now it's futile."));
                scene.add_sequence(ks::DialogItem("", "I look around the room, feeling very tired of all this. The hospital, doctors, my condition, everything. I don't see anything that would make me feel any different."));
                scene.add_sequence(ks::DialogItem("", "There really isn't a choice. I know this, but the thought of going to a disabled school… what are those even like? As much as I try to put a positive spin on this, it's very difficult."));
                scene.add_sequence(ks::DialogItem("", "But let me try."));
                scene.add_sequence(ks::DialogItem("", "A clean slate isn't a bad thing."));
                scene.add_sequence(ks::DialogItem("", "That is all I can think of to get me through this. At least I still have something; even if it's a 'special school,' it's something. It's a fresh start, and my life isn't over. It would be a mistake to just resign myself to thinking that."));
                scene.add_sequence(ks::DialogItem("", "At the very least, I'll try to see what my new life will look like."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_bundle_of_hisao__condition_0;
                // a1_monday_bundle_of_hisao__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayEn::a1_monday_bundle_of_hisao__condition_0_0));
                // scene.add_condition(a1_monday_bundle_of_hisao__condition_0);
                scene.start();
            
                while(!scene.is_finished()) {
                    scene.update();
                    bn::core::update();
                }
            }
            static void a1_monday_gateway_effect() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                bn::optional<bn::regular_bg_ptr> main_bg;
                ks::SceneManager scene(main_bg);
            
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_gate));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_happiness));
                scene.add_sequence(ks::DialogItem("", "The gate looked far too pompous for what it was."));
                scene.add_sequence(ks::DialogItem("", "In fact, gates in general seem to do that, but this one especially so."));
                scene.add_sequence(ks::DialogItem("", "Red bricks, black wrought iron and gray plaster, assembled into a whole that didn't feel welcoming at all."));
                scene.add_sequence(ks::DialogItem("", "I wondered if it looked like what a gate for a school should look like, but couldn't really decide. Probably no."));
                scene.add_sequence(ks::DialogItem("", "Of course I didn't want to get stuck on thinking about the gate for too long, so I entered through it with a brisk pace that felt surprisingly good."));
                scene.add_sequence(ks::DialogItem("", "Moving forward feels good."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_courtyard));
                scene.add_sequence(ks::DialogItem("", "So I walk towards the main building of Yamaku Academy with this brisk pace. I'm alone, as my parents are taking my stuff to the dorms, and there's supposed to be someone waiting for me."));
                scene.add_sequence(ks::DialogItem("", "The grounds are incredibly lush, filled with green."));
                scene.add_sequence(ks::DialogItem("", "It doesn't feel like the kind of grounds a school would have, more like a park, with a clean walkway going past trees and the smell of fresh-cut grass and all other park-like things."));
                scene.add_sequence(ks::DialogItem("", "Words like 'clean' and 'hygienic' pop into my mind. It makes me shudder."));
                scene.add_sequence(ks::DialogItem("", "I shake them off. Stay open-minded now. It's your new life. You have to take it as it comes."));
                scene.add_sequence(ks::DialogItem("", "That's what I tell myself."));
                scene.add_sequence(ks::DialogItem("", "A few big buildings loom behind the leafy canopies, too big and too many for just a school."));
                scene.add_sequence(ks::DialogItem("", "Everything seems off; it's different from what I thought I knew about schools."));
                scene.add_sequence(ks::DialogItem("", "It's an uncanny valley. Even though I was told this is my new school, in the back of my head it doesn't feel like one."));
                scene.add_sequence(ks::DialogItem("", "I wonder if the feeling is real or caused by my expectations of a school for the disabled."));
                scene.add_sequence(ks::DialogItem("", "Speaking of that, I don't see anyone else here. It's kinda eerie."));
                scene.add_sequence(ks::DialogItem("", "It makes me wish there was somebody here so I could anchor myself to something tangible instead of having this feeling that I stepped into another dimension."));
                scene.add_sequence(ks::DialogItem("", "The trees hum with the wind and the green hues flashing all around me catch my attention."));
                scene.add_sequence(ks::DialogItem("", "It makes me think about hospitals again, how they say that the operating rooms are painted green because green is a calming color."));
                scene.add_sequence(ks::DialogItem("", "So why am I feeling so anxious, despite all this greenery?"));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::DialogItem("", "Only after I stand in front of the haughty main building, I surprise myself by realizing why the gate bothered me:"));
                scene.add_sequence(ks::DialogItem("", "It was the last chance I had to turn back, even if I had no life I could return to."));
                scene.add_sequence(ks::DialogItem("", "But still, after entering, there was absolutely no way I could go back any more."));
                scene.add_sequence(ks::DialogItem("", "Feeling nervous and with this realization set in my head, I open the front door."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_lobby));
                scene.add_sequence(ks::DialogItem("", "A tall man with bad posture notices me as I enter. We're the only people in the lobby, so it's only logical."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu_", "You must be… Ni… Na… Niki?"));
                scene.add_sequence(ks::DialogItem("hi", "Nakai."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu_", "So you are. Excellent. I'm your homeroom and science teacher. My name is Mutou."));
                scene.add_sequence(ks::DialogItem("mu", "Welcome."));
                scene.add_sequence(ks::DialogItem("", "We exchange a handshake that is neither firm nor sloppy, and he looks at his watch."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "The head nurse asked you for a brief check-in visit, but there's no time for that now."));
                scene.add_sequence(ks::DialogItem("hi", "Oh. Should I go later?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "Yes, afternoon is probably fine. We should get going and introduce you to the rest of the class. They're waiting already."));
                scene.add_sequence(ks::DialogItem("", "Waiting for me? I don't really like being the center of attention, but I guess it's inevitable in a situation like this."));
                scene.add_sequence(ks::DialogItem("", "Somehow, not knowing what is waiting for me makes me feel really nervous."));
                scene.add_sequence(ks::DialogItem("", "Thinking of this, I almost miss what the teacher is saying."));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0(scene);}));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_staircase2));
                scene.add_sequence(ks::DialogItem("", "My heart is pounding in my chest and it keeps me thinking about my condition as I follow the teacher up the stairs."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_hallway3));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "The third door down the third floor corridor is marked as the classroom for class 3-3."));
                scene.add_sequence(ks::DialogItem("", "Mutou opens the door and enters."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "Good morning everyone, sorry I'm late again."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "I hesitate for a split second at the door, freezing on the spot."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_gateway_effect__condition_0;
                // a1_monday_gateway_effect__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayEn::a1_monday_gateway_effect__condition_0_0));
                // scene.add_condition(a1_monday_gateway_effect__condition_0);
                scene.start();
            
                while(!scene.is_finished()) {
                    scene.update();
                    bn::core::update();
                }
            }
            static void a1_monday_enter_stage_left() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                bn::optional<bn::regular_bg_ptr> main_bg;
                ks::SceneManager scene(main_bg);
            
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_hallway3));
                scene.add_sequence(ks::DialogItem("", "Ah, get a grip! This is a big step, I know that… But there isn't any point to worrying so much about it, at least not this soon."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hisao_class));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_normal));
                scene.add_sequence(ks::DialogItem("", "I follow the teacher into the classroom and look around, partially so I won't have to meet the curious gazes of my new classmates."));
                scene.add_sequence(ks::DialogItem("", "It's pretty spacious; the ceiling is unusually high and there's lots of space left over around and inbetween the desks."));
                scene.add_sequence(ks::DialogItem("", "An entire wall taken up by blackboards and the high, old fashioned windows only make it seem larger."));
                scene.add_sequence(ks::DialogItem("", "The students' desks are just standard wooden desks with a shelf underneath for books and wooden chairs with metal frames. Simple and efficient."));
                scene.add_sequence(ks::DialogItem("", "I stop walking in front of the classroom and face the other students. They all look normal, like students in any other school. But then, why would they be here?"));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hisao_class));
                scene.add_sequence(ks::DialogItem("", "They're probably like me and have something wrong with them, only it's just not immediately obvious. Then, I notice that one of the girls seems to be missing the thumb of her right hand. It's a little jarring."));
                scene.add_sequence(ks::DialogItem("", "Despite the natural tendency to listen when someone's talking about you, I tune out the teacher's speech halfway through while he introduces me to the class."));
                scene.add_sequence(ks::DialogItem("", "I notice a flash of dark hair and see that someone is looking at me. A girl with really long, straight hair that is pretty eye-catching. As she sees me looking back at her, she covers her face with her hands as if it will make her invisible."));
                scene.add_sequence(ks::DialogItem("", "There is one boy with a cane leaning against the lockers at the rear of the class. It's weird seeing someone so young with a cane."));
                scene.add_sequence(ks::DialogItem("", "Another girl seems to be making some weird hand motions. Sign language? She peers at me over the rims of her glasses, then goes back to whatever she's doing."));
                scene.add_sequence(ks::DialogItem("", "She's kind of cute. So is the cheery-looking girl with pink hair sitting next to her. She's really hard to miss; I don't know how I didn't notice her the moment I walked in…"));
                scene.add_sequence(ks::DialogItem("mu", "…please welcome our newest classmate."));
                scene.add_sequence(ks::DialogItem("", "He claps his hands and so does everyone else, except one girl in the first row who has only one hand. I cringe a little, but hide it by bowing in thanks for this applause I did not deserve."));
                // bn::vector<ks::ConditionItem, 2> a1_monday_enter_stage_left__condition_0;
                // a1_monday_enter_stage_left__condition_0.push_back(ks::ConditionItem("wanted_introduce or _in_replay", &ScriptA1MondayEn::a1_monday_enter_stage_left__condition_0_0));
                // a1_monday_enter_stage_left__condition_0.push_back(ks::ConditionItem("None", &ScriptA1MondayEn::a1_monday_enter_stage_left__condition_0_1));
                // scene.add_condition(a1_monday_enter_stage_left__condition_0);
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hisao_class));
                scene.add_sequence(ks::DialogItem("", "I listen to the teacher as he drones about getting along while letting my gaze sweep across the classroom."));
                scene.add_sequence(ks::DialogItem("", "Everyone seems to be listening to him intently and when he's done, they clap their hands again which feels like a weird thing to do."));
                scene.add_sequence(ks::DialogItem("", "The first row girl claps on this round, with her one hand against her other wrist that ends in a bandaged stump."));
                scene.add_sequence(ks::DialogItem("", "It makes me feel a little bad."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_scienceroom));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "We're going to be doing some group work today, so that'll give you a chance to talk with everyone. Is that okay with you?"));
                scene.add_sequence(ks::DialogItem("hi", "Yeah, it's fine with me."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "That's good, you can work with Hakamichi. She is the class representative."));
                scene.add_sequence(ks::DialogItem("mu", "She can explain anything you might want to know. And who else would be able to do that better, right?"));
                scene.add_sequence(ks::DialogItem("", "How could I know?"));
                scene.add_sequence(ks::DialogItem("", "The teacher passes out the day's assignments and announces that we will be working in groups of three."));
                scene.add_sequence(ks::DialogItem("", "It hits me that I don't know who Hakamichi is. Slow. The teacher seems to catch my helpless expression."));
                scene.add_sequence(ks::DialogItem("mu", "Oh, right. Hakamichi is right there, Shizune Hakamichi."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "As he calls out her name, the cute, bubbly looking girl with bright pink hair and gold eyes waves her hand at me. I take a seat next to her, by the window."));
                scene.add_sequence(ks::DialogItem("hi", "Hey, I guess you're Hakamichi, right? It's nice to meet you."));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi_shi", "Hahaha~!"));
                scene.add_sequence(ks::DialogItem("", "What? I'm caught off guard by her laughter."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi_shi", "It's nice to meet you, too!{w=0.5} But~!"));
                scene.add_sequence(ks::DialogItem("mi_not_shi", "It's nice to meet you, too! But~!{fast}, I'm not Hakamichi, I'm Misha! This is Hakamichi. Shicchan~!"));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_shizune));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::bg, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Giggling, Misha points to the girl next to her, the one I saw using sign language before. It looks like she has been staring at me this whole time. She nods once nonchalantly to show that she acknowledges my presence… but only barely."));
                scene.add_sequence(ks::DialogItem("", "She has short, yet carefully, neatly brushed hair, a pair of oval-shaped glasses balanced on the tip of a dainty nose, and dark blue eyes that seem to alternate every few seconds between analytical and slightly bored."));
                scene.add_sequence(ks::DialogItem("hi", "It's nice to meet you."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "She immediately looks at Misha, who smiles and makes a few quick gestures with her hands."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Hakamichi nods and makes a few gestures of her own."));
                scene.add_sequence(ks::DialogItem("", "I start to wonder if the teacher was messing with me, saying things like 'you'll be able to talk to people' and 'who better to explain things to you.'"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "I can see you're a little confused, right?, right? But, I understand why you would think I was Shicchan!"));
                scene.add_sequence(ks::DialogItem("mi", "Shicchan is deaf, so I'm the person who translates things back and forth for her."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "I'm like an interpreter~! She says it's nice to meet you, too!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "You're the new student, aren't you? Well, Shicchan, of course he is! If he wasn't, he would have been standing up there for no reason, right? Right~!"));
                // bn::vector<ks::ConditionItem, 2> a1_monday_enter_stage_left__condition_1;
                // a1_monday_enter_stage_left__condition_1.push_back(ks::ConditionItem("wanted_introduce or _in_replay", &ScriptA1MondayEn::a1_monday_enter_stage_left__condition_1_0));
                // a1_monday_enter_stage_left__condition_1.push_back(ks::ConditionItem("None", &ScriptA1MondayEn::a1_monday_enter_stage_left__condition_1_1));
                // scene.add_condition(a1_monday_enter_stage_left__condition_1);
                scene.add_sequence(ks::DialogItem("mi", "We knew there was going to be a new student, but we didn't know you would be here today. So soon! Hicchan, right?"));
                scene.add_sequence(ks::DialogItem("", "Hicchan…?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Yup~! It fits, doesn't it?"));
                scene.add_sequence(ks::DialogItem("", "Did I say it out loud? It's just a surprise. I've never liked that nickname."));
                scene.add_sequence(ks::DialogItem("hi", "I don't really see how."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "It fits~! You look just like I imagined!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Hahahaha~! Yeah, you look just like a Hicchan!"));
                scene.add_sequence(ks::DialogItem("hi", "I wonder why everyone seems to think so…"));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("", "Hakamichi taps her fingers on the desk to get Misha's attention. They gesture back and forth to each other excitedly, their hands a blur."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Misha seems a little overwhelmed."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ahaha~! Er, sorry about that!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Shicchan wants you to know that she's the class rep, so if there is anything you need to know, you can feel free to ask her."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Do you like the school so far? We can show you around a little if you haven't had the time to walk around and…{w=0.5}{nw}"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("extend", "familiarize?{w=0.5}{nw}"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("extend", "yourself with it!"));
                scene.add_sequence(ks::DialogItem("", "Misha stumbles with the hard word a bit, making it stick out in her otherwise fluid translation."));
                scene.add_sequence(ks::DialogItem("hi", "Thanks, that would be pretty helpful. Yeah, I just kind of came straight to class today."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Hahaha~!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "That's no good! You should always try to learn as much as you can about where you're going before you go there. Not just with school, either~!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Always! Even if it's a trip to the convenience store! Really, Shicchan? Hahaha~!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Learn about where you're going? I guess I didn't bother to do that, or just didn't care enough to do so."));
                scene.add_sequence(ks::DialogItem("", "I didn't look forward to this, even if I committed myself to go along with it half-assedly, but anyway."));
                scene.add_sequence(ks::DialogItem("", "I don't say anything, and Misha signs something that ends in a shrug. What was that? It seems like it was about me."));
                scene.add_sequence(ks::DialogItem("", "I feel like slumping over in my seat. Both of them are smiling, but that shrug hit me unexpectedly deeply."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "You look down, are you okay?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Don't take it the wrong way, please~! I hate it when people are afraid to ask questions! That's how people learn things, by asking~!"));
                scene.add_sequence(ks::DialogItem("mi", "Asking for help is perfectly normal, as much as needing help! Stop looking like you just failed a test!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Wahahaha~!"));
                scene.add_sequence(ks::DialogItem("hi", "All right."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ah, and another thing, you don't have to call Shicchan something so formal like 'Hakamichi' or 'class rep' all the time! Just call her Shicchan~!"));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ahaha~! Okay, maybe that's too casual. Maybe 'Shizune' would be more appropriate?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_shizune));
                scene.add_sequence(ks::DialogItem("mi", "Yup, yup~! 'Shizune' is fine!"));
                scene.add_sequence(ks::DialogItem("hi", "Heh. Okay, that would be a lot easier for me."));
                scene.add_sequence(ks::DialogItem("", "I feel a lot more at ease. Both of them seem so friendly, so I feel like an idiot for being so apprehensive earlier. Especially about Shizune, who I assumed would be all business."));
                scene.add_sequence(ks::DialogItem("", "Well, she still seems like that. Just less so, I guess."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Huh? Oh, right, we haven't even touched the assignment! We should start work now, or Shicchan will get mad."));
                scene.add_sequence(ks::DialogItem("hi", "The assignment is also kind of long, so we should start now if we want to finish it before the end of class."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Wahaha~! That too!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("", "Shizune glares at the two of us impatiently. I don't need to know sign language to understand that."));
                scene.add_sequence(ks::DialogItem("hi", "Okay, okay, I get the message."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "After class, we can take a walk around the grounds together. It's a nice day today! Okay~?"));
                scene.add_sequence(ks::DialogItem("", "The assignment is actually very challenging to get through, combining aspects of being both difficult and unnecessarily long."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_scienceroom));
                scene.add_sequence(ks::DialogItem("", "Still, we finish it a few minutes earlier than anyone else in the class, despite our late start. Shizune and Misha are really capable."));
                scene.add_sequence(ks::DialogItem("", "They're quite different, though. The class rep is as calm and professional as she looks, while Misha is a lot more playful and girlish. Not to mention a little more easily distracted."));
                scene.add_sequence(ks::DialogItem("", "To be honest, the two of them did most of the work. I feel guilty about that."));
                scene.add_sequence(ks::DialogItem("", "The clock tower bells ring, signaling the end of the period. Time for lunch."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_hallway3));
                scene.add_sequence(ks::DialogItem("", "Without knowing what else to do, I follow Misha, who is beckoning me into the hallway and down the stairs."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_enter_stage_left__condition_2;
                // a1_monday_enter_stage_left__condition_2.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayEn::a1_monday_enter_stage_left__condition_2_0));
                // scene.add_condition(a1_monday_enter_stage_left__condition_2);
                scene.start();
            
                while(!scene.is_finished()) {
                    scene.update();
                    bn::core::update();
                }
            }
            static void a1_monday_in_the_nursery() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                bn::optional<bn::regular_bg_ptr> main_bg;
                ks::SceneManager scene(main_bg);
            
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_staircase2));
                scene.add_sequence(ks::DialogItem("", "We descend even below the lobby where I met Mutou, down to the bottom floor."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_cafeteria));
                scene.add_sequence(ks::DialogItem("", "Just like everything in this school, the cafeteria seems too spacious and oddly modern in contrast to the classic exterior."));
                scene.add_sequence(ks::DialogItem("", "Its big windows open to the courtyard, towards the main gate."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_ease));
                scene.add_sequence(ks::DialogItem("mi", "It's the cafeteria~!"));
                scene.add_sequence(ks::DialogItem("", "Her enthusiastic statement of the obvious makes people around us stare, but Misha doesn't seem to care so we proceed to the line."));
                scene.add_sequence(ks::DialogItem("", "There is a rather long list of menu options, which seems great until I realize that many of them are to accommodate students who need special diets."));
                scene.add_sequence(ks::DialogItem("", "How nice. It almost feels like I'm back at the hospital, eating portions measured with scientific precision to meet the needs of the patients."));
                scene.add_sequence(ks::DialogItem("", "I pick something at random and follow Shizune to a table, sitting opposite of her."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "As I nibble indifferently at the food I'd rather not eat, Misha pokes me in the side to get my attention and points to Shizune."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("", "I don't understand sign, so the point escapes me."));
                scene.add_sequence(ks::DialogItem("", "Maybe looking at a person who 'talks' to you is proper and polite?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Do you want to know something?"));
                scene.add_sequence(ks::DialogItem("hi", "What?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "About anything! We're your guides so you should ask if there is something~!"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0(scene);}));
                scene.add_sequence(ks::DialogItem("", "Misha and Shizune sign back and forth very animatedly, throwing sideway glances at me but Misha refrains from translating."));
                scene.add_sequence(ks::DialogItem("", "Maybe they are talking about secret girl stuff or something."));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(1.0, .5, channel="ambient")"));
                scene.add_sequence(ks::DialogItem("", "I quickly notice a conversation in sign is not enough to fill a silence."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_scienceroom));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("", "We arrive in the classroom early, but we're not the first."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hanako, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "That dark haired girl I noticed before is slumped over her desk at the last row."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hanako, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hanako:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "She jumps a little when Misha crashes into the room with the elegance of a rhino."));
                scene.add_sequence(ks::DialogItem("", "She shrinks deeper into her seat. I can feel her tension all the way from here, as if she were slowly turning into stone just from our presence."));
                scene.add_sequence(ks::DialogItem("", "Misha and Shizune either don't notice or don't mind it, as they walk directly past her to their seats and begin to converse."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hanako, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "I'm left wondering about her, even when the classroom slowly fills with other students and finally, the teacher."));
                scene.add_sequence(ks::DialogItem("", "Getting into the rhythm of school feels strange; it's as if my brain remembers how this is done, but my body doesn't."));
                scene.add_sequence(ks::DialogItem("", "Towards the end of the class I start yawning and counting the minutes left."));
                scene.add_sequence(ks::DialogItem("", "I shouldn't be this tired on my first day of school."));
                scene.add_sequence(ks::DialogItem("", "Maybe it's the long time spent in the hospital that made me like this. I'm even feeling physically weak and lifeless."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_scienceroom));
                scene.add_sequence(ks::DialogItem("", "Before long, the final bell rings."));
                scene.add_sequence(ks::DialogItem("", "School is finally over for the day."));
                scene.add_sequence(ks::DialogItem("", "Beside me, Misha and Shizune are having a short conversation. After a bit of deliberation, Misha turns to me."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("mi", "Unfortunately we can't stay and show you around today, Hicchan. We've got to hurry already, since there is a lot of work for us to do."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("mi", "You'll find your way around here, I'm sure of it."));
                scene.add_sequence(ks::DialogItem("hi", "Ah, wait! The teacher said I'd have to see the nurse. Where do I have to go?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Is that so? We can at least show you that much~!"));
                scene.add_sequence(ks::DialogItem("mi", "Come on, the nurses have their own building, so we have to go outside."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_hallway3));
                scene.add_sequence(ks::DialogItem("", "We join the flow of students making their way down the stairwell and outside, with the girls pointing out other senior classrooms in the same hallway as ours."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_courtyard));
                scene.add_sequence(ks::DialogItem("", "When we get outside, the girls make their way to the smaller building right next to the school."));
                scene.add_sequence(ks::DialogItem("", "It's built in the same style, so it looks like it's actually a part of the main building."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("mi", "This is the auxiliary building here. There's a lot of official and important stuff inside, like the Yamaku Foundation office and all the nurses' offices. They even have a swimming pool!"));
                scene.add_sequence(ks::DialogItem("hi", "How is that official?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Don't be silly, Hicchan! It's for physical therapy of course."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Anyway, all the nursing staff facilities are in there too. The head nurse's office is on the first floor."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "You'll be fine from here, right~? We'll be going, then! See you tomorrow!"));
                scene.add_sequence(ks::DialogItem("hi", "Yeah, thanks. Bye."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "A whole building for stuff that has nothing to do with the actual education?"));
                scene.add_sequence(ks::DialogItem("", "I guess it's necessary for a place like this."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_nursehall));
                scene.add_sequence(ks::DialogItem("", "I walk in, hoping that this really will be only a quick visit like the teacher said."));
                scene.add_sequence(ks::DialogItem("", "On a white door on the left is a green cross with the text 'Head Nurse' and a nameplate."));
                scene.add_sequence(ks::DialogItem("", "A voice from the inside responds to my knock almost immediately, but I can't quite make it out."));
                scene.add_sequence(ks::DialogItem("", "It sounded a bit like an invitation to open the door, so I invite myself further in."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_nurseoffice));
                scene.add_sequence(ks::DialogItem("", "The room is not large and it smells strange. A friendly-looking man turns around on his office chair to face me as I enter."));
                scene.add_sequence(ks::DialogItem("", "His desk is neat and tidy, but the bin under the table is overflowing with used medical utensils and there are at least a dozen coffee-cup rings lingering on the desk."));
                scene.add_sequence(ks::MusicNotFoundItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk_", "Hello there. What can I do for you today?"));
                scene.add_sequence(ks::DialogItem("", "He is young-looking and sort of rugged, but the dimples in his cheeks wash that impression away when he smiles."));
                scene.add_sequence(ks::DialogItem("hi", "Erm, are you the nurse?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "He smiles like a person who has heard this very same question hundreds of times."));
                scene.add_sequence(ks::DialogItem("nk_", "Why yes, I am. It says so on the door, no?"));
                scene.add_sequence(ks::DialogItem("nk_", "You can call me by my name or just 'the nurse' like everyone else."));
                scene.add_sequence(ks::DialogItem("", "Of course. I shake off my confusion, realizing I probably should grab his extended hand.{w} His handshake is rather firm and friendly."));
                scene.add_sequence(ks::DialogItem("hi", "Right… err, I'm a new student and my homeroom teacher told me to come and meet you. My name is Hisao Nakai."));
                scene.add_sequence(ks::DialogItem("", "His eyes light up with revelation and he snaps his fingers."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Oh you're THAT Nakai. I was just reading your file in the morning."));
                scene.add_sequence(ks::DialogItem("nk", "Some kind of chronic arrhythmia and related congenital heart muscle deficiency, right?"));
                scene.add_sequence(ks::DialogItem("", "He gestures me to sit down in a vacant armchair in front of his desk."));
                scene.add_sequence(ks::DialogItem("hi", "Eh, yes."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Good. Well, you've probably been briefed about the school enough, so I'll just go over this quickly."));
                scene.add_sequence(ks::DialogItem("nk", "We have all kinds of facilities available, mostly physical therapy and such."));
                scene.add_sequence(ks::DialogItem("nk", "There's always someone from my staff around, even at night, so never hesitate to call us if there is a problem."));
                scene.add_sequence(ks::DialogItem("", "The famous twenty-four-hour nursing staff."));
                scene.add_sequence(ks::DialogItem("hi", "Wow, this is like a hospital."));
                scene.add_sequence(ks::DialogItem("nk", "Well, not exactly. For instance, we don't do brain surgery here."));
                scene.add_sequence(ks::DialogItem("", "His joke feels so out of place that I'm left thinking why he even said it."));
                scene.add_sequence(ks::DialogItem("hi", "Yeah… just that it's really weird to have so many medical people at a school."));
                scene.add_sequence(ks::DialogItem("nk", "You'll get used to it."));
                scene.add_sequence(ks::DialogItem("", "I'm not so sure of that myself but I don't let the nurse know it."));
                scene.add_sequence(ks::DialogItem("nk", "Now, let me just find your file again…"));
                scene.add_sequence(ks::DialogItem("", "While he searches for something from his computer and shuffles stacks of papers around, I let my gaze wander around the room."));
                scene.add_sequence(ks::DialogItem("", "It's the epitome of generic, I'd like to say."));
                scene.add_sequence(ks::DialogItem("", "Beige walls and ceiling, dark gray laminate flooring, and all the equipment you'd expect from a school nurse's office."));
                scene.add_sequence(ks::DialogItem("", "Even the ridiculous educational posters are hanging on all four walls, reminding me to eat properly - three times a day and from all the food groups."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Smiling, the nurse draws a thick file from a stack of similarly thick files and opens it."));
                scene.add_sequence(ks::DialogItem("nk", "So, you already have medication for the arrhythmia, just remember to take your pills every morning and evening or it won't be much help."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Apart from that… do you do any sports? Rash stuff like… I don't know, boxing?"));
                scene.add_sequence(ks::DialogItem("", "He grins to his own joke but I don't."));
                scene.add_sequence(ks::DialogItem("hi", "Eh, well. I played soccer occasionally with some classmates."));
                scene.add_sequence(ks::DialogItem("nk", "All right, I'm afraid I'm going to have to recommend you refrain from doing that. At least, for the time being."));
                scene.add_sequence(ks::DialogItem("hi", "Oh."));
                scene.add_sequence(ks::DialogItem("", "My lack of reaction makes him raise an eyebrow, but really, I'm not too bothered by him forbidding me to kick a ball around."));
                scene.add_sequence(ks::DialogItem("", "I guess I never did it out of burning passion for the sport. Just to have something to do."));
                scene.add_sequence(ks::DialogItem("nk", "Any kind of concussion might be very dangerous to your heart, and risking another attack is not a good idea."));
                scene.add_sequence(ks::DialogItem("nk", "Was the previous one caused by a sudden concussion to the chest area? There is no mention of the cause in your papers."));
                scene.add_sequence(ks::DialogItem("hi", "Err… not exactly."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "I sidestep the question acceptably, and he glances at me over his papers, with a more serious expression on his face."));
                scene.add_sequence(ks::DialogItem("nk", "Still, you need to keep your body healthy so some exercise would do you good."));
                scene.add_sequence(ks::DialogItem("nk", "We have physical therapy and such available as I said, but I don't think you really need such heavy measures."));
                scene.add_sequence(ks::DialogItem("nk", "Just get some light exercise regularly."));
                scene.add_sequence(ks::DialogItem("nk", "Brisk walks or even light jogging, jumping rope, that sort of thing. Swimming, maybe? There's a pool here."));
                scene.add_sequence(ks::DialogItem("hi", "So I was told."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "You were? Very good."));
                scene.add_sequence(ks::DialogItem("nk", "At any rate, and I'm sure you've been told this before, you just need to take care not to overexert yourself."));
                scene.add_sequence(ks::DialogItem("", "He wags his finger to emphasize the point. No need really, I've heard this a thousand times already."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Absolutely no unnecessary risks. Take care of yourself."));
                scene.add_sequence(ks::DialogItem("hi", "Okay."));
                scene.add_sequence(ks::DialogItem("", "He goes over my papers one more time and sets them on the desk, obviously content."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Good. That's it, then. Come meet me if you ever need something."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_nursehall));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "I'm ushered out before I even realize it. A quick visit, indeed."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_in_the_nursery__condition_0;
                // a1_monday_in_the_nursery__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayEn::a1_monday_in_the_nursery__condition_0_0));
                // scene.add_condition(a1_monday_in_the_nursery__condition_0);
                scene.start();
            
                while(!scene.is_finished()) {
                    scene.update();
                    bn::core::update();
                }
            }
            static void a1_monday_nobodys_room() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                bn::optional<bn::regular_bg_ptr> main_bg;
                ks::SceneManager scene(main_bg);
            
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_courtyard));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("", "I end up standing in front of the main building and the auxiliary building, although to my eyes, they still look one and the same."));
                scene.add_sequence(ks::DialogItem("", "It's the first real look I get at the other students, so I watch people coming out of the school, going towards the gate or the dorms."));
                scene.add_sequence(ks::DialogItem("", "Everyone seems to know where they are going."));
                scene.add_sequence(ks::DialogItem("", "And I still keep thinking that most of them don't look too special for being students at a special school. Then again, neither do I."));
                scene.add_sequence(ks::DialogItem("", "Does that make me one of them?{w} One of us?"));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::DialogItem("", "I should go somewhere too, to prevent me from getting lost."));
                scene.add_sequence(ks::DialogItem("", "It's around dinnertime, but I feel tired instead of hungry."));
                scene.add_sequence(ks::DialogItem("", "The weariness in me only grows as I trudge towards the dorms, set a little way apart from the main building complex."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_gardens));
                scene.add_sequence(ks::DialogItem("", "There is a garden of sorts between the school and the dorms; shrubbery, flowers and that overbearing smell of fresh cut grass that fills the atmosphere."));
                scene.add_sequence(ks::DialogItem("", "It dawns on my tired mind that the smell feels novel because I haven't been outside at all for so long."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormext_start));
                scene.add_sequence(ks::DialogItem("", "The dorm building is big and made of red brick. Like the others, it feels way too pompous for what it is, so I push forward, going inside."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormhallground));
                scene.add_sequence(ks::DialogItem("", "It takes more time than necessary to fish out the key I was given from my pocket."));
                scene.add_sequence(ks::DialogItem("hi", "Room one-one-nine…"));
                scene.add_sequence(ks::DialogItem("", "Despite the ornate exterior, the inside of the dorm is fairly new, functional, and boring."));
                scene.add_sequence(ks::DialogItem("", "Just like in the main building, the halls and doors are wide to accommodate wheelchairs. The same goes for the elevators at the ends of the hallways."));
                scene.add_sequence(ks::DialogItem("", "I poke my head around the corner of the common room door."));
                scene.add_sequence(ks::DialogItem("", "Inside a few students are watching the television."));
                scene.add_sequence(ks::DialogItem("", "One nods and gives a quick 'hello' before turning back to the TV."));
                scene.add_sequence(ks::DialogItem("", "Seems that only the girls around here are sociable. I suppose that's perfectly fine with me."));
                scene.add_sequence(ks::DialogItem("", "I climb the stairs to the upper floor."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormhallway));
                scene.add_sequence(ks::DialogItem("", "Here, small corridors branch off from the main hallway."));
                scene.add_sequence(ks::DialogItem("", "Each of these minor halls seems to have a toilet and shower, as well as four rooms."));
                scene.add_sequence(ks::DialogItem("", "About halfway down the hall, I spy room 119."));
                scene.add_sequence(ks::DialogItem("", "The name plates on the rooms adjacent to mine are blank. I guess there are just two of us here."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "Light shines from below the door of room 117, so I knock lightly."));
                scene.add_sequence(ks::DialogItem("hi", "Hello, is anyone home?"));
                scene.add_sequence(ks::DialogItem("", "From inside, I hear a few movements, then the clicking of way more locks than I thought these doors had. After a moment the door squeaks open."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("", "A bespectacled boy is standing in the doorway. He is looking at me very intently through his extremely thick eyeglasses."));
                scene.add_sequence(ks::DialogItem("ke_", "Who is it?"));
                scene.add_sequence(ks::DialogItem("", "Blind? No, at least not completely, why would he have eyeglasses if he was?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "He leans closer to me until our noses are almost touching. His breath stinks of garlic."));
                scene.add_sequence(ks::DialogItem("hi", "Hisao Nakai… I'm moving into the next room. I thought I should introduce my…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "His face suddenly brightens in realization, and he stands back upright, thrusting his hand out in a smiling greeting, almost straight to my diaphragm."));
                scene.add_sequence(ks::DialogItem("ke_", "Oh, 'sup dude? The name's Kenji."));
                scene.add_sequence(ks::DialogItem("hi", "Ah, hi."));
                scene.add_sequence(ks::DialogItem("", "I take Kenji's sweaty hand and shake it, still a little rattled by the sudden change of attitude and vehement welcome."));
                scene.add_sequence(ks::DialogItem("ke", "There were some suspicious-looking people going in and out of your room earlier."));
                scene.add_sequence(ks::DialogItem("hi", "It was probably my parents."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Your parents? You sure? 'Cause they could've been some other people, too. You can't judge a book by its cover."));
                scene.add_sequence(ks::DialogItem("", "His out-of-place proverb is left hanging between us awkwardly as I try to think of some way to respond."));
                scene.add_sequence(ks::DialogItem("hi", "I'd say the chances are high enough."));
                scene.add_sequence(ks::DialogItem("", "He shudders and makes some exaggerated hand gestures."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "You're a brave man, Hisao."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Me, I don't think I could trust the chances."));
                scene.add_sequence(ks::DialogItem("ke", "The only one I trust is myself."));
                scene.add_sequence(ks::DialogItem("hi", "Does that mean I shouldn't get to know you, either?"));
                scene.add_sequence(ks::DialogItem("", "He thinks about this for a while."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "A wise decision."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Damn, you are smarter than you look."));
                scene.add_sequence(ks::DialogItem("ke", "Probably."));
                scene.add_sequence(ks::DialogItem("ke", "What do you look like? I hope not smart."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "He squints his eyes and leans closer again, but I lean backwards to dodge it."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Never mind, it doesn't matter."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "With that, he turns, fumbles around for a moment in search of the door handle,{w=0.3}{nw}"));
                scene.add_sequence(ks::DialogItem("extend", "and shuts the door behind him."));
                scene.add_sequence(ks::DialogItem("", "I slide the key into the lock of the door marked 119."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormhisao_ss));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_night));
                scene.add_sequence(ks::DialogItem("", "Bleak beige walls, white linen, a desk made of some type of light wood. Ugly curtains."));
                scene.add_sequence(ks::DialogItem("", "It's no one's room; impersonal, like my hospital room was."));
                scene.add_sequence(ks::DialogItem("", "My bags are sitting at the foot of my bed, looking a lot emptier than they did this morning."));
                scene.add_sequence(ks::DialogItem("", "The closet is sitting open, stocked with my clothes."));
                scene.add_sequence(ks::DialogItem("", "Also, it seems that there are a number of school uniforms hanging there as well."));
                scene.add_sequence(ks::DialogItem("", "A note is pinned to the sleeve of one of the shirts."));
                scene.add_sequence(ks::DialogItem("", "Well, at least I don't have to worry about unpacking."));
                scene.add_sequence(ks::DialogItem("", "I kind of hoped I would have, then there would be something to do."));
                scene.add_sequence(ks::DialogItem("", "It's still too early."));
                scene.add_sequence(ks::DialogItem("", "I put the note down on the desktop and lie down on the bed, feeling drained."));
                scene.add_sequence(ks::DialogItem("", "Lying there makes me want to read something, but I have nothing with me."));
                scene.add_sequence(ks::DialogItem("", "I wonder if the hospital conditioned me for wanting to read whenever I have nothing to do."));
                scene.add_sequence(ks::DialogItem("", "The restless urge just keeps growing until I have to stand up."));
                scene.add_sequence(ks::DialogItem("", "Maybe it's stress or something."));
                scene.add_sequence(ks::DialogItem("", "I was pretty nervous about it before coming and for the entire day today too. I still am, I think."));
                scene.add_sequence(ks::DialogItem("", "Damn, I have to distract myself somehow, so I won't be this unnatural all the time."));
                scene.add_sequence(ks::DialogItem("", "Tomorrow, I'll go borrow some books from the library."));
                scene.add_sequence(ks::DialogItem("", "Yeah, I'll do that."));
                scene.add_sequence(ks::DialogItem("", "But for now…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::pills:, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::pills:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "The bottles of medications neatly arranged on my night table catch my eye."));
                scene.add_sequence(ks::DialogItem("", "I pick up one and shake it just to hear the contents rattle inside, and then read the glued-on pharmacy label."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::pills:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "It doesn't really say that, but it could just as well."));
                scene.add_sequence(ks::DialogItem("", "It's kinda twisted, having your life depend on chemicals like this. I resent it a little, but what choice do I have?"));
                scene.add_sequence(ks::DialogItem("", "With a sigh, I begin my new daily ritual of taking the right number of pills from each bottle, being careful to check the correct dosages."));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::DialogItem("", "I lie down again, feeling hollow and uncertain, and after that I keep staring at the blank, unfamiliar ceiling for a long time."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormhisao_ni));
                scene.add_sequence(ks::DialogItem("", "It doesn't start looking any more familiar, not even after darkness falls and long shadows draw across my room like fingers."));
                scene.add_sequence(ks::DialogItem("", "The sheets feel slightly more comfortable, warm and nest-like against the chill that passes for room temperature here."));
                scene.add_sequence(ks::DialogItem("", "Soon the lighter shade of darkness that is the ceiling looks like every ceiling does at night, and it becomes the only thing I recognize any more."));
                scene.add_sequence(ks::DialogItem("", "The night beckons me to sleep, and I feel the coldness of unfamiliarity and fear creeping up my spine once again."));
                scene.add_sequence(ks::DialogItem("", "I keep drifting further away from the world I knew."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_nobodys_room__condition_0;
                // a1_monday_nobodys_room__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayEn::a1_monday_nobodys_room__condition_0_0));
                // scene.add_condition(a1_monday_nobodys_room__condition_0);
                scene.start();
            
                while(!scene.is_finished()) {
                    scene.update();
                    bn::core::update();
                }
            }
            static void a1_monday() {
                a1_monday_out_cold();
                bn::core::update();
                a1_monday_bundle_of_hisao();
                bn::core::update();
                a1_monday_gateway_effect();
                bn::core::update();
                a1_monday_enter_stage_left();
                bn::core::update();
                a1_monday_in_the_nursery();
                bn::core::update();
                a1_monday_nobodys_room();
                bn::core::update();
            }
            static void a1c1o1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("hi", "Why? Do I have to?"));
                scene.add_sequence(ks::DialogItem("mu", "Of course not. That's why I asked."));
                scene.add_sequence(ks::DialogItem("hi", "Right."));
                scene.add_sequence(ks::DialogItem("mu", "Let's go then."));
                return;
            }
            static void a1c1o2(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("hi", "Yeah, sure. I mean, isn't that normal?"));
                scene.add_sequence(ks::DialogItem("mu", "Of course. But not everyone likes to be at the center of attention."));
                scene.add_sequence(ks::DialogItem("", "I'm probably one of those people, but I guess I should be the one to give the first impression of myself."));
                scene.add_sequence(ks::DialogItem("hi", "Right, but it's no problem."));
                scene.add_sequence(ks::DialogItem("mu", "Let's go then."));
                return;
            }
            static void a1c2o1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("hi", "Oh, yeah. Is there a library in the school? Lately I've gotten into reading a lot so I'd like to check it out."));
                scene.add_sequence(ks::DialogItem("", "Misha gives the kind of frown that makes it clear she doesn't consider reading a healthy hobby, but then picks up her smile again."));
                scene.add_sequence(ks::DialogItem("mi", "There is~! It's in the second floor, we can show it to you sometime!"));
                scene.add_sequence(ks::DialogItem("hi", "Thanks."));
                scene.add_sequence(ks::DialogItem("", "I return to my food while the girls talk between themselves."));
                return;
            }
            static void a1c2o2(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "Shizune intrigues me, and I kind of want to ask something about her."));
                scene.add_sequence(ks::DialogItem("", "But I can't really ask about something that personal, can I?"));
                scene.add_sequence(ks::DialogItem("", "Hmm…"));
                scene.add_sequence(ks::DialogItem("", "I can't come up with anything else to ask so I just focus on my food while the girls talk between themselves."));
                return;
            }
            static void a1c2o3(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("hi", "I can't think of anything, really."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ooh! That means we've been good guides, doesn't it, doesn't it~?"));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::DialogItem("hi", "Eeh… if you say so."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Misha positively beams, and so does Shizune after a quick translation."));
                scene.add_sequence(ks::DialogItem("", "I shake my head at their somewhat exaggerated enthusiasm, and shift my focus on the food."));
                return;
            }
            static void a1_monday_gateway_effect__menu_question_0(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("mu", "Do you want to introduce yourself to the class?"));
                // bn::vector<ks::AnswerItem, 2> answers;
                // answers.push_back(ks::AnswerItem("Why?", &ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0_why));
                // answers.push_back(ks::AnswerItem("Yeah, of course.", &ScriptA1MondayEn::a1_monday_gateway_effect__menu_question_0_yeah_of_course));
                // scene.add_sequence(ks::MenuItem(answers);
            }
            static void a1_monday_gateway_effect__menu_question_0_why(ks::SceneManager& scene) {
                // scene.add_sequence(ks::AssignmentItem("wanted_introduce = False"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayEn::a1c1o1(scene);}));
            }
            static void a1_monday_gateway_effect__menu_question_0_yeah_of_course(ks::SceneManager& scene) {
                // scene.add_sequence(ks::AssignmentItem("wanted_introduce = True"));
                // scene.add_sequence(ks::AssignmentItem("attraction_sc += 1"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayEn::a1c1o2(scene);}));
            }
            static void a1_monday_in_the_nursery__menu_question_0(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("hi", "Hmm, I wonder…"));
                // bn::vector<ks::AnswerItem, 3> answers;
                // answers.push_back(ks::AnswerItem("Ask about the library.", &ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0_ask_about_the_library));
                // answers.push_back(ks::AnswerItem("Ask about Shizune's deafness.", &ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness));
                // answers.push_back(ks::AnswerItem("I think I got everything I need to know.", &ScriptA1MondayEn::a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know));
                // scene.add_sequence(ks::MenuItem(answers);
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_the_library(ks::SceneManager& scene) {
                // scene.add_sequence(ks::AssignmentItem("attraction_hanako += 1"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayEn::a1c2o1(scene);}));
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness(ks::SceneManager& scene) {
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayEn::a1c2o2(scene);}));
            }
            static void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know(ks::SceneManager& scene) {
                // scene.add_sequence(ks::AssignmentItem("attraction_sc += 1"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayEn::a1c2o3(scene);}));
            }
            static void a1_monday_out_cold__condition_0_0(ks::SceneManager& scene) {
                return;
            }
            static void a1_monday_bundle_of_hisao__condition_0_0(ks::SceneManager& scene) {
                return;
            }
            static void a1_monday_gateway_effect__condition_0_0(ks::SceneManager& scene) {
                return;
            }
            static void a1_monday_enter_stage_left__condition_0_0(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "A collective silence tells me that I should open my mouth now."));
                scene.add_sequence(ks::DialogItem("hi", "So… I'm Hisao Nakai."));
                scene.add_sequence(ks::DialogItem("", "And after that?"));
                scene.add_sequence(ks::DialogItem("hi", "My hobbies are reading and soccer. I hope to get along well with everyone even though I'm a new student."));
                scene.add_sequence(ks::DialogItem("", "And after that?"));
                scene.add_sequence(ks::DialogItem("", "I'm being so boring. This is exactly like every self-introduction ever. I should say something more. Something more exciting."));
                scene.add_sequence(ks::DialogItem("", "I end up saying nothing, and the teacher picks up from there."));
                scene.add_sequence(ks::DialogItem("", "Everyone seems to be satisfied even with what little I said, though. A few girls are whispering to each other, throwing glances at me. It could've gone worse."));
                scene.add_sequence(ks::DialogItem("", "…"));
            }
            static void a1_monday_enter_stage_left__condition_0_1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "After the applause, there is a brief silence that nobody seems to want to be responsible for breaking."));
                scene.add_sequence(ks::DialogItem("", "The teacher soon realizes that he should probably say something. He opens up with some unintelligible noise, shuts up as he loses his momentum, and then starts introducing me."));
                scene.add_sequence(ks::DialogItem("", "Nobody seems to be too interested."));
                scene.add_sequence(ks::DialogItem("", "Maybe I should've said yes to the self-introduction thing."));
                scene.add_sequence(ks::DialogItem("", "Probably realizing he doesn't know anything about me, he just ends up saying my name wrong again, and asks me to write it on the blackboard."));
                scene.add_sequence(ks::DialogItem("", "I do that, and turn back to face the class, feeling awkward."));
            }
            static void a1_monday_enter_stage_left__condition_1_0(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("mi", "He seems like a very interesting person, doesn't he~!"));
            }
            static void a1_monday_enter_stage_left__condition_1_1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "Misha looks at me with a weird expression, then continues."));
                scene.add_sequence(ks::DialogItem("mi", "We don't know much about him, but maybe we'll find out later."));
                scene.add_sequence(ks::DialogItem("", "Maybe I should've introduced myself after all. Anything would've given a better first impression than the teacher's drone and fumbling with my name."));
            }
            static void a1_monday_enter_stage_left__condition_2_0(ks::SceneManager& scene) {
                return;
            }
            static void a1_monday_in_the_nursery__condition_0_0(ks::SceneManager& scene) {
                return;
            }
            static void a1_monday_nobodys_room__condition_0_0(ks::SceneManager& scene) {
                return;
            }
    };
}