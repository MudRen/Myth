// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������յ���ͨ�����ƽ�����¯�����ſ����ɹ����������
����������𡣵��м���ʨ�������ܺ������Ƥ��̺��������
һ�������������鱦����

LONG);

  set("exits", ([
        "east"    : __DIR__"da",
        "south"    : __DIR__"yu",
      ]));
  set("objects", ([
        __DIR__"npc/guozhang"    : 1,
        __DIR__"npc/king"    : 1,
        __DIR__"npc/taijian"    : 1,
      ]));
  setup();
}

