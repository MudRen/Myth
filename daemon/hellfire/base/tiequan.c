#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

#include <magic_power.h>
string get_name(){return "��ȭ��";}//��������
string get_help()                  //����˵���Ժ�ֱ��help,�����޸�
{
        return "�����������ʩչ��ȭ��ÿ����ɫ��������ͬ,�����ǹ̶��ġ�\n"
        +"�˷����������ã���Ҫһ���ķ�����ħ���㣱�� ����Ч������\n"
        +"����:80 ħ��ʦ:20 �ս���:40 ������:50 ���ڵ���ʹ�� 60 Ұ����:90�ٷֱȡ�";
}

int do_cast(object me,object target)
{
        string helltype;
       
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
        
        if(me->query("magic_pointed")<50)
        {
                tell_object(me,"���ħ����̫���ˣ������ò����������!\n");
                return 1;
        }
        
        helltype=me->query("hell_type");
        if(!helltype) helltype="Ұ����";
        if(!userp(me)) return 1;
        me->add("mana",-2* magic_power[helltype]);  
        me->add("magic_pointed",-magic_power[helltype]/10);
        message_vision(HIR "$N���������ֱ�˫Ȫ��$nֻ����һ���޴����ȭͷ������\n" NOR,me,target);
        if(random(magic_power[helltype]+50)>50)
        {
                target->receive_damage("kee", magic_power[helltype]*3,me,"magic_book");
                                                       //���Ӻ���"magic_book"����������� pfm�ļ�����"pfm",��������"cast"��������������ַ������˺�����Դ
                target->receive_wound("kee", (magic_power[helltype])/2,me,"magic_book");         
                                                       //���Ӻ���"magic_book"����������� pfm�ļ�����"pfm",��������"cast"��������������ַ������˺�����Դ
                COMBAT_D->report_status(target, 0);
                me->start_busy(random(2)+1);          
        }
        else
        {
                message_vision(HIR "$N�ľ޴���ȭͷû����$n��\n" NOR,me,target);
                
        } 
        
        me->strat_busy(random(2)+1);
        target->kill_ob(me);
        return 1;
}

