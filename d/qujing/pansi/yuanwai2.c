// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "Ժ��");
  set ("long", @LONG

Ժ��é�ݴ���������˷˷���˲����е㵨����������һ���ߴ�
��ǽ��ǽ��������һ����ֱͨ�ƻ���Ժ�ڡ������Ǿ�·������
�ڣ���·���С�

LONG);

  set("exits", ([
        "south"    : __DIR__"yuannei",
      ]));
  set("objects", ([
        __DIR__"npc/xie3"    : 1,
        __DIR__"npc/xie4"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

