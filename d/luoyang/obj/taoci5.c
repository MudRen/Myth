#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC "���������" NOR, ({ "feitian pei", "feitian", "pei"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIC "�����������Ƶ���������壬�ǳ��İ���\n" NOR);
                set("value", 15000);
        }
}

