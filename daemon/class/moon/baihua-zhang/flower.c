//��Ůɢ�� 
// dream 7/17/97
// modified by xlb 11/98

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int number, size, i, four,amount;
        object *tar;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����Ůɢ������\n");
                
        if (!PFM_D->valid_family(me, "�¹�"))
                return notify_fail("[��Ůɢ��]���¹�����֮�ܣ�\n");

        if((int)me->query("force") < 25+(int)me->query("force_factor") )
                return notify_fail("�������������\n");
                
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("baihua-zhang", 1) <80)
                return notify_fail("��İٻ��Ƽ��𻹲�����\n");

        tar=all_inventory(me);
        size = sizeof(tar); 
        if(size) 
        {
                for(i=0;i<size;i++)
                if(tar[i]->query("material") == "flower") 
                {
                        if (tar[i]->query_amount())
                              number+=tar[i]->query_amount();
                        else number++;
                }
        }
        write((string)number+"\n");
        
        if((int)number < 2)
                return notify_fail("��Ļ�������ʩչ����Ůɢ������\n");

        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);
        msg = HIC
"\n$N΢΢һЦ��������ն����������컨�꣬һʱ��������\n"+
"$nֻ����������Ӱ��ס�ˣ�һʱ��Ȼ��֪����мܣ�������˵�����ˣ�\n" NOR;

        ap = me->query_skill("baihua-zhang", 1);
// + me->query_skill("parry");
        ap = ( ap * ap * ap / (4 * 400) );
// + (int)me->query("kee");
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 400) );
// + (int)target->query("kee");
        dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) 
        {
                msg += HIC "˭֪$n��������ʤ������һ�ڣ��ѽ����л�����䣡\n\n"NOR;
                message_combatd(msg,me,target,"");
        } 
        else 
        {
                damage = (int)me->query_skill("baihua-zhang",1) / 10 +
                        (int)me->query("sen") / 400 + random((int)me->query("sen") / 200 ) +
                        (int)me->query("kee") / 400 + random((int)me->query("kee") / 200 );
                msg += HIC "��Щ���꿴������������ȴ�缲�����������$n,�����Ƕ�����\n" NOR;
                if (number < 10) damage = damage *  (random(number+1)/5);
                else    damage = damage * (random(10)/5);
                        target->receive_damage("sen", me->query("eff_sen")*damage/100, me, "pfm");
                        target->receive_damage("kee", me->query("eff_kee")*damage/70, me, "pfm");
                        me->improve_skill("baihua-zhang", 1, 1);
                        message_combatd(msg,me,target,"");
                        COMBAT_D->report_status(target);
         }


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        
        for (i = 0; i< size; i++)
        {
                if (tar[i]->query("material") == "flower")
                {
                        amount=tar[i]->query_amount();
                        if (amount) four+=amount;
                        else four++;
                        if (four <= 5) destruct(tar[i]);
                        else 
                        {
                                tar[i]->set_amount(four-5);
                                four=5;
                                break;
                        }
                }
        }
        //me->start_busy(3);
        me->start_busy(2);
        return 1;
}

