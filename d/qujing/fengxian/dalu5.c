// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

·ңң�������ģ�����Ĵ�·�ֳ���Զ���������ɽ������
���ǻ��ߵ�ũ�ż���ɼ���һЩСϪС�ӣ����ѸɺԼ��ף�
·�ߴ���֦��Ҷ�䣬�ݻ����ѡ�

LONG);

  set("exits", ([
        "north"    : __DIR__"dalu4",
        "south"    : __DIR__"dalu6",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

