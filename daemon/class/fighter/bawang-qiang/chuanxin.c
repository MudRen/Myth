//����������
//by junhyun@SK

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("spear",1);
        myskill1= (int)me->query_skill("bawang-qiang",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";

        if(!objectp(weapon)||(string)weapon->query("skill_type")!="spear")
                return notify_fail("���ﶼû��ǹ�����������ꣿ");
        if ( myskill1 < 180) return notify_fail("��İ���ǹ�����������\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����������꡻ֻ����ս����ʹ�á�\n");
        if ((int)me->query("force")<300)
                return notify_fail("�����������꡻���ڷ���������Ϊ�\n"); 
        
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-200);
        me->receive_damage("sen", 50);
        message_vision(HIW"
$N������ǹ������Ծ������ǹ�ߣ�����ɱ��������

            �����������꡻ \n\n" NOR,me,target);        
        message_vision(HIY"
$N������ǹ����һ���������һ��������ֱ�Ĵ���Է���\n"NOR,me);
        
        if(random(myexp)>(int)(texp/5))
        {
                msg = HIR"
$n�����������������б�$N���˴�ǹ͸�������\n"NOR;
                damage=(int)(random((int)(myskill1/2))+me->query("force_factor")*3/2);
                if(damage<1)damage = 1;
                target->receive_damage("kee", me->query("eff_kee")*damage/400,me,"pfm");
                target->receive_wound("kee", me->query("eff_sen")*damage/400,me,"pfm");
                target->start_busy(3);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                me->start_busy(1);
        }
        else
        {
                msg = HIW"$n��֪���У�����һ��,���ŵ���ƽƽ�ķ��˳�ȥ��\n\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(target, me, tweapon);
                me->start_busy(2);
        }
        
       
        
     
        return 1;
}


