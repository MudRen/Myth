// Room: /d/huanggong/yhy1b
inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

�д�����������԰����������������ɫ���η��˵��滨����
�м���������ת������ʯ��С����Ϊ������紵������
���ⴼ�����ޱȣ����˻�Ȼ����

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"fst.c",
  "south" : __DIR__"yhy2b",
]));
  set("outdoors", "/d/huanggong");

  setup();
}
