// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/simen.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽǰ��һ���ƾɵ������Ѿ���ɫ���Ű��ڰ뿪��������������
�����ƺ�����ܾ��Ѿ�û��ʲô��͹����ˡ����ϵĴ�������Լ
Լ�ɼ�����Ԩ�¡��������֡�

LONG);

  set("exits", ([
        "northwest"    : __DIR__"shanlu4",
        "east"         : __DIR__"jingang",
      ]));

  set("objects", ([
        __DIR__"npc/heshang"    : 2,
      ]));
  set("outdoors","/d/qujing/chechi");
  setup();
}

