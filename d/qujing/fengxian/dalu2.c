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
        "northeast"    : __DIR__"dalu1",
        "southwest"    : __DIR__"dalu3",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

