// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�廪ׯ");
  set ("long", @LONG

�廪ׯ��һ��СС�Ŀճ��ӣ�������������������ӵı���
��������Ϫˮ������������������һ���é�ݣ�������·ͨ��
�������ӡ�

LONG);

  set("exits", ([
        "northeast"    : __DIR__"xinan",
        "west"    : __DIR__"yang2",
        "east"    : __DIR__"maowu",
      ]));
  set("outdoors",__DIR__"");
  setup();
}
