// writted by fbbz   //edited by dewbaby@sk
// 10/2001

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int calculate_damage(object me, object target, int base_damage, int damge_bonus);

int perform(object me, object target)
{       
        string msg="";
        int damage,wound,k,damage_bonus,mystr;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("һ���˾����˭������\n");

        if(!me->is_fighting())
                return notify_fail("�����项ֻ����ս�����ñ��˵��������ˣ�\n");
        
        if (!PFM_D->valid_family(me, "�¹�"))
                return notify_fail("�����¹�������á����项��\n");
              if ((string)me->query("gender")=="����")
                            return notify_fail("����Ů��ô?���þ���?������ˣ�\n");
                   
        if (me->query_skill_mapped("force")!="moonforce")
                return notify_fail("�����项������Բ���ķ�Ϊ���ӣ�\n");
                
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 600 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ���״̬̫���ˣ�û�˻ῴ�㣡\n");
        if((int)me->query_skill("moonforce", 1) < 100)
                return notify_fail("���Բ���ķ���Ϊ��������������Σ�գ�\n");
        if((int)me->query_skill("jueqingbian", 1) < 100)
                  return notify_fail("��ľ������Ϊ������������ֻ��͵͵������ɣ�\n");
               mystr=me->query_str() * 2;

              k=(int)me->query_skill("whip");
              damage_bonus=k;
              damage_bonus=mystr*(damage_bonus+100+me->query("force_factor"))/209;
        message_vision(HIY"$N�����˺ۣ�ʹ���������޵�������û���ģ��Ҹ���ƴ��! ˵������$n�����������Լ�������!\n"NOR,me,target);
                     
                        if (random((int)me->query("per"))<10 || random((int)target->query("daoxing")) > ((int)me->query("daoxing"))) 
                                                    {
//                         msg = "����$p������$P�����������ͼ��Ц��:�ұ������������壬������Σ�\n" NOR;
//		              message_vision(msg, me, target��;
        message_vision(HIB"����$p������$P�����������ͼ��Ц��:�ұ������������壬������Σ�\n"NOR,me,target);

                                }
                                 else {
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n\n";
               		damage=calculate_damage(me, target, 20, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage,me,"pfm");
//                                if(wound>0) target->receive_wound("kee", wound,me,"pfm");
                                 msg+=WHT"���$n"WHT"����һ���������Ŀ���$N��\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ���驧\n";
			msg +=HIB "   ������\n\n";
               		damage=calculate_damage(me, target, 40, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage,me,"pfm");
//                                if(wound>0) target->receive_wound("kee", wound,me,"pfm");
                                msg+=WHT"���$n"WHT"��������飬������ͷ��\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n";
			msg +=HIB "   ������\n\n";
               		damage=calculate_damage(me, target, 60, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage,me,"pfm");
//                                if(wound>0) target->receive_wound("kee", wound,me,"pfm");
                                msg+=WHT"���$n"WHT"�����Ŀ���$N���޵����ݡ�\n" NOR;
                    			}
			msg +=HIB "   ������\n";
			msg +=HIB "   ���⩧\n";
			msg +=HIB "   ������\n\n";
               		damage=calculate_damage(me, target, 80, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage,me,"pfm");
//                                if(wound>0) target->receive_wound("kee", wound,me,"pfm");
                                msg+=WHT"���$n"WHT"����������⣬����ͨ�죬������֡�\n" NOR;
                    			}
                            message_vision(msg, me, target);
                                                 COMBAT_D->report_status(target);
                            }
        me->start_busy(1+random(1));

        me->add("force", -100);
        me->add("sen",-30);
        return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

        damage=base_damage+(damage_bonus+random(damage_bonus));
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
                damage-=damage/3*2;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(HIC "damage: %d\n" NOR, damage));

	return damage;
}

