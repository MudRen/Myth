// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//fxtd.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��ѩ���");
  set ("long", "
��������������������������������������������������������\n"
HIR"   �㣬�Ǻ�ģ�\n"
BLU"                        �죬�����ģ�\n"
HIY"                                          �أ��ǻƵģ�\n"
HIC"             �ǽ����覵�ѩ���ڴ�����衭��\n"
NOR"��������������������������������������������������������

    ������Ǵ�˵�еķ�ѩ����ˣ�û�뵽�������ɽ���У����
�����������ģ�����ȴ����������ķ�ѩ�������ﲻ������������
�о�������ȥ���Կ�����ѩ���Ĵ��ţ��ϱ������ɵģ�ʲô����
���������ͷ���ղ��������ĵط���ȴ��һ�����£���֪���ɲ���
������ȥ��

");

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fdoor",
  "south" : __DIR__"lake",
]));
  set("outdoors", 1);

  setup();
}

void init()
{ 
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object who=this_player();

  if (arg != "east") 
     return 0;

message_vision("$N�ֽŲ��ã������ߵ�����������ȥ��\n",who);
who->move("/d/moon/yunu3.c");
message_vision("�����������ˣ�$N����������һ������\n",who);
return 1;
}



