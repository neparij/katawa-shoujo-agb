// Generated code, do not edit
// Generated at 2025-10-14T21:45:25+00:00
#pragma once
#define KSDEF(name, value) \
    const char* definitions_##name() override { return value; }

#define KSLANGDEF(name, value) \
    const char* language_##name() override { return value; }

KSDEF(no_scene, "シーンなし")
KSDEF(nothing, "何もない")
KSDEF(hi, "久夫")
KSDEF(ha, "華子")
KSDEF(emi, "笑美")
KSDEF(rin, "琳")
KSDEF(li, "リリー")
KSDEF(shi, "静音")
KSDEF(mi, "ミーシャ")
KSDEF(ke, "健二")
KSDEF(mu, "武藤")
KSDEF(nk, "ナース")
KSDEF(no, "野宮")
KSDEF(yu, "優子")
KSDEF(sa, "さえ")
KSDEF(aki, "晃")
KSDEF(hh, "秀明")
KSDEF(hx, "治五郎")
KSDEF(emm, "芽依子")
KSDEF(sk, "店主")
KSDEF(mk, "美貴")
KSDEF(mi_shi, "静音")
KSDEF(mi_not_shi, "{s}静音{/s} ミーシャ")
KSDEF(mystery, "???")
KSDEF(ha_, "紫色の髪の少女")
KSDEF(emi_, "ツインテールの少女")
KSDEF(rin_, "謎の少女")
KSDEF(li_, "ウェーブヘアの少女")
KSDEF(mi_, "笑っている少女")
KSDEF(ke_, "眼鏡をかけた生徒")
KSDEF(mu_, "背の高い男")
KSDEF(yu_, "司書")
KSDEF(no_, "白髪の男")
KSDEF(sa_, "画廊のオーナー")
KSDEF(aki_, "身なりの良い人")
KSDEF(nk_, "笑っている男")
KSDEF(hx_, "大男")
KSDEF(hh_, "スリムな少女")
KSDEF(emm_, "三つ編みの女性")
KSLANGDEF(en, "英語")
KSLANGDEF(ru, "ロシア語")
KSLANGDEF(fr, "フランス語")
KSLANGDEF(it, "イタリア語")
KSLANGDEF(es, "スペイン語")
KSLANGDEF(de, "ドイツ語")
KSLANGDEF(jp, "日本語")
KSLANGDEF(zh_hans, "簡体字中国語")
#undef KSDEF
#undef KSLANGDEF
