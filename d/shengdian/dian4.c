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
        "east"   : __DIR__"shengdian10",
        "west"   : __DIR__"shengdian9",
//        "north"   : __DIR__"dian5",
        "north"   : __DIR__"baodian",
        "south"   : __DIR__"dian3",
      ]));

  setup();
}
