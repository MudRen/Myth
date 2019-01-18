// huanyang.c
// ������
// modify by mudring
// ����������ʧ����.

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
    if (!wizardp(this_player()))
    {
        set("no_get", "�ٺ٣����ΰ�! \n");
        set("no_drop","��ô����Ļ���������������! \n");
    }
                                             
    add_action("do_eat", "eat");
}

void create()
{
    set_name(HIG "������" NOR, ({"huanyang dan", "dan"}));
    set_weight(20);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ������������˵����������֮Ч��\n");
        set("value", 100000);
    }

    set("is_monitored", 1);
    setup();
}

int do_eat(string arg)
{
    int i, j, k, l;
    object victim = this_player();
    string wizard = this_object()->query("clone_by_wizard");

    if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

    if (!stringp(wizard))
        return notify_fail("�Ķ�͵�ģ���\n");

    i = victim->query("death/combat_exp_loss");
    j = victim->query("death/dx_loss");
    k = victim->query("death/skill_loss");
    l = victim->query("death/pot_loss");

    victim->add("combat_exp", i);
    victim->add("daoxing", j);
    victim->add("potential", l);

    while (k--)
    {
        victim->skill_death_recover();
    }

/*
    if ((int)victim->query("potential") > (int)victim->query("learned_points"))
        victim->add("potential",
                    ((int)victim->query("potential") 
                     - (int)victim->query("learned_points") ) * 4 / 5);
*/

    victim->set("death/combat_exp_loss", 0);
    victim->set("death/dx_loss", 0);
    victim->set("death/skill_loss", 0);
    victim->set("death/pot_loss", 0);
    victim->set("die_reason", "�Ѿ���" + wizard +"�û������ָ�");
    victim->save();

    if (userp(victim))
        log_file("static/EATHYD", sprintf("%s(%s) Got recovered by %s on %s.\n",
                 victim->name(1), geteuid(victim), wizard, log_time()));

    message_vision(HIG "\n$N����һ����������Ӳ�ǴӰ��޳��������ѣ������һ��С����\n\n" NOR, 
                   victim);

    call_out("dest", 0);
    return 1;
}

void dest()
{
    if (this_object())
        destruct(this_object());
}
