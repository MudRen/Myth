// created by error

inherit ITEM;
inherit RANK_D;
#include <ansi.h>

void create()
{
  set_name("��ս����", ({ "jin pai", "pai" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", @LONG
һ����ƣ�������š������һ������ڶ����˸��֡�
�����ƾ������������������ս(challenge)��
LONG);
    set("unit", "��");
      set("value",1000);
  }
  setup();
}

int init ()  
{   
  add_action("do_defend","challenge");
  return 1;
}

int do_defend(string arg)
{
  object me,ob,other;
  int j;
  me=this_player();
  if (!arg) return notify_fail("��Ҫ��˭��ս?\n");	
  ob=LOGIN_D->find_body(arg);
  if (!ob || !me->visible(ob)) return notify_fail("����û������ˡ�\n");
  if (ob==me) return notify_fail("��ս���ң���־����\n");
if(wizardp(ob))
    return notify_fail("����û������ˡ�\n");

  if (me->query_temp("objectob"))
  {
    if (me->query_temp("objectob")==ob->query("id"))
      return notify_fail ("���Ѿ�������ս��!\n");
    else 
     {
      other=LOGIN_D->find_body(me->query_temp("objectob"));
      if (other) 
        {
         tell_object(me,"����ƴ򲻹�"+other->query("name")+"���������������ˡ�\n");
         tell_object(other,me->query("name")+"���㲻������Ϊ�㲻��ȥ��������������ˡ�\n");
        }
     }
   } 
  message_vision("$N���$n�ֽ��д��书������\n",me,ob);
  tell_object(ob,me->query("name")+"�����㣺"+RANK_D->query_rude(ob)
     +"����û�е��Ӻ��Ҵ���һ��(defend)����������̨���㣡\n");
     
  me->set_temp("objectob",ob->query("id"));

  return 1;
}
