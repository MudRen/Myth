// create by snowcat.c 4/20/1997
// room: /d/eastway/ciensi.c

inherit ROOM;

void create ()
{
  set ("short", "�ȶ���");
  set ("long", @LONG

�߽��ȶ��£���������������ΰ�Ĵ��������߲�ͻأ����գ�����׳
�ۡ����ڹŰ�ɭɭ��������Ƭ�������ӹ�¥ңң��ԡ�Ժ��������ʯ
��Ⱥ��ΪһЩ������ʿ����̡�
LONG);

  set("exits", ([
        "out"      : __DIR__"ciensiw",
        "east"     : __DIR__"dyt",
      ]));
  set("objects", ([
        __DIR__"npc/sengren"     : 3,
      ]));
  set("outdoors", __DIR__);

  setup();
}






