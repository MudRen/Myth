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
        "east"   : __DIR__"shengdian4",
        "west"   : __DIR__"shengdian3",
        "north"   : __DIR__"dian2",
        "south"   : __DIR__"dian",
      ]));

  setup();
}
