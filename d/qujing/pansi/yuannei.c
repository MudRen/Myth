// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "Ժ��");
  set ("long", @LONG

Ժ���������룬��ש��·�̲����񡣶����Ƕ���һЩ��é�ݣ�
��һʯ���ϼ���һͭ��¯������������ש·���ſ����������
ȥ��ͨ��һ�����š�

LONG);

  set("exits", ([
        "west"    : __DIR__"menqian",
        "south"    : __DIR__"zheng",
      ]));
  set("objects", ([
        __DIR__"obj/danlu"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

