
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>

string get_name(){return "�����";}//��������
string get_help()                  //����˵��,�Ժ�ֱ��help,�����޸�
{
        return "�����������ʩչ�������ÿ����ɫ��������ͬ,�����ǹ̶��ġ�\n
�˷����������ã���Ҫһ���ķ�����ħ���㣱�� ����Ч���ɸ������������£�\n
ħ��ʦ �ս��� ������ ���ڵ���ʹ�� ���� Ұ���ˡ�";
}

int do_cast(object me,object target)
{
        string helltype;
        int damage;
        
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        {
                tell_object(me,"��û��ս���У�\n");
                return 1;
        }
        
        if(me->query("mana")<300)
        {
                tell_object(me,"��ķ���̫���ˣ������ò����������!\n");
                return 1;
        }
        
        if(me->is_busy())
        {
                tell_object(me,"����æ����!\n");
                return 1;
        }
        
        if(me->query("magic_pointed")<50)
        {
                tell_object(me,"���ħ����̫���ˣ������ò����������!\n");
                return 1;
        }
        
        helltype=me->query("hell_type");
        if(!helltype) helltype="Ұ����";
        if(!userp(me)) return 1;
        me->add("mana",-2* (120-magic_power[helltype]));
        me->add("magic_pointed",-(120-magic_power[helltype])/10);
        message_vision(HIC "$N��ָ��צ˫������$n����ʱ��ָ������â��$n��ȥ��\n" NOR,me,target);
        damage=100-magic_power[helltype];
        if(random((100-magic_power[helltype])*6) > (50+target->query("level"))/2 )
        {
                target->receive_damage("kee", damage*5+random(damage),me);
                target->receive_wound("kee", damage*2+random(damage),me);

                COMBAT_D->report_status(target, 0);
                me->strat_busy(random(3)+1);

        }
        else
        {
                message_vision(CYN "$N�ĵ�â�߹�$n��$n��ʱ����һ����\n" NOR,me,target);

        }
        me->start_busy(random(2)+1);
        target->kill_ob(me);
        return 1;
}

