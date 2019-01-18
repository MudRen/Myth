//雷煌剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIC"倚天剑"NOR,({ "yitian jian", "yitian", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("rigidity", 9);
                set("sharpness", 9);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/dodge", 50);
                set("weapon_prop/parry", 50);
                set("treasure",1);
                set("wield_str", 22);
                set("wield_msg", HIC"
$N“唰”的一声抽出倚天宝剑，之见霞光四射，剑身微颤，嗡嗡作响！\n"NOR);
                set("long", "
这是一柄四尺来长的古剑，整个剑身隐隐发出丝丝青光，剑未出鞘，已可见其不凡。\n");                
                set("unwield_msg", HIB "倚天宝剑幻作一道霞光，「唰」地飞入天际。\n" NOR);                
        }
         init_sword(195);
        setup();
}

