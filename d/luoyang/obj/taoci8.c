#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB "�̺������" NOR, ({ "qingtian jue", "qingtian", "jue"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIB "�����������Ƶı̺���������ǳ��İ���\n" NOR);
                set("value", 15000);
        }
}

