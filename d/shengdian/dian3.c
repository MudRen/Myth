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
        "east"   : __DIR__"shengdian8",
        "west"   : __DIR__"shengdian7",
        "north"   : __DIR__"dian4",
        "south"   : __DIR__"dian2",
      ]));

  setup();
}
