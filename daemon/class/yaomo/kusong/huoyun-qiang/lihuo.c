// �������
// yangwl 1/10/2001 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string get_name(string str)
{
        str="�������";
        return str;
}

string get_help(string str)                
{
        str="ָ����������������\n"
        +"����������ǹ��100��"
        +"������أ����������Է����£�";
        return str;
}

int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("huoyun-qiang",1);
        
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIR"��������ء�"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if(extra < 100)
                return notify_fail("��Ļ���ǹ�����������죡\n");
        if (!PFM_D->valid_family(me, "���ƶ�"))
                return notify_fail("��������ء�ֻ�л��ƶ����˲ſ����ã�\n");
        if(me->query("max_force") < 500)
                return notify_fail("�����������������Ҫ��ǿ�ˣ�\n"); 
        if(me->query("force") < 1000)
                return notify_fail("���������������Ҫ��ǿ�ˣ�\n"); 
              
        
        if(extra >= 400)  extra = 400;
        
        me->add_temp("apply/attack",extra/3);
        me->add_temp("apply/damage",extra/3);
        me->add_temp("apply/strength", extra/10);
        
        message_vision(HIR"$N����ǰָ��ǹ��ͻȻ���Ż�һ�㣬���顱��ը��һ���Ϻ�ɫ�Ļ��棬��
��ͨ��͸����ǹ��ȼ������������ˢ��������һ�������ӳ����������⣬
�������ؾ���һƬ����Ļ��࣬��$n��ͷ�ϸ�ȥ��"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "$Nȫ��������ţ�����ȽȽƮ����˫��ٿת���죡��" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "$N����"+weapon->query("name")+ HIR"����������������ȼ���գ��ų���������ֱ�ӵ���׹⻪��" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra/3);
        me->add_temp("apply/strength", -extra/10);

        me->start_busy(2);
        return 1;
}

