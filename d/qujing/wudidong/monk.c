// Room: /d/qujing/wudidong/monk.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ȼ��յ��С���͵ƣ�΢���Ļƹ���ֻ�����ϵĸɲݶ������Ÿ���
���У��������ã�ȫ��Ѫ���߰ߣ��ѱ���ĥ�ò��������ˣ���ϲ��û
��������͡�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jail",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fangzhang-jail" : 1,
]));
  set("outdoors", 0);

  setup();
}
