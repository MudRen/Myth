// ������ ������ by Calvin

#include <ansi.h>
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�ഫ�����ɽ������������,��Ϊ�ĳ����ṩ�ĳ��ɱ㾶,
ֻҪ���ĵõ�����������ȥ�ͻ�����,���μ�������....
�������������ȥ(jump down)��
          ������������������
          ������������������
          ����ң���������������ң���ڡ���
          ������������������
          ������������������

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up": __DIR__"lingge",
]));
  set("objects", ([
"/d/9ct/npc/piaomiao" : 1,
      ]));

  setup();
}
void init() {
    add_action("do_jump","jump");
}

int do_jump(string arg) {
  object me=this_player(),ridee=me->ride();
  int damage;
  string dest=__DIR__"huayuan.c";

  string msg;

   if (!arg) return 0;
  if (arg!="down") return notify_fail("���Ķ�����\n");

  msg="$N";
  if (ridee) msg=msg+"����"+ridee->query("name");
  msg+="�������µ�Ծ�¡�\n";
  message_vision(msg,me);

  damage=random(300-me->query_skill("dodge"));
  if (damage>me->query("eff_kee")-200) damage=me->query("eff_kee")-200;
  if (damage<=0) damage=0;
  me->receive_wound("kee",damage);
  me->move(dest);
  if (ridee) ridee->move(dest);
  if (!damage) message_vision("$N�������������������������ɵ����ڵ��ϣ�����δ��\n",me);
  else {
  message_vision("$N���������������������˸��������\n",me);
  COMBAT_D->report_status(me); 
  }
  if (ridee) {
      message_vision("\n$N���ŵ�"+ridee->query("name")+"ˤ����һ�������",me);
      ridee->die();
  }
  me->start_busy(1+random(2));
  return 1;
}
