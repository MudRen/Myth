#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();
#include <ansi.h>
void create ()
{
  set ("short", HIB"�ܵ�"NOR);
  set ("long", @LONG

һ�䶷�ң���յ������ƣ�������������˸��һ��˵�����Ĺ���
����ǽ��������Բ��(pan)���ƺ�������ת

LONG);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"moon5",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "pan" : "
����Բ���ϸ���һЩϡ��Źֵ��֣��㿴�˰�������û������
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
    return notify_fail("��Ҫת��ʲô��\n");
  if(arg=="pan")
    return notify_fail("����������趨�������������\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="lovesksjsh")
    {
      message_vision(HIR "��⣡$N�����˻��أ�ֻ������ǽ��С������������档\n" NOR, me);
 if (mykee>0) 
        {
          me->set_temp("death_msg", "˽�����¹����أ��������أ�����������ˡ�\n");
          me->die();
          me->save();
          return 1;
        }
      me->receive_damage("kee", 5000);
      me->receive_wound("kee", 5000);
      message_vision(RED "$N����һ������æ��ܣ������Ǳ������ǵ���\n" NOR, me); 
      return 1;
    }                                                      
  else
    {
      message_vision("$N���չ����趨��������˰��ţ�����һ����ʧ���ź�\n", me);
      me->move(__DIR__"mishi");
      return 1;
    }
}

