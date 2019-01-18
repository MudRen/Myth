// Rainy
// 07/09/98

#include <skill.h>
#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name("��ɰ�", ({"xiang hebao", "hebao", "bao", "fabao"}));
        set_weight(1000);
        if(clonep())
                set_default_object(__FILE__);
        else {
	set("long", "һ����ɫ��С��ɰ��������ý���˿������Щ���ġ�\n");
        set("unit", "��");
        set("value", 0);
        set("no_put",1);
        set("no_sell",1);
	set("replace_file", "/obj/money/gold");
        }
	set("is_monitored", 1);
        setup();
}

void init()
{
  check_owner();
}

int ji_ob(object victim)
{
        object seal=this_object();
        object me=this_player();
        object where=environment(me);

        int limitmana, vicmana;
	int limitdx, vicdx;
	int limitkar, vickar;
	int limit, vic;


        if(me->is_busy())
                return notify_fail("����æ���أ��޷�������ɰ���\n");
        if( !victim)
                return notify_fail("��������˲������\n");
        if( where->query("no_magic"))
                return notify_fail("���ﲻ�ܼ���ɰ���\n");
        if( !me->is_fighting())
                return notify_fail("ֻ��ս���в��ܼ���ɰ���\n");
        if( (int)me->query("mana") < 500 )
                return notify_fail("��ķ������ܿ�����ɰ���\n");
        if( (int)me->query("sen") < 200 )
                return notify_fail("��ľ����㣬���Ѽ�Ԧ��ɰ���\n");


        message_vision(HIC"\n$N��һ�����㡱����һ�ӣ�������$n������\n"NOR, me, seal);
message_vision(HIC"$n��������һ�·ɵ���գ�ֻ�����һ����һ�ɺ���������$N��\n"NOR,victim,seal);

	limitmana = 500+random(300);
	limitdx = 200000+random(100000);
	limitkar = (int)me->query_kar();

	limit = (limitdx/1000 + limitmana) * limitkar;

	vicmana = (int)victim->query("max_mana");
	vicdx = (int)victim->query("daoxing");
	vickar = (int)victim->query_kar();

	vic = (vicdx/1000 + vicmana) + vickar;

                if( random(limit+vic) > vic ){
        message_vision(HIC"\n$N�����������Ѻ��������˱����\n"NOR,victim);
			victim->apply_condition("xiang_air", 5);
                } else {
                        message_vision(HIC"\n$N���˼��������˹�ȥ��\n"NOR,victim);
                }

                if( !victim->is_fighting(me) ) {
                if( living(victim) ) {
                        if( userp(victim) ) victim->fight_ob(me);
                        else
                                victim->kill_ob(me);
                }
                me->kill_ob(victim);
        }
        me->add("mana",-100);
	me->receive_damage("sen", 100);

        me->start_busy(3+random(5));
        destruct(seal);
        return 1;
}

int ji (string target)
{
  object seal = this_object ();
  object me = this_player();
  string name=seal->query("name");
  object victim;

  if (!target)
    return notify_fail("�����˭��"+name+"��\n");

  victim=present(target,environment(me));
  return seal->ji_ob(victim);
}

