// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

һ���̳������Ĵ�·����·ңң������ãã��ǰ�������˺�
�����ߡ�ʱ����Զ���޺�ʱ�����н������������߻�ɽҰ��
������֣��㲻�������ؼӿ첽����

LONG);

  set("exits", ([
        "east"    : __DIR__"dalu12",
        "west"    : __DIR__"dalu10",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

