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
        __DIR__"npc/xie1"    : 1,
        __DIR__"npc/xie2"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

