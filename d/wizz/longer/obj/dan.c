// dan.c   Creat By Longer@ALL_XYJ 
#include <ansi.h>

inherit ITEM;

int do_kiss(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
    set("no_give","��ô���ĵ������������ˣ�\n");
    set("no_drop","��ô�İ��Ķ��������˶��ϧѽ��\n");
    set("no_sell","����֮������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_kiss", "kiss");
}

void create()
{
  set_name(HIR "��" NOR, ({"dan"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "Ϊ����ף���ǵ��߿�վ��������210�������ļ����\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_kiss(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ����ʲô��\n");
  
  me->add("combat_exp",90);
  me->add("daoxing",190);
  me->add("potential",90);
  message_vision(HIR "$N����һ����˼�춹����˼�춹����ҫ�۹�â��\n����ʱ������,���������߿�վ�ȹ�������,$N������Ȼ���¡���\n" NOR, me);
  
  destruct(this_object());
  return 1;
}

