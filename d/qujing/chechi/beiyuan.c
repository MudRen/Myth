// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/beiyuan.c

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ��յ�������ǽϡϡ��������һЩ������������س��š���
�߷���һ���׵���ˮ�ס��������Ǽ������ƴ��ķ��ӣ������ǽ�
�յ

LONG);

  set("exits", ([
        "north"         : __DIR__"zhaifang",
        "south"         : __DIR__"jingang",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

