//ŤתǬ��

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="ŤתǬ��";
        return str;
}

string get_help(string str)                
{
        str="ָ����������������\n"
        +"�������ߵľ�����";
        return str;
}

int cast(object me, object target)
{
        string msg;

        string tar_spells,tar_dodge;

        int ap,dp,dg,damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("��Ҫ��˭��ŤתǬ����\n");

        if (!target->is_fighting(me))
               return notify_fail("ֻ����ս���в���ʹ��ŤתǬ����\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("���������㣬�ò���ŤתǬ����\n");

        if((int)me->query("force") < 100 )
                return notify_fail("����������������ʹ��ŤתǬ����\n");

        if((int)me->query_skill("dengxian-dafa", 1) < 40 )
                return notify_fail("��ĵ��ɴ󷨻��������졣\n");

        if((int)me->query("mana") < 300 )
                return notify_fail("��ķ��������Ա��������˵У�\n");

        msg = HIW"\n$N��$n������ŭ��һ����ת˲�仯��һֻ��������"
                 +"���������ı�����$n��ȥ��\n" NOR;

        ap=(int)me->query_skill("dengxian-dafa", 1)
              +(int)me->query_skill("spells", 1)/2;

        tar_spells=target->query_skill_mapped("spells");
        if (! tar_spells) dp=(int)target->query_skill("spells", 1)/2;
        else dp=(int)target->query_skill("spells", 1)/2
              +(int)target->query_skill(tar_spells, 1);

        tar_dodge=target->query_skill_mapped("dodge");
        if (! tar_dodge) dg=(int)target->query_skill("dodge", 1)/2;
        else dg=(int)target->query_skill("dodge", 1)/2
              +(int)target->query_skill(tar_dodge, 1);
        if (dp!=0) dp=100*ap/dp/3+random(100*ap/dp)/2; else dp=100;
        if (dg!=0) dg=100*ap/dg/3+random(100*ap/dg)/2; else dg=100;
//printf("dp=%5d dg=%5d",dp,dg);
        damage=me->query("max_mana")/20+1;
        damage=(me->query("mana_factor")+me->query("str")+random(damage))*2;
        if (dp<30)
          {           
          msg += HIW "����$n����׼����Ťת��������Գ��һ��ץס��$N�ı��ӣ�\n"
              +"$N�۵�һ���ƺߣ����ɼ��ı�$n���˹�ȥ��\n"NOR;
          message_vision(msg, me, target);
          me->add("kee", me->query("str")*2);
          me->start_busy(30-dp+random(2));
          }
        else if (dp<60 && dp>30)
          {           
          msg += HIW "$n��æŤת������ת�񹦽�$N�ĳ��ǵ�����\n"NOR;
          message_vision(msg, me, target);
          me->start_busy(1+random(2));
          }
        else if (dg<50)
          {           
          msg += HIW "$n�������һԾ����������һ����\n"NOR;
          message_vision(msg, me, target);
          me->start_busy(1+random(2));
          target->start_busy(random(3));
          }
        else 
          {           
          msg += HIW "$n�ٲ���������$N�ĳ��Ǹ߸߾���$N����һ˦��"
              +"$n������ߵķ��ݰ���˳�ȥ��\n"NOR;
          message_vision(msg, me, target);
          target->receive_damage("kee",damage,me,"cast");
          me->start_busy(random(2));
          target->start_busy(1+random(3));
          COMBAT_D->report_status(target); 
          }

        me->add("force", -30);
        me->add("mana", -30);

        me->kill_ob(target);
//        message_vision(msg, me, target);

        return 1;
}

