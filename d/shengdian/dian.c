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
        "east"   : __DIR__"shengdian2",
        "west"   : __DIR__"shengdian1",
        "north"   : __DIR__"dian1",
      ]));

      set("objects", ([ 
                  ]));
  setup();
}
