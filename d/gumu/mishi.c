#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();
#include <ansi.h>
void create ()
{
  set ("short", HIW"�������"NOR);
  set ("long", @LONG


����һƬ�谵����ʲôҲ�����壬��о������ƺ���ʲô����
����ϸ��ԭ����һ�����ã������ǵ�Ĺ�ߵĺ��ǣ�ͻȻ���ͷ����
ײ��ʯͷ(stone)���ˡ�

LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fox" : 4,
]));

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"bianhou",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
һ��Բ�ε�ʯͷ
",
]));

  setup();
}

void init()
{
  add_action("do_turn", "turn");
}
int do_turn(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("��ҪŲ��ʲô��\n");
  if(arg=="stone")
    return notify_fail("�㿴͸��ô��\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="left")
    {
      message_vision(HIR "һ�������ʯͷ������������\n" NOR, me);
      if (mykee<=200)
        {
          me->set_temp("death_msg", "�ڹ�Ĺ���ұ���������ˣ�\n");
          me->die();
          me->save();
          return 1;
        }
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N����һ������æ��ܣ������Ǳ�ʯͷ�ҵ���\n" NOR, me); 
      return 1;
    }                                                      
  else
    {
      message_vision("$N������ת��ʯͷ������ડ�һ��������ǰ��ǽ��ͻȻ�ѿ���$N�������˽�ȥ��\n", me);
      me->move(__DIR__"baoku");
      return 1;
    }
}

