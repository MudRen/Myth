#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ڴ�����һ�����̿��������������һ����������¯��¯����
�����ơ���¯���湩��������λ�����������ɢ�ҵض���һЩ������
��ܱ�ǽ����һ��Сľ��(wheel)����֪�к��ô���
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"inner-tang",
  "east" : __DIR__"cave2",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "wheel" : "
һ�����úܾ�ϸ��ת�̣������㵽�ż������֡�
",
		     "paiwei":"
\t\t��\t\t\t��
\t\t��\t\t\t��
\t\t��\t\t\t��
\t\t��\t\t\t߸
\t\t��\t\t\t��
\t\t��\t\t\t̫
\t\tλ\t\t\t��
\t\t\t\t\t��
\t\t\t\t\tλ

",
]));

  setup();
}
void init()
{
  add_action("do_turn", "turn");
  add_action("do_turn", "zhuan");
}
int do_turn(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("��Ҫתʲô��\n");
  if(arg=="wheel")
    return notify_fail("��������Ӧ�����룡\nƩ�磺turn 1 �� turn 1234������\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="9657")
    {
      message_vision(RED "ֻ��һ���������дܳ���ֱ��$N������\n" NOR, me);
      if (mykee<=200)
	{
	  me->set_temp("death_msg", "���ճ��˷ɻҡ�\n");
	  me->die();
	  me->save();
	  return 1;
	}
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N��Ȼ�˵ò��ᣡ\n" NOR, me);	
      return 1;
    }			                                   
  else
    {
      message_vision("ֻ����������һ����һ������ͻ��$N���ɼ����ƽ�����ȥ�ˣ�\n", me);
      me->move(__DIR__"mishi");
      return 1;
    }
}
