// Room: /d/qujing/wudidong/road2.c

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

��������żҴ�ġ������ؽ硱�ˣ����洫�����������Ĵ���������
�ϱ����Ʈ�����󷹲�������̧ͷһ����é�ݱߴ��������Ÿ��ƻϣ�
�����µ�����д�š��ż��ϵ꡹�����浹Ҳ������
LONG);

  set("outdoors", "1");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road1",
  "north" : __DIR__"smithy",
  "south" : __DIR__"shop",
  "west" : __DIR__"road3",
]));

  setup();
}
