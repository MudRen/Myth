// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "��ǰ");
  set ("long", @LONG

һ��¥����ɽ���ﾲ�ԣ�ֻ��ɽ��ͥԺ��Ϫ��̨ͤ�������ܰ�
�أ���������ݺ����һ���ֹ���Ժ������Ƕ��һ��ʯ�ң�����
���ƻ��ۡ��������֡�

LONG);

  set("exits", ([
        "northwest"    : __DIR__"qiaolin6",
        "east"    : __DIR__"yuannei",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

