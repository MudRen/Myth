#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
                  set_name( HIY "�������ɵ�" NOR , ({"da bu dan","dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
  set("unit", "��");
       set("long", "������ʦ�ǾžŰ�ʮһ�쾫�����ƵĴ󲹵�(dan)����˵��(eat)������Ч��\n");
      set("value", 100);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

 int do_eat(string arg)
{
  object me = this_player();
       if (arg!="dan") return 0;

seteuid(getuid());
  switch (random(5))
{
case 0:
{
     me->add("combat_exp",50);
                 message_vision(HIM "$N����һ��������Ե�󲹵���С������س��˽�ȥ��
         �ÿᰡ��$N����ѧ����������50�㣡\n" NOR, me);
break;
}
case 1:
{
       me->add("daoxing",200);
                   message_vision(HIG "$N����һ��������Ե�󲹵���С������س��˽�ȥ��
           �ÿᰡ��$N�ĵ���������50�죡\n" NOR, me);
break;
}
case 2:
{
        me->add("potential",50);
                    message_vision(HIR "$N����һ��������Ե�󲹵���С������س��˽�ȥ��
            �ÿᰡ��$N��Ǳ��������50�㣡\n" NOR, me);
break;
}
case 3:
{
        me->add("force",5);
        me->add("max_force",5);
                      message_vision(HIB "$N����һ��������Ե�󲹵���С������س��˽�ȥ��
             �ÿᰡ��$N������������5�㣡\n" NOR, me);
break;
}
case 4:
{
        me->add("max_mana",5);
        me->add("mana",5);
                      message_vision(HIW "$N����һ��������Ե�󲹵���С������س��˽�ȥ��
             �ÿᰡ��$N�ķ���������5�㣡\n" NOR, me);
break;
}
}
  destruct(this_object());
  return 1;
}
