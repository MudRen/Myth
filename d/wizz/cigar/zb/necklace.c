#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name(CYN"ˮ������"NOR, ({"shuijing xianglian","necklace","xianglian" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_zm",1);
                set("no_give",1);
                set("material", "pearl");
set("value", 10000);
                set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_put",1);
                set("armor_prop/armor", 50);
        }
        setup();
}

