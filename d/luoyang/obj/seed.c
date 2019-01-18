#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "����" NOR, ({"hua zhong", "hua", "zhong"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һö�޷�ȷ��Ʒ�ֵĻ��֡�\n");
                set("unit", "ֻ");
                set("value", 1);
                set("food_remaining", 1);
                set("food_supply", 10);
        }
}

void init()
{
        add_action("do_zhonghua", "zhonghua");
}

int do_zhonghua()
{
        object me, ob, where;
 
        me = this_player();
        ob = this_object();
        where = environment(me);

        if ((string)where->query("short") != "��԰")
                return notify_fail("�����ƺ����ʺ��ֻ��ɣ�\n");

        if (me->query("combat_exp") < 10000)
        {
                tell_object(me, "��ľ�����ǳ�������ȵ������߶��߶��ɡ�\n");
                return 1;
        }

        if (me->query("combat_exp") > 300000)
        {
                tell_object(me, "�������ݴ�Ų��ʺ��ֻ��˰ɡ�\n");
                return 1;
        }

        if (me->query_temp("zhonghua") == 1)
        {
                tell_object(me, "�����Ѿ������ˣ����ڸ�����"
                                HIY "(peiyu)" NOR "�����ˡ�"
                                "\n");
                return 1;
        }

        message_vision(HIC "$N" HIC "�����ڵ�������һ��С"
                       "�ӣ��ѻ��ַ��˽�ȥ��\n" NOR, me);
        tell_object(me, "�����Ѿ������ˣ����ڸ�����" HIY
                        "(peiyu)" NOR "�����ˡ�\n");
        me->add_temp("zhonghua", 1);
        destruct(ob);
        me->add("sen", -60);
        return 1;
}


