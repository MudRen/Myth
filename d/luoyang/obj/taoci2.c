#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "�������" NOR, ({ "biyu cima", "biyu", "cima"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIW "�����������Ƶı����մ����ǳ��İ���\n" NOR);
                set("value", 15000);
        }
}

