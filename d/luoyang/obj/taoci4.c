#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC "�˱�������" NOR, ({ "lianhua zuo", "lianhua", "zuo"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIC "�����������Ƶİ˱����������ǳ��İ���\n" NOR);
                set("value", 15000);
        }
}

