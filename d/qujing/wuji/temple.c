// snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

ֻ������שǽ���ۣ��������϶��𶤣�����¥̨�����ϣ��ǳǹ���
��ɽ�С���Ȼ��һ������Ժ�������Ϻ���̽��д�������֣�������
�£���
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"road4",
  "enter" : __DIR__"piandian.c",
  "south" : __DIR__"road5.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/monk2" : 2,
  __DIR__"npc/monk1" : 1,
]));

  setup();
}

int valid_leave (object who, string dir)
{
  object seng = present ("shousi seng", environment(who));
  if (dir == "enter" && seng && living (seng))
    return notify_fail (seng->query("name")+"˵��������Ժˡ���ӿͣ���ء���\n");
  return ::valid_leave(who, dir);
}
