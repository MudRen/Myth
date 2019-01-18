//��������
//Created by Wuyou@Sanjie

#include <ansi.h>

inherit F_SSERVER;

int calc_damage(int,int);

int perform(object me, object target)
{
        object weapon;
        string msg,result;
        int i,j,k,total,mypot,tapot; 
        weapon = me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��������򡹣�\n");

        if(!me->is_fighting())
                return notify_fail("����������ֻ����ս����ʹ�ã�\n");
        
        if(!PFM_D->valid_family(me, "����ɽ���Ƕ�"))
                return notify_fail("�����������Ƿ���ɽ���Ƕ��Ĳ���֮�أ����������ܹ�����\n");
        
        if((int)me->query_skill("qianjun-bang", 1) < 100 )
                return notify_fail("���ǧ��������������������ʹ�á��������򡹣�\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if (me->query_skill("qianjun-bang",1)<400 
          ||me->query_temp("oldpili"))
        {
                mypot = (int)me->query_skill("qianjun-bang",1);
                tapot = (int)target->query("parry",1);

                message_combatd(HIY"\n$N˫�ֺ�ʮ�����������\n" NOR,me,target,"");
                message_combatd(HIW"\n               �������ģ�����������������������\n"NOR,me,target,"");
                message_combatd(HIC"\n          ��"BLINK""HIR"�����������������������������������������"NOR""HIC"��\n"NOR,me,target,"");
                message_combatd(HIY"\n                  һ�ɽ����ҫ��$N��$N����"+weapon->name()+ HIY"�����ϡ�\n"NOR,me,target,"");
                message_combatd(HIC"\n          ��"BLINK""HIG"����������������������������"NOR""HIC"��\n"NOR,me,target,"");
                message_combatd(HIB"\n                 $N�𵽣�"HIM"��      "BLINK""HIB"����     "NOR""HIY"��"BLINK"     "HIB"����"NOR""HIM"      ��"HIR" 
                     \n "+weapon->name()+ HIR"����һ��"HIW"�����������"HIB"��$n��ȥ����������������������\n"NOR,me,target,"");
                
                me->add("force", -100);
                me->receive_damage("kee", 100);
                
                if (random(mypot) > tapot/3)
                {
                        target->receive_damage("kee", mypot+random(mypot), me, "pfm");
                        target->receive_wound("kee", mypot+random(mypot), me, "pfm");
                        target->start_busy(2);
                }
                if (!target->is_busy())
                        target->start_busy(1);
                
                message_combatd(HIG"\n       ɲ�Ǽ䣬�˹����룬$Nת�ֿ칥����\n"NOR,me,target,"");
                
                me->add_temp("apply/attack", mypot);
                me->add_temp("apply/damage", mypot); 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"));                  
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
                me->add_temp("apply/attack", -mypot);
                me->add_temp("apply/damage", -mypot);
         
        }
        else
        {       
                me->add("force", -250);
                me->receive_damage("kee", 100);

                i = (me->query_skill("stick", 1) + me->query_skill("qianjun-bang", 1) + me->query_skill("wuxiangforce", 1)) /3 ;
                j = (target->query_skill("force", 1) + target->query_skill("dodge", 1) + target->query_skill("parry", 1))/3;

                mypot = me->query("combat_exp");
                k = mypot / 3000;
                if(k > 1000) k=1000;
                i = i * (1000 + k/3)/1000;
                k = 1000 + random(k/2);

                if(wizardp(me)) tell_object(me,sprintf("\nattack: %d , parry: %d  , mypot: %d \n",i,j,k));

                msg = HIR"$N��$n��������֮����ƴ��ȫ��ʹ������ɽ���Ƕ�����֮������������������\n"NOR;

                if(random(me->query("combat_exp")) > target->query("combat_exp")/4) 
                {
                        total = 0;
                        msg += HIW "\n$N����������ƣ�һ��"HIM"���������ǡ�"HIW"���ֻӳ���\n";
                        msg += "ֻ��$N����һ�ᣬ����"+weapon->name()+ HIW"ӭ��һ������â���ǣ����Ǹ��°�ֱ��$n��\n";
                        msg += "$n����������"+weapon->name()+ HIW"Ϯ��������������������Ȼ��֪���㡣\n"NOR;
                        i = calc_damage(me->query_skill("qianjun-bang",1),k);
                        total += i;
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                        target->receive_damage("kee", i, me, "pfm");
                        target->receive_wound("kee", i/2 , me, "pfm");
                        result = COMBAT_D->damage_msg(i,"����");
                        result = replace_string( result, "$l", "С��Ѩ" );
                        msg += result;
                        message_combatd(msg,me,target,"");
                        COMBAT_D->report_status(target, 0);     
                }
                else
                {
                        msg += HIW "\n$N����������ƣ�һ��"HIM"���������ǡ�"HIW"���ֻӳ���\n";
                        msg += "ֻ��$N����һ�ᣬ����"+weapon->name()+ HIW"ӭ��һ������â���ǣ����Ǹ��°�ֱ��$n��\n";
                        msg += "����$n������$N����ͼ��û���ϵ�������ææ���Ա�һ�������˹�ȥ��\n"NOR;
                        message_combatd(msg,me,target,"");
                }
                
                if(random(me->query("combat_exp")) > target->query("combat_exp")/4) 
                {
                        msg = HIY "\n$Nһ��������ʹ��"HIR"��Ǭ��һ����"HIY"��\n";
                        msg += "$N������$wӭ��һ�ӣ��ó���ǧ��Ӱ�������������߾ٹ�����\n";
                        msg += ""+weapon->name()+ HIY"��׼$n�����ž�������ȥ����һ��Ҫ�Ǵ��У����������޽���Ҳ����һ����\n"NOR;

                        i = calc_damage(me->query_skill("stick",1),k);
                        total += i;
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                        target->receive_damage("kee", i, me, "pfm");
                        target->receive_wound("kee", i/2 , me, "pfm");
                        result = COMBAT_D->damage_msg(i,"����");
                        result = replace_string( result, "$l", "С��" );
                        result = replace_string( result, "$w", weapon->query("name") );
                        msg += result;
                        message_combatd(msg,me,target,"");
                        COMBAT_D->report_status(target, 0);     
                }
                else
                {
                        msg = HIY "\n$Nһ��������ʹ��"HIR"��Ǭ��һ����"HIY"��\n";
                        msg += "$N������$wӭ��һ�ӣ��ó���ǧ��Ӱ�������������߾ٹ�����\n";
                        msg += ""+weapon->name()+ HIY"��׼$n�����ž�������ȥ��\n"NOR;
                        msg += "$n����һ�������漴�侲��������Ȼ�󳷡�\n";      
                        message_combatd(msg,me,target,"");
                }

                if(random(me->query("combat_exp")) > target->query("combat_exp")/4) 
                {
                        msg = HIG "\n$N���쳤Ц����Ҳ������һ��"HIC"������𹿰���"HIG"Ӧ��������\n";
/*
                        msg += "$N˫�ֺ�ʮ��Ĭ����������ģ�$N���е�"+weapon->name()+ HIG"Խ��Խ��ֱ��������\n";
                        msg += ""+weapon->name()+ HIG"ͻȻ����$n��ֻ�����䡱��һ����$n������һ��Ѫ��ģ����\n"NOR;

                        i = calc_damage(me->query_skill("wuxiangforce",1),k);
                        total += i;
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                        target->receive_damage("kee", i, me, "pfm");
                        target->receive_wound("kee", i/2 , me, "pfm");
                        result = COMBAT_D->damage_msg(i,"����");
                        result = replace_string( result, "$l", "ͷ��" );
                        msg += result;
*/
                        message_combatd(msg,me,target,"");
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                        COMBAT_D->report_status(target, 0);
                }
                else
                {
                        msg = HIG "\n$N���쳤Ц����Ҳ������һ��"HIC"������𹿰���"HIG"Ӧ��������\n";
                        msg += "$N˫�ֺ�ʮ��Ĭ����������ģ�$N���е�"+weapon->name()+ HIG"Խ��Խ��ֱ��������\n";
                        msg += ""+weapon->name()+ HIG"ͻȻ����$n��ֻ�����䡱��һ��������Ϊ$n�������ɣ�Ȼ��$nȴ��Ȼ��������δ��\n"NOR;
                        message_combatd(msg,me,target,"");
                }
                
                if(wizardp(me)) tell_object(me,sprintf("Total damage: %d \n",total));
        }
                

        me->start_busy(1+random(2));
        return 1;
}

int calc_damage(int skill,int k)
{
        int i;

        if(skill>200)
                i = (200*3 + (skill-200)*4) * k/1000;
        else
                i = (skill * k/1000) * 5;

        i = i/2 + random(i/2);

        if(i > 1000) i = 1000;
        return i;
}

