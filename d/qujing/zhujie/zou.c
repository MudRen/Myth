// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ǳ��������ȣ����ߵ�ʯ��ӵ����խ�����ȶ��ϴ��³���
��һ������ʯ�����ϳ���һЩʯ�����ȵ�һͷͨ������Ĺ�
������һͷͨ�������

LONG);

  set("exits", ([
        "east"   : __DIR__"da",
        "southwest"   : __DIR__"guo",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



