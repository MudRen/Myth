//created by daiyu for��ؽ�

#include <ansi.h>

inherit ITEM;
#define ZHANSHU "/d/quest/haojie/zhanshu" 
void create()
{
  set_name(HIR"ħ��ս��" NOR ,({"zhanshu"}));
  set("unit", "��");
  set("value", 0);
}
void init()
{
  add_action("get_look","look");
}
int get_look(string arg)
{
  object me = this_player();
  object lw;
  
  if (!userp(me))
      return notify_fail("��ʲôҲû�õ���\n");
  if (arg!="zhanshu")  
      return 0;
      
  //����
  write(REF);
  cat(ZHANSHU);
  return 1;
}

