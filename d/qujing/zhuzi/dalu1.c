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
    "northeast" : __DIR__"lin4",
    "west" : __DIR__"lin6",
    "south" : __DIR__"dalu2",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
