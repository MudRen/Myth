//Cracked by Roath

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "������");
  set ("long", @LONG

һ��ɽ��أ�����ʣ�ٮٮ��Ⱥ���±�һ�����ɣ�
�Ծ�ͦ�Σ�ֱ�����֮�䡣������ǰٻ�������
�ӵ����ڡ������ǰٻ��ȣ�������滨��ݣ���
ϧɽ�ƶ��ͣ������򲻼ѵ����óȻԾ(jump)
��(down)������ˤ�ùǶϽ��ۡ�
LONG);
  set("exits", ([ /* sizeof() == 3 */
//  "northdown" : __DIR__"penglai",
  "enter": __DIR__"hongyandong",
]));
  set("outdoors", 1);
  setup();
}
void init() {
    add_action("do_jump","jump");
}

int do_jump(string arg) {
  object me=this_player(),ridee=me->ride();
  int damage;
  string dest=__DIR__"baihuagu"+(string)(random(4)+1)+random(5)+".c";

  string msg;

   if (!arg) return 0;
  if (arg!="down") return notify_fail("���Ķ�����\n");

  msg="$N";
  if (ridee) msg=msg+"����"+ridee->query("name");
  msg+="�������ȵ�Ծ�¡�\n";
  message_vision(msg,me);

  damage=random(300-me->query_skill("dodge"));
  if (damage>me->query("eff_kee")-50) damage=me->query("eff_kee")-50;
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
