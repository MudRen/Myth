// create by snowcat.c 4/20/1997
// room: /d/eastway/dyt.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������Ϊһ���߲㷽����������ʮ����ΰ�����������
�ͼ��ׯ�����ء������������ţ��������ʯ�̻���

LONG);

  set("exits", ([
        "enter"    : __DIR__"dyt1",
        "west"     : __DIR__"ciensi",
      ]));
  set("outdoors", __DIR__);

  setup();
}






