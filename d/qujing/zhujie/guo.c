// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��Ѩ�������Ե�ʮ��ӵ�������ߵ�ʯ�����������٣������ϲ�
��һЩ��棬���ṩ���ڵ�����������������ͨ���⹬���
����ͨ�����ȡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"wai",
        "northeast"   : __DIR__"zou",
      ]));

  setup();
}



