//edit by xuanzi 2000/9/12

#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "���¸�");
  set ("long", @LONG

�������������������������������������������������������������������������r 
��        .      .  ǧ �� �� �� �� �� �� ת �� �� �� Ψ �� �� �� �� ��  �� 
�� .          .     �� Ը �� �� �� �� �� �� �� �� �� �� �� Ϧ ֪ �� ��  �� 
��   .  ��        . �� �� �� �� �� �� �� �� �� Ū �� �� �� �� �� �� ��  �� 
��          .       � �� �� �� �� �� �� �� �� �� ʤ ¥ �� �� �� �� ʱ  �� 
��    .             �� �� ȫ Բ �� �� �� �� �� Ӱ �� �� �� �� �� �� ��  �� 
��             .    �� �� �� ȱ �� ʱ Ӧ � �� �� �� �� ȥ �� �� �� ��  �� 
�� .      .                  �� �� Բ �� ��          �� ��    ��        �� 
��     .           .         .     �� �� ��                             �� 
�������������������������������������������������������������������������s 

 ����յ����ģ�ֻ�����涴���Ĵ��������Կ����������ɫ�����ߵĴ�������һ��
 С�����������һ�����١�

LONG);

  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
//  "/d/moon/obj/qin" : 1,
]));
  set("no_time", 1);
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"wygdown",
]));

  setup();
}

void init()
{
   add_action("do_play","play");
}

int do_play(string arg)
{
  object me=this_player();
  if (me->is_busy())
  {
    return notify_fail("����æ���أ������ٵ��ѣ����ۻ��ˡ�����\n");
  }
  if (me->query("sen")<100)
  {
    return notify_fail(HIY "��̫��ƣ�룬������Ϣһ�°ɡ�\n" NOR);
  }
  if (!arg) return notify_fail("��Ҫ��ʲô��\n");
  if (arg!="qin") return notify_fail("��Ҫ��ʲô��\n");
  message_vision("$N����������������ָ����ҡ�������\n",me);
  remove_call_out("playing");
  call_out("playing",5);
  me->start_busy(15);
 return 1;
}

void playing()
{
  message_vision("�����r�r�����ɽ������ˮ�����಻��...\n",this_player());
  remove_call_out("playing1");
  call_out("playing1",5);
}

void playing1()
{
  message_vision("$N�ൽ����֮����˿˿��������������������������¸�\n",this_player());
  remove_call_out("end");
  call_out("end",5);
}

void end()
{
 object me=this_player();
 int pot;

 message_vision(HIC "\nһ���Ѿ������������\n" NOR+"�������ã��ż�$N�������һ������վ��������\n",this_player());
 me->start_busy(1);
// pot = (random(me->query_kar()) + me->query_skill("zou-qin",1)) * 2;
// me->improve_skill("zou-qin",pot);
// me->receive_damage("sen",pot/5);
}

