// Room: /d/huanggong/yhy2a
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
  "north" : __DIR__"yhy1a.c",
  "south" : __DIR__"yhy3a",
]));
  set("outdoors", "/d/huanggong");

  setup();
}
