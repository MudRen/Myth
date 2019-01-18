// kuangquan.c ��Ȫˮ

#include <ansi.h>

inherit ITEM;

int filter_user(object ob);

void create()
{
        set_name(HIG "��Ȫˮ" NOR, ({ "water" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һƿ��Ȫˮ���������ƿڸ���"
                            "����ܷɵ�Ϯ���Ժ�о��������á�\n");
                set("value", 8000);
                set("no_sell", 1);
                set("unit", "ƿ");
        }
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me;

        if (! arg || ! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision(HIG "$N�ͳ�һƿ" + name() + HIG
                       "�������˹��ˡ����˸��ɸɾ�����\n" NOR, me);
        me->set("water", me->max_water_capacity());
        me->permit_say(60);
        destruct(this_object());
        return 1;
}

