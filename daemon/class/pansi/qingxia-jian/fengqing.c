// keelv.c ��һ���ķ���
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        object ob;              // ���ֵ�����
        string msg;
        int i,attack_time,skill,damage;
        me=this_player();
        skill = me->query_skill("qingxia-jian",1);
//      target=this_object();
//      ob=target->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character() )                return notify_fail("����һ���ķ��项ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("qingxia-jian", 1) < 200 )
                return notify_fail(HIM"���޷�������������һ���ķ��项��\n"NOR);
               if(me->query("family/family_name")!="��˿��")
                            return notify_fail("������һ���ķ��项��ֻ����˿�����˲ſ����ã�\n");


              if( (int)me->query("max_force") < 2000 )
                return notify_fail("���������Ϊ�������ߣ�\n");

        if( (int)me->query("force") < 1000 )
                return notify_fail("�����ڵ��������㣡\n");


        msg = HIM "$N������̾,ʹ���ˡ���һ���ķ��项,�����д������־���,��������,���ֿɰ���һ�ֲ���һ����\n";

  if(random(me->query_skill("sword")*me->query("int") ) > ((int)target->query_skill("force")*target->query("int"))/3)
        {
 
                if (! objectp(ob = target->query_temp("weapon")))
                {
                        msg += "\n"HIM "�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!"NOR"\n\n"HIR"���$n��Ϊ$N�Ľ�������,��,��һ���³�һ����Ѫ��\n\n" NOR;
                        me->start_busy(1);
                        damage = 700 + random(skill);
                target->receive_damage("kee", damage,me,"pfm"); 
                target->receive_wound("kee", damage/3,me,"pfm");
                        target->start_busy(random(3));
                      
        message_vision(msg, me, target);
                } else
                {
                          msg += "\n"HIM"�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!"NOR"\n\n"HIR"���$n��Ϊ$N�Ľ�������,��,��һ���³�һ����Ѫ��\n" NOR;
                          msg += "\n"YEL"��һ��,������$n�����"+ob->query("name")+"��\n\n"NOR;

                        ob->unequip();
                        ob->move(environment(target));
                        ob->set("name", YEL"���˵�"NOR + ob->query("name"));
                        ob->set("long", "һ"+ob->query("unit")+ob->query("name")+"��\n");
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        damage = 400 + random(skill);
                target->receive_damage("kee", damage,me,"pfm");
                        me->start_busy(1);
                        target->start_busy(1);

        message_vision(msg, me, target);

                } 
            
        }
else
        {
                msg += HIM"�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!\n"NOR"\n"HIY"���$n������������ע���ܿռ�,������$N�Ľ��⡣\n" NOR;
                me->start_busy(2+random(1));
                message_vision(msg, me, target);

        } 

 me->add("force", -300);

                
}
