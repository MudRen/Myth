//modified by vikee for xlqy-zq station
//2000-12-5 9:20
//perform fenguang.
//��ȥ�Է������ͷ�����

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int mypot,tapot,damage,damage_pot;
        
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��ȥ˭��������\n");
                
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail("�����Ķ�͵ѧ�����书��\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");

        if((int)me->query("max_force") < 400 )
                return notify_fail("����ڹ�̫�\n");

        if((int)me->query("force") < 200 )
                return notify_fail("����������㣡���ܻ�����������\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
                
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
                
        if((int)me->query_skill("taoism", 1) < 100)
                return notify_fail("�����ʦ�����ȼ�������ʩ���п��������ѣ�\n");
        
        if((int)me->query_skill("mindsword",1) < 100)
                return notify_fail("��Ľ�����򻹲�����ʹ����һ�л������ѣ�\n");
          
        //as followed was modified by vikee
        mypot=(int)me->query_skill("sword");
        mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));
        
        tapot=((int)target->query_skill("dodge")+(int)target->query_skill("parry"))/2;
        tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));      
        
        damage_pot=(int)me->query_skill("mindsword");           
                  
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIW"\n$N�����񣬿��������\n",me,target);
        message_vision(HIW"\n�����񣬽���ף�����⣬ͬ�䳾��\n",me,target);
        message_vision(HIW"\n���н���һ��������$n\n"NOR,me,target);
        
        
        if ( random( mypot + tapot ) > tapot )  
        {       
                message_vision(HIR"\n$n����һ�����ȣ����ļ�����Ż��������Ѫ����ɫ�԰�����࣡\n"NOR,me,target);
          
                damage=damage_pot+random(damage_pot)*2; 
                //���һ��mindsword=200��player�����������Χ��200-600.          
          
                target->add("force",-damage);
                if ((int)target->query("force")<0)
                {
                        target->set("force",0);
                        message_vision(HIR"$n�����������������޷���֮����\n"NOR);
                }
        
                target->add("mana",-damage);
             
                if ((int)target->query("mana")<0)
                {
                        target->set("mana",0);
                        message_vision(HIR"$n�ķ��������������޷���֮����\n"NOR);
                }
                //ʩ��������һ���������ͷ�����100 pot �ľ�����Ϊ���ۡ�
                me->add("force", -random(damage/2));  
                me->add("mana",-random(damage/2));
                me->receive_damage("sen", 100);
                                         
                if ((int)me->query("force")<0) me->set("force",0);
        
        }
        
        else 
        message_vision(HIY"\n$n����һ�Σ������$N�Ĺ�����\n"NOR,me,target);
        
           if( !target->is_fighting(me) )
            {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
            }
        me->start_busy(1+random(1));
        return 1;
}


