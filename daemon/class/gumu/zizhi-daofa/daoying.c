//��Ӱ����
//by junhyun@sk

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
             return notify_fail("��Ӱ����ֻ����ս����ʹ�ã�\n");
           
     if( time()-(int)me->query_temp("daoying_end") < 5 )
                   return notify_fail("����������������\n");      
     if(me->query("family/family_name") != "��ԯ��Ĺ")
                return notify_fail("[��Ӱ����]����ԯ��Ĺ����֮�ܣ�\n");
      if (me->query_skill("jiuyin-zhua",1)<60) 
          return notify_fail("��ľ����׹�צ�ȼ�������\n");                
     if (me->query_skill("zizhi-blade",1)<60)
          return notify_fail("�����������̫����������Ӱ����\n");
    if (me->query_skill("jiuyin-force",1)<60)
        return notify_fail("��ľ����澫��Ϊ���������������Ӱ����\n");
     if (me->query_skill_mapped("force")!="jiuyin-force")
            return notify_fail("û�о����������ʹ�õ�Ӱ����\n");
     if (me->query_skill_mapped("unarmed")!="jiuyin-zhua")
            return notify_fail("��Ӱ������ȫ��Ĺ���û�о���צ�ǲ��еġ�\n");
      if (me->query("force")<150)
           return notify_fail("���������̣����Գ��С�\n");
    message_vision(HIW"\n
$NĬ�˾�����������צ��ʩ���λε�Ӱ�У�����������צ�硣

��ʱ�䣬����ɳ��������צӰ�������ǵ�������צצҪ��"NOR,me);
    //weapon->unequip();
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","unarmed");
    enhance=me->query_skill("jiuyin-zhua",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("jiuyin-force",1);
    damage=damage/2;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    //weapon->wield();
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+"��"+me->name()+"����ԯ��Ĺ���С���Ӱ���������ˣ�ʬ�������������ĵ���צ�ۣ�";
                         message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());
                       }
    me->reset_action();
    me->set_temp("daoying_end",time());
    return 1;
}


