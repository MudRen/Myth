// Room: /d/qujing/wudidong/tang-gate.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�ѵ��˵��ſڣ���ϡ������������������������յ������ֻ�����ŵ�
������С���������öԸ������ﶨ�����޵׶��Ķ����ˣ�������ߣ�
�ѵ�ҪԵ�һ�棿�㲻��������ɦ��
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hudian" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"houdong",
  "north" : __DIR__"inner-tang",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "north" && 
      member_array("tian shu",me->parse_command_id_list())==-1 &&
      member_array("yu shu",me->parse_command_id_list())==-1 &&
      me->query("family/family_name") != "�ݿ�ɽ�޵׶�" &&
      objectp(present("hudian yao", environment(me))))
    {
      message_vision(CYN"�������ȵ���߾���η����ˣ������ô����أ�\n"NOR, me);
      return notify_fail("");
    }
  return ::valid_leave(me, dir);
}
