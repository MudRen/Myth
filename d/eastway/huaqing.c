// create by snowcat.c 4/20/1997
// room: /d/eastway/huaqing.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����ѵ��˳Ǳߣ����˽�������һ�����ص���Ȫ��Ȫˮ�峺����
�����ƣ�Ϊ�޲����ɵļ��ѳ��������������˷׷�Զ��������
���һԡ��
LONG);

  set("exits", ([
        "enter"         : __DIR__"xianquan",
        "northwest"     : __DIR__"guandao3",
      ]));
  set("objects", ([
        __DIR__"npc/luren"     : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}






