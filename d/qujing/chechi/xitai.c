// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xitai.c

inherit ROOM;

void create ()
{
  set ("short", "Ϸ̨");
  set ("long", @LONG

���������İ����������˴���һ�����ɵ����е���ɫ��Ϸ̨��Ϸ
̨���߹�����յ�����ĵ�����ǰ������Щ���ʣ�������һЩ����
�����Ϳ������Ρ�

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi8",
      ]));
  set("objects", ([
        __DIR__"npc/xizi"  : 1,
      ]));

  setup();
}

