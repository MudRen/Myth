//Cracked by Roath
#include <ansi.h>
#define LAST_PAR "bc"
#define THIS_PAR "bcsf"
#define GIFT_NAME "�½�����"
inherit ITEM;
void create()
{
    set_name(HIR + GIFT_NAME + NOR, ({"gift","liwu"}));
    set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
        set("long",
              HIR+"                ������������������������������������������������
                ��                                            �� 
                ��  "HIY"�����Σ�������ʦ��"HIR"                      �� 
                ��                                            �� 
                ��   "HIY"    �����е���ҵ�Ǹ��HAPPY HAPPY"HIR"        �� 
                ��                                            �� 
                ��   "HIY"         ϣ�������ܹ�����!  "HIR"             �� 
                ��                                            �� 
                ��                                            �� 
                ��                       "HIW"       addoil!"HIR"       �� 
                ��                       "HIG"          ����С��"HIR"   �� 
                ������������������������������������������������
DHXY ��ʦ��һ��С���⣬���(chai)��������ʲô��
"NOR
);
    set("value", 0);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_drop",1);
  }
    setup();
}
void init()
{
    add_action("do_chai", "chai");
}
int do_chai(string arg)
{
      string *skills;
      mapping all_skills;
     object me = this_player();
     int i;
     int jp = me->query("mud_age") / 86400 ;
     object ob = new("/obj/money/gold");
     all_skills=this_player()->query_skills();
     skills=keys(all_skills);
//       if (!sizeof(skills))  return notify_fail("�����ڲ��ܲ������Ȼ��ڲ�! \n");
     for(i=0;i<sizeof(skills);i++)

  if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");

  if (!me->query(THIS_PAR + "_chai"))  {

        this_player()->set_skill(skills[i],all_skills[skills[i]]*3/2);
        this_player()->add("combat_exp",this_player()->query("combat_exp"));
        this_player()->add("daoxing",this_player()->query("daoxing"));        
        this_player()->add("potential",this_player()->query("potential")-this_player()->query("learned_points"));

    if (jp >= 10) {
       ob->set_amount(888);
       ob->move(me);
       me->add("max_force", 1000);
       me->add("maximum_force", 1000);
       me->add("max_mana",1000);
       me->add("maximum_mana",1000);
       me->add("potential",10000);
       me->add("combat_exp",20000) ;
       me->add("daoxing",20000);
     } 

    if ( jp < 10 && jp >= 2) {
       ob->set_amount(888);
       ob->move(me);
       me->add("max_force", 1000);
       me->add("maximum_force", 1000);
       me->add("max_mana",1000);
       me->add("maximum_mana",1000);
       me->add("potential",10000);
       me->add("combat_exp",20000) ;
       me->add("daoxing",20000);
     } 
    if (jp < 2) {
       destruct(ob);
       me->add("max_force", 600);
       me->add("maximum_force", 600);
       me->add("max_mana",600);
       me->add("maximum_mana",600);
       me->add("potential",10000);
       me->add("combat_exp",10000) ;
       me->add("daoxing",10000);
      }    


   message_vision(HIC "$NС������Ĳ��������ֻ��һ���������$N��ʱ����ԼԼ�е��Լ�����������̥���ǵı仯��\n" NOR);
    tell_object(me,HIG "����ү����Ķ�������˵������ϲ���ƣ����� i hp skills ������\n");
//ɾ���ϴ����������ɵĲ��������ӱ��β�����ȷ��ÿλ���ֻ����һ�Ρ�
      me->delete(LAST_PAR + "_chai");
      me->set(THIS_PAR + "_chai",1);
  } else {
      tell_object(me,HIC "��С������Ĳ��������ֻ��һ������������ʱ����ԼԼ�е��Լ�����û�б仯��\n" NOR);
  }
     destruct(this_object());
     return 1;
}
void owner_is_killed() { destruct(this_object()); }

