inherit ROOM;

void create ()
{
  set ("short", "��������ʥ��");
  set ("long", @LONG

ʥ������ϼ���������Ƿ��������Ͻ������崮�������΢�ζ�
�����죬����һƬ�����������ơ��������ﲻʱ�Ӹ�������
�����о���������

LONG);

  set("exits", ([
        "south"   : __DIR__"dian4",
      ]));
           set("objects", ([
            __DIR__"npc/rulai" :1,
           ]));

  setup();
}
