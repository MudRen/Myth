// Room: /d/qujing/wudidong/firemount-wudidong2
inherit ROOM;

void create ()
{
  set ("short", "Сɽͷ");
  set ("long", @LONG

����һ��Сɽͷ���������ܿ���ƬƬ���̵ĵ�������׶���������
ɽ�Ѿ�ֻʣһ��ģ���������ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"firemount-wudidong3",
  "eastdown" : __DIR__"firemount-wudidong1",
]));
  set("outdoors", "/d/qujing/wudidong");

  setup();
}
