//by cigar 2001.12 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string get_name(string str)
{
        str="��׷�ô�";
        return str;
}

string get_help(string str)                
{
        str="ָ���������������\n"
        +"������������100��"
        +"�����ܴ���Է��ı����������ܹ�busy�Է���";
        return str;
}

int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("dali-bang",1) ;
        if ( extra < 100) 
                return notify_fail("���[��������]���������죡\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||        !target->is_character()
        ||        !me->is_fighting(target) )
                return notify_fail("����׷�ô��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
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
                message_vision(HIR "\n\n$Nʹ��һʽ�������е�"+HIG"����׷�ô�]"+HIR"�����е�"+(me->query_temp("weapon"))->name()+HIR"���һ����ɫ¶˿��$n�ı���Խ��Խ����
$n"+HIR"����ôץ��Ҳ�޼������ˣ���ʱ����"+ weapon->name()+  "���ֶ��ɣ�\n\n" NOR, me,target);
                weapon->unequip();
                if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
                message_vision(HIR "\n\n$Nʹ��һʽ�������е�"+HIG"����׷�ô��"+HIR"�����Ҷ��컮��һ����ɫ��Ȧ"+(me->query_temp("weapon"))->name()+  HIR"��"+"$n"+HIR"Խ��Խ�����Ƶ�$n������������ĵز���\n\n" NOR, me,target);
                if(random(hisexp) < myexp*2/3 )
                {
                        target->start_busy(5+random(7));
                }
                else 
                {
                        message_vision(HIY "\n$n��׷���޿��κΣ�����������������һ��"+HIW"�첻����"+HIY"�����в����Լ�������ͳͳ���⣡\n" NOR, me, target);
                }
        }
        me->start_busy(2);
        me->improve_skill("dali-bang", 1, 1);

        return 1;
}

