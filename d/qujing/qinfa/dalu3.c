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
        "west"    : __DIR__"dalu2",
        "east"    : "/d/qujing/wudidong/exit",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

