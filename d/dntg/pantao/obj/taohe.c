#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("�Һ�", ({ "tao he", "taohe","he" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һö�еľ�����Һˡ�\n");
                set("unit", "ö");
        }
//         set("no_give","���������Ӹ����Һˣ������˼Ҵ��㡣\n");
        set("no_get","Ҫ���Ұ����ȥ������Һ˲��ɾ���\n");
        setup();
}

