// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG

һ�����Ĵ�·������ʯ�̾ͣ����г����ϱ������ӳ�ȥ������
����Զ��������ͨ�����Ϲ���·���߳���ׯ�ڣ�ż��ũ�ᡣ

LONG);

  set("exits", ([ 
    "north" : __DIR__"dalu1",
    "south" : __DIR__"zhuzi1",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
