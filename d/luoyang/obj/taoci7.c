#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT "����ī�ƶ�" NOR, ({ "moyun dou", "moyun", "dou"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", WHT "�����������Ƶ�����ī�ƶ����ǳ��İ���\n" NOR);
                set("value", 15000);
        }
}

