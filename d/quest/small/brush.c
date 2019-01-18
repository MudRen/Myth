// brush.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Ьˢ��", ({ "brush", "shua zi" }) );
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "һ��ˢ�ӣ���ר������ˢЬ�õġ�\n");
                set("value", 200);
        }
        setup();
}

void init()
{
        add_action("do_swab", "swab");
        add_action("do_swab", "caxie");
}

int do_swab(string arg)
{
        int exp;
        object ob;      
        object me;
        object money;
        object shoeshine;

        me = this_player();
        if (! arg || ! objectp(ob = present(arg, environment(me))))
                return notify_fail("��ҪΪ˭��Ь��\n");

        if (! ob->is_character() || ob->query("not_living"))
                return notify_fail("������ˣ��ǲ��ǻ��ˣ�\n");

        if (! ob->query("can_speak"))
                return notify_fail("�Թ�����û����˵����" +
                                   ob->name() + "��Ь�ģ�\n");

        if (! living(ob))
                return notify_fail("�㻹�ǵȱ���������˵�ɣ�\n");

        if (ob == me)
        {
                message_vision("$N�������е�ˢ�ӣ������Լ�������"
                               "�Լ����Ǻ����࣬һʱ�̲�ס��Ҫ���ᣡ\n",
                               this_player());
                return 1;
        }

        if (! objectp(shoeshine = present("xie you", me)))
        {
                write("������û��Ь���ˡ�\n");
                return 1;
        }

        if (me->is_busy())
                return notify_fail("��������æ���أ����ǵ�һ�����˵�ɣ�\n");

        me->start_busy(2);

        if (playerp(ob))
        {
                shoeshine->cost();

                if (me->query("couple/id") == ob->query("id"))
                {
                        message_vision("$N������һ�����ĵİ�$n��Ь����������"
                                       "�ġ�$n������$N��ͷ˵������" +
                                       (me->query("gender") == "����" ?
                                        "�Ϲ������Ь���úú�Ŷ��" :
                                        "���ţ����Ь������Ư����") +
                                       "��\n", me, ob);
                        return 1;
                }

                message_vision("$Nһ�����ĵ���$n��Ь����������ֻ��$n"
                               "Ц���п���$P���������ã��ã���\n",
                               me, ob);
                if (ob->is_fighting(me))
                {
                        if (me->query("weiwang") > 1000)
                                me->add("weiwang", -2);
                        else
                        {
                                message_vision("$NЦ������ĵ��л�ǳ������ô"
                                               "���Ҳ�ЬҲû���ã����У�\n",
                                               ob);
                                write("�����д��ֹ��\n");
                                return 1;
                        }
                        ob->remove_enemy(me);
                        ob->remove_killer(me);
                        me->remove_enemy(ob);
                        me->remove_killer(ob);
                        write(ob->name() + "ֹͣ�˶���Ĺ�����\n");
                        return 1;
                }
                write("�����а�����˥��һ��Ǯ��û�У�\n");
                return 1;
        }

        if (me->is_fighting())
        {
                write("�㻹�ǵȴ�����ٲ�Ь�ɣ�\n");
                return 1;
        }

        if (time() - ob->query_temp("last_swab") < 240)
        {
                message_vision("$nһ���߿���$N��������������"
                               "�������ˣ��㻹�Ǹ��������ɣ�\n",
                               me, ob);
                return 1;
        }

        message_vision("$N�������������ڵİ�$n��Ь����һ����һ�顣\n",
                       me, ob);
        shoeshine->cost();
        if (me->query("weiwang") > 10)
                me->add("weiwang", -1);
        else
                me->set("weiwang", 0);

        ob->set_temp("last_swab", time());

        exp = 10 + random(15);
        if (me->query("combat_exp") < 50000)
                me->add("combat_exp", exp);
        if (me->query("daoxing") < 50000)
                me->add("daoxing", exp);                

        if (me->query("potential") < me->query_potential_limit())
                me->add("potential", 5+random(10) );

        money = new("/obj/money/coin");
        money->set_amount(70 + random(50));

        message_vision("$n����Ь���ߺߵ����ã��������Ǯ���͸���ģ�\n"
                       "$N��æ��ͷ������Ц���еĽ��˹�����\n", me, ob);
        money->move(me, 1);
        return 1;
}


