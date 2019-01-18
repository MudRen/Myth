// saozhou
// by mudring Dec/22/2002

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("��ɨ��", ({"sao zhou", "saozhou"}));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("no_drop","�Լ���ɨ��ֵĶ����Ӷ�����\n");
        set("no_sell","��ô��Ķ���˭Ҫ��\n");
        set("no_put",1);
        set("long", "����һ�Ѵ�ɨ�㣬�����������ɨ(sao)��֡�\n");
        set("value", 100);
    }
    setup();
}

void init()
{
    add_action("do_saojie", "sao");
    add_action("do_saojie", "saojie");
}

int do_saojie(string arg)
{
    int t;
    object me = this_player();
    object env = environment(me);

    if (!arg || arg != "here")
        return notify_fail("�����ʲô��\n");  

    if (!env->query("outdoors"))
        return notify_fail("����ɨ��ֻ��ǰ��˼����ӵ㹤ѽ��\n");

/*
    if (env->query("outdoors") != "changan")
        return notify_fail("�����������ɨ�����ֵ��ɣ���\n");
*/

    if (time() - env->query_temp("last_sao") < 30)
        return notify_fail("��������ܸɾ��أ�\n");

    if (me->is_busy())
        return notify_fail("��������æ���أ�\n");

    if (me->is_fighting())
        return notify_fail("�ߴ�ܱ�ɨ��֣��㳬�˰���\n");

    if (me->query("sen") < 100 || me->query("kee") < 100)
        return notify_fail("��̫���ˣ���������Ϣһ��ɣ�\n");

    tell_object (me,"�㿴�˿����ܣ�Ȼ��ʼɨ��֣�\n"NOR);

    if (me->query("daoxing") > 20000 || me->query("combat_exp") > 20000)
    {
        tell_object (me,"�������񹤣�����ΰ�󣬲���������һЩ���ˣ���\n"NOR);
        me->add("potential", 5 + random(6));
        if (me->query("weiwang") > 5) me->add("weiwang", -5);
    } else
    {
        tell_object (me,"���˿�����ĵ��棬���뻹Ҫ���ڣ��㼫����Ը�Ŀ�ʼ��ɨ����\n"NOR);
        me->add("daoxing", 10 + random(15));
        me->add("combat_exp", 10 + random(15));
        me->add("potential", 5 + random(10));
    }

    message_vision(HIC"$N�����ɨ�㿪ʼ�ڴ����������ɨ��������\n"NOR,me);

    if (!random(3))
    {
        MONEY_D->pay_player(me, 70 + random(30));
        tell_object (me,HIY"ͻȻ���ֵ�����һЩͭ�壬��Ͻ������������뻳�У�\n"NOR);
    }
    env->set_temp("last_sao",  time());
    me->start_busy(5);
    t++;

    if (t > (20 + random(10)))
    {
        message_vision("ɨ���Ѿ�ĥ��Ĳ����ˣ�������ȥҪ���µ��ˡ�\n",me); 
        message_vision("�㽫���õ�ɨ�����ڵ��ϣ�ɨ����ʧ�ˡ�\n",me); 
        call_out("dest", 2);
    }
    return 1;
}

void dest()
{   
    if (this_object())
        destruct(this_object());
}

