// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����·");
  set ("long", @LONG

�����ڳ���������·�ϣ������������ģ���紵��Ҷ��֦�裬ʱ��
ʱ����Զ���Ļ�ХԳ�䡣���˲��������ؼӿ첽����

LONG);

  set("exits", ([ 
    "west" : __DIR__"lin5",
    "east" : __DIR__"dalu1",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
