#include "herb.h"

void create()
{
        set_name(HIR "�ܵ�" NOR, ({ "xiong dan", "xiong", "dan", "herb_xiongdan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "����һ�����ʵ��ܵ����ľ�ҩ����\n" NOR);
                set("base_unit", "��");
                set("value", 15000);
                set("base_weight", 200);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision(HIG "$N" HIG "һ��������" + name() +
                       HIG "�������£��������졣\n" NOR, me);

        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}

