#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();
#include <ansi.h>
void create ()
{
  set ("short", HIB"�Ź�����"NOR);
  set ("long", @LONG

һ�䶷�ң���յ������ƣ�������������˸��һ��˵�����Ĺ���
���м�һ����ʯ���Ϻ��������ڷ��žŸ��ǽ��ľ������(qizi)
ÿ�������¶���һ������������й�������������һ��С����
��������һ����ĳ����������Ǻܾ�û���˴�������Щ������

LONG);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"yongdao1",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "qizi" : "
ÿ�������Ͽ���һ�����֣���һ���ţ��������롣
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
  if(arg=="qizi")
    return notify_fail("�밴�Ź�֮���ƶ�����\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="294753618")
    {
      message_vision(HIR "ֻ������ǽ��С������������棬ֱ��$N������\n" NOR, me);
      if (mykee<=200)
        {
          me->set_temp("death_msg", "���ճ��˷ɻҡ�\n");
          me->die();
          me->save();
          return 1;
        }
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N����һ������æ��ܣ������Ǳ������ǵ���\n" NOR, me); 
      return 1;
    }                                                      
  else
    {
      message_vision("$N���վŹ�֮��������һһ�ںã�һ������ͻ��$N��ϲ����ͷ���˽�ȥ��\n", me);
      me->move(__DIR__"yaoguang");
      return 1;
    }
}

