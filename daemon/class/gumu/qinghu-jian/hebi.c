//qinghu-jian perform hebi ������ �L���ē�
// /daemon/class/gumu/qinghu-jian/hebi
// writted by ivy 2002-1-18
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1,myskill2, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("sword",1);
        myskill1= (int)me->query_skill("qinghu-jian",1);
        myskill2= (int)me->query_skill("zizhi-blade",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="sword")
        return notify_fail("�޵��޽���κ�赣�");
        if ( myskill1 < 210) return notify_fail("�������������������\n");
        if ( myskill2 < 210) return notify_fail("��������������������\n");
        if (!PFM_D->valid_family(me, "��ԯ��Ĺ"))
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á������赡�?\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������赡�ֻ����ս����ʹ�á�\n");
        if ((int)me->query("force")<300)
                return notify_fail("�������������\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-300);
        me->receive_damage("sen", 20);
     message_vision(HIW"$N˫��һ�ֻ��������ɣ�����ը�֣�ʹ������ԯ��Ĺ�ľ�ѧ--�������Ļ�����\n\n" NOR,me,target);        
     message_vision(MAG"$N����һ�ӣ�һ���Ϲ⸡����ʣ��죬����������������            "+BLINK""+HIW"       ����"NOR""+HIW"��"+BLINK"����\n"NOR,me);
     message_vision(MAG"��һ�С���������Ю�Ź�������ԴԴ���ϵ�����Է���\n\n"NOR,me);
     if (random(myexp)>(int)(texp/10) && random(myforce) > (int)(tforce/3)) 
        {
             msg = MAG"$nֻ����һ�ɾ���������ը��һ�㣬���������\n"NOR;
        damage= (int)(((int)me->query("max_force")/2+myforce -  (int)target->query("max_force")/2 - tforce)/3);
        if(damage<1)damage = 1;
        target->receive_damage("kee", me->query("eff_kee")*damage/60,me,"pfm");
        target->receive_wound("kee", me->query("eff_sen")*damage/80,me,"pfm");
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        }
     else {
            msg = HIC"$næ�˹��򿹣�����������$N�Ĺ��ƶ���ɢ�ˡ�\n\n"NOR;
            message_vision(msg, me, target);
        }


     message_vision(HIG"$N����һ��,һ���������,�����������,ɷ�Ǻÿ���     "+BLINK""+HIW"               ����"NOR""+HIW"��"+BLINK"���� \n" NOR,me,target);
     message_vision(HIG"��һ�С������а�����޾����Ҫ��������������ɨ����\n\n" NOR,me,target);
     if(random(myexp)>(int)(texp/10)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
     {msg = HIG"$n������æ���ң���֪�����ȥ�м���ɾ��磡\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", me->query("eff_kee")*damage/80,me,"pfm");
     target->receive_wound("kee", me->query("eff_sen")*damage/100,me,"pfm");
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIC"$n˿�����Ի���,�ƹ���ͷ,�߽���$N�⼤�ҵĹ��ơ�\n\n"NOR;
            message_vision(msg, me, target);
        }


     message_vision(HIB"$N˫��һ��,����������âȦ�ɹ⻷��Ȼ�伤������֣�     "+BLINK""+HIW"               ����"NOR""+HIW"��"+BLINK"���� \n" NOR,me,target);
     message_vision(HIB"��һ�С������Դ�����ư���,��֮�������,�������飡\n\n" NOR,me,target);
     if(random(myexp)>(int)(texp/10)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
     {msg = HIB"$n���ǹ⻷���������������Ȼ�������޴룡\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", me->query("eff_kee")*damage/80,me,"pfm");
     target->receive_wound("kee", me->query("eff_sen")*damage/100,me,"pfm");
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIC"$nȴ�ľ���ˮ,���в���,�߽���$N�����ư���Ĺ��ơ�\n\n"NOR;
            message_vision(msg, me, target);
        }


          message_vision(HIW"$N˫��һ�ϣ�����֮�����һ�壬���һ����ǰ��ȥ��                  "+BLINK""+HIW"   ����"NOR""+HIW"��"+BLINK"����\n"NOR,me);
          message_vision(HIW"��һ�С������赡��ѷ����Ļ��ľ��跢�ӵ����쾡�£�\n\n"NOR,me);
if(random(myexp)>(int)(texp/2))
{msg = HIW"$n��æ����,��֪���������Ķ�����Ȼ������һ����\n"NOR;
damage=(int)(random((int)(myskill1/2))+me->query("force_factor")*3/2);
if(damage<1)damage = 1;
target->receive_damage("kee", me->query("eff_kee")*damage/80,me,"pfm");
target->receive_wound("kee", me->query("eff_sen")*damage/100,me,"pfm");
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
else{
         msg = HIC"$n����һ��,������ͷ��˲������Ծ�𣬱ܹ�����һ����\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);
        }
        
        me->start_busy(3+random(1));
        
     
        return 1;
}


