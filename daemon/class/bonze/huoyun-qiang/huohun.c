//Cracked by Roath
//bellicosity
//���

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int remove_ansi(object target,object me,int damage,int enhance);

int perform(object me, object target)
{       
        int damage,howlong,enhance;
        object weapon=me->query_temp("weapon");
        mapping action;        
        
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("��Ҫ����˭��\n");
      if (!target->is_fighting(me))
             return notify_fail("ֻ����ս���вſ���ʹ�á���꡹��\n");
      if (me->query_skill("force")<100)
          return notify_fail("����ڹ���Ϊ������\n");
      if (me->query_skill("huomoforce",1)<50)
         return notify_fail("���ħ�ķ���򲻹���\n");
      if (damage=me->query_skill("spear")<80) 
          return notify_fail("���������Ƿ���\n");
      if (me->query("force")<500)
           return notify_fail("���������̣����Գ��С�\n");
     
      if (me->query_temp("pfm_huohun")) return notify_fail("���Ѿ����������ˡ�\n");
        me->add("force",-200);
        message_vision(HIR"$NͻȻ�������Լұ����ϴ�����ȭ�������������������"NOR+weapon->name()+
        HIR"��ʱ������ӿ�������˵أ��������Ű������$n������\n"NOR,me,target);
        me->add("sen",-100);
        
        howlong=me->query_skill("spear")/5;
        


        me->set_temp("pfm_huohun",1);
        

        enhance=me->query_skill("huomoforce",1)/2;
        me->add_temp("apply/attack", enhance);  
        damage=me->query_skill("huoyun-qiang",1)/2;
        if (damage>150) damage=100;
        action=copy(me->query("actions"));
        damage=action["damage"]*damage/20;
        me->add_temp("apply/damage",damage);
        me->set("actions",action);
        COMBAT_D->do_attack(me, target, weapon);
        me->reset_action();
        me->start_busy(1+random(2));
        call_out("remove_ansi",howlong,target,me,damage,enhance);
        return 1;
}


int remove_ansi(object target,object me,int damage,int enhance)
{       object here;
        string arg;
        if (!me) return 1;
        here=environment(me);
        me->delete_temp("pfm_huohun");
        me->add_temp("apply/attack",-enhance);
        me->add_temp("apply/damage",-damage);
        arg="$N����ɫ�����Ļָ�������";
        if(me->is_fighting(target)) arg+="������Ҳ���������";
        message_vision(arg+"��\n",me);
        return 1;       
}

