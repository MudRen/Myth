// Room: /d/huanggong/yhy2b
// created by snowcat 10/05/1997

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
  "north" : __DIR__"yhy1b.c",
  "south" : __DIR__"yhy3b",
]));
  set("outdoors", "/d/huanggong");

  setup();
}
