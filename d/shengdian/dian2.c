inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

ʥ������ϼ���������Ƿ��������Ͻ������崮�������΢�ζ�
�����죬����һƬ�����������ơ��������ﲻʱ�Ӹ�������
�����о���������

LONG);

  set("exits", ([
        "east"   : __DIR__"shengdian6",
        "west"   : __DIR__"shengdian5",
        "north"   : __DIR__"dian3",
        "south"   : __DIR__"dian1",
      ]));

  setup();
}
