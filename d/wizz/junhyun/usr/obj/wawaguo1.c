//sea.c playerװ��
//by junhyun@SK

#include <armor.h>
#include <ansi.h>

inherit FINGER;


void create()
{
        set_name(HIW"�˲ι�"NOR, ({ "wawaguo", "ring" }) );
        set("long", "�װ����ֵ�һö�˲ι�����ǧ��һ��������ǧ��һ���������ǧ��ŵ��죬ʵ����ؼ���鱦��\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/spells", 50);
                set("armor_prop/dodge", 20);
                set("value", 50000);
        }
        setup();
}

