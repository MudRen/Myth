// ������ָ by Calvin

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(RED"��"+BLU"��"+CYN"��ָ"NOR, ({ "yinyang jiezhi", "jiezhi", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
set("value", 10000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
                set("material", "gold");
   set("armor_prop/armor", 40);
                set("armor_prop/spells", 100);
        }
        setup();
}       
