// yan.c ����

#include <ansi.h>

inherit SSERVER;

void free(object target);

string get_name(string str)
{
        str="���׶���";
        return str;
}

string get_help(string str)                
{
        str="ָ�������������\n"
        +"���ö���ʹ�Է�busy��";
        return str;
}

int cast(object me, object target)
{
        string msg;
        int success, ap, dp, ap2, ap3, dp2, dp3, damage;
        
        if( !target ) target = offensive_target(me);

        if((int)me->query_skill("spells") < 100 || (int)me->query_skill("pingtian-dafa",1) < 100)
                return notify_fail("�㻹ûѧ�ᶾ�̡�����\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("�����˭�綾�̣�\n");  

        if( target->is_busy() )
                return notify_fail(target->name()+"�Ѿ���æ�ˡ�\n");

        if(target->query_temp("no_move"))
                return notify_fail(target->query("name")+"�Ѿ����������ˣ�\n");
                
        if((int)me->query("mana") < 200 )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -80);
        me->receive_damage("sen", 20);

        msg = RED
"$Nһ����ӣ�ҧ����⣬�ſ�һ�磬һ�Ű���ɫ�����׶���ֱ��$n��ȥ��\n\n" 
NOR;

        success = 1;
        ap = me->query_skill("spells");
        ap = (ap/12) * ap * ap;
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");
        ap2 = (int)me->query_cor();
        dp2 = (int)target->query_cor();
        ap3 = (int)me->query("mana");
        dp3 = (int)target->query("mana");
        if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;
        if(success == 1)
        {
                msg +=  WHT "$n��������������һ�ɶ���Ϯ������ʱ��æ���ҡ�\n" NOR;
                
                if( living(target) ) target->kill_ob(me);
                target->start_busy(3+random(2));
                
        }
                        
        message_vision(msg, me, target);

        return 1;
}

