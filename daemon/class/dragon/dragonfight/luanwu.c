#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage_bonus,target_bonus,damage, wound;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ս���У���ôʹ��"HIY"����"NOR"��\n");

        if (!PFM_D->valid_family(me, "��������"))
                return notify_fail("������������ӣ�����ʹ����������?\n");

        if((int)me->query_skill("dragonfight",1)<400
        ||(int)me->query_skill("dragonforce",1)<400) 
                return notify_fail("�����Ϊ���������������"HIY"����"NOR"�ľ��衣\n");

        if((int)me->query("max_force") < 3000 )
                return notify_fail("����ڹ�̫�\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if(time()-me->query_temp("lxtx_end")<4)
               return notify_fail(HIY"����"NOR"�����õ���ôƵ����\n"); 
               
        if( time()-(int)me->query_temp("yinhua_end") < 3 )  
                return notify_fail(WHT"������һЦ��"NOR"��"HIY"����"NOR"�޷�����ʹ�ã�\n"NOR);    
                
        if( time()-(int)me->query_temp("jiuxian_end") < 3 )  
                return notify_fail(WHT"���������֡�"NOR"��"HIY"����"NOR"�޷�����ʹ�ã�\n"NOR);                                           

        me->set_temp("lxtx_end",time());
        me->add("force",-400);
        
        // dodge
        msg = HIW "$N��ת�����ķ������λ���һ�Ű����ƺ�һ�������ڿն���\n";
        msg+= HIW "$N��˫ĿԲ��,��֫��,ʹ����"HIR"����"NOR""HIW"������\n"HIY"���������졿 $N����ľ���ӿ��$nȫ��\n";
        if(!target->is_busy())
                target->start_busy(3);
        damage_bonus=(int)me->query_skill("dodge", 1);
        target_bonus=(int)target->query_skill("dodge", 1);
        if((damage_bonus)>random(target_bonus)) 
        {
                damage=damage_bonus/2+random(damage_bonus/2);
                if(wizardp(me))tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                wound=damage-(int)target->query_temp("apply/armor")/2;
                msg +=HIB "$n��������������������ڵء� \n";
                target->receive_damage("kee", damage, me, "pfm");
                if(wound<=0) wound=random(100);
                if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                msg+=COMBAT_D->damage_msg(damage, "����");
        }
        else msg+=GRN"$n���Ʋ���͵�һ���㿪�ˡ�\n" NOR;
        
        // combat_exp
        msg+= CYN "$N�����Ʒ���������̽���������ץ��$n���߲���\n";
        msg+= CYN"��Ǳ�����á� $N�������Ѿ�������Ϣ����$n��\n";
        damage_bonus=(int)me->query("combat_exp");
        target_bonus=(int)target->query("combat_exp");
        if((damage_bonus)>random(target_bonus)) 
        {
                damage_bonus=(damage_bonus/40000+random(300))/8;
                damage=damage_bonus+random(damage_bonus);
                if(wizardp(me))tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                wound=damage-(int)target->query_temp("apply/armor");
                msg +=HIB  "$n���߲��ѱ�$N˺����Ѫ�ۡ� \n";
                target->receive_damage("kee", damage, me, "pfm");
                if(wound<=0) wound=random(100);
                if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                msg+=COMBAT_D->damage_msg(damage, "����");
        }
        else msg+=GRN"$n˳����ת�������ض㿪������\n" NOR;   
        
        // daoxing
        msg+= YEL "$N�������ĵ��У�����ǿ�д����Ʒ�����$n��\n";
        msg+= YEL"����ս��Ұ��$n�ۿ�����������\n";
        damage_bonus=(int)me->query("daoxing");
        target_bonus=(int)target->query("daoxing");
        if((damage_bonus)>random(target_bonus)) 
        {
                damage_bonus=(damage_bonus/40000+random(300))/8;
                damage=damage_bonus+random(damage_bonus);
                if(wizardp(me))tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                wound=damage-(int)target->query_temp("apply/armor");
                msg +=GRN  "$n��$Nһ�����һ�ɶ�Զ�� \n";
                target->receive_damage("kee", damage, me, "pfm");
                if(wound<=0) wound=random(100);
                if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                msg+=COMBAT_D->damage_msg(damage, "����");
        }
        else msg+=GRN"$n����ͦ�أ����˶���������˹�����\n" NOR;   
        
        // unarmed
        msg+= HIR "$N�ܽ������ϰ�ĵã���̽һ�£�ץס$n�ı��С�\n";
        msg+= HIR"�������лڡ� $N��$n�����ⲫ��\n";
        damage_bonus=(int)me->query_skill("unarmed", 1);
        target_bonus=(int)target->query_skill("unarmed", 1);
        if((damage_bonus)>random(target_bonus)) 
        {
                damage=damage_bonus/2+random(damage_bonus/2);
                if(wizardp(me))tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                wound=damage-(int)target->query_temp("apply/armor")/2;
                msg +=HIB  "$n���ֹ����У���Ȼ���˴���� \n";
                target->receive_damage("kee", damage, me, "pfm");
                if(wound<=0) wound=random(100);
                if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                msg+=COMBAT_D->damage_msg(damage, "����");
        }
        else msg+=GRN"$n�Ŀ��ֹ���ȻҲ�����������$N����ʽ��\n" NOR;   
        
        // ����
        if(!random(5))
        {
                msg+= CYN "$N����������˭֪������Ȼ�����ֳ�һ�С�\n";
                msg+= CYN"��������β�� $N��$n����֮�ʱ���$n��\n";
                damage_bonus=(int)me->query_kar();
                target_bonus=(int)target->query_kar();
                if((damage_bonus)>random(target_bonus)) 
                {
                        damage_bonus*=6;
                        damage=150+(damage_bonus+random(damage_bonus));
                        if(wizardp(me)) tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));
                        wound=damage-(int)target->query_temp("apply/armor");
                        msg +=HIB  "$n������ʯͷһ������$N����һ�ơ� \n";
                        target->receive_damage("kee", damage, me, "pfm");
                        if(wound<=0) wound=random(100);
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        msg+=COMBAT_D->damage_msg(damage, "����");
                }
                else msg+=GRN"$nӭ��ʹ�棬�ι���$N�Ĺ�����\n" NOR;   
        }
        message_vision(msg, me, target);
        return 1;
 }


