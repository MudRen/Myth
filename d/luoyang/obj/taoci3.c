#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "����������" NOR, ({ "puti shu", "puti", "shu"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIR "�����������Ƶĵ������������ǳ��İ���\n" NOR);
                set("value", 15000);
        }
}

