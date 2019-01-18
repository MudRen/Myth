// by cigar 
// quduwan.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "ȥ����" NOR, ({"qudu wan", "wan"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 500000);
                set("no_sell", "���ֺ�����ҩ�費��������������!\n");
                set("unit", "��");
                       set("long", HIG"����һ��̫���Ͼ����ƵĽⶾ��Ʒҩ�衣\n"NOR);
                set("drug_type", "��Ʒ");
//                        set ("ymdh",1);
        }
  
        set("is_monitored",1);
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
 
        if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

        me->set("food", (int)me->max_food_capacity());
            me->set("water",   (int)me->max_water_capacity());
           me->set("eff_sen", (int)me->query("max_sen"));
           me->set("eff_kee", (int)me->query("max_kee"));

        if((int)me->query("max_force")<10*(int)me->query_skill("force"))

                  me->add("max_force",10);
        if((int)me->query("max_mana")<10*(int)me->query_skill("spells"))
                   me->add("max_mana",10);

          me->clear_condition();
        message_vision(HIW"$N��ȥ����������һ������Ȼһ��ս�����ŵ�ð��˿˿������\n" NOR, me);  

        destruct(this_object());
        return 1;
}

