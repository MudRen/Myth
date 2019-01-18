// ���ϲ�� by Cigar

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIR"���ϲ��"NOR , ({"xi tang","tang"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", HIR"����һ��ŨŨ��������ζ���ɿ���ϲ�ǣ���"HIY"����"+HIR"��"+HIY"����"+HIR"�Ľ��ϲ�ǡ�\n"NOR);
    set("value", 0);
    set("no_sell", 1);
    set("drug_type", "��Ʒ");
  }
  setup();
  call_out ("becoming_old",1800);
}
void becoming_old ()
{
  object me = this_object();
  object where = environment (me);
  object dan = new (__DIR__"tang");

  dan->move(where);
  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="xi tang" && arg!="tang") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*20+random(100));
  me->set("water", (int)me->max_water_capacity()*25+random(100));
  message_system(HIG "           \nףԸ"+HIR"���������"+HIG"����úͣ���ͷ���ϣ��������ӣ����������� "+HIR"




                          ��            ��                        
                          ��            �� 
                     �ևևևևևևևևևևևևև�
                          ��            �� 
                          ��            �� 
                        �ևև�        �ևև�

                       �ևևև�      �ևևև�
                       ��    ��      ��    �� 
                       �ևևև�      �ևևև�
 
                       ��    ��      ��    ��
                         �և�          �և�
                    �ևևևևևևևևևևևևևև�
    
                        �ևև�        �ևև�
                        ��  ��        ��  �� 
                        �ևև�        �ևև�



                      "+HIY"ףԸ"+HIR"����"+HIY"��"+HIR"����"+HIY"���»���֣�\n"   NOR, me);

  tell_object(me, HIM"\n�����ף�����ǰɣ���֮���֮�У���������ɽ�ˣ�������ĵ��ϣ��ҵ���ֻΪ�����Ծ... ...    "+HIR"����"+HIM"��"+HIR"����"+HIM"ףԸ�������ҵ�����Ķ�\n");
  destruct(this_object());
  return 1;
}
