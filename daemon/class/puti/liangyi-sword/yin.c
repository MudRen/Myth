// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="ָ��:�������������\n"
        +"���������ǽ���100��"
        +"��Ů�Կ�ʹ�ã����Դ���Է��ı�������ʹ�Է�����busy״̬��";
        return str;
}

int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("liangyi-sword",1) ;
        if ( extra < 100) return notify_fail("���[���ǽ���]���������죡\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
/*
        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("[���־�]��ֻ��Ů�Ӳ���ʹ�õ����ԡ�\n");
*/  
        if((int)me->query("force") < 150 ) 
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 150 ) 
                return notify_fail("���޷����о�����\n");
        me->add("force", -100);
        me->receive_damage("sen", 100);
        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        if(random(hisexp) < myexp*2/3 && weapon)   
        {       
                message_vision(HIB "\n\n$Nʹ��һʽ���ǽ����еģ��������ݣ�����"+(me->query_temp("weapon"))->name()+"��$n�ı���Խ��Խ����$nһ���ѳֲ�ס������"+ 
weapon->name()+  "���ֶ��ɣ�\n\n" NOR, me,target);
                weapon->unequip();
                if( weapon->unequip()) 
                        weapon->move(environment(target));
        }
        else
        {
                message_vision(HIB "\n\n$Nʹ��һʽ���ǽ����еģ��������ݣ�����"+(me->query_temp("weapon"))->name()+  "��$nԽ��Խ�����Ƶ�$nһ����æ���ң�\n\n" NOR, me,target);
                if(random(hisexp) < myexp*2/3 )
                {
                        target->start_busy(3+random(7));
                }
                else 
                {
                        message_vision(HIB "\n$n��Ϊ����վ�˸�����������У�\n" NOR, me, target);
                }
        }
        me->start_busy(2);
        me->improve_skill("liangyi-sword", 1, 1);

        return 1;
}

