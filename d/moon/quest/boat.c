//Cracked by Roath

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "һҶС��");
  set ("long", @LONG

һҶ���ֻ�������˵ı��ۣ���ͷվ��һλ��̤��ɫ���Ƶ�������Ů��
����һ�����̵���ݣ���Ц�����ؿ����㡣����������ϸһ��������
����һ����ԭ������һ���޵״���
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"lotuspond.c",
]));
set("zuo_trigger", 0);

  setup();
}

void init() {

  object me=this_player();
  object *inv=deep_inventory(me);
  if (me->query("daoxing")<1000000 || random(me->query_kar())<10) call_out("drown",1,me);
  else if (me->query("family/family_name")!="�¹�" && random(3)) call_out("drown",1,me);
  else for (int i=0;i<sizeof(inv);i++)
    if (userp(inv[i]) ) {call_out("drown",1,me);return;}

  return;
}

void drown(object me) {
  object *inv;

  if (!me) return;
  inv=deep_inventory(me);

  message_vision(HIC"$Nû��ע�⵽���������޵�֮����һ��̤�˸��գ���ͨһ�������˺��ס�\n"NOR,me);
  me->move(__DIR__"hudi");
  for (int i=0;i<sizeof(inv);i++) 
    if (userp(inv[i])) {
/*
      inv[i]->remove_all_killer();
      inv[i]->remove_all_enemy();
      inv[i]->set_temp("death_msg","�����������޳Ե��ˡ�\n");
      inv[i]->die();
      inv[i]->delete_temp("death_msg");
*/
   inv[i]->unconcious();
   inv[i]->move(__DIR__"hudi");
    } else destruct(inv[i]);
  if (me->query("family/family_name")!="�¹�" || me->query("family/generation")!=2) me->unconcious();
}
