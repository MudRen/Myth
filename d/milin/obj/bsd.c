// bianshi dan.c ��ʬ��

inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
add_action("do_eat", "eat");
}
void create()
{
set_name("��ʬ��", ({"bianshi dan","dan"}));
set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
  set("long", "����������ħǱ�����͵Ĺ�ҩ,��ʳ���档\n");
set("unit", "��");
 set("value", 0);
        }
}
int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan") return 0;
me->set("eff_sen", (int)me->query("max_sen"));
me->set("eff_kee", (int)me->query("max_kee"));
me->set("eff_sen", (int)me->query("sen"));
me->set("eff_kee", (int)me->query("kee"));
me->set("mana", (int)me->query("max_mana"));
me->set("force", (int)me->query("max_force"));
me->set("mana", (int)me->query("mana"));
me->set("force", (int)me->query("force"));
me->set("bellicosity", (int)me->query_kar()*2);
me->add("daoxing",1000+random(1000));
message_vision("$N������һ�ű�ʬ��,ʱ����˿��ܻ�����Ϊ��ʬ��\n", me);
  destruct(this_object());
  return 1;
}
