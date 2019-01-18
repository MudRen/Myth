// smith.c

#include <ansi.h>

inherit F_VENDOR_SALE; 

string ask_me();
int  do_gu(string arg);
int  do_dapi(string arg);
int  do_cuihuo(string arg);
int  do_repair(string arg);
void reward(object me);

// no create_function: inherit by other NPC

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_gu", "gu");
        add_action("do_dapi", "dapi");
        add_action("do_cuihuo", "cuihuo");
        add_action("do_repair", "repair");
        add_action("do_repair", "xiuli");
}

void setup()
{
        set("inquiry/job",    (: ask_me :));
        set("inquiry/����",   (: ask_me :));
        set("inquiry/repair", "����Ҫ��(" HIY "repair" NOR + CYN ")��ʲô��" NOR);
        set("inquiry/����",   "����Ҫ��(" HIY "repair" NOR + CYN ")��ʲô��" NOR);

        ::setup();
}

string ask_me()
{
        object me = this_player();

        if (me->query("combat_exp") > 100000)
                return "�����ϸ����δ�������˰ɣ�";

        if (me->query("kee") < 20)
                return "�㻹��Ъ����ɣ�Ҫ�ǳ��������ҿɳе�����";

        if (me->query_temp("smith/gu"))
                return "����ȥ��(" HIY "gu" NOR + CYN ")���䣬��"
                       "��ô��ĥ�䣿";

        if (me->query_temp("smith/dapi"))
                return "��������(" HIY "dapi" NOR + CYN ")���"
                       "��û�У�";

        if (me->query_temp("smith/cuihuo"))
                return "�ɻ���ô��͵��������Ҵ��(" HIY "cuihuo"
                       NOR + CYN ")ȥ��";

        switch(random(3))
        {
        case 0:
                me->set_temp("smith/gu", 1);
                return "�ã�����ҹ�(" HIY "gu" NOR + CYN ")һ��"
                       "�����䡣";

        case 1:
                me->set_temp("smith/dapi", 1);
                return "�����ɣ�����Ҵ�(" HIY "dapi" NOR + CYN
                       ")һ�����ɣ�";

        case 2:
                me->set_temp("smith/cuihuo", 1);
                return "ȥ���Ұ���Щ�ճ�¯�Ĵ�(" HIY "cuihuo" NOR
                       + CYN ")һ�»�";
        }
}

int do_gu(string arg)
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("��������æ��\n");

        if (! me->query_temp("smith/gu"))
        {
                message_vision(HIR "\n$n" HIR "��͵͵������ķ������"
                               "�˼���硣\n������$N" HIR "��$n" HIR
                               "��ȵ����������Ҹ�ʲô��\n" NOR,
                               this_object(), me);
                return 1;
        }

        message_vision(HIY "$n" HIY "����ķ��ƴ������������$N" HIY
                       "���˵��˵�ͷ��\n" NOR,
                       this_object(), me);
        reward(me);
        return 1;
}

int do_dapi(string arg)
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("��������æ��\n");

        if (! me->query_temp("smith/dapi"))
        {
                message_vision(HIR "\n$n" HIR "���𼸿�������������"
                               "���˵ࡣ\n������$N" HIR "��$n" HIR
                               "��ȵ������£��Ҹ�ʲô��\n" NOR,
                               this_object(), me);
                return 1;
        }

        message_vision(HIY "$n" HIY "���Ŵ��ӶԸճ�¯�Ļ��ȵ�������"
                       "���ô��ţ�$N" HIY "���š���һ��������ȥ��Щ"
                       "���⡣\n" NOR,
                       this_object(), me);
        reward(me);
        return 1;
}

int do_cuihuo(string arg)
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("��������æ��\n");

        if (! me->query_temp("smith/cuihuo"))
        {
                message_vision(HIR "\n$n" HIR "�ճ���һ������õ�����"
                               "����Ū�˼��¡�\n������$N" HIR "��$n"
                               HIR "��ȵ������£�����Ҹ㻵�ˡ�\n" NOR,
                               this_object(), me);
                return 1;
        }

        message_vision(HIY "$N" HIY "����ǯ����һ��������ӣ����"
                       "��ˮ�أ����ꡱ��һ��������ð��\n" NOR, me);
        reward(me);
        return 1;
}

void reward(object me)
{
        int exp, pot;
        object coin;

        me->delete_temp("smith/gu");
        me->delete_temp("smith/dapi");
        me->delete_temp("smith/cuihuo");

        coin = new("/obj/money/silver");
        coin->set_amount(5 + random(5));
        coin->move(this_object());
        message_vision(CYN "$N" CYN "��$n" CYN "�����ɵò��������Ǹ�"
                       "��Ĺ�Ǯ��\n" NOR, this_object(), me);

        command("give silver to " + me->query("id"));

        exp = 10 + random(10);
        pot = 5 + random(5);

        me->add("combat_exp", exp);
        me->improve_potential(pot);

        tell_object(me, HIC "������" + chinese_number(exp) +
                        "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�"
                        "\n" NOR );

        me->receive_damage("kee", 10 + random(10));
        me->start_busy(3);
}

int do_repair(string arg)
{
        object me;
        object ob;
        mixed  msg;
        int consistence;
        int cost;
        mapping repair;

        if (! arg)
                return notify_fail("���������ʲô�����\n");

        me = this_player();

        if (! objectp(ob = present(arg, me)))
                return notify_fail("�����Ϻ���û������������\n");

        if (undefinedp(consistence = ob->query("consistence")))
                return notify_fail(ob->name() + "�ƺ�����Ҫ����������ɣ�\n");

        if (consistence >= 100)
                return notify_fail(ob->name() + "�����������������ʲô��\n");

        if (! undefinedp(msg = ob->query("no_repair")))
        {
                if (! stringp(msg))
                        write(CYN + name() + CYN "��ü�����ⶫ���ҿ���"
                              "���ˡ�\n" NOR);
                else
                        write(CYN + name() + CYN "��ü����" + msg + NOR
                              + CYN);
                return 1;
        }

        if (mapp(repair = me->query_temp("pending/repair")) &&
            repair["item"] == ob)
        {
                if (me->is_busy())
                        return notify_fail("��������æ���أ�\n");

                if (MONEY_D->player_pay(me, repair["cost"]) != 1)
                        return 0;

                message_vision(HIW "$n" HIW "��" + ob->name() + HIW "��"
                               "����$N" HIW "��\nֻ��$N" HIW "���𹤾ߣ�"
                               "������������" + ob->name() + HIW "�ú���"
                               "���ޡ�\n" NOR, this_object(), me);

                ob->set("consistence", 100);
                message_vision(HIC "$N" HIC "���������ˡ������ְ�" + ob->name()
                               + HIC "������$n" HIC "��$n" HIC "���˿���"
                               "������ͳ���һЩǮ�����ʡ�\n" NOR,
                               this_object(), me);

                me->start_busy(1 + random(100 - consistence) / 10);
                me->delete_temp("pending/repair");
                return 1;
        }

        cost = (120 - consistence) * ob->query("value") / 480;
        if (cost >= 100000) cost = ((cost - 100000) / 2 + 100000) / 10000 * 10000; else
        if (cost >= 10000)  cost = cost / 1000 * 1000; else
        if (cost >= 1000)   cost = cost / 100 * 100; else
        if (cost >= 100)    cost = cost / 10 * 10;

        message_vision(CYN "\n$n" CYN "�ó�һ" + ob->query("unit") +
                       ob->name() + NOR + CYN "��$N" CYN "Ƴ��һ��"
                       "������Ҫ�޺�����Ҫ" + MONEY_D->price_str(cost) +
                       NOR + CYN "���С�\n" NOR, this_object(), me);

        tell_object(me, YEL "������ȷ�����������Ʒ����������һ���������\n" NOR);
        me->set_temp("pending/repair/item", ob);
        me->set_temp("pending/repair/cost", cost);
        return 1;
}

