// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "˽��");
  set ("long", @LONG

���������������һ�鰸���������һ����ʱ�õ�ȼ�㡣��
ͷ����һЩ��򣬷���һ��ͭ��ߡ�˽�ӵı�ǽ��һ��������
ȥ�ɼ����ĵ���ɽ��

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao18",
      ]));
  set("objects", ([
        __DIR__"npc/yuan"   : 1,
        __DIR__"npc/kid"   : 3,
      ]));

  setup();
}


