// ���� by Calvin
// 2001.6

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "����" NOR, ({ "long zhu","zhu" }));
        set_weight(2000);
        set("long", "����һ��Ư����Сʯͷ��,�������|��|,��˵�����ռ������߿��������һ��ʱ����� ...\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "stone");
                set("value", 200);
                set("no_sell", 1);
                set("amount",30);
        }
        setup();
}
