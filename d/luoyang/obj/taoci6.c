#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "�״ɹ�����" NOR, ({ "guanyin xiang", "guanyin", "xiang"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIW "�����������Ƶİ״ɹ����񣬷ǳ��İ���\n" NOR);
                set("value", 15000);
        }
}

