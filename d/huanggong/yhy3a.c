// Room: /d/huanggong/yhy3a
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
  "north" : __DIR__"yhy2a.c",
  "southeast" : __DIR__"damen",
]));
  set("outdoors", "/d/huanggong");

  setup();
}
