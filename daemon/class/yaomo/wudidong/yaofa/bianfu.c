#include <ansi.h>
inherit F_DBASE;
inherit SSERVER;
int cast(object me, object target)
{
        int skill_spells, skill_dodge, dodge_amount,howlong;
        skill_dodge = me->query_skill("dodge");            
        if (skill_dodge<100) 
                return notify_fail("����Ṧ��������������������Ҳ�ɲ�������\n");
        skill_spells=me->query_skill("spells");        
        if (skill_spells<100) 
                return notify_fail("��������������졣\n");
        if( (int)me->query("mana") < 100 )      
                return notify_fail("��ķ���������\n");
        if (me->query("sen")<100)
                return notify_fail("��ľ����㡣\n");
        if( (int)me->query_temp("wdd_powerup") )
                return notify_fail("���Ѿ����˹����ˡ�\n");
        if (!me->query_temp("wdd_drink_hulu"))
                return notify_fail("��þ�û͵�ͳ��ˣ��䲻������\n");
        me->add("mana", -50);
        me->add("sen",-50);
        me->delete_temp("wdd_drink_hulu");
        message_vision(HIB"$N���������дǣ�ͻȻ����ϳ�����һ�Գ�򣬱����һֻ����\n"NOR,me);
        dodge_amount=me->query_skill("lingfu-steps",1)/2; 
        me->add_temp("apply/dodge",dodge_amount);  
        me->set_temp("wdd_powerup", 1);
        me->set_temp("wdd_limbs",me->query("limbs"));
        me->set("limbs",({
  "ͷ��",  "����", "�ؿ�",  "����",  "���",  "�Ҽ�",  "���", "�ұ�",
  "����",  "����", "����",  "С��",  "����",  "����",  "���", "�ҽ�",
  "���",  "���",  "���",  "���",  "���",  "���",  "���",  "���",
}));
        howlong=me->query_skill("yaofa",1)/5+5+random(5);
        if (howlong>60) howlong=60;
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, dodge_amount:), howlong);
         return 1;
}
void remove_effect(object me, int dodge_amount)
{
        me->add_temp("apply/dodge", -dodge_amount);
        me->delete_temp("wdd_powerup");
        me->set("limbs",me->query_temp("wdd_limbs"));
        message_vision(HIB"$N���л������ܣ�ҡ��ҡ�Դ����ֳ���ԭ�Ρ�\n"NOR,me);
}

