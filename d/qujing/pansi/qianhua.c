// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ǧ����");
  set ("long", @LONG

������һ�����ڣ�����Ұ��ʢ������ǧ��ҷ��ޱȣ����߰���
�̲��޹���׺��͸�����ڿɼ���������һ���澰������������
Դһ�㡣

LONG);

  set("exits", ([
        "northwest"    : __DIR__"shandao1",
        "south"    : __DIR__"huajian2",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

