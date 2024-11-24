#include "script_a1_monday.h"
namespace ks {
    class ScriptA1MondayRu : public ScriptA1Monday {
        public:
            static void a1_monday_out_cold() {
                // POTENTIAL MEMLEAK!!!! better to provide it globally.
                bn::optional<bn::regular_bg_ptr> main_bg;
                ks::SceneManager scene(main_bg);
            
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::op_snowywoods));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("", "Лёгкий ветерок колышет голые ветви над головой, заставляя их шуметь, словно деревянные колокольчики."));
                scene.add_sequence(ks::DialogItem("", "Летом в этом месте любят уединяться парочки. Густые зелёные своды крон надёжно укрывают их от взглядов учителей и остальных учеников."));
                scene.add_sequence(ks::DialogItem("", "Но сейчас, в середине зимы, у меня создаётся впечатление, будто я стою под кучей хвороста."));
                scene.add_sequence(ks::DialogItem("", "Сложив ладони, я дышу на них и яростно тру друг о друга, чтобы они не онемели на таком морозе."));
                scene.add_sequence(ks::DialogItem("hi", "Сколько мне ещё ждать? Я уверен, что в записке говорилось: «В 16:00»."));
                scene.add_sequence(ks::DialogItem("", "Ах да, записка… Её незаметно подсунули в мой учебник математики."));
                scene.add_sequence(ks::DialogItem("", "Если говорить о штампах, то, хоть этот вариант и демонстрирует некоторую решительность, мне больше по душе вариант с письмом в шкафчике."));
                scene.add_sequence(ks::DialogItem("", "Пока я размышляю над смыслом записки, снегопад постепенно усиливается."));
                scene.add_sequence(ks::DialogItem("", "Падающие с белого неба снежинки остаются единственным признаком того, что время ещё продолжает свой ход в этом оцепеневшем мире."));
                scene.add_sequence(ks::DialogItem("", "То, насколько неспешно они опускаются на замёрзший лес, создаёт впечатление, будто время едва ползёт."));
                scene.add_sequence(ks::DialogItem("", "Хруст шагов по свежему снегу нарушает тишину, заставляя меня вздрогнуть. Кто-то приближается сзади."));
                scene.add_sequence(ks::DialogItem("mystery", "Хи… Хисао? Ты пришёл?"));
                scene.add_sequence(ks::DialogItem("", "Неуверенный, едва слышный вопрос."));
                scene.add_sequence(ks::DialogItem("", "Однако я сразу узнаю этот нежный голос."));
                scene.add_sequence(ks::DialogItem("", "Моё сердце замирает."));
                scene.add_sequence(ks::DialogItem("", "Сотни раз я слышал, как его обладательница обращается к кому-то другому."));
                scene.add_sequence(ks::DialogItem("", "Я оборачиваюсь на него, на голос из моих снов, и сердце начинает учащённо биться…"));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::other_iwanako));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("hi", "Иванако? Я получил записку с просьбой прийти сюда… Она от тебя?"));
                scene.add_sequence(ks::DialogItem("", "Чёрт. Я всё утро пытался придумать какую-нибудь хорошую фразу – и вот что вышло."));
                scene.add_sequence(ks::DialogItem("", "Вышло ужасно."));
                scene.add_sequence(ks::DialogItem("Иванако", "Эм… да. Я попросила подругу передать тебе эту записку. Рада, что ты получил её."));
                scene.add_sequence(ks::DialogItem("", "Взволнованный её застенчивой, радостной улыбкой, я замираю, не в силах пошевелить ни единым мускулом."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::op_snowywoods));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Только сердце неистово бьётся, словно пытается выскочить из груди прямо к ней."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::other_iwanako));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("hi", "Ну… э… вот мы и здесь. На морозе…"));
                scene.add_sequence(ks::DialogItem("", "Ветер вновь принимается качать ветви. Их нестройный шум – словно музыка для моих ушей."));
                scene.add_sequence(ks::DialogItem("", "Иванако слегка вздрагивает от порыва ветра."));
                scene.add_sequence(ks::DialogItem("", "Когда он стихает, она выпрямляется, будто набравшись смелости."));
                scene.add_sequence(ks::DialogItem("", "Наши взгляды встречаются. Она неспешно играет прядью своих длинных тёмных волос."));
                scene.add_sequence(ks::DialogItem("", "Всё это время тревожное биение моего сердца усиливается."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::op_snowywoods));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::snow, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Горло сводит судорогой; сомневаюсь, что способен выдавить из себя хоть слово."));
                scene.add_sequence(ks::DialogItem("Иванако", "Знаешь…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("Иванако", "…Я хотела спросить…"));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("Иванако", "Не хочешь ли ты… встречаться со мной?"));
                scene.add_sequence(ks::DialogItem("", "Я стою словно истукан, и лишь сердце бешено колотится."));
                scene.add_sequence(ks::DialogItem("", "Я бы и рад что-нибудь ответить, но мои голосовые связки словно натянуты до предела."));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_tragic));
                scene.add_sequence(ks::DialogItem("Иванако", "…Хисао?"));
                scene.add_sequence(ks::DialogItem("", "Пытаясь помассировать горло, я поднимаю руки, но в них словно впиваются тысячи игл, отзываясь жгучей болью."));
                scene.add_sequence(ks::DialogItem("Иванако", "Хисао?!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Тело цепенеет, широко открытые глаза мечутся в ужасе."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::heartattack, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("Иванако", "ХИСАО!"));
                scene.add_sequence(ks::DialogItem("", "Внезапно стук в груди прекращается и колени подкашиваются."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::passoutOP1, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("n", "{vspace=210}Полог из голых ветвей, хмурое зимнее небо, Иванако, бегущая ко мне, – весь мир вокруг погружается во тьму."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Последнее, что я успеваю запомнить, прежде чем меня поглощает забытьё, – голос Иванако, зовущий на помощь, и непрерывный шум ветвей на ветру…"));
                // bn::vector<ks::ConditionItem, 1> a1_monday_out_cold__condition_0;
                // a1_monday_out_cold__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayRu::a1_monday_out_cold__condition_0_0));
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
            
                scene.add_sequence(ks::DialogItem("centered", "После моего сердечного приступа прошло четыре месяца."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hosp_room));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::sakura, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hospitalmask, ks::SpriteEventType::None));
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(0.5, 0.0, channel="music")"));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("n", "{vspace=60}За это время все разы, когда я покидал палату без присмотра, можно сосчитать по пальцам одной руки."));
                scene.add_sequence(ks::DialogItem("n", "Четыре месяца – довольно долгий срок, когда остаёшься наедине со своими мыслями. У меня было достаточно времени, чтобы смириться со своим положением."));
                scene.add_sequence(ks::DialogItem("n", "Аритмия."));
                scene.add_sequence(ks::DialogItem("n", "Странное слово. Незнакомое, чужое. Такое, с которым не хочется иметь ничего общего."));
                scene.add_sequence(ks::DialogItem("n", "Редкая болезнь. Вызывает перебои в работе сердца, иногда заставляя его биться слишком быстро. Это может быть смертельно."));
                scene.add_sequence(ks::DialogItem("n", "Очевидно, она была у меня уже давно. Мне сказали, это просто чудо, что я смог прожить так долго безо всяких происшествий."));
                scene.add_sequence(ks::DialogItem("n", "Чудо ли это? Мне кажется, что так они просто хотели заставить меня чуть больше ценить свою жизнь."));
                scene.add_sequence(ks::DialogItem("n", "Однако это нисколько меня не ободрило."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=150}Думаю, мои родители были потрясены куда сильнее меня. Их обоих чуть удар не хватил."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}У меня, по крайней мере, был целый день, чтобы переварить это. Для них же это стало полнейшей неожиданностью. Они готовы были даже продать дом, чтобы заплатить за лекарство от этой болезни."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=60}Но, конечно, лекарства не существует."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Из-за позднего обнаружения этого… состояния, я должен был оставаться в больнице до полного восстановления."));
                scene.add_sequence(ks::DialogItem("n", "Вначале, когда ко мне начали приходить посетители, казалось, будто они по мне скучают…"));
                scene.add_sequence(ks::DialogItem("n", "Примерно неделю моя палата была полна цветов, воздушных шаров и открыток."));
                scene.add_sequence(ks::DialogItem("n", "Но вскоре поток посетителей стал редеть, и все их подарки с пожеланиями скорейшего выздоровления понемногу иссякли."));
                scene.add_sequence(ks::DialogItem("n", "Я понял, что единственной причиной, по которой я получил так много открыток и цветов, было то, что выражение сочувствия ко мне превратили в задание для класса."));
                scene.add_sequence(ks::DialogItem("n", "Может, некоторые и правда волновались, но я сомневаюсь в этом. Даже с самого начала ко мне приходили нечасто. К концу первого месяца меня продолжали регулярно навещать лишь родители."));
                scene.add_sequence(ks::DialogItem("n", "Иванако перестала приходить последней."));
                scene.add_sequence(ks::DialogItem("n", "Спустя полтора месяца я перестал видеть её в больнице. В любом случае нам не о чем было разговаривать."));
                scene.add_sequence(ks::DialogItem("n", "Мы никогда больше не касались темы, которая свела нас в тот снежный день."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Больница?"));
                scene.add_sequence(ks::DialogItem("n", "Это точно не то место, где я хотел бы быть."));
                scene.add_sequence(ks::DialogItem("n", "Доктора и медсёстры казались отстранёнными и безликими."));
                scene.add_sequence(ks::DialogItem("n", "Думаю, потому что они спешат и у них миллион других пациентов, о которых нужно заботиться… но мне от этого становится не по себе."));
                scene.add_sequence(ks::DialogItem("n", "На протяжении первого месяца каждый раз, когда я встречал главного кардиолога, я спрашивал о хотя бы приблизительной дате, когда смогу покинуть больницу."));
                scene.add_sequence(ks::DialogItem("n", "Он никогда не отвечал прямо, говоря только, что надо подождать и понять, насколько эффективно идёт лечение и насколько успешно прошла операция."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Поэтому мне оставалось лишь наблюдать, как шрам, оставшийся на груди после операции, со временем меняется. Он казался клеймом, оставленным судьбой."));
                scene.add_sequence(ks::DialogItem("n", "Я продолжал спрашивать кардиолога о сроках моей выписки, но уже практически не надеялся услышать ответ, поэтому его отсутствие меня не разочаровывало. То, какие слова он использовал, уходя от ответа, по крайней мере оставляло хоть какую-то надежду."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=120}В какой-то момент я перестал смотреть телевизор. Не знаю почему. Просто перестал, и всё."));
                scene.add_sequence(ks::DialogItem("n", "Возможно, в моей ситуации, это был неподходящий способ ухода от реальности."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Вместо этого я начал читать. В больнице была небольшая «библиотека», которая, впрочем, больше походила на кладовку. Я поглощал книгу за книгой, проглатывая по небольшой стопке, и возвращался за добавкой."));
                scene.add_sequence(ks::DialogItem("n", "Внезапно я обнаружил, что мне нравится чтение, я даже немного пристрастился к нему. Я стал чувствовать себя голым без книги в руках."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Но мне так нравились все эти истории…"));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Так я и жил."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Дни становились всё более одноликими, различались только погода за окном да обложка книги у меня в руках. Время словно превратилось в какую-то клейкую массу, в которой я увязал, вместо того чтобы плыть дальше."));
                scene.add_sequence(ks::DialogItem("n", "Я не замечал, как пролетали недели."));
                scene.add_sequence(ks::DialogItem("n", "Случалось, что я даже не знал, какое сегодня число."));
                scene.add_sequence(ks::DialogItem("n", "Но иногда окружающая действительность вдруг пробивалась через барьер безразличия, которым я себя окружил."));
                scene.add_sequence(ks::DialogItem("n", "Страницы книги начинали казаться острыми и жгли руки, а тяжесть в груди становилась невыносимой. Я вынужден был откладывать книгу и просто лежать некоторое время, глядя в потолок, словно собираясь заплакать."));
                scene.add_sequence(ks::DialogItem("n", "Но это случалось нечасто."));
                scene.add_sequence(ks::DialogItem("n", "{vspace=30}Да я даже не мог плакать."));
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(1.0, 1.0, channel="music")"));
                scene.add_sequence(ks::DialogItem("", "Сегодня ко мне с улыбкой на лице пришёл доктор. Он кажется слегка взволнованным. Как будто он пытается порадоваться и от моего имени."));
                scene.add_sequence(ks::DialogItem("", "Мои родители тоже здесь. Я не видел их несколько дней. Они даже одеты как-то по-праздничному. Сегодня должно произойти что-то особенное? Не слишком похоже на вечеринку."));
                scene.add_sequence(ks::DialogItem("", "Начинается привычный ритуал главного кардиолога: он не спеша раскладывает бумаги, затем убирает их в сторону, словно подчёркивая бессмысленность этого действия."));
                scene.add_sequence(ks::DialogItem("", "Он небрежно садится на край соседней койки и пару мгновений смотрит мне в глаза."));
                scene.add_sequence(ks::DialogItem("Доктор", "Здравствуй, Хисао. Как ты себя чувствуешь?"));
                scene.add_sequence(ks::DialogItem("", "Я молчу, но слегка улыбаюсь в ответ."));
                scene.add_sequence(ks::DialogItem("Доктор", "Думаю, ты уже можешь вернуться домой. Твоё сердце стало сильнее, и, если ты будешь соблюдать некоторые меры предосторожности, всё будет в порядке."));
                scene.add_sequence(ks::DialogItem("Доктор", "Мы определились с необходимыми для тебя лекарствами. Я отдам рецепт твоему отцу."));
                scene.add_sequence(ks::DialogItem("", "Доктор протягивает ему лист бумаги. Когда отец пробегается глазами по рецепту, его лицо принимает каменное выражение."));
                scene.add_sequence(ks::DialogItem("Отец", "Так много…"));
                scene.add_sequence(ks::DialogItem("", "Я беру листок у него из рук, чтобы посмотреть самому, и ошеломлённо замираю. Как ещё мне на это реагировать?"));
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(0.5, 2.0, channel="music")"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::drugs:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Абсурдно длинный список лекарств, смотрящий на меня с листа бумаги, кажется недоступным для восприятия. Текст сливается в сплошное море букв."));
                scene.add_sequence(ks::DialogItem("", "Это безумие."));
                scene.add_sequence(ks::DialogItem("", "Побочные эффекты, противопоказания и дозировки перечислены строка за строкой с холодной точностью."));
                scene.add_sequence(ks::DialogItem("", "Я пытаюсь прочесть, что там написано, но тщетно."));
                scene.add_sequence(ks::DialogItem("", "Я не могу понять ни слова. Попытки сделать это лишь вызывают раздражение."));
                scene.add_sequence(ks::DialogItem("", "Всё это… каждый день, всю мою оставшуюся жизнь?"));
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(1.0, 1.0, channel="music")"));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hosp_room));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::sakura, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hospitalmask, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("Доктор", "Боюсь, это всё, что мы пока можем сделать."));
                scene.add_sequence(ks::DialogItem("Доктор", "Однако постоянно появляются новые лекарства, и я не удивлюсь, если с годами список уменьшится."));
                scene.add_sequence(ks::DialogItem("", "С годами… Каким образом это должно вселить в меня уверенность? Я бы чувствовал себя спокойнее, если бы он промолчал."));
                scene.add_sequence(ks::DialogItem("Доктор", "И ещё. Я поговорил с твоими родителями, и мы решили, что тебе лучше не возвращаться в твою прежнюю школу."));
                scene.add_sequence(ks::DialogItem("", "Что?!"));
                scene.add_sequence(ks::DialogItem("Отец", "Хисао, пожалуйста, успокойся. Послушай, что скажет доктор."));
                scene.add_sequence(ks::DialogItem("", "Успокоиться? Тон, которым он просит об этом, показывает, что он предвидел моё недовольство. Я что, перевожусь на домашнее обучение?"));
                scene.add_sequence(ks::DialogItem("", "Но все мои проявления беспокойства игнорируются."));
                scene.add_sequence(ks::DialogItem("Доктор", "Мы все понимаем, что твоё образование – это главное. Вместе с тем оставлять тебя без медицинского присмотра будет неразумно."));
                scene.add_sequence(ks::DialogItem("Доктор", "По крайней мере, пока мы не убедимся, что эти лекарства тебе подходят."));
                scene.add_sequence(ks::DialogItem("Доктор", "Так что я поговорил с твоими родителями о переводе."));
                scene.add_sequence(ks::DialogItem("Доктор", "Речь идёт о школе «Ямаку», созданной специально для учащихся с ограниченными физическими возможностями."));
                scene.add_sequence(ks::DialogItem("", "С ограниченными возможностями? Что? Получается, я…"));
                scene.add_sequence(ks::DialogItem("Доктор", "Их медперсонал работает круглосуточно, и всего в нескольких минутах находится престижная больница. Большинство учеников живёт в общежитии при школе."));
                scene.add_sequence(ks::DialogItem("Доктор", "Считай это своего рода престижной частной школой. Она организована так, чтобы ученики могли научиться самостоятельности и при этом помощь всегда находилась неподалёку."));
                scene.add_sequence(ks::DialogItem("", "«Самостоятельности»? Это школа для детей-инвалидов. Не пытайтесь это скрыть!"));
                scene.add_sequence(ks::DialogItem("", "Будь она на самом деле такой «свободной», там бы не было постоянного медицинского надзора и наличие поблизости больницы не было бы включено в её рекламу."));
                scene.add_sequence(ks::DialogItem("Отец", "Конечно, тебе решать, переводиться туда или нет. Но… мы с мамой не сможем обучать тебя дома."));
                scene.add_sequence(ks::DialogItem("Отец", "Мы ездили туда пару недель назад и внимательно присмотрелись к ней. Думаю, тебе там понравится."));
                scene.add_sequence(ks::DialogItem("", "Кажется, у меня и правда нет выбора."));
                scene.add_sequence(ks::DialogItem("Доктор", "Люди с проблемой вроде твоей обычно живут дольше, чем люди с другими сердечными заболеваниями. Однажды тебе понадобится работа, и это хорошая возможность продолжить обучение."));
                scene.add_sequence(ks::DialogItem("", "Это не возможность, не называйте это возможностью. Какая это, к чертям, возможность?"));
                scene.add_sequence(ks::DialogItem("Доктор", "Ты должен радоваться такому шансу. Я помню, как ты хотел снова вернуться в школу, и пусть это не та же самая…"));
                scene.add_sequence(ks::DialogItem("", "Специальная школа… Это же…"));
                scene.add_sequence(ks::DialogItem("", "Оскорбление. Вот что я хочу сказать. Это шаг назад."));
                scene.add_sequence(ks::DialogItem("Отец", "Это не то, о чём ты думаешь. Все ученики там ведут достаточно активный образ жизни, каждый по-своему."));
                scene.add_sequence(ks::DialogItem("Отец", "Школа создана специально для ребят, которые продолжают жить своей жизнью и учиться, но нуждаются в небольшой помощи… того или иного рода."));
                scene.add_sequence(ks::DialogItem("Доктор", "Твой отец прав. И немалое число выпускников этой школы достигли поразительно многого. Инвалидность не должна препятствовать развитию человека."));
                scene.add_sequence(ks::DialogItem("Доктор", "Один мой коллега из другой больницы – их выпускник."));
                scene.add_sequence(ks::DialogItem("", "Мне плевать. Инвалидность не должна препятствовать развитию? Как раз препятствием она и является."));
                scene.add_sequence(ks::DialogItem("", "Меня ужасно злит, что столь важное решение было принято за меня. Но что я могу поделать? О нормальной жизни теперь не может быть и речи."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "Забавно, я всегда думал, что моя жизнь довольно скучна, но теперь мне её не хватает."));
                scene.add_sequence(ks::DialogItem("", "Я хочу протестовать, но мне остаётся только списать мою вялую реакцию на шок или усталость. Я мог бы закричать, что я, несмотря ни на что, хочу вернуться в прежнюю школу. Но нет."));
                scene.add_sequence(ks::DialogItem("", "Я молчу, потому что знаю, что это бесполезно."));
                scene.add_sequence(ks::DialogItem("", "Я окидываю взглядом свою палату, и меня охватывает усталость от всего этого. От больницы, от докторов, от болезни – всего. Не вижу ничего, что заставило бы меня изменить настрой."));
                scene.add_sequence(ks::DialogItem("", "Выбора действительно нет. Я знаю это, но мысль о том, чтобы пойти в школу для инвалидов… Какая она вообще? Очень трудно думать об этом в позитивном ключе."));
                scene.add_sequence(ks::DialogItem("", "Но я должен попытаться."));
                scene.add_sequence(ks::DialogItem("", "Новое начало – не так уж и плохо."));
                scene.add_sequence(ks::DialogItem("", "Это всё, о чём я могу думать, чтобы заставить себя пережить это. По крайней мере, у меня остаётся ещё хоть что-то, даже спецшкола всё же лучше, чем ничего. Это новое начало, не всё потеряно. Я не могу позволить себе думать иначе."));
                scene.add_sequence(ks::DialogItem("", "Я хотя бы должен увидеть, на что будет похожа моя новая жизнь."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_bundle_of_hisao__condition_0;
                // a1_monday_bundle_of_hisao__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayRu::a1_monday_bundle_of_hisao__condition_0_0));
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
                scene.add_sequence(ks::DialogItem("", "Ворота выглядят слишком помпезно."));
                scene.add_sequence(ks::DialogItem("", "Впрочем, ворота часто производят подобное впечатление, но эти выделяются особенно."));
                scene.add_sequence(ks::DialogItem("", "Красный кирпич, чёрное кованое железо и серая лепнина составляют совершенно негостеприимную композицию."));
                scene.add_sequence(ks::DialogItem("", "Я задумываюсь, должны ли школьные ворота вызывать подобные эмоции, но не могу прийти ни к чему определённому. Наверное, всё же нет."));
                scene.add_sequence(ks::DialogItem("", "Конечно, я не собираюсь вечно тут стоять и думать о воротах, так что прохожу в них быстрым шагом, что оказывается довольно приятно."));
                scene.add_sequence(ks::DialogItem("", "Двигаться по жизни вперёд вообще приятно."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_courtyard));
                scene.add_sequence(ks::DialogItem("", "Я направляюсь к главному корпусу интерната «Ямаку», где кто-то должен меня встретить. Один, потому что родители отвозят мои вещи в общежитие."));
                scene.add_sequence(ks::DialogItem("", "Вокруг всё покрыто пышной зеленью."));
                scene.add_sequence(ks::DialogItem("", "Это мало похоже на обычные школьные клумбы. Скорее напоминает парк с чистыми дорожками, вьющимися между деревьями, запахом свежеподстриженной травы – со всем, что делает парк парком."));
                scene.add_sequence(ks::DialogItem("", "Мне сразу приходят на ум слова «стерильный» и «гигиеничный», и меня передёргивает."));
                scene.add_sequence(ks::DialogItem("", "Выбрось это из головы. Оставайся непредвзятым. Это твоя новая жизнь – прими её такой, какая она есть."));
                scene.add_sequence(ks::DialogItem("", "Вот что я говорю себе."));
                scene.add_sequence(ks::DialogItem("", "За кронами деревьев виднеются очертания нескольких больших зданий. Их слишком много, и они необычайно велики для простой школы."));
                scene.add_sequence(ks::DialogItem("", "Зрелище открывается непривычное и совсем не соответствующее моим прежним представлениям об учебных заведениях."));
                scene.add_sequence(ks::DialogItem("", "Всё какое-то неестественное. Пусть мне и сказали, что это моя новая школа, но я чувствую себя здесь чужим."));
                scene.add_sequence(ks::DialogItem("", "Интересно, правдиво это впечатление или оно является результатом моего предубеждения?"));
                scene.add_sequence(ks::DialogItem("", "Кстати, я до сих пор не встретил ни души. Как-то жутковато."));
                scene.add_sequence(ks::DialogItem("", "Мне уже хочется увидеть хоть кого-нибудь, лишь бы избавиться от ощущения, что я попал в другое измерение."));
                scene.add_sequence(ks::DialogItem("", "Шумящие на ветру деревья и пышная сверкающая зелень вокруг отвлекают моё внимание."));
                scene.add_sequence(ks::DialogItem("", "Я снова думаю о больницах, где «операционные покрашены в зелёный цвет, потому что он успокаивает»."));
                scene.add_sequence(ks::DialogItem("", "Так почему же, несмотря на всю эту зелень, мне так тревожно?"));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::DialogItem("", "Уже дойдя до главного корпуса, я внезапно осознаю причину заминки у ворот."));
                scene.add_sequence(ks::DialogItem("", "Там у меня был последний шанс повернуть назад, пусть я и не смог бы вернуться к прежней жизни."));
                scene.add_sequence(ks::DialogItem("", "Но, когда я вошёл, пути назад не осталось."));
                scene.add_sequence(ks::DialogItem("", "С этой мыслью, по-прежнему волнуясь, я отворяю парадную дверь."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_lobby));
                scene.add_sequence(ks::DialogItem("", "Когда я вхожу, меня сразу замечает высокий, слегка сутулый мужчина. Неудивительно: кроме нас, в вестибюле никого нет."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu_", "Ты, наверное… Ни… На… Ники?"));
                scene.add_sequence(ks::DialogItem("hi", "Накай."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu_", "Да, именно. Отлично. Я твой классный руководитель и учитель естественных наук. Меня зовут Муто."));
                scene.add_sequence(ks::DialogItem("mu", "Добро пожаловать."));
                scene.add_sequence(ks::DialogItem("", "Мы обмениваемся небрежным рукопожатием, и он смотрит на часы."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "Тебе следует зайти в медкабинет, но сейчас на это нет времени."));
                scene.add_sequence(ks::DialogItem("hi", "Ага. Наверное, я тогда загляну туда попозже?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "Да, после обеда было бы замечательно. Сейчас нам нужно представить тебя одноклассникам. Они уже ждут."));
                scene.add_sequence(ks::DialogItem("", "Ждут меня? Я не люблю быть в центре внимания, но, думаю, в подобной ситуации это неизбежно."));
                scene.add_sequence(ks::DialogItem("", "Беспокойство о том, какой мне окажут приём, снова заставляет меня нервничать."));
                scene.add_sequence(ks::DialogItem("", "В результате я пропускаю мимо ушей практически всё, что говорит мне учитель."));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0(scene);}));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_staircase2));
                scene.add_sequence(ks::DialogItem("", "Когда я поднимаюсь за учителем по лестнице, сердце бешеным стуком в груди напоминает о причине моего появления здесь."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_hallway3));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Третья дверь третьего этажа помечена как класс 3-3."));
                scene.add_sequence(ks::DialogItem("", "Муто открывает её и входит."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "Всем доброе утро. Извиняюсь, что снова опоздал."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "У самых дверей меня охватывает сомнение."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_gateway_effect__condition_0;
                // a1_monday_gateway_effect__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayRu::a1_monday_gateway_effect__condition_0_0));
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
                scene.add_sequence(ks::DialogItem("", "Ну же, соберись! Я понимаю, что это важный шаг, но… Наверное, нет причин так сильно переживать, по крайней мере пока."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hisao_class));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_normal));
                scene.add_sequence(ks::DialogItem("", "Я вхожу в класс следом за учителем и оглядываюсь, стараясь не встречаться с любопытными взглядами моих новых одноклассников."));
                scene.add_sequence(ks::DialogItem("", "В классе довольно просторно: высокий потолок и широкие проходы между партами."));
                scene.add_sequence(ks::DialogItem("", "Доска занимает всю стену, а из-за больших, старомодного вида окон, расположенных на уровне головы, она кажется ещё больше."));
                scene.add_sequence(ks::DialogItem("", "Простые деревянные парты с полочками для книг. Простые деревянные стулья с металлическим каркасом. Незамысловато и эффективно."));
                scene.add_sequence(ks::DialogItem("", "Я поворачиваюсь лицом к ученикам. На первый взгляд они выглядят так же, как и ученики любой другой школы. Но тогда почему они здесь?"));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hisao_class));
                scene.add_sequence(ks::DialogItem("", "Наверное, их недуги не видны на первый взгляд, как и у меня. Потом я замечаю, что у одной из девочек не хватает большого пальца на правой руке. Это немного обескураживает."));
                scene.add_sequence(ks::DialogItem("", "Вопреки нормальной практике слушать, когда кто-то говорит о тебе, примерно с середины речи мои мысли начинают заглушать слова учителя, представляющего меня классу."));
                scene.add_sequence(ks::DialogItem("", "Я ловлю на себе робкий взгляд девочки, сидящей на последнем ряду. Моё внимание привлекает блеск её прямых длинных волос. Заметив, что я смотрю, она быстро закрывает лицо руками, будто это поможет ей стать невидимкой."));
                scene.add_sequence(ks::DialogItem("", "Дальше сидит какой-то парень с тростью, прислонённой к шкафчикам. Странно видеть кого-то столь молодого с тростью."));
                scene.add_sequence(ks::DialogItem("", "Другая девочка совершает какие-то странные движения руками. Язык жестов? Она бросает на меня взгляд поверх очков и снова возвращается к своему занятию."));
                scene.add_sequence(ks::DialogItem("", "Она довольно мила, как и её соседка – весёлого вида девчонка с розовыми волосами. Её трудно не заметить – не знаю, как я не обратил на неё внимания, когда вошёл в класс…"));
                scene.add_sequence(ks::DialogItem("mu", "…пожалуйста, поприветствуйте нашего нового ученика."));
                scene.add_sequence(ks::DialogItem("", "Он начинает аплодировать, и все вторят ему, кроме однорукой девочки в первом ряду. Стараясь скрыть свою растерянность, я благодарю их поклоном за эти незаслуженные аплодисменты."));
                // bn::vector<ks::ConditionItem, 2> a1_monday_enter_stage_left__condition_0;
                // a1_monday_enter_stage_left__condition_0.push_back(ks::ConditionItem("wanted_introduce or _in_replay", &ScriptA1MondayRu::a1_monday_enter_stage_left__condition_0_0));
                // a1_monday_enter_stage_left__condition_0.push_back(ks::ConditionItem("None", &ScriptA1MondayRu::a1_monday_enter_stage_left__condition_0_1));
                // scene.add_condition(a1_monday_enter_stage_left__condition_0);
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::hisao_class));
                scene.add_sequence(ks::DialogItem("", "Я слушаю, как учитель бубнит о том, что нам стоит подружиться, а сам смотрю по сторонам."));
                scene.add_sequence(ks::DialogItem("", "Кажется, все внимательно его слушают, и, когда он заканчивает, снова ему хлопают, что выглядит довольно странно."));
                scene.add_sequence(ks::DialogItem("", "В этот раз хлопает даже девочка из первого ряда, ладошкой здоровой руки по запястью другой, которая оканчивается перебинтованной культёй."));
                scene.add_sequence(ks::DialogItem("", "Меня начинает слегка мутить."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_scienceroom));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "Сегодня мы будем работать в группах, так что у тебя будет шанс пообщаться с ребятами. Как ты на это смотришь?"));
                scene.add_sequence(ks::DialogItem("hi", "Замечательно, ничего не имею против."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::muto, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mu", "Хорошо, ты будешь работать с Хакамити. Она – староста класса."));
                scene.add_sequence(ks::DialogItem("mu", "Она расскажет всё, что тебе будет нужно узнать. Никто не справится с этим лучше неё, верно?"));
                scene.add_sequence(ks::DialogItem("", "Мне-то откуда знать?"));
                scene.add_sequence(ks::DialogItem("", "Учитель раздаёт задания и объявляет, что мы будем работать в группах по трое."));
                scene.add_sequence(ks::DialogItem("", "Внезапно я понимаю, что не знаю, кто из них Хакамити. Чёрт. Учитель, кажется, замечает мою растерянность."));
                scene.add_sequence(ks::DialogItem("mu", "А, точно. Хакамити вон там. Сидзунэ Хакамити."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Как только он называет её имя, симпатичная девочка с ярко-розовыми волосами и золотистыми глазами энергично машет мне рукой. Я сажусь рядом с ней, у окна."));
                scene.add_sequence(ks::DialogItem("hi", "Привет, ты, наверное, Хакамити, да? Приятно познакомиться."));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi_shi", "Ха-ха-ха~!"));
                scene.add_sequence(ks::DialogItem("", "В чём дело? Её смех застаёт меня врасплох."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi_shi", "Я тоже рада познакомиться!{w=0.5} Но~!"));
                scene.add_sequence(ks::DialogItem("mi_not_shi", "Я тоже рада познакомиться! Но~!{fast} Я не Хакамити, я Миша! Хакамити – вот. Ситтян~!"));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_shizune));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::bg, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Хихикая, Миша указывает на девочку, сидящую рядом с ней, – ту, что пользовалась языком жестов. Похоже, она наблюдала за мной всё это время. Она безразлично кивает мне, давая понять, что осведомлена о моём присутствии, но её это не слишком волнует."));
                scene.add_sequence(ks::DialogItem("", "У неё короткие, аккуратно уложенные волосы и тёмно-синие глаза, смотрящие то изучающе, то равнодушно поверх овальных очков на изящном носике."));
                scene.add_sequence(ks::DialogItem("hi", "Рад познакомиться."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Она тут же обращает взгляд к Мише, которая улыбается и делает пару быстрых движений руками."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Хакамити кивает и отвечает несколькими жестами."));
                scene.add_sequence(ks::DialogItem("", "Я задумываюсь, не пошутил ли учитель насчёт «пообщаться с ребятами» и «она всё тебе расскажет»."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Я вижу, ты немного сбит с толку, да? Да? Но я понимаю, почему ты принял меня за Ситтян!"));
                scene.add_sequence(ks::DialogItem("mi", "Ситтян – глухонемая, а я передаю сообщения от неё и для неё."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Я словно переводчик~! Она говорит, что ей тоже приятно с тобой познакомиться!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ты ведь новый ученик, да? Конечно же да, Ситтян! Если бы он им не был, то не было бы смысла в том его выступлении перед классом, правильно? Правильно~!"));
                // bn::vector<ks::ConditionItem, 2> a1_monday_enter_stage_left__condition_1;
                // a1_monday_enter_stage_left__condition_1.push_back(ks::ConditionItem("wanted_introduce or _in_replay", &ScriptA1MondayRu::a1_monday_enter_stage_left__condition_1_0));
                // a1_monday_enter_stage_left__condition_1.push_back(ks::ConditionItem("None", &ScriptA1MondayRu::a1_monday_enter_stage_left__condition_1_1));
                // scene.add_condition(a1_monday_enter_stage_left__condition_1);
                scene.add_sequence(ks::DialogItem("mi", "Мы знали, что должен прийти новенький, но не думали, что это будет сегодня. Так скоро! Да, Хиттян?"));
                scene.add_sequence(ks::DialogItem("", "Хиттян?.."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Угу~! Тебе идёт, не правда ли?"));
                scene.add_sequence(ks::DialogItem("", "Я сказал это вслух? Это просто от неожиданности. Мне никогда не нравилась эта кличка."));
                scene.add_sequence(ks::DialogItem("hi", "Не вижу, каким образом."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Идёт~! Ты выглядишь точно так, как я себе представляла!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ха-ха-ха~! Да-да, ты выглядишь в точности как Хиттян!"));
                scene.add_sequence(ks::DialogItem("hi", "Интересно, почему все так считают…"));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("", "Хакамити стучит пальцами по столу, привлекая внимание Миши. Затем они начинают жестикулировать так оживлённо, что движения становятся практически неразличимы."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Мише, кажется, немного трудно воспринять это всё зараз."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "А-ха-ха~! Ой, прости!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ситтян просит передать, что она староста класса и, если тебе нужно о чём-то узнать, можешь её спрашивать."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Как тебе школа? Мы можем показать тебе окрестности, если ты ещё не успел побродить и…{w=0.5}{nw}"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("extend", "ознакомиться?{w=0.5}{nw}"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("extend", "со всем самостоятельно!"));
                scene.add_sequence(ks::DialogItem("", "Миша на мгновение спотыкается на трудном слове, невольно выделив его на фоне в целом беглого перевода."));
                scene.add_sequence(ks::DialogItem("hi", "Спасибо, это было бы здорово. Я, как приехал, сразу отправился в класс."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ха-ха-ха~!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Нехорошо! Нужно заранее как можно больше узнавать о местах, в которые собираешься отправиться. И это касается не только школы~!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Всегда! Даже если это поход в магазин! Так ведь, Ситтян? Ха-ха-ха~!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Узнавать о местах, в которые отправляешься? Я так никогда не поступал, точнее никогда не заботился о таких вещах."));
                scene.add_sequence(ks::DialogItem("", "Я не желал этого перевода, просто кое-как мирился с ним."));
                scene.add_sequence(ks::DialogItem("", "Я ничего не произношу вслух, и Миша делает несколько жестов, под конец пожав плечами. Что это было? Видимо, что-то обо мне."));
                scene.add_sequence(ks::DialogItem("", "Я чувствую себя так, будто сел мимо стула. Они улыбаются, но это её пожатие плечами неожиданно сильно меня задело."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ты какой-то грустный, с тобой всё в порядке?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Пожалуйста, не пойми меня неправильно~! Ненавижу, когда люди боятся задавать вопросы! Ведь только так и можно научиться чему-либо – спрашивая~!"));
                scene.add_sequence(ks::DialogItem("mi", "Просить помощи совершенно нормально, так же как и нуждаться в ней! Прекрати выглядеть так, словно ты только что провалился на экзамене!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ва-ха-ха-ха~!"));
                scene.add_sequence(ks::DialogItem("hi", "Хорошо."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "А, и ещё! Тебе не обязательно обращаться к Ситтян официально – «Хакамити» или «староста», – можешь звать её просто Ситтян!"));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "А-ха-ха~! Ладно, наверное это слишком нескромно. Может, «Сидзунэ» будет лучше?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_shizune));
                scene.add_sequence(ks::DialogItem("mi", "Угу, угу~! «Сидзунэ» подходит!"));
                scene.add_sequence(ks::DialogItem("hi", "Хех, ладно. Мне так будет намного проще."));
                scene.add_sequence(ks::DialogItem("", "Мне становится гораздо спокойнее. Они кажутся столь дружелюбными, что я чувствую себя глупо из-за недавнего страха. Особенно из-за Сидзунэ, которая, как я думал, будет слишком строгой."));
                scene.add_sequence(ks::DialogItem("", "То есть она такая и есть. Просто не настолько, насколько я опасался."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "А? Точно, мы же ещё даже не притронулись к заданию! Надо сейчас же начинать работать, иначе Ситтян рассердится."));
                scene.add_sequence(ks::DialogItem("hi", "К тому же задание довольно большое, так что если мы не приступим сейчас, то не успеем до конца урока."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ва-ха-ха~! И это тоже!"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("", "Сидзунэ нетерпеливо на нас смотрит. Не требуется знать язык жестов, чтобы понять этот взгляд."));
                scene.add_sequence(ks::DialogItem("hi", "Ладно, ладно, я понял."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "После занятий мы сможем погулять вместе. Сегодня такой хороший день! Ладно~?"));
                scene.add_sequence(ks::DialogItem("", "Над заданием действительно приходится поработать: оно весьма трудное и чересчур большое."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_scienceroom));
                scene.add_sequence(ks::DialogItem("", "И всё же, начав с опозданием, мы заканчиваем раньше всех в классе. Сидзунэ и Миша и правда весьма способные."));
                scene.add_sequence(ks::DialogItem("", "Однако они абсолютно разные. Староста спокойная и деловая, каковой и выглядит, Миша же гораздо более весёлая и легкомысленная. И совсем не такая усидчивая."));
                scene.add_sequence(ks::DialogItem("", "По правде говоря, большую часть работы выполнили они. Мне от этого даже как-то неловко."));
                scene.add_sequence(ks::DialogItem("", "На башне с часами бьёт колокол, возвещая конец урока. Время ланча."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_hallway3));
                scene.add_sequence(ks::DialogItem("", "Мне ничего не остаётся, кроме как последовать за Мишей, которая ведёт меня в коридор и дальше, вниз по лестнице."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_enter_stage_left__condition_2;
                // a1_monday_enter_stage_left__condition_2.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayRu::a1_monday_enter_stage_left__condition_2_0));
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
                scene.add_sequence(ks::DialogItem("", "Мы спускаемся на самый нижний этаж, ещё ниже того вестибюля, где я встретил Муто."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_cafeteria));
                scene.add_sequence(ks::DialogItem("", "Как и везде в этой школе, в столовой много свободного места, а её современное убранство контрастирует со старинной архитектурой самого здания."));
                scene.add_sequence(ks::DialogItem("", "Большие арочные окна смотрят во двор, в сторону главных ворот."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_ease));
                scene.add_sequence(ks::DialogItem("mi", "Это – столовая~!"));
                scene.add_sequence(ks::DialogItem("", "Энергичное утверждение столь очевидного факта заставляет людей вокруг оглянуться на нас, но Мише, кажется, всё равно, и мы спокойно встаём в очередь."));
                scene.add_sequence(ks::DialogItem("", "Меню поражает меня широтой ассортимента, но вскоре я понимаю, что большинство блюд предназначены для учеников с определённой диетой."));
                scene.add_sequence(ks::DialogItem("", "Как мило. Я будто снова попал в больницу, где порции отмерялись с математической точностью, чтобы выдать нужную пациенту дозировку."));
                scene.add_sequence(ks::DialogItem("", "Я выбираю себе что-то наугад и, последовав за Сидзунэ к столику, сажусь напротив неё."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Пока я безразлично ковыряюсь в еде, которую предпочёл бы вовсе не есть, Миша толкает меня в бок и указывает на Сидзунэ."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("", "Я не знаю языка жестов, так что всё равно ничего не понимаю."));
                scene.add_sequence(ks::DialogItem("", "Но, может быть, так принято – смотреть не на переводчика, а на того, кто к тебе обращается?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Ты хочешь о чём-нибудь узнать?"));
                scene.add_sequence(ks::DialogItem("hi", "Например?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "О чём угодно! Ведь мы твои проводники, так что не стесняйся спрашивать, если есть о чём~!"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0(scene);}));
                scene.add_sequence(ks::DialogItem("", "Девочки начинают оживлённо жестикулировать, косясь на меня, но Миша воздерживается от перевода."));
                scene.add_sequence(ks::DialogItem("", "Может, обсуждают какие-то девчачьи секреты?"));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::MusicStopItem());
                // scene.add_sequence(ks::AssignmentItem("renpy.music.set_volume(1.0, .5, channel="ambient")"));
                scene.add_sequence(ks::DialogItem("", "Я быстро понимаю, что беседы на языке жестов недостаточно, чтобы заполнить тишину."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_scienceroom));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("", "Мы рано возвращаемся в класс, но, оказывается, мы там уже не первые."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hanako, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Темноволосая девочка, которую я заметил ранее, склонилась над своей партой в последнем ряду."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hanako, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hanako:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Она слегка вздрагивает, когда Миша вламывается в класс с изяществом носорога."));
                scene.add_sequence(ks::DialogItem("", "Она ещё глубже вжимается в стул. Я издалека чувствую исходящее от неё напряжение, будто из-за нашего присутствия она медленно превращается в камень."));
                scene.add_sequence(ks::DialogItem("", "Не обратив на это никакого внимания, Сидзунэ и Миша проходят мимо неё на свои места, не переставая жестикулировать."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::hanako, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Но я продолжаю думать о ней, пока класс медленно заполняется учениками и, наконец, не приходит учитель."));
                scene.add_sequence(ks::DialogItem("", "Странно вновь вливаться в ритм школьной жизни: будто мой мозг помнит, что это такое, но тело позабыло, как это делается."));
                scene.add_sequence(ks::DialogItem("", "К концу занятий я начинаю зевать и считать оставшиеся минуты."));
                scene.add_sequence(ks::DialogItem("", "Нехорошо так уставать в первый же день."));
                scene.add_sequence(ks::DialogItem("", "Наверное, всё дело в долгом пребывании в больнице. Я физически ощущаю вялость и бессилие."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_scienceroom));
                scene.add_sequence(ks::DialogItem("", "Наконец-то звенит последний звонок."));
                scene.add_sequence(ks::DialogItem("", "Занятия на сегодня окончены."));
                scene.add_sequence(ks::DialogItem("", "Сидящие рядом Миша и Сидзунэ обмениваются несколькими жестами. После небольшой заминки Миша поворачивается ко мне."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("mi", "К сожалению, мы не сможем остаться и показать тебе окрестности, Хиттян. У нас много работы на сегодня, поэтому нам уже пора."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("mi", "Ты и сам найдёшь дорогу, я не сомневаюсь."));
                scene.add_sequence(ks::DialogItem("hi", "Эй, постойте! Учитель сказал, что мне надо зайти в медкабинет. Где он находится?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Вот как? Ну, думаю, это мы сможем тебе показать~!"));
                scene.add_sequence(ks::DialogItem("mi", "Пошли, у медиков отдельное здание, так что нам надо выйти на улицу."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_hallway3));
                scene.add_sequence(ks::DialogItem("", "Мы присоединяемся к потоку учеников, спускающихся вниз по лестнице и далее, на улицу. По пути девочки показывают кабинеты других старших классов, находящиеся на нашем этаже."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_courtyard));
                scene.add_sequence(ks::DialogItem("", "Выйдя на улицу, они направляются к небольшому строению рядом со школой."));
                scene.add_sequence(ks::DialogItem("", "Оно построено в том же стиле, что и главное здание, поэтому кажется его частью."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                scene.add_sequence(ks::DialogItem("mi", "Это административный корпус. Внутри – много важных служебных помещений, таких как офис интерната «Ямаку» и медкабинет. Тут даже бассейн есть!"));
                scene.add_sequence(ks::DialogItem("hi", "Это тоже служебное помещение?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("shi", "…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Не глупи, Хиттян! Он нужен для физиотерапии, конечно."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "В общем, медицинские кабинеты тоже находятся тут. Кабинет, который тебе нужен, – на первом этаже."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "Дальше ты и сам найдёшь дорогу, да~? Тогда мы пойдём! До завтра!"));
                scene.add_sequence(ks::DialogItem("hi", "Ага, спасибо. Пока."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "Целое здание для персонала, никак не связанного с обучением?"));
                scene.add_sequence(ks::DialogItem("", "Наверное, для такого места это необходимо."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_nursehall));
                scene.add_sequence(ks::DialogItem("", "Я вхожу внутрь, надеясь, что это и правда будет лишь краткий визит, как говорил учитель."));
                scene.add_sequence(ks::DialogItem("", "На белой двери с зелёным крестом прибита табличка с надписью «Главный фельдшер» и именем."));
                scene.add_sequence(ks::DialogItem("", "Я стучу в дверь, и тут же из-за неё раздаётся неразборчивый возглас."));
                scene.add_sequence(ks::DialogItem("", "Приняв его за приглашение войти, я открываю дверь."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_nurseoffice));
                scene.add_sequence(ks::DialogItem("", "Комната небольшая, и в ней странно пахнет. Когда я вхожу, ко мне разворачивается сидящий в офисном кресле приветливый мужчина."));
                scene.add_sequence(ks::DialogItem("", "На его столе порядок, но под ним стоит корзина, переполненная использованными медицинскими принадлежностями, на столе виднеется по меньшей мере дюжина следов от кружки с кофе."));
                scene.add_sequence(ks::MusicNotFoundItem());
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk_", "Добрый день! Чем могу помочь?"));
                scene.add_sequence(ks::DialogItem("", "Он выглядит молодо и немного сурово, однако ямочки на щеках стирают это впечатление, когда он улыбается."));
                scene.add_sequence(ks::DialogItem("hi", "Кхм, это вы фельдшер?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Он улыбается с видом человека, который не раз слышал подобный вопрос."));
                scene.add_sequence(ks::DialogItem("nk_", "Ну да. Так написано на двери, разве нет?"));
                scene.add_sequence(ks::DialogItem("nk_", "Можешь обращаться ко мне по имени или просто «фельдшер», как и все остальные."));
                scene.add_sequence(ks::DialogItem("", "Конечно. Я прогоняю смущение, поняв, что мне следует пожать протянутую им руку.{w} Его рукопожатие оказывается крепким и дружеским."));
                scene.add_sequence(ks::DialogItem("hi", "Да… эм-м, я новый ученик, и мой классный руководитель сказал зайти к вам. Меня зовут Хисао Накай."));
                scene.add_sequence(ks::DialogItem("", "Он оживляется и щёлкает пальцами."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "А, тот самый Накай! Я читал твою медицинскую карту с утра."));
                scene.add_sequence(ks::DialogItem("nk", "Хроническая аритмия и врождённый порок сердца, не так ли?"));
                scene.add_sequence(ks::DialogItem("", "Он жестом указывает мне сесть в кресло напротив него."));
                scene.add_sequence(ks::DialogItem("hi", "Ну да."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Отлично. Думаю, тебе уже вкратце рассказали о школе, так что я быстренько пройдусь по основным пунктам."));
                scene.add_sequence(ks::DialogItem("nk", "У нас тут имеются все необходимые службы, в основном предназначенные для физиотерапии и тому подобного."));
                scene.add_sequence(ks::DialogItem("nk", "Поблизости всегда есть кто-нибудь из персонала, даже ночью, так что не стесняйся обращаться к нам, если возникнут проблемы."));
                scene.add_sequence(ks::DialogItem("", "Тот самый знаменитый медперсонал с круглосуточным дежурством."));
                scene.add_sequence(ks::DialogItem("hi", "Ух ты, прямо как в больнице."));
                scene.add_sequence(ks::DialogItem("nk", "Ну, не совсем. К примеру, мы здесь не проводим операции на мозге."));
                scene.add_sequence(ks::DialogItem("", "Его шутка столь неуместна, что я не понимаю, зачем он вообще это сказал."));
                scene.add_sequence(ks::DialogItem("hi", "Да уж… Просто мне непривычно такое количество медперсонала в школе."));
                scene.add_sequence(ks::DialogItem("nk", "Скоро привыкнешь."));
                scene.add_sequence(ks::DialogItem("", "Я не так в этом уверен, однако не считаю нужным оповещать его об этом."));
                scene.add_sequence(ks::DialogItem("nk", "Давай-ка я снова найду твою медкарту…"));
                scene.add_sequence(ks::DialogItem("", "Пока он ищет что-то в компьютере и тасует пачки бумаг на столе, я осматриваюсь вокруг."));
                scene.add_sequence(ks::DialogItem("", "Обстановка представляет собой воплощённую заурядность."));
                scene.add_sequence(ks::DialogItem("", "Бежевые стены и потолок, пол, покрытый тёмно-серым ламинатом, и оборудование, которое ожидаешь увидеть в кабинете у школьного медработника."));
                scene.add_sequence(ks::DialogItem("", "А на стенах висят нелепые плакаты, призывающие меня правильно питаться – три раза в день и полным набором продуктов."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Фельдшер с довольной улыбкой извлекает из кипы бумаг толстенную папку и открывает её."));
                scene.add_sequence(ks::DialogItem("nk", "Так, ты уже принимаешь лекарства от аритмии, просто не забывай делать это утром и вечером, иначе от них будет мало пользы."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Помимо этого… ты занимаешься спортом? Активным? Например, не знаю… боксом?"));
                scene.add_sequence(ks::DialogItem("", "Он улыбается собственной шутке, но я её игнорирую."));
                scene.add_sequence(ks::DialogItem("hi", "Ну, я, бывало, играл в футбол с одноклассниками."));
                scene.add_sequence(ks::DialogItem("nk", "Ясно. Боюсь, мне придётся порекомендовать тебе воздержаться от этого, по крайней мере на время обучения здесь."));
                scene.add_sequence(ks::DialogItem("hi", "Угу."));
                scene.add_sequence(ks::DialogItem("", "Он приподнимает брови в ответ на мою вялую реакцию, но сейчас меня и в самом деле не особенно заботит запрет пинать мяч."));
                scene.add_sequence(ks::DialogItem("", "Думаю, я делал это не из-за горячей любви к спорту, а просто чтобы убить время."));
                scene.add_sequence(ks::DialogItem("nk", "Любой удар в область сердца для тебя очень опасен, и рисковать схлопотать очередной приступ было бы не очень хорошей идеей."));
                scene.add_sequence(ks::DialogItem("nk", "Предыдущий приступ тоже был вызван ударом? В бумагах об этом не упоминается."));
                scene.add_sequence(ks::DialogItem("hi", "Ну… не совсем."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Я уклоняюсь от ответа, и он серьёзно смотрит на меня поверх бумаг."));
                scene.add_sequence(ks::DialogItem("nk", "Но всё равно тебе нужно поддерживать форму и кое-какие упражнения пойдут на пользу."));
                scene.add_sequence(ks::DialogItem("nk", "Как я уже сказал, у нас есть кабинет физиотерапии, но я не думаю, что в твоём случае она столь необходима."));
                scene.add_sequence(ks::DialogItem("nk", "Просто регулярно выполняй простые упражнения."));
                scene.add_sequence(ks::DialogItem("nk", "Небольшие прогулки или даже бег трусцой, скакалка и тому подобное. Например, плавание. У нас тут есть бассейн."));
                scene.add_sequence(ks::DialogItem("hi", "Мне уже сказали."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Да? Очень хорошо."));
                scene.add_sequence(ks::DialogItem("nk", "В любом случае, хоть я и уверен, что тебе это уже говорили, будь осторожен и не переутомляйся."));
                scene.add_sequence(ks::DialogItem("", "Он грозит пальцем, чтобы подчеркнуть важность своих слов. Впрочем, я действительно слышал это уже тысячу раз."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Никакого ненужного риска. Береги себя."));
                scene.add_sequence(ks::DialogItem("hi", "Хорошо."));
                scene.add_sequence(ks::DialogItem("", "Он ещё раз пробегает глазами по моим бумагам и откладывает их на край стола, по-видимому удовлетворённый."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::nurse, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("nk", "Хорошо. Тогда всё. Приходи, если ещё что-нибудь понадобится."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_nursehall));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "Меня выпроваживают так быстро, что я даже не успеваю опомниться. И правда, краткий визит."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_in_the_nursery__condition_0;
                // a1_monday_in_the_nursery__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayRu::a1_monday_in_the_nursery__condition_0_0));
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
                scene.add_sequence(ks::DialogItem("", "Передо мной открывается вид на главное и административное здания. Впрочем, на мой взгляд, они практически одинаковые."));
                scene.add_sequence(ks::DialogItem("", "Зато я впервые могу спокойно рассмотреть других учеников, поэтому просто стою и наблюдаю, как они выходят из школы и расходятся по своим делам – в общежитие или к воротам, за территорию."));
                scene.add_sequence(ks::DialogItem("", "Кажется, они все знают, куда им нужно."));
                scene.add_sequence(ks::DialogItem("", "И я всё ещё думаю, что большинство из них не выглядят настолько «особенными», чтобы ходить в специальную школу. Да и я тоже."));
                scene.add_sequence(ks::DialogItem("", "Это делает меня одним из них?{w} Одним из нас?"));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::DialogItem("", "Я тоже должен идти, пока меня не потеряли."));
                scene.add_sequence(ks::DialogItem("", "Пора ужинать, но я чувствую себя скорее уставшим, чем голодным."));
                scene.add_sequence(ks::DialogItem("", "Пока я плетусь к общежитию, удаляясь от главного здания, усталость во мне только нарастает."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_gardens));
                scene.add_sequence(ks::DialogItem("", "Между школой и общежитием раскинулся небольшой сквер. Кусты, цветы и наполняющий воздух сильный запах свежескошенной травы."));
                scene.add_sequence(ks::DialogItem("", "Сквозь усталость мне приходит в голову мысль, что запах кажется таким непривычным просто потому, что я давно не был на свежем воздухе."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormext_start));
                scene.add_sequence(ks::DialogItem("", "Общежитие оказывается большим старомодным строением из красного кирпича, таким же помпезным, как и всё в этой школе. Я толкаю дверь и вхожу внутрь."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormhallground));
                scene.add_sequence(ks::DialogItem("", "С трудом выудив ключ из кармана, я отправляюсь искать свою комнату."));
                scene.add_sequence(ks::DialogItem("hi", "Комната один-один-девять…"));
                scene.add_sequence(ks::DialogItem("", "Несмотря на весь внешний антураж, внутри здание общежития выглядит современным, функциональным и скучным."));
                scene.add_sequence(ks::DialogItem("", "Как и в главном здании, просторные коридоры, широкие двери и лифты в коридорах приспособлены для инвалидных колясок."));
                scene.add_sequence(ks::DialogItem("", "Я заглядываю в первую попавшуюся комнату."));
                scene.add_sequence(ks::DialogItem("", "Внутри несколько учеников смотрят телевизор."));
                scene.add_sequence(ks::DialogItem("", "Один из них кивает мне и бросает «привет», прежде чем вновь отвернуться к экрану."));
                scene.add_sequence(ks::DialogItem("", "Видимо, общительны здесь только девушки. Что ж, меня это вполне устраивает."));
                scene.add_sequence(ks::DialogItem("", "Я поднимаюсь на второй этаж."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormhallway));
                scene.add_sequence(ks::DialogItem("", "Здесь коридор разветвляется на небольшие блоки."));
                scene.add_sequence(ks::DialogItem("", "В каждом из этих блоков расположены четыре комнаты и общие туалет и душевая."));
                scene.add_sequence(ks::DialogItem("", "Примерно в середине коридора одного из них я и нахожу комнату 119."));
                scene.add_sequence(ks::DialogItem("", "Именные таблички на дверях напротив пусты. Видимо, нас тут только двое."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "Из-под двери комнаты 117 виден свет, и я тихонько стучусь туда."));
                scene.add_sequence(ks::DialogItem("hi", "Эй, есть кто дома?"));
                scene.add_sequence(ks::DialogItem("", "Внутри слышится возня, затем щёлкает гораздо больше замков, чем можно было ожидать. Через мгновение дверь со скрипом открывается."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::MusicNotFoundItem());
                scene.add_sequence(ks::DialogItem("", "На пороге стоит парень в очках; он пристально смотрит на меня сквозь невероятно толстые линзы."));
                scene.add_sequence(ks::DialogItem("ke_", "Кто там?"));
                scene.add_sequence(ks::DialogItem("", "Слепой? Нет, видимо не совсем, иначе зачем ему очки…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Он подходит ко мне так близко, что наши носы чуть не соприкасаются. От него воняет чесноком."));
                scene.add_sequence(ks::DialogItem("hi", "Хисао Накай. Я буду жить в соседней комнате. Я подумал, что мне следует предста—"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Его лицо неожиданно проясняется, и он, отступив назад, с улыбкой протягивает руку куда-то в область моей диафрагмы."));
                scene.add_sequence(ks::DialogItem("ke_", "О, привет, чувак. Я Кендзи."));
                scene.add_sequence(ks::DialogItem("hi", "Привет."));
                scene.add_sequence(ks::DialogItem("", "Я пожимаю его потную ладонь, слегка опешив от резкой перемены его настроения и столь пылкого приветствия."));
                scene.add_sequence(ks::DialogItem("ke", "В твоей комнате недавно были какие-то подозрительные люди."));
                scene.add_sequence(ks::DialogItem("hi", "Вероятно, это были мои родители."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Родители? Ты уверен? Ведь это могли быть и какие-то другие люди. Никогда не стоит судить о книге по обложке."));
                scene.add_sequence(ks::DialogItem("", "Это неуместное сравнение повисает между нами, пока я пытаюсь придумать, что бы ответить."));
                scene.add_sequence(ks::DialogItem("hi", "Вероятность этого достаточно высока."));
                scene.add_sequence(ks::DialogItem("", "Он вздрагивает и делает неопределённый жест руками."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Да ты храбрец, Хисао."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "А вот я бы не стал доверять вероятности."));
                scene.add_sequence(ks::DialogItem("ke", "Единственный, кому я доверяю, – это я сам."));
                scene.add_sequence(ks::DialogItem("hi", "Значит, у тебя нет оснований доверять и моим словам."));
                scene.add_sequence(ks::DialogItem("", "Он ненадолго задумывается."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Верно подмечено."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Чёрт, а ты умнее, чем кажешься."));
                scene.add_sequence(ks::DialogItem("ke", "Возможно."));
                scene.add_sequence(ks::DialogItem("ke", "Как ты выглядишь? Надеюсь, не как какой-нибудь умник?"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Он щурится и снова наклоняется ко мне, однако я отступаю назад."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::kenji, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("ke", "Ладно, неважно."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::DialogItem("", "Он разворачивается, замешкавшись на мгновение, чтобы нашарить дверную ручку,{w=0.3}{nw}"));
                scene.add_sequence(ks::DialogItem("extend", "и захлопывает за собой дверь."));
                scene.add_sequence(ks::DialogItem("", "Я вставляю ключ в замочную скважину комнаты номер 119."));
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormhisao_ss));
                scene.add_sequence(ks::MusicItem(bn::music_items::music_night));
                scene.add_sequence(ks::DialogItem("", "Унылые бежевые стены, белое постельное бельё, стол из какого-то светлого дерева. Уродливые занавески."));
                scene.add_sequence(ks::DialogItem("", "Ничья комната. Лишённая всякой индивидуальности, как больничная палата."));
                scene.add_sequence(ks::DialogItem("", "Рядом с кроватью валяются мои сумки, уже гораздо более пустые, чем были с утра."));
                scene.add_sequence(ks::DialogItem("", "Открытый шкаф забит моей одеждой."));
                scene.add_sequence(ks::DialogItem("", "Я замечаю несколько комплектов школьной формы."));
                scene.add_sequence(ks::DialogItem("", "К рукаву одной из рубашек приколота записка."));
                scene.add_sequence(ks::DialogItem("", "Ну, по крайней мере, мне не нужно беспокоиться о распаковке вещей."));
                scene.add_sequence(ks::DialogItem("", "Хотя я надеялся, что можно будет ненадолго занять себя этим."));
                scene.add_sequence(ks::DialogItem("", "Ещё довольно рано."));
                scene.add_sequence(ks::DialogItem("", "Совершенно измотанный, я кладу записку на стол и ложусь."));
                scene.add_sequence(ks::DialogItem("", "Стоит мне только растянуться на кровати, как меня охватывает жажда чтения, но книг я с собой не взял."));
                scene.add_sequence(ks::DialogItem("", "Очевидно, это сказывается больничная привычка читать, когда больше нечем заняться."));
                scene.add_sequence(ks::DialogItem("", "Во мне нарастает странное беспокойство, в конце концов заставляющее меня встать."));
                scene.add_sequence(ks::DialogItem("", "Может, это из-за стресса?"));
                scene.add_sequence(ks::DialogItem("", "Я нервничал перед тем, как попасть сюда, и затем весь сегодняшний день. Наверное, продолжаю нервничать и сейчас."));
                scene.add_sequence(ks::DialogItem("", "Чёрт, мне надо как-то отвлечься, чтобы не быть постоянно таким скованным."));
                scene.add_sequence(ks::DialogItem("", "Завтра пойду и возьму пару книг в библиотеке."));
                scene.add_sequence(ks::DialogItem("", "Точно, так и сделаю."));
                scene.add_sequence(ks::DialogItem("", "А пока…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::pills:, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::pills:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Моё внимание привлекают аккуратно расставленные на прикроватном столике пузырьки с лекарствами."));
                scene.add_sequence(ks::DialogItem("", "Я беру один и трясу, просто чтобы услышать, как загремит содержимое, а затем читаю приклеенную этикетку."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::pills:, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "На самом деле надпись немного другая, но смысл примерно такой."));
                scene.add_sequence(ks::DialogItem("", "Это ненормально, когда твоя жизнь зависит от лекарств. Меня это раздражает, но разве у меня есть выбор?"));
                scene.add_sequence(ks::DialogItem("", "Со вздохом я приступаю к своему новому ежедневному ритуалу приёма нужного количества таблеток, внимательно следя за дозировкой."));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::DialogItem("", "Я снова ложусь, а затем долго смотрю на незнакомый и ничем не примечательный потолок, чувствуя внутри пустоту и неуверенность."));
                scene.add_sequence(ks::MusicStopItem());
                scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::school_dormhisao_ni));
                scene.add_sequence(ks::DialogItem("", "Потолок продолжает казаться чужим и когда комната погружается во тьму, а по стенам, словно пальцы, протягиваются тени."));
                scene.add_sequence(ks::DialogItem("", "Но постель становится чуть уютнее по сравнению с тем холодом, который считается тут комнатной температурой: смявшиеся простыни образовали подобие тёплого гнезда."));
                scene.add_sequence(ks::DialogItem("", "Скоро потолок превращается в смутную тень и начинает выглядеть как любой другой потолок ночью, оставшись единственной вещью, которую я ещё могу различить."));
                scene.add_sequence(ks::DialogItem("", "Ночь зовёт меня в сон, и я снова чувствую, как по моей спине ползёт холод от страха и неизвестности."));
                scene.add_sequence(ks::DialogItem("", "Я уплываю всё дальше от знакомого мне мира."));
                // bn::vector<ks::ConditionItem, 1> a1_monday_nobodys_room__condition_0;
                // a1_monday_nobodys_room__condition_0.push_back(ks::ConditionItem("_in_replay", &ScriptA1MondayRu::a1_monday_nobodys_room__condition_0_0));
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
                scene.add_sequence(ks::DialogItem("hi", "Зачем? Это обязательно?"));
                scene.add_sequence(ks::DialogItem("mu", "Конечно нет. Поэтому я и спрашиваю."));
                scene.add_sequence(ks::DialogItem("hi", "Ладно."));
                scene.add_sequence(ks::DialogItem("mu", "Ну, тогда пойдём."));
                return;
            }
            static void a1c1o2(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("hi", "Да, конечно. В смысле, мне кажется, что так принято."));
                scene.add_sequence(ks::DialogItem("mu", "Разумеется. Просто не все любят быть в центре внимания."));
                scene.add_sequence(ks::DialogItem("", "Наверное, я как раз из таких людей, но лучше бы мне произвести первое впечатление самостоятельно."));
                scene.add_sequence(ks::DialogItem("hi", "Бывает, но для меня это не проблема."));
                scene.add_sequence(ks::DialogItem("mu", "Ну, тогда пойдём."));
                return;
            }
            static void a1c2o1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("hi", "Ах да. В этой школе есть библиотека? В последнее время я увлёкся чтением, так что хотел бы туда сходить."));
                scene.add_sequence(ks::DialogItem("", "Миша одаряет меня хмурым взглядом, дающим понять, что она не считает чтение здоровой привычкой, но затем улыбка снова возвращается к ней."));
                scene.add_sequence(ks::DialogItem("mi", "Есть~! На втором этаже, мы потом тебе покажем!"));
                scene.add_sequence(ks::DialogItem("hi", "Спасибо."));
                scene.add_sequence(ks::DialogItem("", "Я возвращаюсь к еде, а девочки тем временем общаются между собой."));
                return;
            }
            static void a1c2o2(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "Сидзунэ меня интересует, и мне хочется спросить что-нибудь о ней."));
                scene.add_sequence(ks::DialogItem("", "Но ведь я не могу спрашивать о чём-то столь личном, правильно?"));
                scene.add_sequence(ks::DialogItem("", "Хм…"));
                scene.add_sequence(ks::DialogItem("", "Я не могу придумать другого вопроса, поэтому просто возвращаюсь к еде, а девочки тем временем общаются между собой."));
                return;
            }
            static void a1c2o3(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("hi", "Честно говоря, на ум ничего не приходит."));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("mi", "О! Значит, мы были хорошими проводниками, правда, правда~?"));
                scene.add_sequence(ks::DialogItem("", "…"));
                scene.add_sequence(ks::DialogItem("hi", "Э… Как скажешь…"));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::misha, ks::SpriteEventType::None));
                // scene.add_sequence(ks::SpriteItem(bn::sprite_items::shizu, ks::SpriteEventType::None));
                scene.add_sequence(ks::DialogItem("", "Миша радостно улыбается и быстро переводит мои слова, после чего улыбка появляется и на лице Сидзунэ."));
                scene.add_sequence(ks::DialogItem("", "На их избыточный энтузиазм я качаю головой и сосредотачиваюсь на еде."));
                return;
            }
            static void a1_monday_gateway_effect__menu_question_0(ks::SceneManager& scene) {
                // bn::vector<ks::AnswerItem, 2> answers;
                // answers.push_back(ks::AnswerItem("Why?", &ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0_why));
                // answers.push_back(ks::AnswerItem("Yeah, of course.", &ScriptA1MondayRu::a1_monday_gateway_effect__menu_question_0_yeah_of_course));
                // scene.add_sequence(ks::MenuItem(answers);
            }
            static void a1_monday_gateway_effect__menu_question_0_why(ks::SceneManager& scene) {
                // scene.add_sequence(ks::AssignmentItem("wanted_introduce = False"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayRu::a1c1o1(scene);}));
            }
            static void a1_monday_gateway_effect__menu_question_0_yeah_of_course(ks::SceneManager& scene) {
                // scene.add_sequence(ks::AssignmentItem("wanted_introduce = True"));
                // scene.add_sequence(ks::AssignmentItem("attraction_sc += 1"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayRu::a1c1o2(scene);}));
            }
            static void a1_monday_in_the_nursery__menu_question_0(ks::SceneManager& scene) {
                // bn::vector<ks::AnswerItem, 3> answers;
                // answers.push_back(ks::AnswerItem("Ask about the library.", &ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0_ask_about_the_library));
                // answers.push_back(ks::AnswerItem("Ask about Shizune's deafness.", &ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness));
                // answers.push_back(ks::AnswerItem("I think I got everything I need to know.", &ScriptA1MondayRu::a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know));
                // scene.add_sequence(ks::MenuItem(answers);
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_the_library(ks::SceneManager& scene) {
                // scene.add_sequence(ks::AssignmentItem("attraction_hanako += 1"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayRu::a1c2o1(scene);}));
            }
            static void a1_monday_in_the_nursery__menu_question_0_ask_about_shizunes_deafness(ks::SceneManager& scene) {
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayRu::a1c2o2(scene);}));
            }
            static void a1_monday_in_the_nursery__menu_question_0_i_think_i_got_everything_i_need_to_know(ks::SceneManager& scene) {
                // scene.add_sequence(ks::AssignmentItem("attraction_sc += 1"));
                scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){ScriptA1MondayRu::a1c2o3(scene);}));
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
                scene.add_sequence(ks::DialogItem("", "После этого в классе повисает пауза, намекающая мне, что следует наконец что-то сказать."));
                scene.add_sequence(ks::DialogItem("hi", "Ну… Я – Хисао Накай."));
                scene.add_sequence(ks::DialogItem("", "И что ещё?"));
                scene.add_sequence(ks::DialogItem("hi", "Я увлекаюсь чтением и футболом. Надеюсь, что мы поладим, хоть я здесь и новенький."));
                scene.add_sequence(ks::DialogItem("", "А ещё что?"));
                scene.add_sequence(ks::DialogItem("", "Я ужасно скучен. Самопредставление до невозможности банальное. Надо придумать что-нибудь ещё. Что-нибудь поинтереснее."));
                scene.add_sequence(ks::DialogItem("", "…В итоге я так ничего и не говорю и учитель продолжает за меня."));
                scene.add_sequence(ks::DialogItem("", "Впрочем, кажется, все вполне удовлетворены и той малостью, что я рассказал. Несколько девочек перешёптываются, бросая на меня взгляды. Могло быть и хуже."));
                scene.add_sequence(ks::DialogItem("", "…"));
            }
            static void a1_monday_enter_stage_left__condition_0_1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "После этого в классе повисает пауза, которую никто не торопится прервать."));
                scene.add_sequence(ks::DialogItem("", "Учитель понимает, что пора сказать что-нибудь ещё. Он неразборчиво произносит моё имя и умолкает, потеряв настрой."));
                scene.add_sequence(ks::DialogItem("", "После этого он пытается рассказать обо мне классу, но никто не проявляет особого интереса."));
                scene.add_sequence(ks::DialogItem("", "Может быть, мне стоило представиться самому?"));
                scene.add_sequence(ks::DialogItem("", "Вероятно, поняв, что толком ничего обо мне не знает, он заканчивает тем, что снова перевирает моё имя и просит написать его на доске."));
                scene.add_sequence(ks::DialogItem("", "Я делаю это и поворачиваюсь к классу, чувствуя себя идиотом."));
            }
            static void a1_monday_enter_stage_left__condition_1_0(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("mi", "Похоже, он очень интересный человек, правда~?"));
            }
            static void a1_monday_enter_stage_left__condition_1_1(ks::SceneManager& scene) {
                scene.add_sequence(ks::DialogItem("", "Миша окидывает меня странным взглядом, а затем продолжает."));
                scene.add_sequence(ks::DialogItem("mi", "Мы о нём почти ничего не знаем, но, наверное, узнаем позже."));
                scene.add_sequence(ks::DialogItem("", "Всё же мне следовало рассказать о себе самостоятельно. Что угодно – это позволило бы сложить первое впечатление о себе куда лучше, чем невнятное бормотание учителя и путаница с именем."));
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