//����
//write by yesi
//yeahsi@21cn.com

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon=me->query_temp("weapon");
        int enhance,damage;
        string str;

        if (!weapon) return 0;
        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()||target->is_corpse()||target==me)
                return notify_fail("��Ҫ����˭��\n");
        
        if (!me->is_fighting())
                return notify_fail("����ֻ����ս����ʹ�ã�\n");
      
        if( time()-(int)me->query_temp("jianzhang_end") < 3 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");
/*     
        if (me->query_temp("jianmang"))
                return notify_fail("������ʩ�ý�â��û�����������ƣ�\n");
*/                       
        if( time()-(int)me->query_temp("jianmang_end") < 3 )
                return notify_fail("����������������\n"); 
                     
        if (!PFM_D->valid_family(me, "��ׯ��"))
                return notify_fail("[����]����ׯ�۲���֮�ܣ�\n");
                
        if (me->query_skill("sanqing-jian",1)<60)
                return notify_fail("������彣��̫�����������ơ�\n");
      
        if (me->query_skill("wuxing-quan",1)<60) 
                return notify_fail("�������ȭ̫�����������ơ�\n");
    
        if (me->query_skill("zhenyuan-force",1)<60)
                return notify_fail("�����Ԫ����Ϊ����������������ơ�\n");
     
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("���Ʊ��������Ԫ�񹦲���ʹ�á�\n");
     
        if (me->query_skill_mapped("unarmed")!="wuxing-quan")
                return notify_fail("���Ʊ����������ȭ����ʹ�á�\n");
      
        if (me->query("force")<100)
                return notify_fail("���������̣����Գ��С�\n");
     
        me->add("force", -100);
        seteuid(getuid());
        me->set("actions", (: call_other, SKILL_D("wuxing-quan"), "query_action" :) );
   
        message_combatd(HIC"\n$N������Ԫ�񹦣�û����ʽ���ϣ���̤���ԣ�����һ��ת��һ�ߣ��������ս����ơ�\n"NOR,me,0,"");
        weapon->unequip();
        weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
        weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
        weapon->set("use_apply_skill",1);
        weapon->set("apply/skill_type","unarmed");
        enhance=me->query_skill("wuxing-quan",1);
        me->add_temp("apply/attack", enhance);  
        damage=me->query_skill("zhenyuan-force",1);
        damage=damage/2;
        me->add_temp("apply/damage",damage);        
        COMBAT_D->do_attack(me, target);
        weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
        weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
        me->add_temp("apply/attack",-enhance);
        me->add_temp("apply/damage",-damage);
        weapon->wield();
/*      
        if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
        {
                str=target->name()+"��"+me->name()+"����ׯ�۾��С����ơ������ˣ����������л����ּ����ںڵ���ӡ��";
                message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());
        }
*/              
        me->reset_action();
        me->set_temp("jianzhang_end",time());
        return 1;
}

