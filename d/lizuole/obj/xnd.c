// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xiannidan.c ���൤

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_drop","��ô��������൤����������! \n");
        }
        add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "���൤" NOR, ({"xianni dan","dan","ni","xnd"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("long", "�������һ���൤�衣������У�����̶���ɡ��ĸ��֡�\n");
     //set("value", 5000);
     set("drug_type", "��Ʒ");
        }
  set("is_monitored",1); //��ؾ���
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg)) 
    {
      return notify_fail("��Ҫ��ʲô��\n");
    }
   else
     {
      if ( me->query("xndc")=="�Թ���" )
        {
          command("say ���Ѿ��Թ��ˣ���Ҫ��ô̰���������������˰ɣ�");
          destruct(this_object());
          return 1;
        }
       else
         {
           me->set("food", (int)me->max_food_capacity());
           //me->set("xndc", "�Թ���");
           me->add("max_mana",200);
           me->add("max_force",200);
           me->add("combat_exp",10000); 
           me->add("potential",30000);
           me->set("xndc", "�Թ���");    
           message_vision(HIC "$N����һ�����൤��ֻ������ȽȽ����һ����������ʹ�� ���ò��󺰵������磬�����ˡ��� ������մ���һ���󺰣������������������200�㣬Ǳ������30000�����м�10�ꡣ  �������������ˣ� \n" NOR, me);
           destruct(this_object());  //���������Ʒ
           //me->set("xndc","�Թ���");
           return 1;
         }
     }
}
