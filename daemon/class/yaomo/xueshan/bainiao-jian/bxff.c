#include <ansi.h>
#include <combat.h>

inherit SSERVER;

string get_name(string str)
{
        str="��ѩ�׷�";
        return str;
}

string get_help(string str)                
{
        str="ָ���������������\n"
        +"���������񽣷�160��������1000"
        +"����֮ҹ����ѩ���죬���²Ҳ�";
        return str;
}


int perform(object me, object target)
{
        object weapon, ob;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���С���ѩ�׷ɡ�?\n");


        if( !me->is_fighting() )
            return notify_fail("����ѩ�׷ɡ�ֻ����ս����ʹ�á�\n");

        if (!PFM_D->valid_family(me, "��ѩɽ"))
                return notify_fail("�㲻�Ǵ�ѩɽ���ӣ���ô��ʹ�ô�ѩɽ������\n");
                
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( (int)me->query_skill("bainiao-jian",1) < 50 )
                return notify_fail("��İ��񽣵ȼ�����������ô��ʹ������ѩ�׷ɡ���\n");

        if( time()-(int)me->query_temp("bxffs_end") < 3 )    
                return notify_fail(CYN"��������ô�������ǣ������ѩ�׷ɡ���\n"NOR);    
                
        if (me->query("force") < 1000)
                return notify_fail("���������̣�����ʹ������ѩ�׷ɡ���\n");

//        if( target->is_busy() )
//                return notify_fail(target->name() + "Ŀǰ����æ���ң��Ͽ�����ɣ�\n");
        

        msg = HIW "$Nʹ������ѩ�׷ɡ��������ޱ߼ʵ�ѩ��һ�����������򷢳�������\n\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        target->start_busy(1);
        message_vision(HIW"ֻ��һƬѩ��ƮƮȻ����$n��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIC"ֻ��һ����������ĳ���$n��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIB"�����ιǵĺ�����С��һ�����$n��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        if( (int)me->query_skill("bainiao-jian",1) > 99 )
        {
                message_vision(HIM"��ҹ���׵����޼ɵ�������$n��"NOR, me, ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

                message_vision(HIY"��ҹ�ĺ�˪Χ����$n��"NOR, me, ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

                message_vision(HIG"������ʧ�����������˲��������޺��š�"NOR, me, ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        }
        
        if( (int)me->query_skill("bainiao-jian",1) > 149 )
        {
                message_vision(HIR"����֮ҹ��ʳ��Ұ��Χ����$n��Χ��"NOR, me, ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), TYPE_SUPER);

                message_vision(YEL"Ʈѩ�����$n��ʱ��������ѻ�İ�����"NOR, me, ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), TYPE_SUPER);
        }

        if ((int)me->query_skill("bainiao-jian",1) > 179 )
        {
            me->add("force", -200);
            me->add_temp("apply/attack", get_level(me->query("combat_exp")));
            me->add_temp("apply/damage", get_level(me->query("combat_exp")));
            message_vision(MAG"��·��$n����������ң�$N�˻�ȫ���ӳ�����һ����"NOR, me, ob);

            COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), TYPE_SUPER);

            me->add_temp("apply/damage", -get_level(me->query("combat_exp")));
            me->add_temp("apply/attack", -get_level(me->query("combat_exp")));
        }            
        me->add("force", -100);
        me->set_temp("bxffs_end",time());    



        return 1;  

}

